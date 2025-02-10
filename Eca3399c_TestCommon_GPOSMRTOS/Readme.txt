项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。

说明：

    测试eac3399c平台，测试的目标是TTOS系统API的使用方法。

此项目为GPOS+MultiRTOS项目, 不能单独下载编译，需配合对应的app项目作为测试。
此工程配合各种基于Eca3399c的测试项目使用，例如：Eca3399c_Test_multi_task_APP，Eca3399c_Test_TTOS_timer_App， Eca3399c_Test_TTOS_Sema_App等等。

工程完成，创建于2022.07.07，可在IDE中导入打开此工程。


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
