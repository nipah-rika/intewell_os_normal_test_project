/*********************************************************************************
*				                                         �ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
* 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * �޸���ʷ��
 * 2017-05-10     ����, �ƶ������ݣ�����Ƽ����޹�˾
 *                �������ļ���
 *                
*/

/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <ttos.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/
/************************ȫ�ֱ���******************************/
T_MODULE TASK_ID g_TaskID[4];

T_MODULE SEMA_ID g_Sema;
/************************ʵ   ��*******************************/

/* ˵����
 * �����嵥���ź�������
 *
 * �����̴�����һ��������̬�ź�������ʼ��4���̣߳�4���̶߳�Ҫȡ���ź�����ֻ��2������ȡ���ź���
 * ������һ���ͷ��ź���֮��������߳̿���ȡ���ź�������������
 *
 * ��̷��
 *         ����linux/��unix���
 *         �ֲ�������������������
 *         ȫ�ֱ�����������������
 *         �궨�壺linux��� ��д
 */


void TTOS_thread_1(void)
{
	while(1)
	{
		TTOS_ObtainSema (g_Sema, TTOS_SEMA_WAIT_FOREVER);
		printk("thread 1 got a semaphore.  sema value:%u\n", g_Sema->semaControlValue);

		/* ռ���ź��������˯��һ��ʱ�䣬�ͷż����ź������������߳̿��Ի�ȡ�������ź��� */
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

		/* ռ���ź��������˯��һ��ʱ�䣬�ͷż����ź������������߳̿��Ի�ȡ�������ź��� */
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

		/* ռ���ź��������˯��һ��ʱ�䣬�ͷż����ź������������߳̿��Ի�ȡ�������ź��� */
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

		/* ռ���ź��������˯��һ��ʱ�䣬�ͷż����ź������������߳̿��Ի�ȡ�������ź��� */
		TTOS_SleepTask( TTOS_GetSysClkRate()*(rand()%10) );
		TTOS_ReleaseSema(g_Sema);
	}
}



/*
 * ��ʼ���ź���
 * ��ʼֵ1
 * ���ԣ������ź�����TTOS_MUTEX_SEMAPHORE��
 * ���ȼ���priorityCeiling
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
	/* ��ʼֵ��2����ʾ�����߳̿��Ի�ȡ���ź������������� */
	mSemaParam.initValue = 2;
	mSemaParam.attributeSet = TTOS_COUNTING_SEMAPHORE;
	mSemaParam.priorityCeiling = 0;

	/* �����ź������������ź���*/
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

    /* ����task2 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task1",
			250,
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_1,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID[0]);


    /* ����task2 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task2",
			250,
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_2,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID[1]);

    /* ����task3 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task3",
			250,
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_3,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID[2]);

    /* ����task4 */
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
