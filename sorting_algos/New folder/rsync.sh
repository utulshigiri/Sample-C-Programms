#!/bin/sh

# This script rsync the next incremental / full with cloned vmdk backup

if [[ $# != 3 ]]
then
	echo "Error : Insufficient number of arguments."
	echo "Usage : $0 <Source Dir/File> <Destination Dir/File>"
	exit 1
fi

echo $3

if [[ $3 = 1 ]]
then
	echo "Its full to be rsynched"
	echo "rsync --times --hard-links --executability --acls --xattrs  --perms --links --stats --inplace --delete -r $1/ $2"
	rsync --times --hard-links --executability --acls --xattrs  --perms --links --stats --inplace --delete -r $1/ $2
else
	echo "Its incremental"
	echo "rsync --times --hard-links --executability --acls --xattrs  --perms --links --stats --inplace -r $1/ $2"
	rsync --times --hard-links --executability --acls --xattrs  --perms --links --stats --inplace -r $1/ $2
fi
