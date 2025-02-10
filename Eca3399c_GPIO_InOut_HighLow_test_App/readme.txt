项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。
例如：
Eca399c_Usart_Send_test_GposRtos
表示测试eac3399c平台，测试的目标组件是串口，测试目的是发送，测试的工程是GPOS+RTOS


编程风格：
         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写
		 

此项目是一个TTOS应用项目，需配合对应的RTOS项目作为测试。
工程完成，创建于2022.07.06，可在IDE中导入打开此工程。

测试目的，做一个简单的入门工程演示，控制GPIO，测试网络基于ttos GPIO打开、读写的简单使用
让用新户理解如何在TTOS应用中使用GPIO基本流程。

测试说明：
1. 软件环境：
	win10 （开发host端）
	天启萤火虫eca3399c自带ubuntu 18.04系统
	在3399c上18.04系统先安装RTRE for aarch64
	IDE 1.8.2_beta
	可连通内网（网段10.10.8.x）
	串口调试工具（putty，secureCRT等）

	
	
2. 硬件环境：
   天启 萤火虫rk3399c开发板
   TLL串口线（调试串口）
   键鼠
   usb HUB
   通用usb网卡（rtl8xxx系列linux自带驱动）
   显示器
   12V DC电源
   u盘一个
   网线若干 
   双母头杜邦线，用于改变IO状态
   示波器 或者 万用表 或者 LED灯，用于直观测量IO状态。
	
3. 详细配合教程/wiki说明：
	http://10.10.8.200/mediawiki/index.php/0x002_入门教程:Eca3399c_Intewell_ROTS_GPIO使用简单demo详细教程