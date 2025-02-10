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
T_VOID IntewellOS_GPIO_test_output(T_VOID)
{
	T_WORD fd = -1;
	T_WORD ret = 0;
    T_BYTE high[]="1";
    T_BYTE low[]="0";
    T_WORD cnt = 100;

    /* 配置 GPIO 管脚复用功能 */
	//void *gpio3_d = (void *)(0xff770000 +0xe01c);
	//*(volatile unsigned int *)(gpio3_d) = (0xffff << 16);

	/* 打开 GPIO */
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
		/* 测试 GPIO 输出高电平 */
		write(fd, high, 1);
		TTOS_SleepTask(1000);

		/* 测试 GPIO 输出低电平 */
		write(fd, low, 1);
		TTOS_SleepTask(1000);
	}

	/* 关闭 GPIO */
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

    /* 配置GPIO管脚  */
	//void *gpio3_d = (void *)(0xff770000+0xe01c);
	//*(volatile unsigned int *)(gpio3_d) = (0xffff << 16);

	/* 打开 GPIO */
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

	/* 关闭 GPIO */
	ret = close(fd);
	if (ret < 0)
	{
		printk("close error\n");
	}
}


int userAppInit(void)
{
	/* 先测试GPIO的输入，一段时间，这段时间内用户可以通拉低拉高GPIO来测试读取到的值  */
	printf("\r\n **********TTOS Test Gpio Input for a while: **********\n");
	IntewellOS_GPIO_test_input();

	/* 先测试GPIO的输入，一段时间，这段时间内用户可以观察GPIO电平判断，电平应该为高低交替  */
	printf("\r\n **********TTOS Test Gpio Output for a while: **********\n");
	IntewellOS_GPIO_test_output();

	printf("\r\n **********TTOS Test Gpio finished **********\n");

    return 0;
}

