/****************************************************************************
 *    �ƶ������ݣ�����Ƽ����޹�˾ ��Ȩ����
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

�������ʶ��:
TTOS_CreateTask

������������ʶ��:
RTOS_WD_002

��Ŀ������͡�:
֧����������ƽ̨

������Ŀ�ġ�:
��������Ź���Ӧ��������ι��������ʱ��ִ�������������������ֻ���������������ָ����ݶι��ܡ�����ʱ����Ҫ���ļ�ϵͳ���¼��ؾ���������Ƿ�ָ����ݶΡ�

���������͡�:
�ӿڲ���

���Ⱦ�������:
��

�����Բ��衿:
1������GPOS+RTOS/MRTOS��Ŀ��������һ���������Ŀ��vm1���д��룬�����������У�
2���鿴������Ƿ������������Ƿ��ָ����ݶΡ�
��Ԥ�ڽ����:
��������������һָ����ݶΡ�

������׼��:
��Ԥ�ڽ��һ��

�������Լ����:
����ϵͳ������

������ߡ�:
XXX

�����ʱ�䡿:
2020-01-18

</EXECL> */

#include <ttos.h>

#define USE_GPIO_WATCHDOG (1)
#ifdef USE_GPIO_WATCHDOG
	#include "watchdog.h"
	#define TTOS_StartWatchdog GPIO_StartWatchdog
	#define TTOS_FeedWatchdog GPIO_FeedWatchdog
	#define TTOS_StopWatchdog GPIO_StopWatchdog
#endif

INT32 RTOS_WD_002(T_VOID)
{
	int cnt=0;
	T_UWORD max_dog_time = 0xffff;
	T_VMK_ReturnCode vmk_rc;
	/*���ݶ�*/
	 static int data_val[4] = {0, 1, 2, 3};

	 printk("data_val  primary data %d,%d,%d,%d \n", data_val[0], data_val[1], data_val[2], data_val[3]);
	 data_val[0] = 0x1234;
	 printk("data_val %d,%d,%d,%d \n", data_val[0], data_val[1], data_val[2], data_val[3]);

	/*δι��max_dog_time����ʱ����ʱ���ִ�в���ΪFALSE��ʾ��ʱ������TTOS*/
	vmk_rc = GPIO_StartWatchdog(max_dog_time, FALSE);
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}

	printk("\nTTOS_StartWatchdog successful!\n");

	 while(1)
	 {
		 TTOS_SleepTask(100);
		 if(cnt<100)
		 GPIO_FeedWatchdog();
		 printf("    Feed Watchdog cnt:%d\r\n",cnt++);
	 }
	return TTOS_OK;
}

