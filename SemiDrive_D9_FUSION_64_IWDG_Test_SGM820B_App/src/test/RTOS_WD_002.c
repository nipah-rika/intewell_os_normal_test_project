/****************************************************************************
 *    科东（广州）软件科技有限公司 版权所有
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

【需求标识】:
TTOS_CreateTask

【测试用例标识】:
RTOS_WD_002

【目标机类型】:
支持现有所有平台

【测试目的】:
虚拟机看门狗由应用任务负责喂狗，狗叫时，执行虚拟机重启，该用例只测试重启和重启恢复数据段功能【重启时不需要从文件系统重新加载镜像，虚拟机是否恢复数据段】

【测试类型】:
接口测试

【先决条件】:
无

【测试步骤】:
1、创建GPOS+RTOS/MRTOS项目，并创建一个虚拟机项目，vm1运行代码，编译下载运行；
2、查看虚拟机是否重启，并且是否会恢复数据段。
【预期结果】:
虚拟机重启，并且恢复数据段。

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
	/*数据段*/
	 static int data_val[4] = {0, 1, 2, 3};

	 printk("data_val  primary data %d,%d,%d,%d \n", data_val[0], data_val[1], data_val[2], data_val[3]);
	 data_val[0] = 0x1234;
	 printk("data_val %d,%d,%d,%d \n", data_val[0], data_val[1], data_val[2], data_val[3]);

	/*未喂狗max_dog_time将超时，超时后的执行策略为FALSE表示超时后重启TTOS*/
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

