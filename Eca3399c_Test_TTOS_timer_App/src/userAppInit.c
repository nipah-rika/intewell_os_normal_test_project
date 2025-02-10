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
T_MODULE TIMER_ID g_timerId0;
T_MODULE TIMER_ID g_timerId1;

/************************ʵ   ��*******************************/


/*
 * ��̷��
 *         ����linux/��unix���
 *         �ֲ�������������������
 *         ȫ�ֱ�����������������
 *         �궨�壺linux��� ��д
 */

/* ˵����
 * �����嵥����ʱ������
 *
 * �����̴�����2����ʱ����һ�����޴��������һ�����޴��������ÿ�ζ�ʱ�����������ӡ����Ϣ��
 */

T_MODULE T_VOID timer0_handle()
{
	printk("TTOS timer0 timeout.\n");
}

T_MODULE T_VOID timer1_handle()
{
	printk("TTOS timer1 timeout.\n");
}

int userAppInit(void)
{

	T_TTOS_ReturnCode ret;
	T_UWORD timerCount = 10;

	printf("************ begin to test ***************\n");
	/*����һ��������ʱ������ʱ�������TTOS_GetSysClkRate * 2 = 2s;
	 * ��ʱ���Զ�����;
	 * ��ʱ����������timer1_handle;
	 * ��ʱ������������10 + 1 = 11;
	 * ��ʱ��ID��timerId0
	 */
	ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate()*2, timerCount, NULL, timer0_handle, &g_timerId0);
	if(ret !=0)
	{
		printk("CreateTimer Fail!\n");
		return -1;
	}


		/*����һ��������ʱ������ʱ�������TTOS_GetSysClkRate = 1s;
		 * ��ʱ���Զ�����;
		 * ��ʱ����������timer1_handle;
		 * ��ʱ������������30 + 1 = 31;
		 * ��ʱ��ID��timerId0
		 */
		timerCount = 30;
		ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate(), timerCount, NULL, timer1_handle, &g_timerId1);
		if(ret !=0)
		{
			printk("CreateTimer Fail!\n");
			return -1;
		}


		/**  ����ȴ� **/
		while(1)
			TTOS_SleepTask(5000);


    return 0;
}

