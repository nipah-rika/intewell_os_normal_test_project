#!/bin/bash
/download/create_img.sh
/usr/bin/qga-serial 1>/dev/null 2>&1 &
/usr/bin/uevent-agent 1>/dev/null 2>&1 &
python /etc/intewell/TTOS_Collect.py &
sync
/etc/intewell/none_rt/reset_net.sh
