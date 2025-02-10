/*********************************************************************************
*				                                         科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * 修改历史：
 * 2017-05-10     李燕, 科东（广州）软件科技有限公司
 *                创建该文件。
 *                
*/

/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

/************************头 文 件******************************/
#include <commonTypes.h>
#include <components/modbusIO.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/
T_VOID IntewellOS_UART1_BR_POLL_FUNC_0001(T_VOID)
{
	T_WORD fd = -1;
	T_WORD ret = 0;
	T_BYTE *testStr = "hello, 3399, com1 test.\n";
	T_DR_UartConfigTable uartCfg;

	/* 打开串口1 */
	fd = open("/COM1", MODBUS_IO_BLOCK);
	if (fd < 0)
	{
		printf("open errno = %d\n", errno);
	}

	/* 获取串口配置 */
	ret = ioctl(fd, MODBUS_IO_GET_ATTR, &uartCfg);
	if (ret < 0)
	{
		printf("ioctl errno = %d\n", errno);
	}

	printf("name: %s\n", uartCfg.name);
	printf("mode: %d\n", uartCfg.mode);
	printf("baudrate: %d\n", uartCfg.baudrate);
	printf("bits_per_char: %d\n", uartCfg.bits_per_char);
	printf("num_of_stop_bits: %d\n", uartCfg.num_of_stop_bits);
	printf("parity_mode: %d\n", uartCfg.parity_mode);

//	uartCfg.name[1] = 't';
//	uartCfg.name[2] = '\0';
	uartCfg.baudrate = 57600;

	/* 设置串口波特率 */
	ret = ioctl(fd, MODBUS_IO_SET_ATTR, &uartCfg);
	if (ret < 0)
	{
		printf("ioctl errno = %d\n", errno);
	}
	printk("\n");

	/* 获取串口配置 */
	ret = ioctl(fd, MODBUS_IO_GET_ATTR, &uartCfg);
	if (ret < 0)
	{
		printf("ioctl errno = %d\n", errno);
	}

	printf("name: %s\n", uartCfg.name);
	printf("baudrate: %d\n", uartCfg.baudrate);

	TTOS_SleepTask(TTOS_GetSysClkRate());

	for(int cnt=0; cnt<10; cnt++){
		/* 测试串口发送 */
		write(fd, testStr, strlen(testStr));

		TTOS_SleepTask(TTOS_GetSysClkRate());
	}
	/* 关闭串口1 */
	ret = close(fd);
	if (ret < 0)
	{
		printf("close fd errno = %d\n", errno);
	}

}


BOOL IsBigEndian()
{
	short a = 0x1234;
	char b = *(char*)&a;
	if(0x12 == b)
	{
		return TRUE;
	}

	return FALSE;
}


int userAppInit(void)
{
	printf("Hello TTOS for EC-A3399C!!!\n");
	int bits = sizeof(char *);
	if(bits == 4)
		printf("The TTOS is 32bit!!!\n");
	else if(bits == 8)
		printf("The TTOS is 64bit!!!\n");
	else
		printf("The TTOS is others, bits = %d ", bits);

	if(FALSE == IsBigEndian())
		printf("Little Endian!\n");
	else if(TRUE == IsBigEndian())
		printf("Big Endian\n");

	IntewellOS_UART1_BR_POLL_FUNC_0001();
    return 0;
}

