## 1.项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。 
    SemiDrive_D9_FUSION_64_Fatfs_File_Test_App

## 2.说明：

    测试菲森电力SemDrive D9平台，测试TTOS系统的Fat文件系统文件的创建、读、写、删除、重命名操作。

## 3.编程风格：

         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写


## 4.程序演示逻辑说明：

此例程演示TTOS的Fat文件系统文件的创建、读、写、删除、重命名操作。

## 5.此项目为TTOS的App应用项目, 需配合对应的CFG（Gpos+MultiRtos）项目作为测试，配套配置项目：SemiDrive_D9_FUSION_64_Fatfs_File_Test_Gposmrtos项目作为测试

工程完成，创建于2024.02.5，可在IDE中导入打开此工程并编译下载运行。

## 6.测试说明：

### 6.1. 软件环境：

	win10 （开发host端）
	SemiDrive D9 64bit软件环境
	开发IDE版本：Intewell Developer V2.2.0_FUSION_C1_b4
	可连通内网（网段10.10.8.x，或其他网段）
	串口调试工具（putty，secureCRT，powershell等）

### 6.2. 硬件环境：

	菲森电力DTU SemiDrive D9主板
	TLL串口线（调试串口）
	DC电源
	网线若干 
