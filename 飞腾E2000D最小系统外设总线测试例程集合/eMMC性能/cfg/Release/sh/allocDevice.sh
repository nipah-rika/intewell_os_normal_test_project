#!/bin/bash
pci-unbind 0000\:0\:0\.0
pci-unbind 0000\:0\:0\.0
pci-unbind 0000\:0\:0\.0
iommumap 0 0 0
iommumap 0 0 0
iommumap 0 0 0
modprobe -r active_serial
modprobe active_serial irq_num=,,,,,,,,
