#!/bin/bash
export PYTHONPATH="${PYTHONPATH}:/etc/intewell/tools"
python3 /etc/intewell/tools/service/system/host_serial_redirect.py --off
