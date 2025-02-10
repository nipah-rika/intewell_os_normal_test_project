/****************************************************************************
 *    科东（广州）软件技术有限公司 版权所有
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/

/* <EXECL>
需求标识：
XXX
测试用例标识：
gpio_test
目标机类型：
iTOP-RK3588
测试目的:
验证GPIO输出输入高低电平功能
测试类型：
功能测试
先决条件：
实时系统运行正常
测试步骤：
1、配置项目配置打开的GPIO组；
2、打开对应的两个GPIO口；
3、一个GPIO口作输出写操作，一个GPIO口作输入读操作；
4、将读到的数据打印出来；
预期结果：
GIOP口读写正常。
评价准则：
与预期结果一致
假设和约束：
操作系统可运行
设计者：
XXX
设计时间：
XXXX-XX-XX
</EXECL>
 */

/**************************** 引用部分 *****************************************/

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
    /* 打开 GPIO 需确保该GPIO没有被其它外设或当前系统外的系统占用 */
    fd = open("/GPIO_2C3", 0);
    if (fd < 0)
    {
        printf("open GPIO_2C3 errno = %d\n", errno);
        return;
    }
    T_DR_GpioConfigTable config;
    /* 先获取GPIO引脚的信息 */
    ioctl(fd, UIO_GET_CFG, &config);

    /* 将GPIO引脚方向设置为输入 */
    config.direction = GPIO_INPUT;
    ioctl(fd, UIO_SET_CFG, &config);

	/* 设置中断 */
	T_DR_GpioIrqControl irq_ctl;
	irq_ctl.mode = PIN_IRQ_MODE_FALLING;// 下降沿触发，
//	irq_ctl.mode = PIN_IRQ_MODE_RISING;// 上升沿触发
	irq_ctl.hdr = gpio_irq_handle;
	irq_ctl.args = NULL;

	ioctl(fd, GPIO_ATTACH_IRQ, &irq_ctl);
	ioctl(fd, GPIO_ENABLE, &irq_ctl);

	/* 设置GPIO_2C4输出 */
	fd2 = open("/GPIO_2C4", 0);
	if (fd2 < 0)
	{
		printf("open GPIO_2C4 errno = %d\n", errno);
		flag = 0;
	}

	T_DR_GpioConfigTable config_1;
	/*获取GPIO引脚信息*/
	ioctl(fd2, UIO_GET_CFG, &config_1);

	/* 设置GPIO_2C4输出 */
	config_1.direction = GPIO_OUTPUT;
	ioctl(fd2, UIO_SET_CFG, &config_1);

    while(cnt--)
    {
    	/*测试低电平*/
    	write(fd2, low, 0);
        printk("output low \n");
    	TTOS_SleepTask(TTOS_GetSysClkRate());

        read(fd, &value, 1);
        printf("read GPIO value: %c\n", value);
    	TTOS_SleepTask(TTOS_GetSysClkRate());

    	/*测试高电平*/
    	write(fd2, high, 0);
        printk("output high \n");
    	TTOS_SleepTask(TTOS_GetSysClkRate());

        read(fd, &value, 1);
        printf("read GPIO value: %c\n", value);
    	TTOS_SleepTask(TTOS_GetSysClkRate());
    }
    /* 关闭 GPIO */
    ret = close(fd);
    if (ret < 0)
    {
        printf("close error\n");
    }
}
