#!/bin/sh

# This script extract the given backup file into given output directory using uasm tool

bkup_path=$1
dest_path=$2

if [ $# -ne 2 ]
then
	echo "Incorrect number of arguments..."
	echo "Usage: ./extract_bkup.sh <absolute path of backup file> <absolute path of destination folder>"
	exit 1
fi

cat $1  | /mnt/home/pshilane/bin/uasm -rv -m /=$2 -i N
