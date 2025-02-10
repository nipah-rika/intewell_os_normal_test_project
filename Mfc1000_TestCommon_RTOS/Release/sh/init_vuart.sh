#!/bin/bash
modprobe vrtc addr=0x4f01000
modprobe vconfig cfg_space_base_addr=0x4f01000 size=0x300000