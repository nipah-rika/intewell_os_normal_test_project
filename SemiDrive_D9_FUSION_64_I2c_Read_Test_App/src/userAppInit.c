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
#include <fcntl.h>
#include <modbusIO.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysI2c.h>
#include <time.h>
#include <ttos.h>
#include <types.h>

/************************�� �� ��******************************/
#define INPUT_PORT_REGISTER0									0x00   /* ����˿ڼĴ���0������IO00-IO07 */
#define INPUT_PORT_REGISTER1									0x01   /* ����˿ڼĴ���1������IO10-IO17 */
#define OUTPUT_PORT_REGISTER0								0x02   /* ����˿ڼĴ���0������IO00-IO07 */
#define OUTPUT_PORT_REGISTER1								0x03   /* ����˿ڼĴ���1������IO10-IO17 */
#define POLARITY_INVERSION_PORT_REGISTER0		0x04   /* ���Է�ת�˿ڼĴ���0������IO00-IO07 */
#define POLARITY_INVERSION_PORT_REGISTER1		0x05   /* ���Է�ת�˿ڼĴ���1������IO10-IO17 */
#define CONFIG_PORT_REGISTER0								0x06   /* ��������˿ڼĴ���0������IO00-IO07 */
#define CONFIG_PORT_REGISTER1								0x07   /* ��������˿ڼĴ���1������IO10-IO17 */

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

//��׼����ʱ������ʱ��������ʱ�䣬ʱ���õ�Ŀǰʱ�䣬��ǰʱ����㣬��㣬ʱ���
#define T_HOR (0)//��Ҫѭ���ܵ�ʱ
#define T_MIN (0)//��Ҫѭ���ܵķ�
#define T_SEC (60)//��Ҫѭ���ܵ���
#define TIME ((((T_HOR * 60) + T_MIN) * 60) + T_SEC)//ѭ�����Ե���ʱ�䣬�������û����������ѭ���ܶ�á�TIME
#define MSEC_PER_SEC 1000//ÿ1s��������ms����Ȼ��1000

#define CLOCK_TO_USE 1 // CLOCK_MONOTONIC


/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

//�趨�´�������ʱ�䣬����һ�ε�wakeupTime�����ϣ��趨��һ�������ľ�׼ʱ��
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

// ���Ĵ�����ֵ
INT32 pca9555_read_byte(INT32 fd, INT32 slave_num, UINT8 regAddr, UINT8 *buf,
		INT32 len) {
	INT32 ret = -1;

	struct i2c_msg msg[2] = { 0 };
	T_DR_I2CMessage i2c_rx_message = { NULL, 2 }; // I2C�������ݽṹ��

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

// ��ȡ���Ž��յ���ֵ
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
	INT32 slave_addr = 0x20; // I2C_10�豸��ַ


	/**********************
	 *         I2C ����
	 *
	 **********************/

	// �������ķ�ʽ��I2C_10
	fd = open("/I2C_10", MODBUS_IO_BLOCK);
	if (fd < 0) {
		printf("open d9 I2C failed!\tretVal:%d\r\n", fd);
		return -1;
	}

	// ��ȡI2C_10����
	ret = ioctl(fd, UIO_GET_CFG, &i2cCtrlCfg);
	if (ret < 0) {
		printf("ioctl get i2c cfg failed!\tioctl errno = %d\n", ret);
		close(fd);
		return -2;
	}

	i2cCtrlCfg.config.speed = I2C_SPEED_STANDARD_RATE; // 100kHz
	i2cCtrlCfg.config.slaveAddr = slave_addr;     // �豸��ַ

	// ����I2C_10����
	ret = ioctl(fd, UIO_SET_CFG, &i2cCtrlCfg);
	if (ret < 0) {
		printf("ioctl i2c set cfg failed!\tioctl errno = %d\n", ret);
		close(fd);
		return -3;
	}

	//�����ָ��˯�߼������׼��ִ��do while����ĳ���
	const struct timespec cycletime = { 0, 1000000};    //������Ҫ˯�ߵĶ�ʱ��ʱ��������λ��ns������������1ms

	//��ʼ������
	struct timespec wakeupTime;
	struct timespec;
	T_UDWORD t0, t1, diff;
	int ms = 0;
	int sum = 0;
	int preRet = 0;

	//��ʼ������ʱ�䣬��ʼֵ
	t0 = TTOS_GetCurrentSystemCount();

	// get current time���õ���ǰʱ��
	clock_gettime(CLOCK_TO_USE, &wakeupTime);
	//��ѭ�����������ָ���ļ�����治��ִ��todo
	do {
		wakeupTime = timespec_add(wakeupTime, cycletime); //�趨�´�������ʱ�䣬����һ�ε�wakeupTime�����ϣ��趨��һ�������ľ�׼ʱ��
		clock_nanosleep(CLOCK_TO_USE, TIMER_ABSTIME, &wakeupTime, NULL); //��ʼ���ߣ�����wakeupTime֮������

		// ��ȡ����Դ���͵�ֵ
		ret = pca9555_get_gpio_status(fd, slave_addr, GPIO_PORT0, GPIO_1);

		// ÿ��ѭ��ʱ��Ϊ1ms������ͳ�����ж��ٺ���
		ms++;

		// ��һ�ζ����������1������preRetΪ1������֤��һ�ζ����Ľ���Ƿ���ȷ������0ͬ���Դ�����
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

		// �ڶ��ζ����ж϶����Ľ���Ƿ���ȷ������һ�����ʹ1����εĽ���Ƿ���0������������ʹ����˳�ѭ��
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

		t1 = TTOS_GetCurrentSystemCount();//��ȡ��ǰϵͳ�����ŵ�TSC COUNT����
		diff = TTOS_GetCurrentSystemSubTime(t0, t1, TTOS_MS_UNIT); //����������������λ��ms�������ж��Ƿ�õ��û������Ĳ���ʱ��
	} while (diff < (TIME * MSEC_PER_SEC));    //ѭ���ܵ�ʱ��TIME������TIME֮���˳�doѭ��

	// ͳ���ܹ����ж��ٺ���
	printk("ms:%d\n", ms);
	// ����Ƶ��
	printk("sum:%d\n", sum);

	// �ر�i2c
	close(fd);

	return 0;
}

