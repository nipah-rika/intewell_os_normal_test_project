#!/bin/bash
#free mem
rt mem free 0x40000000 0xf900000
rt mem free 0x4f900000 0x700000
rt mem free 0x50000000 0x19000000
#free cpu
rt cpu free 2
rt cpu free 3
#delete vuart
rt vuart delete
#delete vnet
rt vnet delete
#delete vrtc
rt vrtc delete
#unmount disk
rt umount rootAgent /nfs_root/
rt umount vm1 /nfs_root/
#free shmem
rt shmem delete 0x456e1000 0x4000000
