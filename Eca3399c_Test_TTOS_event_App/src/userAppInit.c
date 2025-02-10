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
T_TTOS_EventSet  event1;
T_TTOS_EventSet  event2;
T_TTOS_EventSet  event3;
/************************实   现*******************************/

/* 说明：
 * 程序清单：TTOS事件的使用例程
 *
 * 此例程演示TTOS的事件使用方法，例程中创建了3个任务，
 * 每个任务都等待事件到来，其中，任务1等待事件8000 ticks的时间。
 * 任务2和任务3会一直等待事件。
 * 一个任务可以对多个事件感兴趣，一个事件可以被多个任务识别。
 * 演示中，任务对2个事件感兴趣，而且必须获取到两个事件都到来才会触发。
 * 任务三也对两个事件感兴趣，但是只需要任意一个事件到来，就会触发
 */

 /*
 *
 * 编程风格：
 *         函数linux/类unix风格
 *         局部变量：匈牙利命名法
 *         全局变量：匈牙利命名法
 *         宏定义：linux风格 大写
 */


void TTOS_thread_1(void)
{
	T_TTOS_ReturnCode ret;
    while (1)
    {
        ret = TTOS_ReceiveEvent (TTOS_EVENT_0, TTOS_EVENT_ANY,/*表示等待任意一个事件都可以才触发，等待事件1到来即可触发*/
                                 8000,/*表示等待事件 8000 ticks*/
                                 & event1);

        if(ret == TTOS_OK)
		{
			printf("TTOS thread1 got event 0. In 8 seconds.\n");
		}

        TTOS_SleepTask(100);
    }
}

void TTOS_thread_2(void)
{
	T_TTOS_ReturnCode ret;
    while (1)
    {
        ret = TTOS_ReceiveEvent (TTOS_EVENT_1|TTOS_EVENT_2, TTOS_EVENT_ALL,/*表示该任务对两个事件感兴趣，必须等待所有事件才触发*/
                                 TTOS_EVENT_WAIT_FOREVER,/*表示任务永久等待事件*/
                                 & event2);
        if(ret == TTOS_OK)
        {
        	printf("TTOS thread2 got event1 and event2.\n");
        }

        TTOS_SleepTask(100);
    }
}


void TTOS_thread_3(void)
{
	T_TTOS_ReturnCode ret;
    while (1)
    {
        ret = TTOS_ReceiveEvent (TTOS_EVENT_3|TTOS_EVENT_2, TTOS_EVENT_ANY,/*表示等待任意一个事件都可以才触发，等待事件3或者事件2到来都可触发*/
                                 TTOS_EVENT_WAIT_FOREVER,/*表示任务永久等待事件*/
                                 & event3);

        if(ret == TTOS_OK)
		{
			printf("TTOS thread3 got event2 or event 3.\n");
		}

        TTOS_SleepTask(100);
    }
}


int userAppInit(void)
{

	T_TTOS_ReturnCode mTtosRet = 0;
	T_MODULE TASK_ID g_TaskID1;
	T_MODULE TASK_ID g_TaskID2;
	T_MODULE TASK_ID g_TaskID3;


    /* 创建task1 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task1",
			220, // 比当前任务优先级低
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_1,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID1);


    /* 创建task2 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task2",
			220, // 比当前任务优先级低
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_2,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID2);

    /* 创建task3 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task3",
			220, // 比当前任务优先级低
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_3,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID3);



	/* 开始往各个任务派发event */
	mTtosRet = TTOS_SendEvent(g_TaskID1, TTOS_EVENT_0);
	if (TTOS_OK != mTtosRet)
	{
		printf("{%s}:[%d].  fail ret=%d\n", __func__, __LINE__, mTtosRet);
	}
	TTOS_SleepTask(1000);

	/*对任务2发送一个事件1，此时任务2还不会打印*/
	mTtosRet = TTOS_SendEvent(g_TaskID2, TTOS_EVENT_1);
	if (TTOS_OK != mTtosRet)
	{
		printf("{%s}:[%d].  fail ret=%d\n", __func__, __LINE__, mTtosRet);
	}
	TTOS_SleepTask(1000);

	/*对任务2发送一个事件2，此时任务2会触发打印，因为所有事件到齐*/
	mTtosRet = TTOS_SendEvent(g_TaskID2, TTOS_EVENT_2);
	if (TTOS_OK != mTtosRet)
	{
		printf("{%s}:[%d].  fail ret=%d\n", __func__, __LINE__, mTtosRet);
	}
	TTOS_SleepTask(1000);

	/*对任务3发送一个事件3，此时任务3会触发打印，因为只需要一个事件即可触发*/
	mTtosRet = TTOS_SendEvent(g_TaskID3, TTOS_EVENT_3);
	if (TTOS_OK != mTtosRet)
	{
		printf("{%s}:[%d].  fail ret=%d\n", __func__, __LINE__, mTtosRet);
	}

    return 0;
}

