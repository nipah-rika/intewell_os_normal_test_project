#!/bin/bash
$RTENV/hacl load $DOWNLOAD/configtable.bin -a 0x4f900000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/configtable.bin -a 0x4f900000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/sskCfg.bin -a 0x4f908000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/sskCfg.bin -a 0x4f908000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0x4f90e000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0x4f90e000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0x4f90f000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0x4f90f000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0x4f911000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0x4f911000 fail"
    exit 1
fi

