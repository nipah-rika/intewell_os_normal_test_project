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
#include <sysI2c.h>
#include <components/modbusIO.h>
#include <fcntl.h>

/************************宏 定 义******************************/
#define SLAVE_ADDR		0x48	/*	gx21m15 i2c address*/
#define WRITE_FLAG		0
#define READ_FLAG			1

/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

INT32 i2c_read_data(INT32 fd, UINT8 regAddr, UINT8 *buf, INT32 len)
{
	INT32 ret = -1;

	struct i2c_msg msg[2] = {0};
	T_DR_I2CMessage i2c_rx_message = {NULL, 2}; // I2C接收数据结构体

	msg[0].addr = SLAVE_ADDR;
	msg[0].buf = &regAddr;
	msg[0].flags = WRITE_FLAG;
	msg[0].len = 1;

	msg[1].addr = SLAVE_ADDR;
	msg[1].buf = buf;
	msg[1].flags = READ_FLAG;
	msg[1].len = len;
	i2c_rx_message.msg = msg;

	ret = ioctl(fd, I2C_IOC_TRANSFER, &i2c_rx_message);
	if(ret)
	{
		printf("%s:i2c read data failed!\r\n", __func__);
		return -1;
	}
	return ret;
}

int userAppInit(void)
{
	UINT8 temp_reg = 0x00;
	UINT8 rxBuf[2] = {0};
	INT32 fd, ret;
	UINT16 temp;
	SINGLE temperature;
	T_DR_I2CControl i2cCtrlCfg;

/**********************
 *         I2C 测试
 *
 **********************/

	fd = open("/I2C_1", MODBUS_IO_BLOCK);
	if (fd < 0)
	{
		printf("open d9 I2C failed!\tretVal:%d\r\n", fd);
		return -1;
	}

	ret = ioctl(fd, UIO_GET_CFG, &i2cCtrlCfg);
	if (ret < 0)
	{
		printf("ioctl get i2c cfg failed!\tioctl errno = %d\n", ret);
		close(fd);
		return -2;
	}

    printf("get i2c cfg,i2c Info :\n");
    printf("name: %s\n", i2cCtrlCfg.config.name);
    printf("index: %d\n", i2cCtrlCfg.config.index);
    printf("speed: %d\n", i2cCtrlCfg.config.speed);
    printf("slaveAddr: %x\n", i2cCtrlCfg.config.slaveAddr);

    i2cCtrlCfg.config.speed = I2C_SPEED_STANDARD_RATE; // 100k
    i2cCtrlCfg.config.slaveAddr = SLAVE_ADDR;     // 设备地址

    ret = ioctl(fd, UIO_SET_CFG, &i2cCtrlCfg);
    if (ret < 0)
    {
		printf("ioctl i2c set cfg failed!\tioctl errno = %d\n", ret);
		close(fd);
		return -3;
    }

    ret = ioctl(fd, UIO_GET_CFG, &i2cCtrlCfg);
    if (ret < 0)
    {
		printf("After ioctl set i2c cfg, get i2c cfg failed!\tioctl errno = %d\n", ret);
		close(fd);
		return -2;
    }
    printf("After set i2c cfg, get i2c Info :\n");
    printf("speed: %d\n", i2cCtrlCfg.config.speed);
    printf("slaveAddr: %x\n", i2cCtrlCfg.config.slaveAddr);

    printf("d9 read gx21m15 i2c_device data Test start!\n");

	while (1)
	{
		i2c_read_data(fd, temp_reg, rxBuf, 2);

		temp = (rxBuf[0] << 8 | rxBuf[1]) & 0xffff;
		temp = temp >> 5;
		temperature = temp * 0.125;
		printf("temperature : %f\r\n", temperature);
		TTOS_SleepTask(1000);
	}
	close(fd);

    return 0;
}

