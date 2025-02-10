#!/bin/bash
#free mem
rt mem free 0xa0000000 0xf900000
rt mem free 0xaf900000 0x700000
rt mem free 0xb0000000 0x10000000
#free cpu
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
rt shmem delete 0xa7b00000 0x4000000
