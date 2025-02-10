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

$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0x4f911000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0x4f911000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0x4f912000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0x4f912000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/rootAgentConfig.bin -a 0x4f914000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/rootAgentConfig.bin -a 0x4f914000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0x4f915000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0x4f915000 fail"
    exit 1
fi

