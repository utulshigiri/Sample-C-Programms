#!/usr/bin/python

import sys, os, subprocess, time, shlex, heapq
from pprint import pprint

if (len(sys.argv) != 3):
	print "Insufficient number of arguments."
	print "Usage : " + sys.argv[0] + " <userpathi> <clustersize for NTSF>"
	sys.exit()

user_path = sys.argv[1]
blocksize = sys.argv[2]
empty_bkp = 0
bkp_dict = {}
lst1 = []
full_bkp_gen = [3, 10, 17, 22, 29, 36, 41, 48]

def list_bkp_for_user(usr_path):
    f = open(usr_path+"workstations.filelist", 'w+r')
    cmd="./filelist_nw.pl " + usr_path
    args = shlex.split(cmd)
    p = subprocess.Popen(args, stdout=f)
    p.communicate()
    f.close()

def exec_cmd(cmd):
    print "[CMD] : " + cmd
    subprocess.call(cmd, shell=True)

def print_map():
    global lst1,user_path
    version = 0
    stdout = sys.stdout
    sys.stdout = open(user_path+"bkp.map", 'w+r')
    print "----" * 40
    print "VMDK \t\t\t\t\tRestored from Backup\t\t\t\t\t\t\t\tDate & Time\t\tSize in GiB"
    print "----" * 40
    for i in lst1:
	print "gen"+ str(version) + "\t" + i[0] + "\t" + str(i[1]) + "\t" + str(i[2]) 
	version = version + 1
    print "----" * 40
    sys.stdout = stdout

def print_dict():
    global bkp_dict,user_path
    stdout = sys.stdout
    sys.stdout = open(user_path+"bkp.map", 'w+r')
    for i in range(len(bkp_dict.keys())):
	print bkp_dict.keys()[i] + " " + str(bkp_dict.values()[i][0]) + " " + str(bkp_dict.values()[i][1])
    sys.stdout = stdout

def get_vmdk_size():
    global lst1
    tmp = []
    for i in lst1:
        tmp.append(i[2])
    return max(tmp) + max(tmp) + (0.1 * max(tmp))
	
def create_bkp_map(path):
    global user_path
    f = open(user_path+"workstations.filelist", 'r+b')
    global empty_bkp, bkp_dict
    for line in f.readlines():
        if "notes" not in line:
            bkp_file = line.split()[0]
	    bkp_time = line.split()[1]
            bkp_size = float(line.split()[2])
            bkp_sz_byte = os.stat(bkp_file).st_blocks*512

            if (bkp_sz_byte == 512):
                    empty_bkp = empty_bkp + 1
            else:
		    bkp_dict.setdefault(bkp_file, [  ]).append(bkp_sz_byte)
		    bkp_dict.setdefault(bkp_file, [  ]).append(bkp_time)

                   
def create_bkp_map1(path): 
    global user_path
    f = open(user_path+"workstations.filelist", 'r+b')
    global lst1, empty_bkp 
    for line in f.readlines():
        if "notes" not in line:
            bkp_file = line.split()[0]
            bkp_time = line.split()[1]
            bkp_size = float(line.split()[2])
	    bkp_sz_byte = os.stat(bkp_file).st_blocks*512

            if (bkp_sz_byte == 512):
                    empty_bkp = empty_bkp + 1

	    else:
		    lst = [bkp_file, bkp_time, bkp_size]
            	    lst1.append(lst)

def mount_bkp(bkp_name):
    cmd = "ntfs-3g -o user_xattr /dev/mapper/" + bkp_name
    exec_cmd(cmd)

def unmount_bkp(bkp_dev):
    cmd = "umount /dev/mapper/" +  bkp_dev
    exec_cmd(cmd)


# main    
print "Creating VMDKs for User : " + user_path.split('/')[-2]
list_bkp_for_user(user_path)
create_bkp_map1(user_path)
print_map()

print "Total Non-Empty Backups : " + str(len(lst1))
print "Total Empty Backups : " + str(empty_bkp)

#print heapq.nlargest(2, L)

#print heapq.nlargest(int(len(L)/30), L)[int(len(L)/30) - 1]
#base_vmdk = max(L) + heapq.nlargest(int(len(L)/30), L)[int(len(L)/30) - 1] + 1 # TEMP
#base_vmdk = base_vmdk / ( 1024 * 1024 * 1024)

base_vmdk = get_vmdk_size()
print "Base VMDK Size in GB: " + str(base_vmdk)

# Create the gen0 VMDK
script_base =  "/mnt/dd580/workstations2/ujwala/mnt/" + user_path.split('/')[-2] + "/WITH-DEL/"
mount_dir = script_base + "gen0"       # TEMP

vmdk_base =  "/mnt/dd580/workstations2/ujwala/VMDK/" + user_path.split('/')[-2] + "/WITH-DEL/"

if not os.path.exists(mount_dir):
        os.makedirs(mount_dir)

if not os.path.exists(vmdk_base):
        os.makedirs(vmdk_base)

cmd = " ./create_vmdk.sh " + vmdk_base + "gen0 " + str(base_vmdk) + "G " + " gen0 "  + mount_dir + " " + blocksize
exec_cmd(cmd)

cmd = "ntfs-3g /dev/mapper/gen0 " + mount_dir
exec_cmd(cmd)

print (lst1[0])[0]
cmd = "cat " + (lst1[0])[0] + " | /mnt/home/pshilane/bin/uasm -rv -m /=" + mount_dir + " -i N"
exec_cmd(cmd)

unmount_bkp("gen0")

j = 1
for i in range(1, 50):#len(lst1)):						# TEMP
	gen = "gen" + str(i)
	gen_prev = "gen" + str(i-1)
	gen_temp = "gen_temp"
	mount_dir = script_base + gen	# TEMP
	if not os.path.exists(mount_dir):     
		os.makedirs(mount_dir)

	cmd = "vmware-vdiskmanager -r " + vmdk_base + gen_prev + ".vmdk -t 4 " + vmdk_base + gen + ".vmdk"
        exec_cmd(cmd)

	cmd = "./tmp_cr.sh " + vmdk_base + gen + " " +  gen + " " + mount_dir
	exec_cmd(cmd)

	mount_tmp = script_base + gen_temp       # TEMP
	if not os.path.exists(mount_tmp):
	        os.makedirs(mount_tmp)

	cmd = "./create_vmdk.sh "+ vmdk_base + gen_temp + " " + str(base_vmdk) + "G " + gen_temp + " " + mount_tmp + " " + blocksize
        exec_cmd(cmd)

        mount_bkp(gen + " " + mount_dir)
	mount_bkp(gen_temp + " " + mount_tmp)

	count_temp = 0;
	while True:
		cmd = "./extract_bkup.sh " + (lst1[j+count_temp])[0] + " " + mount_tmp
        	exec_cmd(cmd)
		print (lst1[j + count_temp])[1].split(":")[0], #str(lst1[i+count_temp+1])[2].split(':')[1]
		if (lst1[j + count_temp])[1].split(':')[0] != (lst1[j + 1 + count_temp])[1].split(':')[0]:
			print (lst1[j + count_temp])[1].split(':')[0],
			print (lst1[j + count_temp + 1])[1].split(':')[0]
			break;
		else:
			print "[INFO] Sanme Day Backup."
			count_temp = count_temp + 1

	if i in full_bkp_gen:
		print "Full backup to be synced"
		delete = 1
	else:
		delete = 0

	j = j + 1 + count_temp

        cmd = "./rsync.sh " + mount_tmp + " " + mount_dir + " " + str(delete)
        exec_cmd(cmd)

	unmount_bkp(gen_temp)
	unmount_bkp(gen)

	cmd = "dmsetup remove " + gen_temp
	exec_cmd(cmd)

	cmd = "losetup -d /dev/loop2" 
	exec_cmd(cmd)
	
        cmd = "rm -rf " + vmdk_base + gen_temp + "*"
        exec_cmd(cmd)

	os.system("dmsetup remove " + gen_prev)
	for i in range(0,7):
		os.system("losetup -d /dev/loop" + str(i))	

