/****************************************************************************
 *				北京科银京成技术有限公司 版权所有
 *
 * 		 Copyright (C) 2014-2016 CoreTek Systems Inc. All Rights Reserved.
 ***************************************************************************/

 /* <EXECL>

【需求标识】:
UART

【测试用例标识】:
IntewellOS_UART_InterruptBlock_001

【目标机类型】:
具有uart的设备

【测试目的】:
验证【中断+阻塞】通信是否正常（波特率覆盖9600/19200/38400/57600/115200）

【测试类型】:
接口测试

【先决条件】:
1、配置一个应用分区，自启动

【测试步骤】:
1、IDE界面，给实时分配串口COMx，Interrupt pass-through模式；
2、open串口COMx;通过ioctl设置串口模式为Interrupt模式，阻塞；
3、验证设置是否成功，ioctl是否返回提示信息：
4、通过ioctl设置串口的接收波特率（覆盖9600、19200、38400、57600、115200）；
5、ioctl获取串口配置，查看设置是否成功；
6、查看串口是否能正确收发数据【每个波特率对端发送10次大小为TEST_SIZE数据即可】。
【预期结果】:
串口设置成功；能正确收发数据。

【评价准则】:
与预期结果一致

【假设和约束】:
操作系统可运行

【设计者】:
yep

【设计时间】:
2024-02-18

</EXECL> */

 
/**************************** 引用部分 *****************************************/
 
#include <components/modbusIO.h>
#include <errno.h>
#include <string.h>
#include <ttos.h>
#include <fcntl.h>
#include <x86/i386/sysUart.h>
//#include <sysUart.h>

#include "testSuite.h"
#include <ttosShell.h>

#define		TEST_SIZE				(16)
#define		SEND_TIMES				(10)
#define 	TEST_COM			  	"/COM2"	//打开串口COM1、2、3、4
T_WORD fd = -1;

T_VOID IntewellOS_UART_InterruptBlock_001(T_VOID)
{
	T_DR_UartConfigTable uartCfg;

	T_WORD ret = 0;
	T_WORD recv_count = 0;
	T_BYTE buf[TEST_SIZE+1] = {0};

	static UINT64 start_time, end_time;
	static UINT64 time1;


	start_time = TTOS_GetCurrentSystemCount();
	fd = open(TEST_COM, MODBUS_IO_BLOCK);

	end_time = TTOS_GetCurrentSystemCount();
	printk("start_time is %lld ms\n",start_time);
	printk("end_time is %lld ms\n",end_time);

	time1 = TTOS_GetCurrentSystemSubTime(start_time,end_time,TTOS_NS_UNIT);
	printk("open time is %lld ns\n",time1);

	if (fd < 0)
	{
		printk("open errno = %d\n", errno);
		return;
	}



	ret = ioctl(fd, UIO_SET_RXTX_MODE, DR_UART_INTERRUPT);
	if (ret < 0)
	{
		printk("ioctl errno = %d\n", errno);
		TEST_ERRFPRINT()
		return;
	}

	ret = ioctl(fd, MODBUS_IO_GET_ATTR, &uartCfg);
	if (ret < 0)
	{
		printk("ioctl errno = %d\n", errno);
		TEST_ERRFPRINT()
		return;
	}

	printk("name: %s\n", uartCfg.name);
	printk("baudrate: %d\n", uartCfg.baudrate);
	printk("mode: %d\n", uartCfg.mode);


//	uartCfg.baudrate = 9600;
//	uartCfg.baudrate = 19200;
//	uartCfg.baudrate = 38400;
//	uartCfg.baudrate = 57600;
	uartCfg.baudrate = 115200;

	ret = ioctl(fd, MODBUS_IO_SET_ATTR, &uartCfg);
	if (ret < 0)
	{
		printk("ioctl errno = %d\n", errno);
		TEST_ERRFPRINT()
		return;		
	}
	printk("baudrate: %d\n", uartCfg.baudrate);

	printk("waiting for input output\n");

//	for (T_WORD lp = 0; lp < SEND_TIMES; lp++)
	while (1)
	{
		recv_count = 0;
		while (1)
		{
			ret = read(fd, buf + recv_count, TEST_SIZE-recv_count);
			if (ret < 0)
			{
	//			printk("read failed %d\n", ret);
				TEST_ERRFPRINT();			
			}
			else
			{
				recv_count += ret;
			}
			printf("read buf = %s\n", buf);


			if (recv_count >= TEST_SIZE)
			{
				break;
			}
		}

		recv_count = 0;

		while (1)
		{
			ret = write(fd, buf + recv_count, TEST_SIZE-recv_count);
			if (ret < 0)
			{
				TEST_ERRFPRINT();
			}
			else
			{
				recv_count += ret;
				printf("write ret count = %d\n", ret);
			}

			if (recv_count >= TEST_SIZE)
			{
				break;
			}
		}
	}

	TTOS_SleepTask(TTOS_GetSysClkRate());

	ret = close(fd);

	if (ret < 0)
	{
		TEST_ERRFPRINT();
		return;		
	}

	TEST_OKPRINT();
}
