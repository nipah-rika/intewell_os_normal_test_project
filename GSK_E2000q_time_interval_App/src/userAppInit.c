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
#include <time.h>
/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
T_MODULE TIMER_ID g_timerId0;


/************************实   现*******************************/

static  T_UDWORD  Count1=0 ,Count2=0, CountTime = 0;

 T_MODULE T_VOID timer0_handle()
 {

	Count2 = TTOS_GetCurrentSystemCount();

	CountTime = TTOS_GetCurrentSystemSubTime(Count1, Count2, TTOS_NS_UNIT);

	printk("time: %llu ns*******Count1:%llu,  Count2:%llu\n",CountTime, Count1, Count2);

	Count1 = TTOS_GetCurrentSystemCount();

 }


int userAppInit(void)
{

	T_TTOS_ReturnCode ret;
	T_UWORD timerCount = 5;



	Count1 = TTOS_GetCurrentSystemCount();
	ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate()*2, timerCount, NULL, timer0_handle, &g_timerId0);

	if(ret !=0)
	{
		printk("CreateTimer Fail!\n");
		return -1;
	}


		while(1)
			TTOS_SleepTask(5000);


    return 0;
}





