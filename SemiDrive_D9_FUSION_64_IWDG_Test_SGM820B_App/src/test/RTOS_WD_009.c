/****************************************************************************
 *    �ƶ������ݣ�����Ƽ����޹�˾ ��Ȩ����
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

�������ʶ��:
TTOS_CreateTask

������������ʶ��:
RTOS_WD_009

��Ŀ������͡�:
֧����������ƽ̨

������Ŀ�ġ�:
��������Ź���Ӧ��������ι��������ʱ����ΪTTOS_WatchdogInstallCallbackע��ص�����true,�޷�ִ��ι����Ҳ������ִ��ֹͣ���Ź������·���ֹͣ

���������͡�:
�ӿڲ���

���Ⱦ�������:
��

�����Բ��衿:
1������GPOS+RTOS/MRTOS��Ŀ��������һ���������Ŀ��vm1���д��룬�����������У�
2���鿴��������������Ƿ�ֹͣ����������
3��������������������������������������������ԣ���ͨ��ping����鿴�����Ƿ�ֹͣ��
��Ԥ�ڽ����:
����ֹͣ��

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
#ifdef USE_GPIO_WATCHDOG
	#include "watchdog.h"
	#define TTOS_StartWatchdog GPIO_StartWatchdog
	#define TTOS_FeedWatchdog GPIO_FeedWatchdog
	#define TTOS_StopWatchdog GPIO_StopWatchdog
#endif
static T_BOOL wd_cb(T_VOID * ctx)
{
	printk("vm will stop!\n");
	return true;
}


INT32 RTOS_WD_009(T_VOID)
{
	T_UWORD max_dog_time = 0xffff;
	T_VMK_ReturnCode vmk_rc;

	T_WORD timeout = 4*max_dog_time;

	int ctx;
	T_TTOS_ReturnCode rc = TTOS_WatchdogInstallCallback(timeout, wd_cb, &ctx);
	if (TTOS_OK != rc)
	{
		printk("\nTTOS_WatchdogInstallCallback failed! %d\n", rc);
		return TTOS_FAIL;
	}

	/*δι��max_dog_time����ʱ����ʱ���ִ�в��ԣ�ΪTRUEʱ��ʱ��ֹͣTTOS��ΪFALSEʱ��ʱ������TTOS*/
	vmk_rc = TTOS_StartWatchdog(max_dog_time, TRUE);
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}

	printk("\nTTOS_StartWatchdog successful!\n");

	/*����ʱι��*/
	rc = TTOS_SleepTask(2*max_dog_time);

	if (TTOS_OK != rc)
	{
		printk("\nTTOS_SleepTask failed!\n");
		return TTOS_FAIL;
	}

	/*��ΪTTOS_WatchdogInstallCallbackע��ص�����true���޷�ִ�е���*/
	vmk_rc = TTOS_FeedWatchdog();
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_FeedWatchdog failed!\n");
		//return TTOS_FAIL;
	}

	//printk("\nTTOS_FeedWatchdog successful!\n");

	/*��ΪTTOS_WatchdogInstallCallbackע��ص�����true���޷�ִ�е���*/
	vmk_rc = TTOS_StopWatchdog();
	if (VMK_OK != vmk_rc) {
		printk("\nTTOS_StopWatchdog failed!\n");
		return TTOS_FAIL;
	}
	else {
		printk("\nTTOS_StopWatchdog successful!\n");
		return TTOS_OK;
	}
}

