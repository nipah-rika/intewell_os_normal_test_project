项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。

说明：
    测试eac3399c平台，测试的目标是TTOS下多任务的演示，在TTOS应用中，运行多个任务，并打印信息。


编程风格：
         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写
		 
		 
		 
此项目为TTOS的App应用项目作为测试VM，需配合对应的VM（MultiRTOS）项目作为测试。
工程完成，创建于2022.07.07，可在IDE中导入打开此工程。

测试目的，做一个简单的入门工程演示，TTOS下多任务的演示;
让用新户理解如何在TTOS应用中使用多任务/多线程。

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
   网线若干 

	
3. 详细配合教程/wiki说明：
	http://10.10.8.200/mediawiki/index.php/Eca3399c_TTOS基础测试之_001_多任务demo