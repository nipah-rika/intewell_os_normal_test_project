#!/bin/bash
#alloc mem
rt mem alloc 0x40000000 0xf900000
rt mem alloc 0x4f900000 0x700000
rt mem alloc 0x50000000 0x19000000
#load imagefile
rt load 0x50000000 /download/rootAgent.bin
rt load 0x5c800000 /download/vm1.bin
rt load 0x4f900000 /download/config.bin
rt load 0x402e0000 /download/vsc.bin
#alloc cpu
rt cpu alloc 2
rt cpu alloc 3
#create vuart
rt vuart create 0x44de1000
#create vnet
rt vnet create 0x44de1000 3
#create vrtc
rt vrtc create 0x44de1000
#create shmem
rt shmem create 0x456e1000 0x4000000
#mount disk
rt mount rootAgent /nfs_root/  200MB
rt mount vm1 /nfs_root/  200MB
#start cpu
rt cpu start 2 0x402e0000 0x4f900000
