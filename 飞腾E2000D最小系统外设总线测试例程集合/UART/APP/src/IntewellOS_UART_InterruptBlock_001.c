/****************************************************************************
 *				�����������ɼ������޹�˾ ��Ȩ����
 *
 * 		 Copyright (C) 2014-2016 CoreTek Systems Inc. All Rights Reserved.
 ***************************************************************************/

 /* <EXECL>

�������ʶ��:
UART

������������ʶ��:
IntewellOS_UART_InterruptBlock_001

��Ŀ������͡�:
����uart���豸

������Ŀ�ġ�:
��֤���ж�+������ͨ���Ƿ������������ʸ���9600/19200/38400/57600/115200��

���������͡�:
�ӿڲ���

���Ⱦ�������:
1������һ��Ӧ�÷�����������

�����Բ��衿:
1��IDE���棬��ʵʱ���䴮��COMx��Interrupt pass-throughģʽ��
2��open����COMx;ͨ��ioctl���ô���ģʽΪInterruptģʽ��������
3����֤�����Ƿ�ɹ���ioctl�Ƿ񷵻���ʾ��Ϣ��
4��ͨ��ioctl���ô��ڵĽ��ղ����ʣ�����9600��19200��38400��57600��115200����
5��ioctl��ȡ�������ã��鿴�����Ƿ�ɹ���
6���鿴�����Ƿ�����ȷ�շ����ݡ�ÿ�������ʶԶ˷���10�δ�СΪTEST_SIZE���ݼ��ɡ���
��Ԥ�ڽ����:
�������óɹ�������ȷ�շ����ݡ�

������׼��:
��Ԥ�ڽ��һ��

�������Լ����:
����ϵͳ������

������ߡ�:
yep

�����ʱ�䡿:
2024-02-18

</EXECL> */

 
/**************************** ���ò��� *****************************************/
 
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
#define 	TEST_COM			  	"/COM2"	//�򿪴���COM1��2��3��4
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
