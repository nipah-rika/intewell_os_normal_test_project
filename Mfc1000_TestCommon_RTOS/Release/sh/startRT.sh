#!/bin/bash
#alloc mem
rt mem alloc 0x120000 0xb900000
rt mem alloc 0xba20000 0x700000
rt mem alloc 0x40000000 0x1f400000
#load imagefile
rt load 0xba20000 /download/configtable.bin
rt load 0xba28000 /download/sskCfg.bin
rt load 0xba2d000 /download/hardware.bin
rt load 0xba2e000 /download/hypervisor.bin
rt load 0xba30000 /download/vm1Config.bin
rt load 0x40000000 /download/Mfc1000_Test_TTOS_Mesq_App.bin
rt load 0x400000 /download/vsc.bin
#alloc cpu
rt cpu alloc 0
rt cpu alloc 2
rt cpu alloc 4
rt cpu alloc 6
#create vuart
rt vuart create 0x4f01000
#create vrtc
rt vrtc create 0x4f01000
#alloc pci(netcard)
rt pci alloc 0000:03:00.0
rt pci alloc 0000:04:00.0
#map iommu(netcard)
rt pci iommumap 0000:03:00.0
rt pci iommumap 0000:04:00.0
#install irq
rt irq install "4,3"
#start cpu
rt cpu start 0 0x400000 0xba20000
