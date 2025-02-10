/****************************************************************************
 *    科东（广州）软件科技有限公司 版权所有
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

【需求标识】:
TTOS_CreateTask

【测试用例标识】:
RTOS_WD_014_1

【目标机类型】:
支持现有所有平台

【测试目的】:
单TTOS多核下绑定核，正常使用看门狗的情况，启动看门狗+周期几次喂狗+停止看门狗，查看TTOS运行是否正常【不会重启也不会停止】。
【测试类型】:
接口测试

【先决条件】:
无

【测试步骤】:
1、创建GPOS+RTOS/MRTOS项目，并创建一个虚拟机项目，vm1运行代码，编译下载运行；
2、查看虚拟机是否重启或者停止。
【预期结果】:
分区既不会重启也不会停止。

【评价准则】:
与预期结果一致

【假设和约束】:
操作系统可运行

【设计者】:
XXX

【设计时间】:
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


	/*未喂狗max_dog_time将超时，超时后的执行策略，为TRUE时超时后停止TTOS，为FALSE时超时后重启TTOS*/
	vmk_rc = TTOS_StartWatchdog(2*WD_TIMEOUT, FALSE);
	if (VMK_OK != vmk_rc)
	{
		printk("TTOS_StartWatchdog failed!\n");
		return;
	}


    /* 启动task_id_wd_feed */
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

	/*及时喂狗*/
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
            0, // 最高优先级
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

    /* 绑定task_id_wd_create到核心0*/
    CPUSET_ZERO(affinity);
    CPUSET_SET(affinity, 0);
    while (TTOS_OK != TTOS_SetTaskAffinity(task_id_wd_create, affinity))
    {
        TTOS_SleepTask(1 * VMK_GetSysClkRate());
    }


    ttos_ret = TTOS_CreateTaskEx(
            (T_UBYTE *)"feed_wd_task",
            0, // 最高优先级
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

    /* 绑定task_id_wd_start到核心1*/
    CPUSET_ZERO(affinity);
    CPUSET_SET(affinity, 1);
    while (TTOS_OK != (ttos_ret = TTOS_SetTaskAffinity(task_id_wd_feed, affinity)))
    {
     	printk("error, %d ttos_ret=%d\n", __LINE__, ttos_ret);
        TTOS_SleepTask(1 * VMK_GetSysClkRate());
    }

    /* 启动task_id_wd_create */
    ttos_ret = TTOS_ActiveTask(task_id_wd_create);
    if (ttos_ret != 0)
    {
    	printk("error, %d ttos_ret=%d\n", __LINE__, ttos_ret);
    	return TTOS_FAIL;
    }

	return TTOS_OK;
}

