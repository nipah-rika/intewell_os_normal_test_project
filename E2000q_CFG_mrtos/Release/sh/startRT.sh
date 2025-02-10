#!/bin/bash
#alloc mem
rt mem alloc 0xa0000000 0xf900000
rt mem alloc 0xaf900000 0x700000
rt mem alloc 0xb0000000 0x10000000
#load imagefile
#vmname=rootAgent
rt load 0xb0000000 /download/rootAgent.bin
#vmname=vm1
rt load 0xb8000000 /download/test_e2000q_spi_app.bin
#vmname=config
rt load 0xaf900000 /download/config.bin
#vmname=vsc
rt load 0xa02e0000 /download/vsc.bin
#alloc cpu
rt cpu alloc 3
#create vuart
rt vuart create 0xa7200000
#create vnet
rt vnet create 0xa7200000 2
#create vrtc
rt vrtc create 0xa7200000
#create shmem
rt shmem create 0xa7b00000 0x4000000
#mount disk
rt mount rootAgent /nfs_root/  128MB
rt mount vm1 /nfs_root/  128MB
#start cpu
rt cpu start 3 0xa02e0000 0xaf900000
