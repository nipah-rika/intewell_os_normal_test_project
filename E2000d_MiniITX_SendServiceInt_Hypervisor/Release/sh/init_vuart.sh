#!/bin/bash
modprobe vrtc addr=0xa7200000
modprobe vconfig cfg_space_base_addr=0xa7200000 size=0x300000