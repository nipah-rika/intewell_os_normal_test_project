/****************************************************************************
 *    �ƶ������ݣ�����Ƽ����޹�˾ ��Ȩ����
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>

�������ʶ��:
TTOS_CreateTask

������������ʶ��:
RTOS_WD_003

��Ŀ������͡�:
֧����������ƽ̨

������Ŀ�ġ�:
����������쳣��������������Ƿ��ܴ��������������������Ҫȷ����Щ�쳣������������

���������͡�:
�ӿڲ���

���Ⱦ�������:
��

�����Բ��衿:
1������GPOS+RTOS/MRTOS��Ŀ��������һ���������Ŀ��vm1���д��룬�����������У�
2���鿴������Ƿ�������
��Ԥ�ڽ����:
�����������

������׼��:
��Ԥ�ڽ��һ��

�������Լ����:
����ϵͳ������

������ߡ�:
XXX

�����ʱ�䡿:
2020-01-18

</EXECL> */
#include <ttos.h>
#ifdef USE_GPIO_WATCHDOG
	#include "watchdog.h"
	#define TTOS_StartWatchdog GPIO_StartWatchdog
	#define TTOS_FeedWatchdog GPIO_FeedWatchdog
	#define TTOS_StopWatchdog GPIO_StopWatchdog
#endif

#define			WD_GENERAL_ZDIV_INT 	0
#define			WD_GENERAL_PAGE_INT 	1

#define 		EXCEPT_MODE			WD_GENERAL_PAGE_INT

INT32 RTOS_WD_003(T_VOID)
{
	T_UWORD max_dog_time = 0xff;
	T_VMK_ReturnCode vmk_rc;

	/*δι��max_dog_time����ʱ����ʱ���ִ�в���ΪFALSE��ʾ��ʱ������TTOS*/
	vmk_rc = TTOS_StartWatchdog(max_dog_time, FALSE);
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}

	printk("\nTTOS_StartWatchdog successful!\n");

	T_EXTERN T_UWORD tbspVintStackStart;
	T_ULONG* pAddr = (T_ULONG*)tbspVintStackStart;
	*pAddr = 0x1234;
	return TTOS_OK;

}

