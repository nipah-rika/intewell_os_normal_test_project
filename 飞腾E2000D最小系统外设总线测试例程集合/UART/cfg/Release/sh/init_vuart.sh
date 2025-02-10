#!/bin/bash
modprobe vrtc addr=0x87200000
modprobe vconfig cfg_space_base_addr=0x87200000 size=0x300000