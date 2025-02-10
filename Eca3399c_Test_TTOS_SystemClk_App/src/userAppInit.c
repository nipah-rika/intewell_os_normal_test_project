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



/* ˵����
 * �����嵥��ϵͳʱ������
 *
 * ��������ʾTTOSϵͳʱ��API��ʹ�ã���ӡ������ϵͳʱ�ӵ�״̬��
 */

int userAppInit(void)
{
	T_UDWORD mNowCounts = 0;
	T_TTOS_ReturnCode mRet;
	T_UDWORD mCurrentTicks, t1, t2;

	for(int cnt=0; cnt<100; cnt++){

			mRet = TTOS_GetSystemTicks(&mCurrentTicks);
			if (mRet != TTOS_OK)
				{
				printf("TTOS_GetSystemTicks return error code.\n");
				}
			printf("TTOS_GetSystemTicks: %u. \n", mCurrentTicks);

			/* ��ȡϵͳÿ�� tick �� */
			printf("TTOS_GetSysClkRate: %u. \n", TTOS_GetSysClkRate());

			/* ��ȡ��ǰϵͳ�����ŵ� TSC COUNT �� */
			printf("TTOS_GetCurrentSystemCount: %u. \n", TTOS_GetCurrentSystemCount());

			/* ��ȡ��ǰϵͳ�����ŵ� TSC Ƶ�� */
			printf("TTOS_GetCurrentSystemFreq: %u. \n", TTOS_GetCurrentSystemFreq());

			/* ��ȡϵͳ���������ŵ�ʱ�� */
			mNowCounts = TTOS_GetCurrentSystemCount();
			mNowCounts %= TTOS_GetCurrentSystemFreq();
			printf("TTOS_GetCurrentSystemTime: %u. \n", TTOS_GetCurrentSystemTime(mNowCounts ,TTOS_MS_UNIT));

			/* ��ȡ����ʱ���ļ��ʱ�� */
			t1 = TTOS_GetCurrentSystemCount();
			TTOS_SleepTask(TTOS_GetSysClkRate());
			t2 = TTOS_GetCurrentSystemCount();
			printf("TTOS_GetCurrentSystemSubTime: %u. \n", TTOS_GetCurrentSystemSubTime(t1, t2, TTOS_US_UNIT));

	}

    return 0;
}

