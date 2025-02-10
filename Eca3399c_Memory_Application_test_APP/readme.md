# Intewell_OS_Normal_Test_Project


## 1.项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。

## 2.说明：

    测试Eac3399c平台，测试TTOS系统中申请内存测试。

## 3.编程风格：

         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写
		 

## 4.程序演示逻辑说明：

此例程演示TTOS的内存申请方法和内存测试。

## 5.此项目为TTOS的App应用项目, 需配合对应的VM（GPOS+MultiRTOS）项目作为测试。配合测试RTOS配置工程文件夹名字：Eca3399c_Memory_Application_test_GPOSMRTOS

工程完成，创建于2023.8.9，可在IDE中导入打开此工程并编译下载运行。


## 6.测试说明：

### 6.1. 软件环境：

	win10 （开发host端）
	天启萤火虫eca3399c自带ubuntu 18.04系统
	在3399c上18.04系统先安装RTRE for aarch64
	开发IDE版本：1.4.0_beta
	可连通内网（网段10.10.8.x，或其他网段）

	
### 6.2. 硬件环境：

	天启 萤火虫rk3399c开发板
	键鼠
	usb HUB
	通用usb网卡（rtl8xxx系列linux自带驱动）
	显示器
	12V DC电源
	网线若干 

	
### 6.3. 详细配合教程/wiki说明：

无

