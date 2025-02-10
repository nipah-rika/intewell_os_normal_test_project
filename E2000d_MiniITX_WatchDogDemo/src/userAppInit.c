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


/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

int userAppInit(void)
{
	/*����ι��ʱ��, ��λΪϵͳtick*/
	T_UWORD max_dog_time = 0x2fff;
	T_VMK_ReturnCode vmk_rc;
	/*���ݶ�*/
	 static int data_val[4] = {0, 1, 2, 3};

	 printk("data_val  primary data %d,%d,%d,%d \n", data_val[0], data_val[1], data_val[2], data_val[3]);
	 data_val[0] = 0x1234;
	 printk("data_val %d,%d,%d,%d \n", data_val[0], data_val[1], data_val[2], data_val[3]);

	/*δι��max_dog_time����ʱ����ʱ���ִ�в���ΪFALSE��ʾ��ʱ������TTOS*/
	vmk_rc = TTOS_StartWatchdog(max_dog_time, FALSE);
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}

	printk("\nTTOS_StartWatchdog successful!\n");

	return TTOS_OK;

}

