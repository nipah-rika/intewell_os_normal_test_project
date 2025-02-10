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
T_MODULE T_DWORD g_Var1, g_Var2;
T_MODULE MUTEX_ID g_Mutex = NULL;
/************************ʵ   ��*******************************/

/* ˵����
 * �����嵥��������ʹ������
 *
 *
 * ��������һ�ֱ���������Դ�ķ�������һ���߳�ӵ�л�������ʱ��
 * ���Ա���������Դ���������߳��ƻ����߳�1��2��g_Var�ֱ���м�1����
 * �߳�2Ҳ���2��g_Var�ֱ���м�1������ʹ�û�������֤2��g_Varֵ����һ�£�
 * ��Ȼ�ǹ�����Դ��ÿ������var����һ������һ�±�ʾ��������Ч��������Դ��
 *
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
    while (1)
    {
        /* �߳�1��ȡ�����������Ⱥ��g_Var1��g_Var2���м�1������Ȼ���ͷŻ����� */
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
        /* �߳�1��ȡ�����������Ⱥ��g_Var1��g_Var2���м�1������Ȼ���ͷŻ����� */
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

