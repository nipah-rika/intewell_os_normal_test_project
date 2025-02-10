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
T_TTOS_EventSet  event1;
T_TTOS_EventSet  event2;
T_TTOS_EventSet  event3;
/************************ʵ   ��*******************************/

/* ˵����
 * �����嵥��TTOS�¼���ʹ������
 *
 * ��������ʾTTOS���¼�ʹ�÷����������д�����3������
 * ÿ�����񶼵ȴ��¼����������У�����1�ȴ��¼�8000 ticks��ʱ�䡣
 * ����2������3��һֱ�ȴ��¼���
 * һ��������ԶԶ���¼�����Ȥ��һ���¼����Ա��������ʶ��
 * ��ʾ�У������2���¼�����Ȥ�����ұ����ȡ�������¼��������Żᴥ����
 * ������Ҳ�������¼�����Ȥ������ֻ��Ҫ����һ���¼��������ͻᴥ��
 */

 /*
 *
 * ��̷��
 *         ����linux/��unix���
 *         �ֲ�������������������
 *         ȫ�ֱ�����������������
 *         �궨�壺linux��� ��д
 */


void TTOS_thread_1(void)
{
	T_TTOS_ReturnCode ret;
    while (1)
    {
        ret = TTOS_ReceiveEvent (TTOS_EVENT_0, TTOS_EVENT_ANY,/*��ʾ�ȴ�����һ���¼������ԲŴ������ȴ��¼�1�������ɴ���*/
                                 8000,/*��ʾ�ȴ��¼� 8000 ticks*/
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
        ret = TTOS_ReceiveEvent (TTOS_EVENT_1|TTOS_EVENT_2, TTOS_EVENT_ALL,/*��ʾ������������¼�����Ȥ������ȴ������¼��Ŵ���*/
                                 TTOS_EVENT_WAIT_FOREVER,/*��ʾ�������õȴ��¼�*/
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
        ret = TTOS_ReceiveEvent (TTOS_EVENT_3|TTOS_EVENT_2, TTOS_EVENT_ANY,/*��ʾ�ȴ�����һ���¼������ԲŴ������ȴ��¼�3�����¼�2�������ɴ���*/
                                 TTOS_EVENT_WAIT_FOREVER,/*��ʾ�������õȴ��¼�*/
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


    /* ����task1 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task1",
			220, // �ȵ�ǰ�������ȼ���
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_1,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID1);


    /* ����task2 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task2",
			220, // �ȵ�ǰ�������ȼ���
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_2,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID2);

    /* ����task3 */
	mTtosRet = TTOS_CreateTaskEx(
            (T_UBYTE *)"task3",
			220, // �ȵ�ǰ�������ȼ���
			TRUE,
            TRUE,
            (T_TTOS_TaskRoutine)TTOS_thread_3,
            NULL,
            TTOS_MINIMUM_STACK_SIZE,
            &g_TaskID3);



	/* ��ʼ�����������ɷ�event */
	mTtosRet = TTOS_SendEvent(g_TaskID1, TTOS_EVENT_0);
	if (TTOS_OK != mTtosRet)
	{
		printf("{%s}:[%d].  fail ret=%d\n", __func__, __LINE__, mTtosRet);
	}
	TTOS_SleepTask(1000);

	/*������2����һ���¼�1����ʱ����2�������ӡ*/
	mTtosRet = TTOS_SendEvent(g_TaskID2, TTOS_EVENT_1);
	if (TTOS_OK != mTtosRet)
	{
		printf("{%s}:[%d].  fail ret=%d\n", __func__, __LINE__, mTtosRet);
	}
	TTOS_SleepTask(1000);

	/*������2����һ���¼�2����ʱ����2�ᴥ����ӡ����Ϊ�����¼�����*/
	mTtosRet = TTOS_SendEvent(g_TaskID2, TTOS_EVENT_2);
	if (TTOS_OK != mTtosRet)
	{
		printf("{%s}:[%d].  fail ret=%d\n", __func__, __LINE__, mTtosRet);
	}
	TTOS_SleepTask(1000);

	/*������3����һ���¼�3����ʱ����3�ᴥ����ӡ����Ϊֻ��Ҫһ���¼����ɴ���*/
	mTtosRet = TTOS_SendEvent(g_TaskID3, TTOS_EVENT_3);
	if (TTOS_OK != mTtosRet)
	{
		printf("{%s}:[%d].  fail ret=%d\n", __func__, __LINE__, mTtosRet);
	}

    return 0;
}

