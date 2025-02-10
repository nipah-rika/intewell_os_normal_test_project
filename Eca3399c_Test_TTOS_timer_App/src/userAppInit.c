/*********************************************************************************
*				                                         科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * 修改历史：
 * 2017-05-10     李燕, 科东（广州）软件科技有限公司
 *                创建该文件。
 *                
*/

/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

/************************头 文 件******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <ttos.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
T_MODULE TIMER_ID g_timerId0;
T_MODULE TIMER_ID g_timerId1;

/************************实   现*******************************/


/*
 * 编程风格：
 *         函数linux/类unix风格
 *         局部变量：匈牙利命名法
 *         全局变量：匈牙利命名法
 *         宏定义：linux风格 大写
 */

/* 说明：
 * 程序清单：定时器例程
 *
 * 该例程创建了2个定时器，一个有限次数溢出，一个无限次数溢出，每次定时器溢出，都打印出信息；
 */

T_MODULE T_VOID timer0_handle()
{
	printk("TTOS timer0 timeout.\n");
}

T_MODULE T_VOID timer1_handle()
{
	printk("TTOS timer1 timeout.\n");
}

int userAppInit(void)
{

	T_TTOS_ReturnCode ret;
	T_UWORD timerCount = 10;

	printf("************ begin to test ***************\n");
	/*创建一个匿名定时器，定时器间隔：TTOS_GetSysClkRate * 2 = 2s;
	 * 定时器自动启动;
	 * 定时器处理函数：timer1_handle;
	 * 定时器触发次数：10 + 1 = 11;
	 * 定时器ID：timerId0
	 */
	ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate()*2, timerCount, NULL, timer0_handle, &g_timerId0);
	if(ret !=0)
	{
		printk("CreateTimer Fail!\n");
		return -1;
	}


		/*创建一个匿名定时器，定时器间隔：TTOS_GetSysClkRate = 1s;
		 * 定时器自动启动;
		 * 定时器处理函数：timer1_handle;
		 * 定时器触发次数：30 + 1 = 31;
		 * 定时器ID：timerId0
		 */
		timerCount = 30;
		ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate(), timerCount, NULL, timer1_handle, &g_timerId1);
		if(ret !=0)
		{
			printk("CreateTimer Fail!\n");
			return -1;
		}


		/**  必须等待 **/
		while(1)
			TTOS_SleepTask(5000);


    return 0;
}

