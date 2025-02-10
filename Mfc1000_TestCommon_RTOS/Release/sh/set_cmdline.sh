#!/bin/bash
sync
cmd_line="intel_iommu=on intremap=on nox2apic hpet=disable nohugeiomap pci=assign-busses idle=poll nohalt intel_pstate=disable intel_idle.max_cstate=0 processor.max_cstate=0 nomodeset i915.enable_gvt=0  memmap=4K\\\$0x1000 memmap=4K\\\$0x42000 memmap=185M\\\$0x120000 memmap=7M\\\$0xba20000 memmap=1024M\\\$0x1c0000000  dmamap=1024M@0x1c0000000 dmamap=32M@0x2f01000"
grub_file="/boot/grub/grub.cfg"
proc_cmdline="/proc/cmdline"
function get_cmd_line()
{
    linux_cfg=`grep  ro $grub_file | grep linux`
    if [ -z "$linux_cfg" ]
    then
        echo "failed to execute grep ro $grub_file, plese check whether $grub_file is exist and in right format"
        exit 1
    fi
    linux_cfg=${linux_cfg//\"/}
    linux_cfg_tail=${linux_cfg#*ro }
    linux_cfg_head=${linux_cfg%ro *}
    linux_cfg_line=`grep -n ro $grub_file | grep linux | awk -F: '{ print $1 }'`
}

function set_cmd_line()
{
    proc_cmdline_content=`cat /proc/cmdline`
    proc_tail=${proc_cmdline_content#*ro }
    proc_tail=${proc_tail//\"/}
    modify_cmd_line=${cmd_line//\\}
    vara=`echo $modify_cmd_line| xargs`
    varb=`echo $proc_tail| xargs`
    if [ "$vara" == "$varb" ]
    then
        echo "new command line and old command line are the same"
        exit 0
    else
        new_cmd_line=${linux_cfg_head}" ro "${cmd_line}
        new_cmd_line=${new_cmd_line//\\/\\\\}
        sed -i "${linux_cfg_line}s#.*#$new_cmd_line#" $grub_file
           echo $vara
        echo "---->"
           echo $varb
    fi
}

get_cmd_line
set_cmd_line
