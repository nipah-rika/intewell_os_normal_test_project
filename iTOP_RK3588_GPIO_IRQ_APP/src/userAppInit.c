/*********************************************************************************
 *				                                         科东(广州)软件科技有限公司 版权所有
 * 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
 **********************************************************************************/

/*
 * 修改历史：
 * 2017-05-10     李燕, 科东（广州）软件科技有限公司
 *                创建该文件。
 *                
 */

/*
 * @file：userAppInit.c
 * @brief：
 *	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
 * @implements：
 */

/************************头 文 件******************************/
#include <commonTypes.h>
#include <errno.h>
#include <sysGpio.h>
#include <fcntl.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/


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
            /* 读IO电平 */
            read(fd, buf,1);
            printk("read read_val = %s\n",buf);
    }

	/* 关闭gpio */
	ret = close(fd);
	if (ret < 0) {
		printk("close error\n");
	}

	return 0;
}

