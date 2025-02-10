## 1.项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。 
    SemiDrive_D9_FUSION_64_I2c_TestIoExpander_App

## 2.说明：

    试菲森电力SemDrive D9平台，测试TTOS系统中使用I2C获取或设置io状态的方法。

## 3.编程风格：

         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写


## 4.程序演示逻辑说明：

此例程演示TTOS的I2C的控制方法，配置、读写I2C的方法，例程中，设置模块I2C地址为0x20，对应io0-io4配置为输出，每隔3秒翻转一下io0-io4输出状态。


## 5.测试说明：

### 5.1. 软件环境：

	win10 （开发host端）
	SemiDrive D9 64bit软件环境
	开发IDE版本：Intewell DeveloperV2.3.0_FUSION_C1_b1
	可连通内网（网段10.10.8.x，或其他网段）
	串口调试工具（putty，secureCRT，powershell等）

### 5.2. 硬件环境：

	菲森电力 SemiDrive D9主板
	TLL串口线（调试串口）
	DC电源
	网线若干 
