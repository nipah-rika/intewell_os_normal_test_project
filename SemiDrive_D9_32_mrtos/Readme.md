此项目为GPOS+MultiRTOS项目作为测试，是一个vm需配合app项目作为测试。配置工程，并非完整的项目，需另外配合对应的app项目作为测试。
工程创建于2023.05.29，可在IDE中导入打开工程。

编程风格：
         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写
		 
		 
		 
测试目的：测试网络基于ttos lwip网络组播的简单使用，包括：网络的打开，收发。让用新户理解如何在TTOS应用中使用网络API。

测试说明：
1. 软件环境：
	win10 （开发host端）
	装好对应版本的IDE
	在3399c上18.04系统先安装RTRE for aarch64
	IDE 1.8.2_beta
	可连通内网（网段10.10.8.x）
	串口调试工具
	网络调试工具
	
2. 硬件环境：
   南京芯驰SemiDrive D9官方开发板
   TLL串口线（调试串口）
   键盘、鼠标
   usb HUB
   通用usb网卡（rtl8xxx系列linux自带驱动）
   显示器
   12V DC电源
   网线若干
   交换机一个
	