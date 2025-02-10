#!/bin/bash
pci-unbind 0000\:03\:00\.0
pci-unbind 0000\:04\:00\.0
iommumap 03 00 0
iommumap 04 00 0
modprobe -r active_serial
modprobe active_serial irq_num=4,3
