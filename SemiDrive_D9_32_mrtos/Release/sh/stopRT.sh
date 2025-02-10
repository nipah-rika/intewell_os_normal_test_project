#!/bin/bash
#free mem
rt mem free 0x70000000 0xf900000
rt mem free 0x7f900000 0x700000
rt mem free 0x80000000 0x24800000
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
rt umount vm2 /nfs_root/
#free shmem
rt shmem delete 0x756e1000 0x4000000
