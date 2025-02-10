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
#include <fcntl.h>
#include <modbusIO.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//精准计算时间间隔，时间间隔计算时间，时间差，得到目前时间，当前时间计算，打点，时间点
#define T_HOR (0)//需要循环跑的时
#define T_MIN (0)//需要循环跑的分
#define T_SEC (60)//需要循环跑的秒
#define TIME ((((T_HOR * 60) + T_MIN) * 60) + T_SEC)//循环测试的总时间，决定了用户想跑这个死循环跑多久。TIME
#define MSEC_PER_SEC 1000//每1s包含多少ms，当然是1000

#define CLOCK_TO_USE 1 // CLOCK_MONOTONIC


/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

//设定下次醒来的时间，在上一次的wakeupTime基础上，设定下一次醒来的精准时间
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

// 读寄存器的值
INT32 pca9555_read_byte(INT32 fd, INT32 slave_num, UINT8 regAddr, UINT8 *buf,
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

	ret = ioctl(fd, I2C_IOC_TRANSFER, &i2c_rx_message);
	if (ret) {
		printf("%s:i2c read data failed!\r\n", __func__);
		return -1;
	}
	return ret;
}

// 获取引脚接收到的值
UINT8 pca9555_get_gpio_status(INT32 fd, UINT8 slave_num, UINT8 gpio_port,
		UINT8 gpio_num) {
	UINT8 register_original_data = 0;
	UINT8 gpio_status = 0;
	if (gpio_port > 1 || gpio_num > 0x80) {
		printf("[ERROR] gpio_port > 1 || gpio_num > 0x80\r\n");
		return 2;
	}
	if (gpio_port == 0) {

		pca9555_read_byte(fd, slave_num, INPUT_PORT_REGISTER0,
				&register_original_data, 1);

	} else if (gpio_port == 1) {
		pca9555_read_byte(fd, slave_num, INPUT_PORT_REGISTER1,
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

int userAppInit(void) {
	INT32 fd, ret = 0;
	T_DR_I2CControl i2cCtrlCfg;
	INT32 slave_addr = 0x20; // I2C_10设备地址


	/**********************
	 *         I2C 测试
	 *
	 **********************/

	// 以阻塞的方式打开I2C_10
	fd = open("/I2C_10", MODBUS_IO_BLOCK);
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

	i2cCtrlCfg.config.speed = I2C_SPEED_STANDARD_RATE; // 100kHz
	i2cCtrlCfg.config.slaveAddr = slave_addr;     // 设备地址

	// 设置I2C_10配置
	ret = ioctl(fd, UIO_SET_CFG, &i2cCtrlCfg);
	if (ret < 0) {
		printf("ioctl i2c set cfg failed!\tioctl errno = %d\n", ret);
		close(fd);
		return -3;
	}

	//程序会指定睡眠间隔，精准的执行do while里面的程序。
	const struct timespec cycletime = { 0, 1000000};    //输入需要睡眠的定时的时间间隔，单位是ns，这里设置了1ms

	//初始化变量
	struct timespec wakeupTime;
	struct timespec;
	T_UDWORD t0, t1, diff;
	int ms = 0;
	int sum = 0;
	int preRet = 0;

	//初始化配置时间，初始值
	t0 = TTOS_GetCurrentSystemCount();

	// get current time，得到当前时间
	clock_gettime(CLOCK_TO_USE, &wakeupTime);
	//主循环，程序会在指定的间隔里面不断执行todo
	do {
		wakeupTime = timespec_add(wakeupTime, cycletime); //设定下次醒来的时间，在上一次的wakeupTime基础上，设定下一次醒来的精准时间
		clock_nanosleep(CLOCK_TO_USE, TIMER_ABSTIME, &wakeupTime, NULL); //开始休眠，经过wakeupTime之后，醒来

		// 读取数据源发送的值
		ret = pca9555_get_gpio_status(fd, slave_addr, GPIO_PORT0, GPIO_1);

		// 每个循环时间为1ms，这里统计运行多少毫秒
		ms++;

		// 第一次读，如果读到1则设置preRet为1用来验证下一次读到的结果是否正确，读到0同理，以此类推
		if(ms % 2 == 1) {
			if(ret == 1){
				sum += ret;
				preRet = 1;
			}
			if(ret == 0){
				sum ++;
				preRet = 0;
			}
		}

		// 第二次读，判断读到的结果是否正确，即上一个结果使1，这次的结果是否是0，如果不是则发送错误，退出循环
		if (ms % 2 ==0){
			if(preRet == 1 && ret ==1){
				printk("1 error\n");
				break;
			}
			if(preRet == 0 && ret ==0){
				printk("0 error\n");
				break;
			}
		}

		t1 = TTOS_GetCurrentSystemCount();//获取当前系统中流逝的TSC COUNT数。
		diff = TTOS_GetCurrentSystemSubTime(t0, t1, TTOS_MS_UNIT); //计算间隔，计算结果单位是ms，用于判定是否得到用户结束的测试时间
	} while (diff < (TIME * MSEC_PER_SEC));    //循环跑的时间TIME，到达TIME之后，退出do循环

	// 统计总共运行多少毫秒
	printk("ms:%d\n", ms);
	// 计算频率
	printk("sum:%d\n", sum);

	// 关闭i2c
	close(fd);

	return 0;
}

