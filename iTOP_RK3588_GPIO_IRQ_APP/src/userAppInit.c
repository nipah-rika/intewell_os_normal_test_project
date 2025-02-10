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


void gpio_irq_callback(void *arg) {
	printk("------------gpio irq happen-----------------\n");
}


int userAppInit(void) {
	T_WORD fd = -1;
	T_WORD fd1 = -1;
	T_WORD ret = 0;
	T_BYTE buf[20] = { 0 };
	int cnt = 50;

	fd = open("/GPIO_4C3", 0);
	if (fd < 0) {
		printk("open errno = %d\n", errno);
		return;
	}

	T_DR_GpioConfigTable config;
	ioctl(fd, UIO_GET_CFG, &config);
	config.direction = GPIO_INPUT;
	ioctl(fd, UIO_SET_CFG, &config);

	T_DR_GpioIrqControl irq_ctl;
	irq_ctl.mode = PIN_IRQ_MODE_RISING;
	irq_ctl.hdr = gpio_irq_callback;
	irq_ctl.args = NULL;

	ioctl(fd, GPIO_ATTACH_IRQ, &irq_ctl);
	ioctl(fd, GPIO_ENABLE,0);

    while(cnt--)
    {
            TTOS_SleepTask(2000);
            /* ��IO��ƽ */
            read(fd, buf,1);
            printk("read read_val = %s\n",buf);
    }

	/* �ر�gpio */
	ret = close(fd);
	if (ret < 0) {
		printk("close error\n");
	}

	return 0;
}

