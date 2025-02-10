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

#include <semaphore.h>
#include <ttos.h>
#include <pthread.h>
#include <timer.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/

pthread_t gThreadId1, gThreadId2, gThreadId3;
/************************ʵ   ��*******************************/

/**
 * @brief:
 *      �½����߳�0��ʵ�ִ�ӡ���ԡ�
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
 *      �½����߳�1��ʵ�ִ�ӡ���ԡ�
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
 *      �½����߳�2��ʵ�ִ�ӡ���ԡ�
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
 *      ����TTOS�̣߳�ʵ�������߳����ܣ�ÿ���̴߳�ӡ�Լ�����Ϣ�����Ի����Ķ��̹߳��ܡ�
 */
int userAppInit(void)
{
	T_WORD ret;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setschedprio(&attr, PTHREAD_MAXIMUM_PRIORITY); //�������ȼ�����
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

