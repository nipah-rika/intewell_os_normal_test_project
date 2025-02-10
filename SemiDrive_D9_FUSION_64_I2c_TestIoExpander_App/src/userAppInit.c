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
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

INT32 pca9555_write_byte(INT32 fd, INT32 slave_num, UINT8 regAddr, UINT8 buf, INT32 len)
{
	INT32 ret = -1;
	struct i2c_msg tx_msg;
	T_DR_I2CMessage i2c_tx_message = {NULL, 1}; // I2C�������ݽṹ�壬��ioctl���õ���1��ģ��ֻ��һ��message package

	UINT8 *tx_buf = (UINT8 *)malloc(sizeof(UINT8) + len);
	if (tx_buf == NULL)
	{
		printf("%s:malloc tx_buf failed!\r\n", __func__);
		return -2;
	}

	tx_buf[0] = regAddr;
	memcpy(&tx_buf[1], &buf, len);
	tx_msg.addr = slave_num;
	tx_msg.buf = tx_buf;
	tx_msg.flags = WRITE_FLAG;
	tx_msg.len = len + 1;
	i2c_tx_message.msg = &tx_msg;

	ret = ioctl(fd, I2C_IOC_TRANSFER, &i2c_tx_message);
	if (ret)
	{
		printf("%s:i2c write %s data failed!\r\n", __func__, buf);
		return -1;
	}

	free(tx_buf);
	tx_buf = NULL;

    return ret;
}

INT32 pca9555_read_byte(INT32 fd, INT32 slave_num, UINT8 regAddr, UINT8 *buf, INT32 len)
{
	INT32 ret = -1;

	struct i2c_msg msg[2] = {0};
	T_DR_I2CMessage i2c_rx_message = {NULL, 2}; // I2C�������ݽṹ��

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
	if (ret)
	{
		printf("%s:i2c read data failed!\r\n", __func__);
		return -1;
	}
	return ret;
}

void pca9555_set_output_mode(INT32 fd, INT32 slave_num, UINT8 gpio_port,  UINT8 gpio_num)
{
    UINT8 register_original_data = 0;
    if(gpio_port > 1 || gpio_num > 0x80)  return;
    if(gpio_port == 0)
    {
        pca9555_read_byte(fd, slave_num, CONFIG_PORT_REGISTER0, &register_original_data, 1);
        pca9555_write_byte(fd, slave_num, CONFIG_PORT_REGISTER0, register_original_data & (~gpio_num), 1);
    }
    else if(gpio_port == 1)
    {
        pca9555_read_byte(fd, slave_num, CONFIG_PORT_REGISTER1, &register_original_data, 1);
        pca9555_write_byte(fd, slave_num, CONFIG_PORT_REGISTER1, register_original_data & (~gpio_num), 1);
    }
}

void pca9555_set_output_mode_all(INT32 fd, UINT8 slave_num, UINT8 gpio_port)
{
    UINT8 register_original_data = 0x00;
    if(gpio_port > 1)  return;
    if(gpio_port == 0)
    {
        pca9555_write_byte(fd, slave_num, CONFIG_PORT_REGISTER0, register_original_data, 1);
    }
    else if(gpio_port == 1)
    {
        pca9555_write_byte(fd, slave_num, CONFIG_PORT_REGISTER1, register_original_data, 1);
    }
}

void pca9555_set_input_mode(INT32 fd, UINT8 slave_num, UINT8 gpio_port,  UINT8 gpio_num)
{
    UINT8 register_original_data = 0;
    if(gpio_port > 1 || gpio_num > 0x80)  return;
    if(gpio_port == 0)
    {
        pca9555_read_byte(fd, slave_num, CONFIG_PORT_REGISTER0, &register_original_data, 1);
        pca9555_write_byte(fd, slave_num, CONFIG_PORT_REGISTER0, register_original_data | gpio_num, 1);
    }
    else if(gpio_port == 1)
    {

        pca9555_read_byte(fd, slave_num, CONFIG_PORT_REGISTER1, &register_original_data, 1);
        pca9555_write_byte(fd, slave_num, CONFIG_PORT_REGISTER1, register_original_data | gpio_num, 1);
    }
}

void pca9555_set_input_mode_all(INT32 fd, UINT8 slave_num, UINT8 gpio_port)
{
    UINT8 register_original_data = 0xff;
    if(gpio_port > 1 )  return;
    if(gpio_port == 0)
    {
        pca9555_write_byte(fd, slave_num, CONFIG_PORT_REGISTER0, register_original_data, 1);
    }
    else if(gpio_port == 1)
    {
        pca9555_write_byte(fd, slave_num, CONFIG_PORT_REGISTER1, register_original_data, 1);
    }
}

void pca9555_set_gpio_output_status(INT32 fd, UINT8 slave_num, UINT8 gpio_port,  UINT8 gpio_num, UINT8 status)
{
    UINT8 register_original_data = 0;
    if(gpio_port > 1 || gpio_num > 0x80)  return;
    if(gpio_port == 0)
    {
        pca9555_read_byte(fd, slave_num, OUTPUT_PORT_REGISTER0, &register_original_data, 1);
        if(status == 1)
        {
            pca9555_write_byte(fd, slave_num, OUTPUT_PORT_REGISTER0, register_original_data | gpio_num, 1);
        }
        else
        {
            pca9555_write_byte(fd, slave_num, OUTPUT_PORT_REGISTER0, register_original_data & (~gpio_num), 1);
        }
    }
    else if(gpio_port == 1)
    {
        pca9555_read_byte(fd, slave_num, OUTPUT_PORT_REGISTER1, &register_original_data, 1);
        if(status == 1)
        {
            pca9555_write_byte(fd, slave_num, OUTPUT_PORT_REGISTER1, register_original_data | gpio_num, 1);
        }
        else
        {
            pca9555_write_byte(fd, slave_num, OUTPUT_PORT_REGISTER1, register_original_data & (~gpio_num), 1);
        }
    }
}

UINT8 pca9555_get_gpio_status(INT32 fd, UINT8 slave_num, UINT8 gpio_port,  UINT8 gpio_num)
{
    UINT8 register_original_data = 0;
    UINT8 gpio_status = 0;
    if(gpio_port > 1 || gpio_num > 0x80)
    {
        printf("[ERROR] gpio_port > 1 || gpio_num > 0x80\r\n");
        return 2;
    }
    if(gpio_port == 0)
    {

        pca9555_read_byte(fd,  slave_num, INPUT_PORT_REGISTER0, &register_original_data, 1);

    }
    else if(gpio_port == 1)
    {
        pca9555_read_byte(fd, slave_num, INPUT_PORT_REGISTER1, &register_original_data, 1);
    }
    switch(gpio_num)
    {
        case 0x01:  gpio_status = register_original_data & gpio_num;break;
        case 0x02:  gpio_status = (register_original_data & gpio_num) >> 1;break;
        case 0x04:  gpio_status = (register_original_data & gpio_num) >> 2;break;
        case 0x08:  gpio_status = (register_original_data & gpio_num) >> 3;break;
        case 0x10:  gpio_status = (register_original_data & gpio_num) >> 4;break;
        case 0x20:  gpio_status = (register_original_data & gpio_num) >> 5;break;
        case 0x40:  gpio_status = (register_original_data & gpio_num) >> 6;break;
        case 0x80:  gpio_status = (register_original_data & gpio_num) >> 7;break;
        default:  	printf("[ERROR] gpio error!\r\n");
    }
    return gpio_status;
}

int userAppInit(void)
{
	INT32 fd, ret;
	T_DR_I2CControl i2cCtrlCfg;
	INT32 slave_addr = 0x20;
	UINT8 status = 0;
/**********************
 *         I2C ����
 *
 **********************/

	fd = open("/I2C_10", MODBUS_IO_BLOCK);
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
    i2cCtrlCfg.config.slaveAddr = slave_addr;     // �豸��ַ

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

    pca9555_set_output_mode(fd, slave_addr, GPIO_PORT0, GPIO_0 | GPIO_1 | GPIO_2 | GPIO_3 | GPIO_4);

    while (1)
	{
    	status =  ~status & 0x1;
    	pca9555_set_gpio_output_status(fd, slave_addr, GPIO_PORT0, GPIO_0 | GPIO_1 | GPIO_2 | GPIO_3 | GPIO_4, status);
		TTOS_SleepTask(3000);
	}
	close(fd);

    return 0;
}

