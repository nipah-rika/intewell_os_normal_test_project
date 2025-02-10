#!/bin/bash
$RTENV/hacl load $DOWNLOAD/configtable.bin -a 0xaf900000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/configtable.bin -a 0xaf900000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/sskCfg.bin -a 0xaf908000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/sskCfg.bin -a 0xaf908000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0xaf911000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0xaf911000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0xaf912000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0xaf912000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/rootAgentConfig.bin -a 0xaf914000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/rootAgentConfig.bin -a 0xaf914000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0xaf915000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0xaf915000 fail"
    exit 1
fi

