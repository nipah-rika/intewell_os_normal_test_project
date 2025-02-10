## 1.项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。 
    SemiDrive_D9_YONGE_Lwip_Net_Set_Addr_Test_App

## 2.说明：

    测试YONGE SemDrive D9平台，TTOS系统的网络测试。

## 3.编程风格：

         函数linux/类unix风格
         局部变量：匈牙利命名法
         全局变量：匈牙利命名法
         宏定义：linux风格 大写


## 4.程序演示逻辑说明：

此例程演示TTOS在网络使用中修改ip、gateway、netmask。

## 5.此项目为TTOS的App应用项目, 需配合对应的CFG（Gpos+MultiRtos）项目作为测试，配套配置项目：SemiDrive_D9_YONGE_Lwip_Net_Set_Addr_Test_Gposmrtos项目作为测试

工程完成，创建于2024.02.23，可在IDE中导入打开此工程并编译下载运行。

## 6.测试说明：

### 6.1. 软件环境：

	win10 （开发host端）
	开发IDE版本：Intewell Developer V2.2.0_YONGE_C1_b8
	可连通内网（网段10.10.8.x，或其他网段）
	NetAssist网络调试工具

### 6.2. 硬件环境：

	YONGE SemiDrive D9主板
	Type-c（调试串口）
	12V电源
	网线若干 
