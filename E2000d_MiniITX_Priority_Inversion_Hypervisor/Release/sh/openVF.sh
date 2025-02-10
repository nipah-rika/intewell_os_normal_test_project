#!/bin/bash

#get origin status of network card and recored it
nic_list=""
online_nic_list=()

j=0
for i in ${nic_list[@]};do
  nic_interface_name=`ls /sys/bus/pci/devices/$i/net/`
  status=`ethtool $nic_interface_name | grep -i detected | awk '{print $3}'`
  if [[ "yes" == $status ]]; then
    online_nic_list[j]=$nic_interface_name
    let j++
  fi
done


# check pf is ready or not ,if not then keep waiting
for nic in ${online_nic_list[@]}
do
while true
  do
    status=`ethtool $nic | grep -i detected | awk '{print $3}'` 
    if [[ "yes" == $status ]]; then
      break;
    fi
  done
done

if [  -e ./pf.txt ];then
    cat pf.txt |while read line
    do
      #echo $line
      ifconfig $line up > /dev/null
    done
    rm -rf ./pf.txt
else
    exit 0
fi
