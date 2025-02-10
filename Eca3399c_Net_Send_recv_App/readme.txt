此项目为TTOS arm的应用项目，还需配合GPOS+MultiRTOS项目作为测试，测试源码在src文件夹中。
工程创建于2022.07.05，可在IDE中导入打开工程。


编程风格：
         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写
		 
		 
		 
测试目的：测试网络基于ttos API的简单使用，包括：网络的打开，收发。让用新户理解如何在TTOS应用中使用网络API。

测试说明：
1. 软件环境：
	win10 （开发host端）
	天启萤火虫eca3399c自带ubuntu 18.04系统
	在3399c上18.04系统先安装RTRE for aarch64
	IDE 1.8.2_beta
	可连通内网（网段10.10.8.x）
	PC端串口调试工具
	PC端网络调试工具
	
2. 硬件环境：
	win10 PC，开发机
	天启萤火虫eca3399c开发板
	高速usb转串口
	显示器（hdmi接口）
	usb HUB
	usb网卡
	网线
	鼠标键盘
	
3. 详细配合教程/wiki说明：
	http://10.10.8.200/mediawiki/index.php/Eca3399c网络基于TTOS的socket_demo记录步骤#0x09._.E8.BF.90.E8.A1.8C.E9.A1.B9.E7.9B.AE