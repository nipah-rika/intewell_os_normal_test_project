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
/************************实   现*******************************/



/* 说明：
 * 程序清单：系统时钟例程
 *
 * 该例程演示TTOS系统时钟API的使用，打印出各个系统时钟的状态。
 */

int userAppInit(void)
{
	T_UDWORD mNowCounts = 0;
	T_TTOS_ReturnCode mRet;
	T_UDWORD mCurrentTicks, t1, t2;

	for(int cnt=0; cnt<100; cnt++){

			mRet = TTOS_GetSystemTicks(&mCurrentTicks);
			if (mRet != TTOS_OK)
				{
				printf("TTOS_GetSystemTicks return error code.\n");
				}
			printf("TTOS_GetSystemTicks: %u. \n", mCurrentTicks);

			/* 获取系统每秒 tick 数 */
			printf("TTOS_GetSysClkRate: %u. \n", TTOS_GetSysClkRate());

			/* 获取当前系统中流逝的 TSC COUNT 数 */
			printf("TTOS_GetCurrentSystemCount: %u. \n", TTOS_GetCurrentSystemCount());

			/* 获取当前系统中流逝的 TSC 频率 */
			printf("TTOS_GetCurrentSystemFreq: %u. \n", TTOS_GetCurrentSystemFreq());

			/* 获取系统从启动流逝的时间 */
			mNowCounts = TTOS_GetCurrentSystemCount();
			mNowCounts %= TTOS_GetCurrentSystemFreq();
			printf("TTOS_GetCurrentSystemTime: %u. \n", TTOS_GetCurrentSystemTime(mNowCounts ,TTOS_MS_UNIT));

			/* 获取两个时间点的间隔时间 */
			t1 = TTOS_GetCurrentSystemCount();
			TTOS_SleepTask(TTOS_GetSysClkRate());
			t2 = TTOS_GetCurrentSystemCount();
			printf("TTOS_GetCurrentSystemSubTime: %u. \n", TTOS_GetCurrentSystemSubTime(t1, t2, TTOS_US_UNIT));

	}

    return 0;
}

