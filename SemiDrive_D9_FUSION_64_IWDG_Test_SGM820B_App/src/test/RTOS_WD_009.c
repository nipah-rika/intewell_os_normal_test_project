/****************************************************************************
 *    科东（广州）软件科技有限公司 版权所有
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

【需求标识】:
TTOS_CreateTask

【测试用例标识】:
RTOS_WD_009

【目标机类型】:
支持现有所有平台

【测试目的】:
虚拟机看门狗由应用任务负责喂狗，狗叫时，因为TTOS_WatchdogInstallCallback注册回调返回true,无法执行喂狗，也不可以执行停止看门狗，导致分区停止

【测试类型】:
接口测试

【先决条件】:
无

【测试步骤】:
1、创建GPOS+RTOS/MRTOS项目，并创建一个虚拟机项目，vm1运行代码，编译下载运行；
2、查看虚拟机（分区）是否停止或者重启；
3、给虚拟机分配网卡（物理网卡或者虚拟网卡均可以），通过ping命令查看分区是否停止。
【预期结果】:
分区停止。

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

	/*未喂狗max_dog_time将超时，超时后的执行策略，为TRUE时超时后停止TTOS，为FALSE时超时后重启TTOS*/
	vmk_rc = TTOS_StartWatchdog(max_dog_time, TRUE);
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}

	printk("\nTTOS_StartWatchdog successful!\n");

	/*不及时喂狗*/
	rc = TTOS_SleepTask(2*max_dog_time);

	if (TTOS_OK != rc)
	{
		printk("\nTTOS_SleepTask failed!\n");
		return TTOS_FAIL;
	}

	/*因为TTOS_WatchdogInstallCallback注册回调返回true，无法执行到此*/
	vmk_rc = TTOS_FeedWatchdog();
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_FeedWatchdog failed!\n");
		//return TTOS_FAIL;
	}

	//printk("\nTTOS_FeedWatchdog successful!\n");

	/*因为TTOS_WatchdogInstallCallback注册回调返回true，无法执行到此*/
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

