#!/bin/bash
$RTENV/hacl load $DOWNLOAD/configtable.bin -a 0x7f900000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/configtable.bin -a 0x7f900000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/sskCfg.bin -a 0x7f908000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/sskCfg.bin -a 0x7f908000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0x7f915000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hardware.bin -a 0x7f915000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0x7f916000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/hypervisor.bin -a 0x7f916000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/rootAgentConfig.bin -a 0x7f918000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/rootAgentConfig.bin -a 0x7f918000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0x7f919000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/vm1Config.bin -a 0x7f919000 fail"
    exit 1
fi

$RTENV/hacl load $DOWNLOAD/vm2Config.bin -a 0x7f91a000
if [ $? -ne 0 ]
then
    echo "$RTENV/hacl load $DOWNLOAD/vm2Config.bin -a 0x7f91a000 fail"
    exit 1
fi

