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
#include <ttos.h>
#include <components/modbusIO.h>
#include <fcntl.h>
#include <errno.h>
#include <sysI2c.h>
#include <string.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

#define SLAVE_ADDR    0x4f
#define WRITE_FLAG     0
#define READ_FLAG        1

static int fd = -1;


BOOL IsBigEndian()
{
    short a = 0x1234;
    char b = *(char*)&a;
    if(0x12 == b)
    {
        return TRUE;
    }

    return FALSE;
}

/*
 * @brief:
 * @param:
 *         fd:
 *         regAddr:
 *         buf:
 *         len:
 *     @return:
 *
 * */
int i2c_write_data(int fd, unsigned char regAddr, unsigned char *buf, int len)
{
    int ret = -1;
    struct i2c_msg tx_msg;
    T_DR_I2CMessage i2c_tx_message = {NULL, 1}; // I2C�������ݽṹ�壬��ioctl���õ���1��ģ��ֻ��һ��message package

    unsigned char *tx_buf = (unsigned char *)malloc(sizeof(unsigned char) + len);
    if(tx_buf == NULL)
    {
        printf("%s:malloc tx_buf failed!\r\n", __func__);
        return -2;
    }

    tx_buf[0] = regAddr;
    memcpy(&tx_buf[1], buf, len);
    tx_msg.addr = SLAVE_ADDR;
    tx_msg.buf = tx_buf;
    tx_msg.flags = WRITE_FLAG;
    tx_msg.len = len + 1;
    i2c_tx_message.msg = &tx_msg;

    ret = ioctl(fd, I2C_IOC_TRANSFER, &i2c_tx_message);
    if(ret)
    {
        printf("%s:i2c write %s data failed!\r\n", __func__, buf);
        return -1;
    }

    free(tx_buf);
    tx_buf = NULL;
    return ret;
}

/*
 * @brief:
 * @param:
 *         fd:
 *         regAddr:
 *         buf:
 *         len:
 *     @return:
 *
 * */
int i2c_read_data(int fd, unsigned char regAddr, unsigned char *buf, int len)
{
    int ret = -1;

    struct i2c_msg msg[2] = {0};
    struct i2c_msg rx_msg;
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

    int ret = -1;

    unsigned char sgm452_reg_conf = 0x01;
    unsigned char sgm452_reg_temp = 0x00;
    unsigned char sgm452_reg_product_id = 0x07;
    unsigned char rxBuf[2] = {0};
    u16 temp;
    float temperature;

    printf("Hello TTOS for SemidriveD9!!!\n");
    int bits = sizeof(char *);
    if(bits == 4)
        printf("The TTOS is 32bit!!!\n");
    else if(bits == 8)
        printf("The TTOS is 64bit!!!\n");
    else
        printf("The TTOS is others, bits = %d ", bits);

    if(FALSE == IsBigEndian())
        printf("Little Endian!\n");
    else if(TRUE == IsBigEndian())
        printf("Big Endian\n");

/**********************        I2C ����         ***********************/
    int _tmpCnt = 0;
    int txCnt = 0, rxCnt = 0;          // ���ͺͽ������ݵĴ���
    T_DR_I2CControl i2cCtrlCfg;        // I2C���ýṹ�壬��Ҫ�������minor����������ioctl���õ�
    int i = 0;
    int _tmpVal = 0;
    /* 2�� ��I2C�豸 */
    fd = open("/I2C_4", MODBUS_IO_BLOCK);
    if (fd < 0)
    {
        printk("open d9 I2C failed!\tretVal:%d\r\n", fd);
        return -1;
    }

    /* 2.1 ��ȡi2C���� */
    ret = ioctl(fd, UIO_GET_CFG, &i2cCtrlCfg);
    if (ret < 0)
    {
        printf("ioctl get i2c cfg failed!\tioctl errno = %d\n", ret);
        return -2;
    }

    printf("get i2c cfg,i2c Info :\n");
    printf("name: %s\n", i2cCtrlCfg.config.name);
    printf("index: %d\n", i2cCtrlCfg.config.index);
    printf("speed: %d\n", i2cCtrlCfg.config.speed);     // ��ʼ��ʱ����I2CͨѶ�ٶ�Ĭ��100k
    printf("slaveAddr: %x\n", i2cCtrlCfg.config.slaveAddr); // ��ʼ��ʱ����I2CͨѶ��ַĬ��0x00

    /* 2.2 ����I2C�豸��ͨѶ�ٶȡ���ַ */
    i2cCtrlCfg.config.speed = I2C_SPEED_STANDARD_RATE; // 100k
    i2cCtrlCfg.config.slaveAddr = SLAVE_ADDR;     // �豸��ַ
    ret = ioctl(fd, UIO_SET_CFG, &i2cCtrlCfg);
    if (ret < 0)
    {
        printf("ioctl i2c set cfg failed!\tioctl errno = %d\n", ret);
        return -3;
    }
    /* 2.3 ���ú��ٻ�ȡi2C���� */
    ret = ioctl(fd, UIO_GET_CFG, &i2cCtrlCfg);
    if (ret < 0)
    {
        printf("After ioctl set i2c cfg, get i2c cfg failed!\tioctl errno = %d\n", ret);
        return -2;
    }
    printf("After set i2c cfg, get i2c Info :\n");
    printf("speed: %d\n", i2cCtrlCfg.config.speed);
    printf("slaveAddr: %x\n", i2cCtrlCfg.config.slaveAddr);

    // 2.4 sgm452�¶ȴ�������ʼ��
    u8 _tmpBuf[2] = {sgm452_reg_conf, 0x00};
    i2c_write_data(fd, SLAVE_ADDR, _tmpBuf, 2);


    TTOS_SleepTask(TTOS_GetSysClkRate());
    // 3���շ�����
    printf("d9 read i2c_device data Test start!\n");

    while (1)
    {
        i2c_read_data(fd, sgm452_reg_temp, rxBuf, 2);

        temp = (rxBuf[0] << 8 | rxBuf[1]) & 0xffff;
        temp = temp >> 5;
        temperature = temp * 0.125;
        printk("temp : %f\r\n", temperature);
        TTOS_SleepTask(1000);
    }
    close(fd);
/**********************     I2C ����    ����        ***********************/

    return 0;
}
