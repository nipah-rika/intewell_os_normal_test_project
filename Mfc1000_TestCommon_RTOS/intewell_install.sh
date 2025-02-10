#!/bin/bash
while getopts ":d:" opt 
do
  case $opt in 
    d)
      disk_node=$OPTARG
      ;;
    ?)
    echo "parms error"
    exit 1;;
  esac
done
echo $disk_node

#fdisk ${disk_node}
if [ -z $disk_node ]; then
  echo "you must specify a disk!"
  exit 1
fi

fdisk $disk_node << EOF
o
n
p
1
2048

p
w
EOF

mkfs.vfat -F 32 $disk_node"1"

mount $disk_node"1" /mnt
rm -rf /mnt/*

mkdir /mnt/boot

grub-install --boot-director=/mnt/boot $disk_node

mkdir /mnt/boot/grub/recover

cp recover.zip /mnt/boot/grub
unzip -o /mnt/boot/grub/recover.zip -d /mnt/boot/grub/recover
# cp /mnt/boot/grub/recover/grub.cfg /mnt/boot/grub
cp /mnt/boot/grub/recover/* /mnt/boot/grub
sync
umount /mnt
echo "ALL DONE"
