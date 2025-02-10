## 1.项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。 
    SemiDrive_D9_FUSION_64_I2c_TestIoExpander_App

## 2.说明：

    试菲森电力SemDrive D9平台，测试TTOS系统中在定时器中断里面进行AD7616采样。

## 3.编程风格：

         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写


## 4.程序演示逻辑说明：

此例程演示TTOS的在定时器中断里面进行AD7616采样的控制方法,156us采样一次,在定时器中断里面进行触发采样,轮询BUSY引脚采样完成然后进行SPI接口通讯,演示读取芯片内的ADC测试通道数据输出,当通道选择测试通道时，AD7616会一直输出0XAA(固定值,芯片数据手册上有)。
突发模式，序列化模式，基本模式都已调通



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
