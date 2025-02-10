/****************************************************************************
 *    �ƶ������ݣ�����Ƽ����޹�˾ ��Ȩ����
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

�������ʶ��:
TTOS_CreateTask

������������ʶ��:
RTOS_WD_014_1

��Ŀ������͡�:
֧����������ƽ̨

������Ŀ�ġ�:
��TTOS����°󶨺ˣ�����ʹ�ÿ��Ź���������������Ź�+���ڼ���ι��+ֹͣ���Ź����鿴TTOS�����Ƿ���������������Ҳ����ֹͣ����
���������͡�:
�ӿڲ���

���Ⱦ�������:
��

�����Բ��衿:
1������GPOS+RTOS/MRTOS��Ŀ��������һ���������Ŀ��vm1���д��룬�����������У�
2���鿴������Ƿ���������ֹͣ��
��Ԥ�ڽ����:
�����Ȳ�������Ҳ����ֹͣ��

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
#include <ttosUtils.h>
#ifdef USE_GPIO_WATCHDOG
	#include "watchdog.h"
	#define TTOS_StartWatchdog GPIO_StartWatchdog
	#define TTOS_FeedWatchdog GPIO_FeedWatchdog
	#define TTOS_StopWatchdog GPIO_StopWatchdog
#endif

T_MODULE TASK_ID task_id_wd_create;
T_MODULE TASK_ID task_id_wd_feed;

#define WD_TIMEOUT						(0xff)
#define	WD_CB_TIMEOUT_DELAY		(4*WD_TIMEOUT)
#define	WD_FEED_CNT						(0xf)

T_MODULE T_BOOL wd_cb(T_VOID * ctx)
{
	printk("wd_cb!\n");

	return false;

}


T_MODULE T_VOID create_wd_task_cb (T_VOID *p_arg)
{
	T_VMK_ReturnCode vmk_rc;

	T_TTOS_ReturnCode ttos_ret = TTOS_WatchdogInstallCallback(WD_CB_TIMEOUT_DELAY, wd_cb, NULL);
	if (TTOS_OK != ttos_ret)
	{
		printk("TTOS_WatchdogInstallCallback failed! %d\n", ttos_ret);
		return;
	}


	/*δι��max_dog_time����ʱ����ʱ���ִ�в��ԣ�ΪTRUEʱ��ʱ��ֹͣTTOS��ΪFALSEʱ��ʱ������TTOS*/
	vmk_rc = TTOS_StartWatchdog(2*WD_TIMEOUT, FALSE);
	if (VMK_OK != vmk_rc)
	{
		printk("TTOS_StartWatchdog failed!\n");
		return;
	}


    /* ����task_id_wd_feed */
    ttos_ret = TTOS_ActiveTask(task_id_wd_feed);
    if (ttos_ret != 0)
    {
    	printk("error, %d ttos_ret=%d\n", __LINE__, ttos_ret);
    	return;
    }

	printk("TTOS_StartWatchdog successful!\n");
}


T_MODULE T_VOID  feed_wd_task_cb (T_VOID *p_arg)
{
    T_TTOS_ReturnCode rc = 0;
	T_VMK_ReturnCode vmk_rc;
	int lp = 0;

    rc = TTOS_SleepTask(WD_TIMEOUT);

	if (TTOS_OK != rc)
	{
		printk("TTOS_SleepTask failed!\n");
		return;
	}

	/*��ʱι��*/
	for (; lp < WD_FEED_CNT; lp++)
	{
		vmk_rc = TTOS_FeedWatchdog();
		if (VMK_OK != vmk_rc) {
			printk("TTOS_FeedWatchdog failed!\n");
			//return;
		}
		else {
			printk("TTOS_FeedWatchdog successful!\n");
		}
	}

	vmk_rc = TTOS_StopWatchdog();
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StopWatchdog failed!\n");
	}
	else {
		printk("\nTTOS_StopWatchdog success!\n");
	}
}


INT32 RTOS_WD_014_1(T_VOID)
{
    T_TTOS_ReturnCode ttos_ret = 0;
    cpu_set_t affinity;

    ttos_ret = TTOS_CreateTaskEx(
            (T_UBYTE *)"create_wd_task",
            0, // ������ȼ�
            FALSE,
            TRUE,
            (T_TTOS_TaskRoutine)create_wd_task_cb,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &task_id_wd_create);
    if (ttos_ret != 0)
    {
    	printk("error, %d ttos_ret=%d\n", __LINE__, ttos_ret);
    	return TTOS_FAIL;
    }

    /* ��task_id_wd_create������0*/
    CPUSET_ZERO(affinity);
    CPUSET_SET(affinity, 0);
    while (TTOS_OK != TTOS_SetTaskAffinity(task_id_wd_create, affinity))
    {
        TTOS_SleepTask(1 * VMK_GetSysClkRate());
    }


    ttos_ret = TTOS_CreateTaskEx(
            (T_UBYTE *)"feed_wd_task",
            0, // ������ȼ�
            FALSE,
            TRUE,
            (T_TTOS_TaskRoutine)feed_wd_task_cb,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &task_id_wd_feed);
    if (ttos_ret != 0)
    {
    	printk("error, %d ttos_ret=%d\n", __LINE__, ttos_ret);
    	return TTOS_FAIL;
    }

    /* ��task_id_wd_start������1*/
    CPUSET_ZERO(affinity);
    CPUSET_SET(affinity, 1);
    while (TTOS_OK != (ttos_ret = TTOS_SetTaskAffinity(task_id_wd_feed, affinity)))
    {
     	printk("error, %d ttos_ret=%d\n", __LINE__, ttos_ret);
        TTOS_SleepTask(1 * VMK_GetSysClkRate());
    }

    /* ����task_id_wd_create */
    ttos_ret = TTOS_ActiveTask(task_id_wd_create);
    if (ttos_ret != 0)
    {
    	printk("error, %d ttos_ret=%d\n", __LINE__, ttos_ret);
    	return TTOS_FAIL;
    }

	return TTOS_OK;
}

