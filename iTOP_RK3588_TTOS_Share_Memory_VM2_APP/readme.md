# Intewell_OS_Normal_Test_Project


## 1.项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。

## 2.说明：

    测试iTOP_RK3588平台，测试TTOS系统中共享内存测试。

## 3.编程风格：

         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写
		 

## 4.程序演示逻辑说明：

此例程演示TTOS的共享内存测试。

## 5.此项目为TTOS的App应用项目, 需配合对应的cfg以及os项目作为测试。配合测试RTOS配置工程文件夹名字分别是：iTOP_RK3588_TTOS_Share_memory_GPOSMRTOS、iTOP_RK3588_TTOS_Share_memory_OS

工程完成，创建于2024.1.5，可在IDE中导入打开此工程并编译运行。


## 6.测试说明：

### 6.1. 软件环境：

	win10 （开发host端）
	Intewell版本：V1.9.0_DKS3588_C1_b8
	开发IDE版本：V1.9.0_DKS3588_C1_b8
	可连通内网（网段192.168.1.x，或其他网段）

	
### 6.2. 硬件环境：

	iTOP_RK3588开发板
	TLL串口线（调试串口）
	12V Delippo电源
	网线若干
	交换机
	
### 6.3. 详细配合教程/wiki说明：

无

