#!/bin/bash
$DOWNLOAD/allocDevice.sh
$RTENV/hacl load $DOWNLOAD/APP.bin -a 0x90000000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/APP.bin -a 0x90000000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/vsc.bin -a 0x802e0000 -s 0x802e0000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/vsc.bin -a 0x802e0000 -s 0x802e0000 fail"
    exit 1
fi

