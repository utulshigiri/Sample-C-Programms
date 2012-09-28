#!/bin/sh

free_lo_device=`losetup -f`
echo "Loopback device in use : $free_lo_device"
echo "VMDK FILE in use : $1-flat.vmdk"

input="./input.file"
ntfs_dev=$2
ntfs_mountpath=$3

losetup -f $1-flat.vmdk
losetup $free_lo_device

# Create the partition over loopback device
#/sbin/fdisk  -u $free_lo_device < $input >/dev/null
/sbin/fdisk  -l $free_lo_device

losetup -d $free_lo_device
kpartx_op=`kpartx -l $1-flat.vmdk`

param_dmsetup=`echo $kpartx_op | awk '{print $3 " " $4 " "}'`linear`echo $kpartx_op | awk '{print " "$5 " " $6}'`

echo $param_dmsetup

echo "$param_dmsetup" | dmsetup create $ntfs_dev

ls -ll /dev/mapper/

#mount -t ntfs-3g /dev/mapper/$ntfs_dev $ntfs_mountpath
