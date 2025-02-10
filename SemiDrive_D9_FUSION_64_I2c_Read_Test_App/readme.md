## 1.项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。 
    SemiDrive_D9_FUSION_64_I2c_Read_Test_App

## 2.说明：

    测试菲森电力SemDrive D9平台，测试TTOS系统中使用I2C读取IO状态并计算频率。

## 3.编程风格：

         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写


## 4.程序演示逻辑说明：

此例程演示TTOS的I2C读取IO状态并计算频率的方法，例程中，设置模块I2C地址为0x20。

## 5.此项目为TTOS的App应用项目, 需配合对应的CFG（Gpos+MultiRtos）项目作为测试，配套配置项目：SemiDrive_D9_FUSION_64_I2c_Read_Test_Gposmrtos。

工程完成，创建于2024.01.18，可在IDE中导入打开此工程并编译下载运行。

## 6.测试说明：

### 6.1. 软件环境：

	win10 （开发host端）
	SemiDrive D9 64bit软件环境
	开发IDE版本：Intewell Developer V2.2.0_FUSION_C1_b3
	可连通内网（网段10.10.8.x，或其他网段）
	串口调试工具（putty，secureCRT，powershell等）

### 6.2. 硬件环境：

	菲森电力 SemiDrive D9主板
	TLL串口线（调试串口）
	DC电源
	网线若干 
