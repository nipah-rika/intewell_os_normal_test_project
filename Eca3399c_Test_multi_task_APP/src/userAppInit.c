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

#include <semaphore.h>
#include <ttos.h>
#include <pthread.h>
#include <timer.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/

pthread_t gThreadId1, gThreadId2, gThreadId3;
/************************实   现*******************************/

/**
 * @brief:
 *      新建的线程0，实现打印测试。
 */
void *test_thread_0(void *data)
{
	T_ULONG cnt;
	cnt = 256;

	while(cnt --){
		printf("In thread 0, func: %s, line: %d;\n", __FUNCTION__, __LINE__);
		TTOS_SleepTask(TTOS_GetSysClkRate());
	}

}

/**
 * @brief:
 *      新建的线程1，实现打印测试。
 */
void *test_thread_1(void *data)
{
	T_ULONG cnt;
	cnt = 256;


	while(cnt --){
		printf("In thread 1, func: %s, line: %d;\n", __FUNCTION__, __LINE__);
		TTOS_SleepTask(TTOS_GetSysClkRate());
	}

}


/**
 * @brief:
 *      新建的线程2，实现打印测试。
 */
void *test_thread_2(void *data)
{
	T_ULONG cnt;
	cnt = 256;


	while(cnt --){
		printf("In thread 2, func: %s, line: %d;\n", __FUNCTION__, __LINE__);
		TTOS_SleepTask(TTOS_GetSysClkRate());
	}

}


/**
 * @brief:
 *      测试TTOS线程，实现两个线程在跑，每个线程打印自己的信息，测试基本的多线程功能。
 */
int userAppInit(void)
{
	T_WORD ret;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setschedprio(&attr, PTHREAD_MAXIMUM_PRIORITY); //增加优先级属性
	ret = pthread_create(&gThreadId1, &attr, test_thread_0, NULL);
	if (ret != 0) {
		printf("func: %s, line: %d, create thread failed  !!!\n", __FUNCTION__, __LINE__);
		return -1;
	}


	ret = pthread_create(&gThreadId2, NULL, test_thread_1, NULL);
	if (ret != 0) {
		printf("func: %s, line: %d, create thread failed !!!\n", __FUNCTION__, __LINE__);
		return -2;
	}

	ret = pthread_create(&gThreadId3, NULL, test_thread_2, NULL);
	if (ret != 0) {
		printf("func: %s, line: %d, create thread failed !!!\n", __FUNCTION__, __LINE__);
		return -3;
	}

    return 0;
}

