#!/bin/bash
dest_dir=""
rm /etc/exports
touch /etc/exports
exportfs -r
umount $dest_dir/rootAgent
while [ 1 -eq 1 ]
do
    df -h | grep $dest_dir &> /dev/null
    if [ $? -eq 0 ]
    then
        path=`df -h | grep $dest_dir | awk '{print $6}'`
        umount $path -f
    else
        break
    fi
done
