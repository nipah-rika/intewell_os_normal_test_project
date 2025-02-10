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
#include <sysI2c.h>
#include <components/modbusIO.h>
#include <fcntl.h>

/************************�� �� ��******************************/
#define SLAVE_ADDR		0x48	/*	gx21m15 i2c address*/
#define WRITE_FLAG		0
#define READ_FLAG			1

/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

INT32 i2c_read_data(INT32 fd, UINT8 regAddr, UINT8 *buf, INT32 len)
{
	INT32 ret = -1;

	struct i2c_msg msg[2] = {0};
	T_DR_I2CMessage i2c_rx_message = {NULL, 2}; // I2C�������ݽṹ��

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
 *         I2C ����
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
    i2cCtrlCfg.config.slaveAddr = SLAVE_ADDR;     // �豸��ַ

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

