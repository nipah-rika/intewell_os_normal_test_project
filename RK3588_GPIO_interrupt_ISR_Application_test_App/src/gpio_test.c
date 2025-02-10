/****************************************************************************
 *    �ƶ������ݣ�����������޹�˾ ��Ȩ����
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/
 
/* <EXECL>
�����ʶ��
XXX
����������ʶ��
gpio_test
Ŀ������ͣ�
iTOP-RK3588
����Ŀ��:
��֤GPIO�������ߵ͵�ƽ����
�������ͣ�
���ܲ���
�Ⱦ�������
ʵʱϵͳ��������
���Բ��裺
1��������Ŀ���ô򿪵�GPIO�飻
2���򿪶�Ӧ������GPIO�ڣ�
3��һ��GPIO�������д������һ��GPIO���������������
4�������������ݴ�ӡ������
Ԥ�ڽ����
GIOP�ڶ�д������
����׼��
��Ԥ�ڽ��һ��
�����Լ����
����ϵͳ������
����ߣ�
XXX
���ʱ�䣺
XXXX-XX-XX
</EXECL>
 */

/**************************** ���ò��� *****************************************/
 
#include <components/modbusIO.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "test.h"
#include <sysGpio.h>

T_VOID gpio_test(T_VOID)
{
	T_WORD fd = -1;
    T_WORD fd2 = -1;
	T_WORD ret = 0;
	T_BYTE buf[20] = {0};
    T_BYTE high[]="1";
    T_BYTE low[]="0";
	int i=0;
	int flag=1;
	T_BYTE array_high[20];
	T_BYTE array_low[20];

	/* ��GPIO_2C4 ��Ϊ���*/
	fd = open("/GPIO_2C4", 0);
	if (fd < 0)
	{
		printf("open errno = %d\n", errno);
		flag = 0;
	}
	/* ��GPIO_2C3 ��Ϊ����*/
	fd2 = open("/GPIO_2C3", 0);
	if (fd < 0)
	{
		printf("open errno = %d\n", errno);
		flag = 0;
	}
	while(1)
	{
	i++;
	if(i>20)
	{
		break;
	}
	/* ����gpio����ߵ�ƽ */
	write(fd, high, 1);
	TTOS_SleepTask(TTOS_GetSysClkRate());
    
	/* ����gpio�� */
	ret = read(fd2, buf, 1);
	if (ret != 1)
	{
		TEST_ERRPRINT(ret);
		flag = 0;
		return;
	}
	
	array_high[i-1] = buf[0];
	printf("write 1 read buf = %s\n", buf);
	printf("array_high = %c\n", array_high[i-1]);
    
    /* ����gpio����͵�ƽ */
	write(fd, low, 0);
    
	TTOS_SleepTask(TTOS_GetSysClkRate());
	/* ����gpio�� */
	ret = read(fd2, buf, 1);
	if (ret != 1)
	{
		TEST_ERRPRINT(ret);
		flag = 0;
		return;
	}
    

	printf("write 0 read buf = %s\n", buf);
	array_low[i-1] = buf[0];
	printf("array_low = %c\n", array_low[i-1]);
	}
	
	for(i=0;i<20;i++)
	{
		if(array_high[i] != '1')
		{
			TEST_FAILRINT();
			flag = 0;
     		return;
		}
	}
	
	for(i=0;i<20;i++)
	{
		if(array_low[i] != '0')
		{
			TEST_FAILRINT();
			flag = 0;
     		return;
		}
	}
	
	if(flag==1)
	{
		TEST_OKPRINT();
	}
	
	TTOS_SleepTask(TTOS_GetSysClkRate());
	/* �ر�gpio */
	ret = close(fd);
	if (ret < 0)
	{
		TEST_ERRPRINT(ret);
	}

}
