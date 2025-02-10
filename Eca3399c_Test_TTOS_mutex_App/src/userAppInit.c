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
T_MODULE T_DWORD g_Var1, g_Var2;
T_MODULE MUTEX_ID g_Mutex = NULL;
/************************实   现*******************************/

/* 说明：
 * 程序清单：互斥锁使用例程
 *
 *
 * 互斥锁是一种保护共享资源的方法。当一个线程拥有互斥锁的时候，
 * 可以保护共享资源不被其他线程破坏。线程1对2个g_Var分别进行加1操作
 * 线程2也会对2个g_Var分别进行加1操作。使用互斥量保证2个g_Var值保持一致，
 * 虽然是公共资源，每次两个var都加一，两者一致表示互斥锁有效保护了资源。
 *
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
    while (1)
    {
        /* 线程1获取到互斥量后，先后对g_Var1、g_Var2进行加1操作，然后释放互斥量 */
    	TTOS_ObtainMutex(g_Mutex, TTOS_SEMA_WAIT_FOREVER);
    	 if (g_Var1 != g_Var2)
    	        {
    		 	 	printf("not protect. var1 = %d, var2 = %d \n", g_Var1, g_Var2);
    	        }
    	        else
    	        {
    	        	printf("mutex protect ,var1 = var2 is %d\n", g_Var1);
    	        }


    	g_Var1++;
        TTOS_SleepTask(100);
        g_Var2++;
        TTOS_ReleaseMutex(g_Mutex);
    }
}

void TTOS_thread_2(void)
{
    while (1)
    {
        /* 线程1获取到互斥量后，先后对g_Var1、g_Var2进行加1操作，然后释放互斥量 */
    	TTOS_ObtainMutex(g_Mutex, TTOS_SEMA_WAIT_FOREVER);
    	g_Var1++;
        TTOS_SleepTask(100);
        g_Var2++;
        TTOS_ReleaseMutex(g_Mutex);
    }
}


int userAppInit(void)
{
	T_TTOS_ReturnCode mTtosRet = 0;
	T_MODULE TASK_ID g_TaskID1;
	T_MODULE TASK_ID g_TaskID2;

	g_Var1 = 0;
	g_Var2 = 0;

	if (TTOS_OK != TTOS_CreateMutex(1, 0, &g_Mutex))
	{
		printf("ERROR: cannot create mutex.\n");
		return -1;
	}

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

