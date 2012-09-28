#!/bin/sh

if [[ $# < 4 ]]
then
	echo "Insufficient Number of arguments."
	echo "Usage: $0 <name for vmdk> <size of vmdk> <ntfs-name> <ntfs mount point>"
	exit 1
fi

vmdk_name=$1.vmdk
vmdk_size=$2
ntfs_dev=$3
ntfs_mountpath=$4
clustersize=$5
input="./input.file"

echo "[INFO] Input params : $@"

echo "[CMD] vmware-vdiskmanager -c -s $vmdk_size $vmdk_name -t 4 -a lsilogic"
vmware-vdiskmanager -c -s $vmdk_size $vmdk_name -t 4 -a lsilogic

if [ $? -eq 0 ]
then 
	echo "[INFO] VMDK $vmdk_name successfully created.."
else
	echo "[ERROR] VMDK $vmdk_name creation failed."
	exit 1
fi

echo "[INFO] VMDK Files created:" `ls  $1*`

# Get the free loopback device and set it up for VMDK
free_lo_device=`losetup -f`
echo "[INFO] Loopback device in use : $free_lo_device"
echo "[INFO] VMDK FILE in use : $1-flat.vmdk"

losetup -f $1-flat.vmdk
losetup $free_lo_device

# Create the partition over loopback device
/sbin/fdisk  -u $free_lo_device < $input >/dev/null
/sbin/fdisk  -l $free_lo_device

losetup -d $free_lo_device
kpartx_op=`kpartx -l $1-flat.vmdk`

param_dmsetup=`echo $kpartx_op | awk '{print $3 " " $4 " "}'`linear`echo $kpartx_op | awk '{print " "$5 " " $6}'`

echo "[INFO] Parameters to dmsetup $param_dmsetup"

echo "$param_dmsetup" | dmsetup create $ntfs_dev

ls -ll /dev/mapper/

echo "[CMD] mkntfs /dev/mapper/$ntfs_dev -c $clustersize -f"
mkntfs /dev/mapper/$ntfs_dev -c $clustersize -f

#mount -t ntfs-3g /dev/mapper/$ntfs_dev $ntfs_mountpath
#ntfsmount /dev/mapper/$ntfs_dev $ntfs_mountpath
