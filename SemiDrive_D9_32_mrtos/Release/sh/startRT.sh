#!/bin/bash
#alloc mem
rt mem alloc 0x70000000 0xf900000
rt mem alloc 0x7f900000 0x700000
rt mem alloc 0x80000000 0x24800000
#load imagefile
rt load 0x80000000 /download/rootAgent.bin
rt load 0x98000000 /download/app_semidrive_multicast_test.bin
rt load 0x9e400000 /download/app_semidrive_multicast_test_vm2.bin
rt load 0x7f900000 /download/config.bin
rt load 0x702e0000 /download/vsc.bin
#alloc cpu
rt cpu alloc 2
rt cpu alloc 3
#create vuart
rt vuart create 0x74de1000
#create vnet
rt vnet create 0x74de1000 3
#create vrtc
rt vrtc create 0x74de1000
#create shmem
rt shmem create 0x756e1000 0x4000000
#mount disk
rt mount rootAgent /nfs_root/  200MB
rt mount vm1 /nfs_root/  100MB
rt mount vm2 /nfs_root/  100MB
#start cpu
rt cpu start 2 0x702e0000 0x7f900000
