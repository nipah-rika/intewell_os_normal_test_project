#!/bin/bash
/download/create_img.sh
task_status=`ps ax | grep /etc/intewell/TTOS | grep -v grep`
if [ ${#task_status} -eq 0 ]; then
    /usr/bin/qga-serial 1>/dev/null 2>&1 &
    /usr/bin/uevent-agent 1>/dev/null 2>&1 &
    python /etc/intewell/TTOS_Collect.py &
    /etc/disk_resize.sh
    sync
fi
