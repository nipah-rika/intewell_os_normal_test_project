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
#include <modbusIO.h>
#include <fcntl.h>
#include <stdio.h>
#include <sysGpio.h>
#include <sysI2c.h>
#include <time.h>
#include <ttos.h>
#include <types.h>

/************************宏 定 义******************************/
#define INPUT_PORT_REGISTER0									0x00   /* 输入端口寄存器0，负责IO00-IO07 */
#define INPUT_PORT_REGISTER1									0x01   /* 输入端口寄存器1，负责IO10-IO17 */
#define OUTPUT_PORT_REGISTER0								0x02   /* 输出端口寄存器0，负责IO00-IO07 */
#define OUTPUT_PORT_REGISTER1								0x03   /* 输出端口寄存器1，负责IO10-IO17 */
#define POLARITY_INVERSION_PORT_REGISTER0		0x04   /* 极性反转端口寄存器0，负责IO00-IO07 */
#define POLARITY_INVERSION_PORT_REGISTER1		0x05   /* 极性反转端口寄存器1，负责IO10-IO17 */
#define CONFIG_PORT_REGISTER0								0x06   /* 输入输出端口寄存器0，负责IO00-IO07 */
#define CONFIG_PORT_REGISTER1								0x07   /* 输入输出端口寄存器1，负责IO10-IO17 */

#define GPIO_PORT0													0
#define GPIO_PORT1													1

#define GPIO_0																0x01
#define GPIO_1																0x02
#define GPIO_2																0x04
#define GPIO_3																0x08
#define GPIO_4																0x10
#define GPIO_5																0x20
#define GPIO_6																0x40
#define GPIO_7																0x80

#define WRITE_FLAG													0
#define READ_FLAG														1
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

//精准计算时间间隔，时间间隔计算时间，时间差，得到目前时间，当前时间计算，打点，时间点
#define T_HOR (0)//需要循环跑的时
#define T_MIN (0)//需要循环跑的分
#define T_SEC (60)//需要循环跑的秒
#define TIME ((((T_HOR * 60) + T_MIN) * 60) + T_SEC)//循环测试的总时间，决定了用户想跑这个死循环跑多久。TIME
#define MSEC_PER_SEC 1000//每1s包含多少ms，当然是1000

#define CLOCK_TO_USE 1 // CLOCK_MONOTONIC

#define	TEST_GPIO			"/GPIO_H3"
#define SLAVE_ADDR	0x21
#define	I2C_BUS		"/I2C_10"

int ms = 0;
int one = 0;
int zero = 0;
int preRet = -1;
int errorNum = 0;
int retVal = -1;

struct timespec timespec_add(struct timespec time1, struct timespec time2) {
	struct timespec result;

	if ((time1.tv_nsec + time2.tv_nsec) >= NSEC_PER_SEC) {
		result.tv_sec = time1.tv_sec + time2.tv_sec + 1;
		result.tv_nsec = time1.tv_nsec + time2.tv_nsec - NSEC_PER_SEC;
	} else {
		result.tv_sec = time1.tv_sec + time2.tv_sec;
		result.tv_nsec = time1.tv_nsec + time2.tv_nsec;
	}

	return result;
}


INT32 pca9555_read_byte(T_DR_I2CControl *CBlk, INT32 slave_num, UINT8 regAddr, UINT8 *buf,
		INT32 len) {
	INT32 ret = -1;

	struct i2c_msg msg[2] = { 0 };
	T_DR_I2CMessage i2c_rx_message = { NULL, 2 }; // I2C接收数据结构体

	msg[0].addr = slave_num;
	msg[0].buf = &regAddr;
	msg[0].flags = WRITE_FLAG;
	msg[0].len = 1;

	msg[1].addr = slave_num;
	msg[1].buf = buf;
	msg[1].flags = READ_FLAG;
	msg[1].len = len;
	i2c_rx_message.msg = msg;

	ret = i2c_control(CBlk, I2C_IOC_TRANSFER, &i2c_rx_message);
	if (ret) {
		printf("%s:i2c read data failed!\r\n", __func__);
		return -1;
	}
	return ret;
}

// 获取引脚接收到的值
UINT8 pca9555_get_gpio_status(T_DR_I2CControl *CBlk, UINT8 slave_num, UINT8 gpio_port,
		UINT8 gpio_num) {
	UINT8 register_original_data = 0;
	UINT8 gpio_status = 0;
	if (gpio_port > 1 || gpio_num > 0x80) {
		printf("[ERROR] gpio_port > 1 || gpio_num > 0x80\r\n");
		return 2;
	}
	if (gpio_port == 0) {

		pca9555_read_byte(CBlk, slave_num, INPUT_PORT_REGISTER0,
				&register_original_data, 1);

	} else if (gpio_port == 1) {
		pca9555_read_byte(CBlk, slave_num, INPUT_PORT_REGISTER1,
				&register_original_data, 1);
	}
	switch (gpio_num) {
	case 0x01:
		gpio_status = register_original_data & gpio_num;
		break;
	case 0x02:
		gpio_status = (register_original_data & gpio_num) >> 1;
		break;
	case 0x04:
		gpio_status = (register_original_data & gpio_num) >> 2;
		break;
	case 0x08:
		gpio_status = (register_original_data & gpio_num) >> 3;
		break;
	case 0x10:
		gpio_status = (register_original_data & gpio_num) >> 4;
		break;
	case 0x20:
		gpio_status = (register_original_data & gpio_num) >> 5;
		break;
	case 0x40:
		gpio_status = (register_original_data & gpio_num) >> 6;
		break;
	case 0x80:
		gpio_status = (register_original_data & gpio_num) >> 7;
		break;
	default:
		printf("[ERROR] gpio error!\r\n");
	}
	return gpio_status;
}

// 中断回调函数
void gpio_irq_callback() {
	 ms++;
	 // 获取i2c指定控制块
	 T_DR_I2CControl *CBlk = i2c_get_control_block(I2C_BUS);
	 // 读i2c的值
	 retVal = pca9555_get_gpio_status(CBlk,SLAVE_ADDR, GPIO_PORT0, GPIO_1);
	 printk("retVal: %d\n",retVal);
	 if(retVal == 1){
		 // 统计为1的次数
		 one++;
		 // 判断上一次读取的值是否为1，如果是则过程有误
		 if(preRet == 1){
			 errorNum++;
		 }
		 preRet = 1;
	 }
	 else if(retVal == 0){
		 // 统计为0的次数
		 zero++;
		 // 判断上一次读取的值是否为0，如果是则过程有误
		 if(preRet == 0){
			 errorNum++;
		 }
		 preRet = 0;
	 }
}


int userAppInit(void) {
	T_DR_GpioConfigTable config;
	T_DR_I2CControl i2cCtrlCfg;
	T_WORD fd = -1;
	T_WORD fd1 = -1;
	INT32 ret = 0;

	// 打开GPIO
	fd1 = open(TEST_GPIO, 0);
	if (fd1 < 0) {
		printk("open gpio errno = %d\n", errno);
		return -1;
	}

	// 以阻塞的方式打开I2C_10
	fd = open(I2C_BUS, MODBUS_IO_BLOCK);
	if (fd < 0) {
		printf("open d9 I2C failed!\tretVal:%d\r\n", fd);
		return -1;
	}

	// 获取I2C_10配置
	ret = ioctl(fd, UIO_GET_CFG, &i2cCtrlCfg);
	if (ret < 0) {
		printf("ioctl get i2c cfg failed!\tioctl errno = %d\n", ret);
		close(fd);
		return -2;
	}

	i2cCtrlCfg.config.speed = I2C_SPEED_FAST_RATE; // 100kHz
	i2cCtrlCfg.config.slaveAddr = SLAVE_ADDR;     // 设备地址

	// 设置I2C_10配置
	ret = ioctl(fd, UIO_SET_CFG, &i2cCtrlCfg);
	if (ret < 0) {
		printf("ioctl i2c set cfg failed!\tioctl errno = %d\n", ret);
		close(fd);
		return -3;
	}

	/* 获取GPIO配置 */
	ioctl(fd1, UIO_GET_CFG, &config);
	config.direction = GPIO_INPUT;// 设置输入模式
	/* 设置GPIO配置 */
	ioctl(fd1, UIO_SET_CFG, &config);

	T_DR_GpioIrqControl irq_ctl;
	irq_ctl.mode = PIN_IRQ_MODE_RISING_FALLING;// 设置下降沿和上升沿触发
	irq_ctl.hdr = gpio_irq_callback;// 设置回调函数
	irq_ctl.args = NULL;

	/* 设置中断配置 */
	ioctl(fd1, GPIO_ATTACH_IRQ, &irq_ctl);
	/* 使能中断 */
	ioctl(fd1, GPIO_ENABLE, 0);

	//程序会指定睡眠间隔，精准的执行do while里面的程序。
	const struct timespec cycletime = { 0, 1000000};    //输入需要睡眠的定时的时间间隔，单位是ns，这里设置了1ms

	//初始化变量
	struct timespec wakeupTime;
	struct timespec;
	T_UDWORD t0, t1, diff;

	//初始化配置时间，初始值
	t0 = TTOS_GetCurrentSystemCount();

	// get current time，得到当前时间
	clock_gettime(CLOCK_TO_USE, &wakeupTime);
	//主循环，程序会在指定的间隔里面不断执行todo
	do {
		wakeupTime = timespec_add(wakeupTime, cycletime); //设定下次醒来的时间，在上一次的wakeupTime基础上，设定下一次醒来的精准时间
		clock_nanosleep(CLOCK_TO_USE, TIMER_ABSTIME, &wakeupTime, NULL); //开始休眠，经过wakeupTime之后，醒来


		t1 = TTOS_GetCurrentSystemCount();//获取当前系统中流逝的TSC COUNT数。
		diff = TTOS_GetCurrentSystemSubTime(t0, t1, TTOS_MS_UNIT); //计算间隔，计算结果单位是ms，用于判定是否得到用户结束的测试时间
	} while (diff < (TIME * MSEC_PER_SEC));    //循环跑的时间TIME，到达TIME之后，退出do循环

	ioctl(fd1, GPIO_DISABLE, 0);

	printk("end\n");
	// 统计总共运行多少毫秒
	printk("ms:%d\n", ms);
	// 统计值为1的次数
	printk("one:%d\n", one);
	// 统计值为0的次数
	printk("zero:%d\n", zero);
	// 统计错误发生的次数
	printk("errorNum:%d\n", errorNum);

	// 关闭i2c设备
	close(fd);
	// 关闭gpio设备
	close(fd1);
	return 0;
}
