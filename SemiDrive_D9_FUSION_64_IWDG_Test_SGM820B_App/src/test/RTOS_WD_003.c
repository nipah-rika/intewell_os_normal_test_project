/****************************************************************************
 *    科东（广州）软件科技有限公司 版权所有
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

【需求标识】:
TTOS_CreateTask

【测试用例标识】:
RTOS_WD_003

【目标机类型】:
支持现有所有平台

【测试目的】:
虚拟机发生异常导致虚拟机挂起，是否能触发狗叫重启虚拟机【需要确认哪些异常触发重启？】

【测试类型】:
接口测试

【先决条件】:
无

【测试步骤】:
1、创建GPOS+RTOS/MRTOS项目，并创建一个虚拟机项目，vm1运行代码，编译下载运行；
2、查看虚拟机是否重启。
【预期结果】:
虚拟机重启。

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

#define			WD_GENERAL_ZDIV_INT 	0
#define			WD_GENERAL_PAGE_INT 	1

#define 		EXCEPT_MODE			WD_GENERAL_PAGE_INT

INT32 RTOS_WD_003(T_VOID)
{
	T_UWORD max_dog_time = 0xff;
	T_VMK_ReturnCode vmk_rc;

	/*未喂狗max_dog_time将超时，超时后的执行策略为FALSE表示超时后重启TTOS*/
	vmk_rc = TTOS_StartWatchdog(max_dog_time, FALSE);
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}

	printk("\nTTOS_StartWatchdog successful!\n");

	T_EXTERN T_UWORD tbspVintStackStart;
	T_ULONG* pAddr = (T_ULONG*)tbspVintStackStart;
	*pAddr = 0x1234;
	return TTOS_OK;

}

