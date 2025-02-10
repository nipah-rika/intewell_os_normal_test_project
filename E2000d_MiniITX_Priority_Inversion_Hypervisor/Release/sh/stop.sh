#!/bin/bash
$RTENV/vnet_exit.sh
$RTENV/hacl disable
$DOWNLOAD/umnt_vir_disk.sh
modprobe -r hacl
modprobe -r powermanager
kill -s 10 $(pgrep -f "open_vcfg")
