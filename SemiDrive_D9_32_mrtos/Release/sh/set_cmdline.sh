#!/bin/bash
sync
cmd_line="stmmacmask=0x0 nohugeiomap pci=assign-busses idle=poll nohalt memmap=4K\\\$0x1000 memmap=4K\\\$0x42000 memmap=256M\\\$0x70000000 memmap=7M\\\$0x7f900000 memmap=768M\\\$0xc0000000  dmamap=768M@0xc0000000 dmamap=32M@0x72de1000"
grub_file="/boot/efi/EFI/BOOT/grub.cfg"
NO_REBOOT="Reboot is NOT needed"
NEED_REBOOT="Please reboot"
function get_cmd_line()
{
    linux_cfg=`grep  ro $grub_file | grep linux | grep vmlinu`
    linux_cfg=${linux_cfg//\"/}
    linux_cfg_tail=${linux_cfg#*ro }
    linux_cfg_head=${linux_cfg%ro *}
    linux_cfg_line=`grep -n ro $grub_file | grep linux | awk -F: '{ print $1 }'`
}

function set_cmd_line()
{
    if [ "$cmd_line" == "$linux_cfg_tail" ]
    then
        echo $NO_REBOOT
        exit 0
    else
        new_cmd_line=${linux_cfg_head}" ro "${cmd_line}
        new_cmd_line=${new_cmd_line//\\/\\\\}
        sed -i "${linux_cfg_line}s#.*#$new_cmd_line#" $grub_file
        echo $linux_cfg_tail
        echo "---->"
        echo $cmd_line
        echo $NEED_REBOOT
    fi
}

if [ ! -e "$grub_file" ]
then
    echo $NO_REBOOT
    exit 0
else
    get_cmd_line
    set_cmd_line
fi
