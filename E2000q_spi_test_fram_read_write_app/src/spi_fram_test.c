/*
 * spi_fram_test.c
 *
 *  Created on: 2022年11月29日
 *      Author: kd
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sysGpio.h>
#include <sysSpi.h>

#define WREN  0x06
#define WRDI  0x04
#define RDSR  0x05
#define WRSR  0x01
#define READ  0x03
#define FSTRD  0x0B
#define WRITE  0x02
#define SLEEP  0xB9
#define RDID   0x9F
#define SNR    0xC3

#define SIZE_1K	(0x400)
#define SIZE_32K	(0x8000)
#define SIZE_64K	(0x10000)

#define TEST_SIZE	SIZE_1K
#define TEST_SPI_NAME "/SPI_2"

void SPI_FRAM_TEST_01(void)
{
	int ret;
	int fd = open(TEST_SPI_NAME, 0);
	if (fd < 0)
	{
		printf("***open SPI_x errno\n");
		return ;
	}
	else
	{
		printf("***open SPI_x ok\n");
	}

	/* 设置传输模式 */
	int mode = SPI_MODE_0;
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置频率 */
	int speed = 1000000;
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置数据长度 */
	int bitsperword = 8;
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsperword);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	printf("bits per word: %d \n", bitsperword);
	printf("spi mode: 0x%x \n", (mode & 0x3));
	printf("max speed: %d Hz (%d KHz) \n", speed, speed/1000);

	T_BYTE buf_rx[10];
	T_BYTE buf_tx[] ={RDID,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
	write(fd, buf_tx, sizeof(buf_tx));
	read(fd, buf_rx, sizeof(buf_tx));
	for (int k =0; k < sizeof(buf_rx); k++)
	{
			printf("0x%02x ", buf_rx[k]);
	}

err:
	close(fd);
}


void SPI_FRAM_TEST_02(void)
{
	int ret;
	int fd = open(TEST_SPI_NAME, 0);
	if (fd < 0)
	{
		printf("***open SPI_0 errno");
	}
	else
	{
		printf("***open SPI_0 ok\n");
	}

	/* 设置传输模式 */
	int mode = SPI_MODE_0;
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置频率 */
	int speed = 1000000;
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置数据长度 */
	int bitsperword = 8;
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsperword);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	printf("bits per word: %d \n", bitsperword);
	printf("spi mode: 0x%x \n", (mode & 0x3));
	printf("max speed: %d Hz (%d KHz) \n", speed, speed/1000);

	T_BYTE buf_rx[9];
	T_BYTE buf_tx[] ={SNR,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
	write(fd, buf_tx, sizeof(buf_tx));
	read(fd, buf_rx, sizeof(buf_tx));
	for (int k =0; k < sizeof(buf_rx); k++)
	{
			printf("0x%02x ", buf_rx[k]);
	}

err:
	close(fd);
}


void SPI_FRAM_TEST_03(void)
{
	int ret;
	int fd = open(TEST_SPI_NAME, 0);
	if (fd < 0)
	{
		printf("***open SPI_0 errno");
	}
	else
	{
		printf("***open SPI_0 ok\n");
	}

	/* 设置传输模式 */
	int mode = SPI_MODE_0;
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置频率 */
	int speed = 1000000;
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置数据长度 */
	int bitsperword = 8;
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsperword);
	if (ret < 0)
	{
		printf("ioctl errno = %x\n", errno);
		goto err;
	}

	printf("bits per word: %d \n", bitsperword);
	printf("spi mode: 0x%x \n", (mode & 0x3));
	printf("max speed: %d Hz (%d KHz) \n", speed, speed/1000);

    T_BYTE buf_rx[10];
    T_BYTE buf_tx[] = {WREN,0xff,0xff};//WREN寄存器，set write enable
    write(fd, buf_tx, sizeof(buf_tx));

#if 0
    T_WORD addr =0x1000 ;//ok
    T_BYTE hi;
    T_BYTE low;
    hi = (addr & 0xff00 )>>8;
    low = (addr & 0x00ff);

    T_BYTE buf1_tx[] = {WRITE, hi, low, 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a};
    write(fd, buf1_tx, sizeof(buf1_tx));//do write

    T_BYTE buf2_tx[] = {READ, hi, low, 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};//read
    //T_BYTE buf2_tx[] = {FSTRD,hi,low,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};//Fast Read
    T_BYTE buf2_rx[sizeof(buf2_tx)];

    write(fd, buf2_tx, sizeof(buf2_tx));
    read(fd,buf2_rx,sizeof(buf2_rx));


    for(int k =0 ;k < sizeof(buf2_rx);k++)
    {
     printf("0x%02x ",buf2_rx[k]);
    }
    printf("\r\n");
    TTOS_SleepTask(1000);
#else
    T_WORD addr =0x0000 ;//ok
    T_BYTE hi;
    T_BYTE low;
    hi = (addr & 0xff00 )>>8;
    low = (addr & 0x00ff);

    //T_BYTE buf1_tx[TEST_SIZE+3] = {WRITE, hi, low, 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a};
    T_BYTE buf1_tx[TEST_SIZE+3] = {0};
    buf1_tx[0] = WRITE;
    buf1_tx[1] = hi;
    buf1_tx[2] = low;
    write(fd, buf1_tx, sizeof(buf1_tx));//do write

    //T_BYTE buf2_tx[TEST_SIZE+3] = {READ, hi, low, 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};//read
    T_BYTE buf2_tx[TEST_SIZE+3] = {0};//read
    buf2_tx[0] = READ;
    buf2_tx[1] = hi;
    buf2_tx[2] = low;
    //T_BYTE buf2_tx[] = {FSTRD,hi,low,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};//Fast Read
    T_BYTE buf2_rx[sizeof(buf2_tx)];

    write(fd, buf2_tx, sizeof(buf2_tx));
    read(fd, buf2_rx, sizeof(buf2_rx));


    for (int k =0 ;k < sizeof(buf2_rx);k++)
    {
    	printf("0x%02x ",buf2_rx[k]);
    }
    printf("\r\n");
    TTOS_SleepTask(1000);
#endif
err:
	close(fd);
}
