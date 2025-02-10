#!/bin/bash
$DOWNLOAD/allocDevice.sh
$RTENV/hacl load $DOWNLOAD/Mfc1000_Test_TTOS_Mesq_App.bin -a 0x40000000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/Mfc1000_Test_TTOS_Mesq_App.bin -a 0x40000000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/vsc.bin -a 0x400000 -s 0x400000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/vsc.bin -a 0x400000 -s 0x400000 fail"
    exit 1
fi

