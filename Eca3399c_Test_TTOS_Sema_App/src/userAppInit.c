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
T_MODULE TASK_ID g_TaskID1;
T_MODULE TASK_ID g_TaskID2;
T_MODULE SEMA_ID g_Sema;
/************************实   现*******************************/

/* 说明：
 * 程序清单：信号量例程
 *
 * 该例程创建了一个二值信号量，初始化两个线程，线程1每计数200次时，
 * 发送一个信号量，线程2在接收信号量后，对mCount进行加1操作
 *
 * 编程风格：
 *         函数linux/类unix风格
 *         局部变量：匈牙利命名法
 *         全局变量：匈牙利命名法
 *         宏定义：linux风格 大写
 */


void TTOS_thread_1(void)
{
	T_TTOS_ReturnCode mTtosRet = 0;
    static T_DWORD mCount = 0;
    while (1)
    {
    	/* 线程1先获取到信号量，让线程2等待 */
    	mTtosRet = TTOS_ObtainSema (g_Sema, TTOS_SEMA_WAIT_FOREVER);
		if (mTtosRet != TTOS_OK)
		{
				TTOS_DeleteSema(g_Sema);
				return (-EBUSY);
		}


        while (mCount <= 200)
        {
        	mCount++;
        }


        /* count每计数200次，就释放一次信号量 */
		printf("thread1 release a semaphore.\n");
		TTOS_ReleaseSema(g_Sema);
		TTOS_SleepTask(50);
    }
}

void TTOS_thread_2(void)
{
	T_TTOS_ReturnCode mTtosRet = 0;
	T_WORD mCount = 0;
	while(1)
	{
		/* 一直等待，直到线程1释放信号量 */
		mTtosRet = TTOS_ObtainSema (g_Sema, TTOS_SEMA_WAIT_FOREVER);
	    if (mTtosRet != TTOS_OK)
	    {
	    	TTOS_DeleteSema(g_Sema);
	        return (-EBUSY);
	    }

	    printf("thread2 got a semaphore. count : %d.\n", mCount++);
	    /* 获取之后，马上释放信号量给线程1 */
	    TTOS_ReleaseSema(g_Sema);
	    TTOS_SleepTask(50);
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
	mSemaParam.initValue = 1;
	mSemaParam.attributeSet = TTOS_MUTEX_SEMAPHORE;//TTOS_COUNTING_SEMAPHORE
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
			250, // 比当前任务优先级低
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_1,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID1);


    /* 创建task2 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task2",
			250, // 比当前任务优先级低
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_2,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID2);



    return 0;
}

