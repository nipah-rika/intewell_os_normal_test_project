# Intewell_OS_Normal_Test_Project


### 目标是让用户更容易上手Intewell os，努力图、文、源码、教程同时并茂，完整地带领客户使用工程，建议搭配说明或者wiki链接。
欢迎大家贡献。说明文档基于Markdown语法编写，需要用Markdown渲染器打开更为美观。


* 本工程，用于存放通用简单测试程序，一般的接口测试，以及基础基本的TTOS使用测试demo，除特殊声明除外，默认基于IDE 1.8.2 beta版本；
* 项目以文件夹为单位，命名方式：设备型号+测试组件+测试目的+工程类型，大驼峰方式。

		例如：
			Eca399c_Usart_Send_test_GposRtos
			表示测试eac3399c平台，测试的目标组件是串口，测试目的是发送，测试的工程是GPOS+RTOS。其中APP表示测试源码（测试源码兼容，和平台、板级无关），cfg、rtos、mrtos表示对应的配置工程，和平台板级相关。

* 每个工程下面应该写一个readme.txt文本文件，说明测试的软硬环境，测试教程参考链接等。详见具体工程。

## 工程说明列表：

| 名称 | 测试内容 | 备注 |
| :-----| :----: | :----: |
| Eca3399c_GPIO_InOut_HighLow_test_App | 测试3399平台GPIO控制的应用程序工程以及源码 | NULL |
| Eca3399c_GPIO_InOut_HighLow_test_RTOS | 测试3399平台GPIO控制应用程序对应的RTOS配置工程+MultiRTOS配置项目 | NULL |
| Eca3399c_Memory_Application_test_APP| 测试3399平台的内存申请方法和内存测试的应用程序工程以及源码 | NULL |
| Eca3399c_Memory_Application_test_GPOSMRTOS| 测试3399平台的内存申请方法和内存测试对应的RTOS配置工程+MultiRTOS配置项目 | NULL |
| Eca3399c_Net_Send_recv_App | 测试3399平台的网络收发API的应用程序工程以及源码 | NULL |
| Eca3399c_Net_Send_recv__Gposmrtos | 测试3399平台的网络收发API的应用程序所对应的GPOS | NULL |
| Eca3399c_TestCommon_GPOSMRTOS | 测试3399平台多个应用程序所配套的GPOS+MultiRTOS配置项目 | NULL |
| Eca3399c_Test_TTOS_SemaCount_App | 测试3399平台计数信号量的应用程序工程以及源码 | NULL |
| Eca3399c_Test_TTOS_Sema_App | 测试3399平台二值信号量使用应用程序工程以及源码 | NULL |
| Eca3399c_Test_TTOS_SystemClk_App | 测试3399平台系统时钟相关API使用的应用程序工程以及源码 | NULL |
| Eca3399c_Test_TTOS_mutex_App | 测试3399平台互斥锁的应用程序工程以及源码 | NULL |
| Eca3399c_Test_TTOS_timer_App | 测试3399平台定时器使用的应用程序工程以及源码 | NULL |
| Eca3399c_Test_multi_task_APP | 测试3399平台多任务的应用程序工程以及源码 | NULL |
| eca3399c_for_usart_test_app | 测试3399平台串口发送的应用程序工程以及源码 | UART、USART、串口、测试程序 |
| eca3399c_usart_send_test_rtos | 测试3399平台串口发送的应用程序对应的RTOS配置工程 | UART、USART、串口、测试程序 |
| Eca3399c_Test_TTOS_event_App | 测试3399平台TTOS中事件的使用方法 | NULL |
| Mfc1000_Share_Memory_test_APP | 测试mfc1000平台TTOS中共享内存的分配使用 | NULL |
| Mfc1000_Test_TTOS_mesq_App | 测试mfc1000平台TTOS中消息队列的使用方法 | NULL |
| NewPre3102_File_Read_Write_Test_VM | 测试NewPre3102平台中文件的读写程序以及源码 | NULL |
| NewPre3102_TCP_Send_Recv_Test_Client | 测试NewPre3102平台中网络TCP收发客户端程序以及源码 | NULL |
| NewPre3102_TCP_Send_Recv_Test_Server | 测试NewPre3102平台中网络TCP收发服务端程序以及源码 | NULL |
| NewPre3102_UDP_Send_Recv_Test | 测试NewPre3102平台中网络UDP收发程序以及源码 | NULL |
| E2000q_CFG_mrtos | 飞腾E2000q平台TTOS mrtos配置工程 | NULL |
| E2000q_spi_test_fram_read_write_app | 测试飞腾E2000q平台TTOS中SPI读写用方法demo | NULL |
| E2000d_MiniITX_Priority_Inversion_APP | 测试E2000d平台TTOS中优先级反转测试程序及源码 | NULL |
| E2000d_MiniITX_Priority_Inversion_Hypervisor | 测试E2000d平台TTOS中优先级反转测试所配套的Hypervisor配置项目 | NULL |
| E2000d_MiniITX_Hook_Test_APP | 测试E2000d平台TTOS中钩子函数测试程序及源码 | NULL |
| E2000d_MiniITX_Hook_Test_Hypersivor | 测试E2000d平台TTOS中钩子函数测试所配套的Hypervisor配置项目 | NULL |
| E2000d_MiniITX_SendServiceInt_VM1 | 测试E2000d平台TTOS中虚拟服务请求VM1测试程序及源码，测试VM之间的服务中断 | NULL |
| E2000d_MiniITX_SendServiceInt_VM2 | 测试E2000d平台TTOS中虚拟服务请求VM2测试程序及源码，测试VM之间的服务中断 | NULL |
| E2000d_MiniITX_SendServiceInt_Hypervisor | 测试E2000d平台TTOS中虚拟服务请求测试所配套的Hypervisor配置项目 | NULL |
| E2000d_MiniITX_WatchdogDemo| 测试E2000d平台TTOS软件看门狗的使用测试Demo，里面包含使用手册 | TTOS软件看门狗 |
| d9_32_test_i2c_app | 测试芯驰d9平台的I2C读写demo | NULL |
| SemiDrive_D9_32_mrtos | 测试芯驰d9平台的配置项目工程 | NULL |
| SemiDrive_D9_32_app_multicast_test | D9 ttos中组播发送测试（gmac0） | NULL |
| SemiDrive_D9_32_app_multicast_test_vm2 | D9 ttos中组播发送测试（虚拟网卡） | NULL |
| Mfc1000_Windows_Test_ShareMemory_Projects | Windows实时扩展的Win和Intewell之间共享内存的demo工程和说明 | 请看readme |
| Mfc1000_Delay_Func_test_APP |	Mfc1000平台延迟函数测试程序以及源码，测试常用的延迟函数 | NULL |
| Mfc1000_Math_Func_test_APP |	Mfc1000平台数学函数测试程序以及源码，测试常用的数学库函数 | NULL |
| iTOP_RK3588_GPIO_IRQ_GPOSMRTOS |	测试3588平台GPIO中断测试所配套的GPOS+MultiRTOS配置项目 | NULL |
| iTOP_RK3588_GPIO_IRQ_APP |	测试3588GPIO中断测试程序以及源码 | NULL |
| iTOP_RK3588_TTOS_Share_Memory_GPOSMRTOS |	测试3588平台TTOS共享内存测试所配套的GPOS+MultiRTOS配置项目 | NULL |
| iTOP_RK3588_TTOS_Share_Memory_OS |	测试3588平台TTOS共享内存测试所配套的OS配置项目 | NULL |
| iTOP_RK3588_TTOS_Share_Memory_VM1_APP |	测试3588 TTOS共享内存VM1测试程序以及源码 | NULL |
| iTOP_RK3588_TTOS_Share_Memory_VM2_APP |	测试3588 TTOS共享内存VM2测试程序以及源码 | NULL |
| SemiDrive_D9_FUSION_64_Can_Func_Test_App |	测试芯驰D9菲森电力项目can收发测试相关操作程序以及源码 | NULL |
| SemiDrive_D9_FUSION_64_Fatfs_File_Test_App |	测试芯驰D9菲森电力项目Fat文件系统相关操作程序以及源码 | NULL |
| SemiDrive_D9_FUSION_64_Fatfs_File_Test_Gposmrtos |	测试芯驰D9菲森电力项目Fat文件系统测试所配套的GPOS+MultiRTOS配置项目 | NULL |
| SemiDrive_D9_FUSION_64_I2c_TestTemperature_App |	测试芯驰D9菲森电力项目I2C接口温度模块 | 芯片型号gx21m15 |
| SemiDrive_D9_FUSION_64_I2c_TestRtc_App |	测试芯驰D9菲森电力项目I2C接口时钟模块 | 芯片rx8025t |
| SemiDrive_D9_FUSION_64_I2c_Read_Test_App |	测试芯驰D9菲森电力项目I2C读取IO状态并计算频率测试程序及源码 | NULL |
| SemiDrive_D9_FUSION_64_I2c_Read_Test_Gposmrtos |	测试芯驰D9菲森电力项目I2C读取IO状态并计算频率所配套的GPOS+MultiRTOS配置项目 | NULL |
| SemiDrive_D9_FUSION_64_I2c_Read_ByGpioInt_Test_App |	测试芯驰D9菲森电力项目I2C借助gpio中断读取IO状态并计算频率测试程序及源码 | NULL |
| SemiDrive_D9_FUSION_64_I2c_Read_ByGpioInt_Test_Gposmrtos |	测试芯驰D9菲森电力项目I2C借助gpio中断读取IO状态并计算频率所配套的GPOS+MultiRTOS配置项目 | NULL |
| SemiDrive_D9_FUSION_64_I2c_TestIoExpander_App |	测试芯驰D9菲森电力项目I2C接口IO扩展模块 | 芯片PCA9555 |
| SemiDrive_D9_FUSION_64_IWDG_Test_SGM820B_App |	测试芯驰D9菲森电力项目GPIO接口外部看门狗 | 芯片SGM820B，IO控制的硬件看门狗 |
| SemiDrive_D9_FUSION_64_SPI_Test_AD7616_App |	测试芯驰D9菲森电力项目SPI接口多路ADC采样器 | 芯片AD7616 |
| SemiDrive_D9_FUSION_64_Timer_Test_AD7616_App |	测试芯驰D9菲森电力项目SPI接口多路ADC采样器 | 芯片AD7616 |
| SemiDrive_D9_FUSION_64_Timer_And_GPIO_IRQ_Test_AD7616_App |	测试芯驰D9菲森电力项目SPI接口多路ADC采样器 | 芯片AD7616 |
| SemiDrive_D9_FUSION_64_Optimized_Timer_And_GPIO_IRQ_Test_AD7616_App |	测试芯驰D9菲森电力项目SPI接口多路ADC采样器 | 芯片AD7616 |此为优化后的例程
| SemiDrive_D9_FUSION_64_SPI_Test_HT7038_App |	测试芯驰D9菲森电力项目SPI接口电量计量芯片 | 芯片HT7038 |
| SemiDrive_D9_FUSION_64_SPI_Test_Flash_App |	测试芯驰D9菲森电力项目SPI接口FLASH | 芯片W25Q64 |
| SemiDrive_D9_YONGE_Lwip_Net_Set_Addr_Test_App |	测试YONGE D9网络的例程测试程序以及源码 | NULL |
| SemiDrive_D9_YONGE_Lwip_Net_Set_Addr_Test_Gposmrtos |	测试YONGE D9网络的例程所配套的GPOS+MultiRTOS配置项目 | NULL |
| intewellrtre_windows-testshmm-20231213共性内存测试例程x64x32 |	基于VS平台级的共享内存测试例程 | 注意基于vs2017平台集的 |
|PC_UDP_Send_Recv_Test测试PC端UDP网络数据的接收和发送|需要将文档中源代码导入CLion中运行| 非TTOS程序，是PC端应用程序 |
|Phytium_I2c_OperateEEPROM_App|飞腾Pi下II2驱动EEPROM例程| NULL |
|Phytium_Pwm_OperateServoSG90_App|飞腾Pi下PWM驱动舵机例程| PWM控制舵机转动 |
|Phytium_Spi_OperateFlash_App|飞腾Pi下II2读写SPI Flash例程| TTOS下，使用SFUD（通用串行flash库）来测试flash |
|GSK_RK3399_Autostart_Test_App|测试TTOS系统的自启动测试| 在ARM平台下，通过TCP网络和智能电源，控制自己的断电重启 |
|GSK_E2000q_time_interval_App|TTOS系统的时间间隔测试，使用精准的nano sleep函数来测试精准的时间间隔|
|GSK_E2000q_get_ip_App|TTOS系统的获取IP测试，在TTOS应用程序中，获取IP地址|NULL|
|E2000D最小系统外设|此文件夹包含一个飞腾E2000D开发板的外设最小测试代码集合，里面包含：emmc读写测试、emmc速度测试、GPIO测试、I2C测试、PCIe测试、RTC测试、UART测试、系统抖动测试、以太网基础通讯测试|独立文件夹、c源码兼容其他平台|
|飞腾E2000D最小系统外设总线测试例程集合\UART\APP\src|TTOS系统的串口中断阻塞测试程序|UART、USART、串口的中断阻塞测试代码|
* 每一个文件夹为一个测试工程，可以在IDE中导入打开使用。
