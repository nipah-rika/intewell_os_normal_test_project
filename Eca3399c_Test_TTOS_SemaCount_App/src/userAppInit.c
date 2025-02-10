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
/************************全局变量******************************/
T_MODULE TASK_ID g_TaskID[4];

T_MODULE SEMA_ID g_Sema;
/************************实   现*******************************/

/* 说明：
 * 程序清单：信号量例程
 *
 * 该例程创建了一个计数动态信号量，初始化4个线程，4个线程都要取得信号量，只有2个可以取得信号量
 * 当其中一个释放信号量之后，另外的线程可以取得信号量，不会阻塞
 *
 * 编程风格：
 *         函数linux/类unix风格
 *         局部变量：匈牙利命名法
 *         全局变量：匈牙利命名法
 *         宏定义：linux风格 大写
 */


void TTOS_thread_1(void)
{
	while(1)
	{
		TTOS_ObtainSema (g_Sema, TTOS_SEMA_WAIT_FOREVER);
		printk("thread 1 got a semaphore.  sema value:%u\n", g_Sema->semaControlValue);

		/* 占有信号量，随机睡眠一段时间，释放计数信号量，让其他线程可以获取到计数信号量 */
		TTOS_SleepTask( TTOS_GetSysClkRate()*(rand()%10) );
		TTOS_ReleaseSema(g_Sema);
	}
}

void TTOS_thread_2(void)
{
	while(1)
	{
		TTOS_ObtainSema (g_Sema, TTOS_SEMA_WAIT_FOREVER);
		printk("thread 2 got a semaphore.  sema value:%u\n", g_Sema->semaControlValue);

		/* 占有信号量，随机睡眠一段时间，释放计数信号量，让其他线程可以获取到计数信号量 */
		TTOS_SleepTask( TTOS_GetSysClkRate()*(rand()%10) );
		TTOS_ReleaseSema(g_Sema);
	}
}

void TTOS_thread_3(void)
{
	while(1)
	{
		TTOS_ObtainSema (g_Sema, TTOS_SEMA_WAIT_FOREVER);
		printk("thread 3 got a semaphore.  sema value:%u\n", g_Sema->semaControlValue);

		/* 占有信号量，随机睡眠一段时间，释放计数信号量，让其他线程可以获取到计数信号量 */
		TTOS_SleepTask( TTOS_GetSysClkRate()*(rand()%10) );
		TTOS_ReleaseSema(g_Sema);
	}
}

void TTOS_thread_4(void)
{
	while(1)
	{
		TTOS_ObtainSema (g_Sema, TTOS_SEMA_WAIT_FOREVER);
		printk("thread 4 got a semaphore. sema value:%u\n", g_Sema->semaControlValue);

		/* 占有信号量，随机睡眠一段时间，释放计数信号量，让其他线程可以获取到计数信号量 */
		TTOS_SleepTask( TTOS_GetSysClkRate()*(rand()%10) );
		TTOS_ReleaseSema(g_Sema);
	}
}



/*
 * 初始化信号量
 * 初始值1
 * 属性：互斥信号量（TTOS_MUTEX_SEMAPHORE）
 * 优先级：priorityCeiling
 *
 * */
void init_sema(void)
{
	T_TTOS_ReturnCode mStatus;
	T_TTOS_ConfigSema mSemaParam;
	mStatus = TTOS_InitSemaConfig(&mSemaParam);
	    if (mStatus != TTOS_OK)
	    {
	        return -EINVAL;
	    }

	strcpy((T_BYTE *)mSemaParam.cfgSemaName, (T_CONST T_BYTE *)"SEMA_DEMO");
	/* 初始值是2，表示两个线程可以获取该信号量，不会阻塞 */
	mSemaParam.initValue = 2;
	mSemaParam.attributeSet = TTOS_COUNTING_SEMAPHORE;
	mSemaParam.priorityCeiling = 0;

	/* 根据信号量参数创建信号量*/
	mStatus = TTOS_CreateSema(&mSemaParam, &g_Sema);
		if (mStatus != TTOS_OK)
		{
			return (-EAGAIN);
		}
}


int userAppInit(void)
{
	T_TTOS_ReturnCode mTtosRet = 0;

	init_sema();

    /* 创建task2 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task1",
			250,
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_1,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID[0]);


    /* 创建task2 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task2",
			250,
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_2,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID[1]);

    /* 创建task3 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task3",
			250,
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_3,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID[2]);

    /* 创建task4 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task4",
			250,
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_4,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID[3]);


    return 0;
}
