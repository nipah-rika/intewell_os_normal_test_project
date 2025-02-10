## 1.项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。 
    SemiDrive_D9_FUSION_64_I2c_TestIoExpander_App

## 2.说明：

    试菲森电力SemDrive D9平台，测试TTOS系统中使用SPI驱动。

## 3.编程风格：

         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写


## 4.程序演示逻辑说明：

此例程演示TTOS的HT7038的控制方法,SPI接口通讯,演示读取芯片内部DeviceID(固定为0x7126A0),ChipID(0x7026E0),采集内部温度传感器数据，采集3相电压通道数据。
注意，只需观察读取内部芯片DeviceID，ChipID是否读取正确即可判断SPI是否功能正常。采集温度传感器和采用电压通道数据是应用层需要做的事情，这是只是做简单代码演示。


## 5.测试说明：

### 5.1. 软件环境：

	win10 （开发host端）
	SemiDrive D9 64bit软件环境
	开发IDE版本：Intewell DeveloperV2.3.0_FUSION_C1_b2
	可连通内网（网段10.10.8.x，或其他网段）
	串口调试工具（putty，secureCRT，powershell等）

### 5.2. 硬件环境：

	菲森电力 SemiDrive D9主板
	TLL串口线（调试串口）
	DC电源
	网线若干 
