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
T_MODULE TASK_ID g_TaskID1;
T_MODULE TASK_ID g_TaskID2;
T_MODULE SEMA_ID g_Sema;
/************************ʵ   ��*******************************/

/* ˵����
 * �����嵥���ź�������
 *
 * �����̴�����һ����ֵ�ź�������ʼ�������̣߳��߳�1ÿ����200��ʱ��
 * ����һ���ź������߳�2�ڽ����ź����󣬶�mCount���м�1����
 *
 * ��̷��
 *         ����linux/��unix���
 *         �ֲ�������������������
 *         ȫ�ֱ�����������������
 *         �궨�壺linux��� ��д
 */


void TTOS_thread_1(void)
{
	T_TTOS_ReturnCode mTtosRet = 0;
    static T_DWORD mCount = 0;
    while (1)
    {
    	/* �߳�1�Ȼ�ȡ���ź��������߳�2�ȴ� */
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


        /* countÿ����200�Σ����ͷ�һ���ź��� */
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
		/* һֱ�ȴ���ֱ���߳�1�ͷ��ź��� */
		mTtosRet = TTOS_ObtainSema (g_Sema, TTOS_SEMA_WAIT_FOREVER);
	    if (mTtosRet != TTOS_OK)
	    {
	    	TTOS_DeleteSema(g_Sema);
	        return (-EBUSY);
	    }

	    printf("thread2 got a semaphore. count : %d.\n", mCount++);
	    /* ��ȡ֮�������ͷ��ź������߳�1 */
	    TTOS_ReleaseSema(g_Sema);
	    TTOS_SleepTask(50);
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
	mSemaParam.initValue = 1;
	mSemaParam.attributeSet = TTOS_MUTEX_SEMAPHORE;//TTOS_COUNTING_SEMAPHORE
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
			250, // �ȵ�ǰ�������ȼ���
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_1,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID1);


    /* ����task2 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task2",
			250, // �ȵ�ǰ�������ȼ���
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_2,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID2);



    return 0;
}

