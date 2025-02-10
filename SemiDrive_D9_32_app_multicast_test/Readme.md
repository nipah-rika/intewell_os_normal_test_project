项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。

说明：

    测试SemiDrive D9 32bit官方平台，测试的目标是TTOS系统lwip 组播的使用方法。

此项目为GPOS+MultiRTOS项目, 不能单独下载编译，需配合对应的app项目作为测试。
此工程配合各种基于SemiDrive D9的测试项目使用，例如：SemiDrive_D9_32_app_multicast_test，SemiDrive_D9_32_app_multicast_test2等等。

工程完成，创建于2023.05.29，可在Intewell的IDE中导入打开此工程。IDE版本是： InteWell Developer V1.9.0_FeatureD9_C1_b5


测试说明：
1. 软件环境：
	win10 （开发host端）
	SemiDrive D9 32bit自带编译环境的，ubuntu 18.04系统
	在SemiDrive D9 32bit开发板先安装RTRE for arm（D9的rtre）
	InteWell Developer V1.9.0_FeatureD9_C1_b5
	可连通内网（网段10.10.8.x），可ssh登录开发板
	串口调试工具（putty，MobaXterm，secureCRT等）

	
	
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
