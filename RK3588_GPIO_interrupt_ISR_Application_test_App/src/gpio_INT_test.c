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

static int cnt = 0;
void gpio_irq_handle(void *arg)
{
	cnt++;
	printk("gpio irq cnt:%d\n", cnt);
}


T_VOID IntewellOS_GPIO_test_input_IRQ(T_VOID)
{
    T_WORD fd = -1;
    T_WORD fd2 = -1;
    T_WORD ret = 0;
    T_BYTE value = -1;
    T_WORD cnt = 100;
    T_BYTE high[]="1";
    T_BYTE low[]="0";
	int flag=1;
    /* �� GPIO ��ȷ����GPIOû�б����������ǰϵͳ���ϵͳռ�� */
    fd = open("/GPIO_2C3", 0);
    if (fd < 0)
    {
        printf("open GPIO_2C3 errno = %d\n", errno);
        return;
    }
    T_DR_GpioConfigTable config;
    /* �Ȼ�ȡGPIO���ŵ���Ϣ */
    ioctl(fd, UIO_GET_CFG, &config);

    /* ��GPIO���ŷ�������Ϊ���� */
    config.direction = GPIO_INPUT;
    ioctl(fd, UIO_SET_CFG, &config);

	/* �����ж� */
	T_DR_GpioIrqControl irq_ctl;
	irq_ctl.mode = PIN_IRQ_MODE_FALLING;// �½��ش�����
//	irq_ctl.mode = PIN_IRQ_MODE_RISING;// �����ش���
	irq_ctl.hdr = gpio_irq_handle;
	irq_ctl.args = NULL;

	ioctl(fd, GPIO_ATTACH_IRQ, &irq_ctl);
	ioctl(fd, GPIO_ENABLE, &irq_ctl);

	/* ����GPIO_2C4��� */
	fd2 = open("/GPIO_2C4", 0);
	if (fd2 < 0)
	{
		printf("open GPIO_2C4 errno = %d\n", errno);
		flag = 0;
	}

	T_DR_GpioConfigTable config_1;
	/*��ȡGPIO������Ϣ*/
	ioctl(fd2, UIO_GET_CFG, &config_1);

	/* ����GPIO_2C4��� */
	config_1.direction = GPIO_OUTPUT;
	ioctl(fd2, UIO_SET_CFG, &config_1);

    while(cnt--)
    {
    	/*���Ե͵�ƽ*/
    	write(fd2, low, 0);
        printk("output low \n");
    	TTOS_SleepTask(TTOS_GetSysClkRate());

        read(fd, &value, 1);
        printf("read GPIO value: %c\n", value);
    	TTOS_SleepTask(TTOS_GetSysClkRate());

    	/*���Ըߵ�ƽ*/
    	write(fd2, high, 0);
        printk("output high \n");
    	TTOS_SleepTask(TTOS_GetSysClkRate());

        read(fd, &value, 1);
        printf("read GPIO value: %c\n", value);
    	TTOS_SleepTask(TTOS_GetSysClkRate());
    }
    /* �ر� GPIO */
    ret = close(fd);
    if (ret < 0)
    {
        printf("close error\n");
    }
}
