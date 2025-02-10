#!/bin/bash
$RTENV/hacl load $DOWNLOAD/configtable.bin -a 0xba20000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/configtable.bin -a 0xba20000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/sskCfg.bin -a 0xba28000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/sskCfg.bin -a 0xba28000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0xba2d000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0xba2d000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0xba2e000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0xba2e000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0xba30000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0xba30000 fail"
    exit 1
fi

