#!/bin/bash
dest_dir=""
need_format=0
num=0
i=0
cfg_img_size=0
vm_name=("vm1")
vm_limit_size=(
#create nfs root dir
mkdir -p $dest_dir &> /dev/null
chmod 0777 $dest_dir

#check nfs root dir in /etc/exports,if not exsit,create it
dir=`cat /etc/exports | grep -w $dest_dir |awk -v dir=$dest_dir '$1==dir{print dir;exit}'`
if [ "$dir" != "$dest_dir" ]
then
    echo "$dest_dir *(rw,sync,no_subtree_check,all_squash,anonuid=0,anongid=0,nohide)" >> /etc/exports
    exportfs -r
fi

while [ $i -lt ${#vm_name[@]} ]
do
    vm_dir=${vm_name[$i]}
    vm_dir_limit_size=${vm_limit_size[$i]}

    #if vm disk img file not exist
    ls /dev/vg/$vm_dir &> /dev/null
    if [ $? -ne 0 ]
    then
    #create lvm disk img
        lvcreate -L $vm_dir_limit_size"b" -n $vm_dir vg -y
        mke2fs -t ext4 /dev/vg/$vm_dir >& /dev/null
    else
        img_size=`lvs --units b | grep -w $vm_dir | awk '{print $4}' | sed s'/.$//'`
         # get cfg disk size data
        cfg_img_size=$vm_dir_limit_size
        t1=`echo "${img_size} < ${cfg_img_size}" | bc`
        t2=`echo "${img_size} > ${cfg_img_size}" | bc`
        if [ 1 -eq $t1 ]
        then
            lvresize -L $cfg_img_size"b" /dev/vg/$vm_dir >& /dev/null
            resize2fs /dev/vg/$vm_dir >& /dev/null
        elif [ 1 -eq $t2 ]
        then
            umount -f /dev/vg/$vm_dir
            lvremove /dev/vg/$vm_dir -y >& /dev/null
            lvcreate -L $vm_dir_limit_size"b" -n $vm_dir vg -y
            mke2fs -t ext4 /dev/vg/$vm_dir  >& /dev/null
        fi
    fi

    mkdir $dest_dir/$vm_dir &> /dev/null

    #check vm dir is exist /etc/exprots ? not exist, add it
    dir=`cat /etc/exports | grep $dest_dir/$vm_dir |awk -v dir=$dest_dir/$vm_dir '$1==dir{print dir; exit}'`
    if [ "$dir" != "$dest_dir/$vm_dir" ]
    then
        echo "$dest_dir/$vm_dir *(rw,sync,no_subtree_check,all_squash,anonuid=0,anongid=0,nohide)" >> /etc/exports
        exportfs -r
    fi

    #check vm disk img is mount on its dir? not,mount it
    df -h | grep $dest_dir/$vm_dir &> /dev/null
    if [ $? -ne 0 ]
    then
        mount /dev/vg/$vm_dir $dest_dir/$vm_dir
        if [ $? -ne 0 ]
        then
            echo "mount $new_loop $dest_dir/$vm_dir failed"
            exit 1
        fi
    fi
    let i++

done

chmod -R 0777 $dest_dir
#used by ttos reboot func
mkdir -p $dest_dir/rootAgent
mount --bind /download $dest_dir/rootAgent
if [ $? -ne 0 ]
then
    echo "mount /download to rootAgent err"
    exit 1
fi

exit 0
