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
#include <time.h>
/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
T_MODULE TIMER_ID g_timerId0;


/************************ʵ   ��*******************************/

static  T_UDWORD  Count1=0 ,Count2=0, CountTime = 0;

 T_MODULE T_VOID timer0_handle()
 {

	Count2 = TTOS_GetCurrentSystemCount();

	CountTime = TTOS_GetCurrentSystemSubTime(Count1, Count2, TTOS_NS_UNIT);

	printk("time: %llu ns*******Count1:%llu,  Count2:%llu\n",CountTime, Count1, Count2);

	Count1 = TTOS_GetCurrentSystemCount();

 }


int userAppInit(void)
{

	T_TTOS_ReturnCode ret;
	T_UWORD timerCount = 5;



	Count1 = TTOS_GetCurrentSystemCount();
	ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate()*2, timerCount, NULL, timer0_handle, &g_timerId0);

	if(ret !=0)
	{
		printk("CreateTimer Fail!\n");
		return -1;
	}


		while(1)
			TTOS_SleepTask(5000);


    return 0;
}





