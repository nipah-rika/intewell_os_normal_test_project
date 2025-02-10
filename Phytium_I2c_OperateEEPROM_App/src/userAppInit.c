/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

/************************头 文 件******************************/
#include <commonTypes.h>
#include <components/modbusIO.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sysGpio.h>
#include <semaphore.h>
#include <ttos.h>
#include <pthread.h>
#include <timer.h>

#include <components/modbusIO.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sysGpio.h>
#include <sysI2c.h>

/************************宏 定 义******************************/
#define PAGE_SIZE 						0x10

/*write address : 0xA0,  read address : 0xA1*/
#define SLAVE_ADDR					0x50	/*i2c slave address*/
#define WRITE_FLAG					0
#define READ_FLAG						1
#define RX8025_REG_FLAG			0x0e
#define RX8025_BIT_FLAG_VDET	(1 << 0)
#define RX8025_BIT_FLAG_VLF		(1 << 1)
#define RX8025_REG_SEC				0x00
#define RX8025_REG_MIN				0x01
#define RX8025_REG_HOUR			0x02
#define RX8025_REG_WDAY			0x03
#define RX8025_REG_MDAY			0x04
#define RX8025_REG_MONTH		0x05
#define RX8025_REG_YEAR			0x06

#define IIC_NAME "/I2C_8"

#define bcd2bin(x)					\
		(__builtin_constant_p((u8 )(x)) ?	\
		const_bcd2bin(x) :			\
		_bcd2bin(x))

#define bin2bcd(x)					\
		(__builtin_constant_p((u8 )(x)) ?	\
		const_bin2bcd(x) :			\
		_bin2bcd(x))

#define const_bcd2bin(x)	(((x) & 0x0f) + ((x) >> 4) * 10)
#define const_bin2bcd(x)	((((x) / 10) << 4) + (x) % 10)

/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

/*
 * @brief:
 *    将BCD码转换为二进制码
 * @param[in]: val: 待转换的BCD码
 * @return:
 *    成功则返回转换后的二进制码
 */
unsigned _bcd2bin(UINT8 val)
{
	return (val & 0x0f) + (val >> 4) * 10;
}

/*
 * @brief:
 *    将二进制码转换为BCD码
 * @param[in]: val: 待转换的二进制码
 * @return:
 *    成功则返回转换后的BCD码
 */
UINT8 _bin2bcd(UINT8 val)
{
	return ((val / 10) << 4) + val % 10;
}

/*
 * @brief:
 *    实现IIC接口写数据
 * @param[in]: fd: 设备描述符
 * @param[in]: regAddr: 写入数据的地址
 * @param[in]: buf: 待写的数据
 * @param[in]: len: 数据的长度
 * @return:
 *    成功返回值为 0，失败返回值为负数
 */
INT32 i2c_write_data(INT32 fd, UINT8 regAddr, UINT8 *buf, INT32 len)
{
	INT32 ret = -1;
	struct i2c_msg tx_msg;
	T_DR_I2CMessage i2c_tx_message = {NULL, 1}; // I2C发送数据结构体，在ioctl上用到，1：模拟只有一个message package

	UINT8 *tx_buf = (UINT8 *)malloc(sizeof(UINT8) + len);
	if (tx_buf == NULL)
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
	if (ret)
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
 *    实现IIC接口读取数据
 * @param[in]: fd: 设备描述符
 * @param[in]: regAddr: 读取数据的地址
 * @param[in]: len: 读取数据的长度
 * @return:
 *    成功返回值为 0，失败返回值为负数
 */
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
	if (ret)
	{
		printf("%s:i2c read data failed!\r\n", __func__);
		return -1;
	}
	return ret;
}

/*
 * @brief:
 *    实现IIC接口操作EEPROM的测试程序
 * @return:
 *    成功返回值为 0;失败返回值为负数
 */
int32_t i2c_test()
{

	UINT8 temp_reg = 0x00;
	UINT8 rxBuf[7];
	INT32 fd, ret;
	T_DR_I2CControl i2cCtrlCfg;

	fd = open(IIC_NAME, MODBUS_IO_BLOCK);
	if (fd < 0)
	{
		printf("open %s failed! \tretVal:%d \r\n", IIC_NAME,fd);
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
    printf("get i2c Info :\n");
    printf("speed: %d\n", i2cCtrlCfg.config.speed);
    printf("slaveAddr: %x\n", i2cCtrlCfg.config.slaveAddr);

	UINT8 wbuf[16];
	UINT8 rbuf[16];

	/*EEProm at24c08
	 *存储容量 1KBytes
	 *页面数	64页
	 * 字节数/页  16字节/页
	 *一页最多写入16字节
	 */
	memset(wbuf,0,sizeof(wbuf));
	strcpy(wbuf,"write to page1\n"); //15个字节
	/*写数据到第0x0页*/
	i2c_write_data(fd, PAGE_SIZE * 0x0, wbuf, strlen(wbuf));
	/*从第0x0页读取数据*/
	ret = i2c_read_data(fd,PAGE_SIZE * 0x0, &rbuf, strlen(wbuf));
	if (ret)
	{
		printf("i2c read data failed\n");
		return -2;
	}
	for(INT32 loop= 0;loop < strlen(wbuf);loop++)
	{
		/*把从第0x0页读取到的数据打印出来*/
		printf("%c" ,rbuf[loop]);
	}


	memset(wbuf,0,sizeof(wbuf));
	strcpy(wbuf,"write to page2\n");
	/*写数据到第0x1页*/
	i2c_write_data(fd, PAGE_SIZE * 0x01, wbuf, strlen(wbuf));
	/*从第0x1页读取数据*/
	ret = i2c_read_data(fd,PAGE_SIZE * 0x01, &rbuf, strlen(wbuf));
	if (ret)
	{
		printf("i2c read data failed\n");
		return -2;
	}
	for(INT32 loop= 0;loop < strlen(wbuf);loop++)
	{
		/*把从第0x1页读取到的数据打印出来*/
		printf("%c" ,rbuf[loop]);
	}

	close(fd);
	printf("test %s end\n",IIC_NAME);
    return 0;
}


/*
 * @brief:
 *    实现IIC接口操作EEPROM的测试程序
 * @return:
 *    成功返回值为 0
 */
int userAppInit(void)
{
	i2c_test();

	return 0;
}



