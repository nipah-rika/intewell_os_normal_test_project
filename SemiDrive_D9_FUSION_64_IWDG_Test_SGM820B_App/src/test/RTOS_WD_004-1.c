/****************************************************************************
 *    �ƶ������ݣ�����Ƽ����޹�˾ ��Ȩ����
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

�������ʶ��:
RTOS_WD_004_1

������������ʶ��:
RTOS_WD_004_1

��Ŀ������͡�:
֧����������ƽ̨

������Ŀ�ġ�:
��������Ź���Ӧ��������ι��������ʱ��ִ�������ֹͣ��
���������͡�:
�ӿڲ���

���Ⱦ�������:
��

�����Բ��衿:
1������GPOS+RTOS/MRTOS��Ŀ��������һ���������Ŀ��vm1���д��룬�����������У�
2���鿴������Ƿ�ֹͣ��
��Ԥ�ڽ����:
���񴴽�ʧ�ܣ�����ֵΪTTOS_INVAILD_VERSION��

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
#include <unistd.h>
#ifdef USE_GPIO_WATCHDOG
	#include "watchdog.h"
	#define TTOS_StartWatchdog GPIO_StartWatchdog
	#define TTOS_FeedWatchdog GPIO_FeedWatchdog
	#define TTOS_StopWatchdog GPIO_StopWatchdog
#endif
T_MODULE TASK_ID task_id;
T_MODULE volatile T_WORD flag = 0x0;

T_MODULE T_BOOL wd_cb(T_VOID * ctx)
{
	flag = 0x1;
	printk("wd_cb enter\n");
	while (0x1 == flag)
	{
		printk("wd_cb\n");
	}
	printk("wd_cb exit\n");
	return true;
}


T_MODULE T_VOID task_cb (T_VOID *p_arg)
{
	while (!flag)
	{
		printk("task_cb\n");
		flag = 0x0;
		TTOS_SleepTask(1);
	}
	printk("finished\n");
}


INT32 RTOS_WD_004_1(T_VOID)
{
	T_UWORD max_dog_time = 0xf;
	INT32 count = 0;

	T_WORD timeout = max_dog_time;
	int ctx;
	T_TTOS_ReturnCode rc = TTOS_OK;

	rc = TTOS_CreateTaskEx(
            (T_UBYTE *)"task_cb",
            0, // ������ȼ�
            FALSE,
            TRUE,
            (T_TTOS_TaskRoutine)task_cb,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &task_id);
    if (rc != 0)
    {
    	printk("error, %d ttos_ret=%d\n", __LINE__, rc);
    	return TTOS_FAIL;
    }

	 rc =TTOS_WatchdogInstallCallback(timeout, wd_cb, &ctx);
	 if (TTOS_OK != rc)
	 {
		printk("\nTTOS_WatchdogInstallCallback failed!\n");
		return TTOS_FAIL;
	 }

	printk("\nTTOS_WatchdogInstallCallback successful!\n");

	rc = TTOS_ActiveTask(task_id);
    if (rc != 0)
    {
    	printk("error, %d ttos_ret=%d\n", __LINE__, rc);
    	return TTOS_FAIL;
    }

	/*δι��max_dog_time����ʱ����ʱ���ִ�в���ΪTRUE��ʾʱ��ʱ��ֹͣTTOS,ΪFALSEʱ��ʱ������TTOS*/
	rc = TTOS_StartWatchdog(max_dog_time, FALSE);
	if (VMK_OK != rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}

	printk("\nTTOS_StartWatchdog successful!\n");

	while (1)
	{
		TTOS_SleepTask(0xfff);
//		sleep(1);
		printk("\nI'am alive! times = %d\n", count++);
	}

#if 0
	vmk_rc = TTOS_FeedWatchdog();
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_FeedWatchdog failed!\n");
		return TTOS_FAIL;
	}

	vmk_rc = TTOS_StopWatchdog();
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}
#endif

	return TTOS_OK;
}

