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
#include <errno.h>
#include <sysGpio.h>
#include <fcntl.h>


/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/
T_VOID IntewellOS_GPIO_test_output(T_VOID)
{
	T_WORD fd = -1;
	T_WORD ret = 0;
    T_BYTE high[]="1";
    T_BYTE low[]="0";
    T_WORD cnt = 100;

    /* ���� GPIO �ܽŸ��ù��� */
	//void *gpio3_d = (void *)(0xff770000 +0xe01c);
	//*(volatile unsigned int *)(gpio3_d) = (0xffff << 16);

	/* �� GPIO */
	fd = open("/GPIO_2B4", 0);
	if (fd < 0)
	{
		printk("open GPIO errno = %d\n", errno);
		return;
	}

	T_DR_GpioConfigTable config;

	ioctl(fd, UIO_GET_CFG, &config);

	config.direction = GPIO_OUTPUT;

	ioctl(fd, UIO_SET_CFG, &config);

	while(cnt--)
	{
		/* ���� GPIO ����ߵ�ƽ */
		write(fd, high, 1);
		TTOS_SleepTask(1000);

		/* ���� GPIO ����͵�ƽ */
		write(fd, low, 1);
		TTOS_SleepTask(1000);
	}

	/* �ر� GPIO */
	ret = close(fd);
	if (ret < 0)
	{
		printk("close GPIO error\n");
	}
}



T_VOID IntewellOS_GPIO_test_input(T_VOID)
{
	T_WORD fd = -1;
	T_WORD ret = 0;
    T_BYTE value = -1;
    T_WORD cnt = 100;

    /* ����GPIO�ܽ�  */
	//void *gpio3_d = (void *)(0xff770000+0xe01c);
	//*(volatile unsigned int *)(gpio3_d) = (0xffff << 16);

	/* �� GPIO */
    fd = open("/GPIO_2B3", 0);
	if (fd < 0)
	{
		printk("open GPIO errno = %d\n", errno);
		return;
	}

	T_DR_GpioConfigTable config;

	ioctl(fd, UIO_GET_CFG, &config);

	config.direction = GPIO_INPUT;

	ioctl(fd, UIO_SET_CFG, &config);

	while(cnt--)
	{
		read(fd, &value, 1);
		TTOS_SleepTask(1000);
		printk("read GPIO value: %c\n", value);
	}

	/* �ر� GPIO */
	ret = close(fd);
	if (ret < 0)
	{
		printk("close error\n");
	}
}


int userAppInit(void)
{
	/* �Ȳ���GPIO�����룬һ��ʱ�䣬���ʱ�����û�����ͨ��������GPIO�����Զ�ȡ����ֵ  */
	printf("\r\n **********TTOS Test Gpio Input for a while: **********\n");
	IntewellOS_GPIO_test_input();

	/* �Ȳ���GPIO�����룬һ��ʱ�䣬���ʱ�����û����Թ۲�GPIO��ƽ�жϣ���ƽӦ��Ϊ�ߵͽ���  */
	printf("\r\n **********TTOS Test Gpio Output for a while: **********\n");
	IntewellOS_GPIO_test_output();

	printf("\r\n **********TTOS Test Gpio finished **********\n");

    return 0;
}

