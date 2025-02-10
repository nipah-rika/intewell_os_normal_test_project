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
#include <unistd.h>
#include <sysGpio.h>
#include <ttosShell.h>
#include <errno.h>

#include "lwip/netif.h"
#include "lwip/sockets.h"
#include <netif_adapter.h>

#define DEBUG_F  printf


#define INTR_CLR   (0x40)
#define INTR_STATE (0x44)
/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/
T_MODULE TASK_ID TaskID0;
T_MODULE TASK_ID TaskIDNET;
int  G_fpgaFd = -1;

static void wr_reg(int fd, int reg, int val)
{
    lseek(fd, reg, SEEK_SET);
    write(fd, &val, sizeof(val));
}

static int rd_reg(int fd, int reg, int *val)
{
    lseek(fd, reg, SEEK_SET);
    return  read(fd, val, sizeof(int));
}



#define FPGA_IRQ    "/GPIO0_14"
#define FPGA_10ms    "/GPIO0_13"
#define TEST_GPIO1  "/GPIO2_9"  //测量 R822 电阻

void gpio_irq10ms_callback(void *arg) {
    int status = *(volatile unsigned int *) (0x58800000 + INTR_STATE);
	if (status != 0x400) {
		printf("got other int: 0x%x\r\n", status);
	}
	// wr_reg(G_fpgaFd, INTR_CLR, 0x400);
	*(volatile unsigned int *) (0x58800000 + INTR_CLR) = status;//清中断
	//TTOS_ResumeTask(TaskID0);
	 printk("gpio irq13 \n");
}

void gpio_irq_callback14(void *arg) {
    T_TTOS_ReturnCode rc = 0;

    printk("gpio irq14 happen 0x%x\n", *(volatile unsigned int *) (0x58800000 + INTR_STATE));

}


void gpio_init (void)
{
	int iofd = -1;
    T_DR_GpioConfigTable config;
    T_DR_GpioIrqControl irq_ctl;

    iofd = open(FPGA_10ms, 0);
	if (iofd < 0) {
		printf(FPGA_IRQ" open fail !\r\n");
		printf("error: %d\r\n", errno);
		return;
	}

    ioctl(iofd, UIO_GET_CFG, &config);
    config.direction = GPIO_INPUT;
    ioctl(iofd, UIO_SET_CFG, &config);


    irq_ctl.mode = PIN_IRQ_MODE_LOW_LEVEL;//PIN_IRQ_MODE_HIGH_LEVEL;
    irq_ctl.hdr = gpio_irq10ms_callback;
    irq_ctl.args = NULL;


    ioctl(iofd, GPIO_ATTACH_IRQ, &irq_ctl);
    ioctl(iofd, GPIO_ENABLE,0);


    iofd = open(FPGA_IRQ, 0);

    ioctl(iofd, UIO_GET_CFG, &config);
    config.direction = GPIO_INPUT;
    ioctl(iofd, UIO_SET_CFG, &config);


    irq_ctl.mode = PIN_IRQ_MODE_FALLING;//PIN_IRQ_MODE_HIGH_LEVEL;
    irq_ctl.hdr = gpio_irq_callback14;
    irq_ctl.args = NULL;

    *(volatile unsigned int *) (0x58800000 + 0x30) = 0x3;  //特殊设置，产生中断
    *(volatile unsigned int *) (0x58800000 + INTR_CLR) = 0x400; // 先清除中断
    ioctl(iofd, GPIO_ATTACH_IRQ, &irq_ctl);
    ioctl(iofd, GPIO_ENABLE,0);
}



int gpio_test(void)
{
	int ttos_ret;

	printf("%s running...., %s %s\r\n", __func__, __TIME__, __DATE__);


	int fd = open("fpga", 0);
	if (fd < 0) {
		printf("fpga dev open fail\r\n");
		return;
	}

	G_fpgaFd = fd;
	
	gpio_init();

	while(1) {
		TTOS_SleepTask(10);

	}
    return 0;
}

