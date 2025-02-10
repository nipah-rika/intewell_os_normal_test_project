#!/bin/bash
#free mem
rt mem free 0x120000 0xb900000
rt mem free 0xba20000 0x700000
rt mem free 0x40000000 0x1f400000
#free cpu
rt cpu free 0
rt cpu free 2
rt cpu free 4
rt cpu free 6
#delete vuart
rt vuart delete
#delete vrtc
rt vrtc delete
