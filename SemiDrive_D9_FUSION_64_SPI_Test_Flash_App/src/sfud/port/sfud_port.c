/*
 * This file is part of the Serial Flash Universal Driver Library.
 *
 * Copyright (c) 2016-2018, Armink, <armink.ztl@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Function: Portable interface for each platform.
 * Created on: 2016-04-23
 */

#include <commonTypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sfud/inc/sfud.h>
#include <main.h>
#include <sysGpio.h>
#include <sysSpi.h>
#include "pthread.h"
#define TASK_LOG(...) printf(__VA_ARGS__)
//#define TASK_LOG(...)
static char log_buf[256];

void sfud_log_debug(const char *file, const long line, const char *format, ...);
extern spi_info_t spi_info[];
static void rcc_configuration(spi_info_t* info)
{

}

static void gpio_configuration(spi_info_t* info)
{

}

static void spi_configuration(spi_info_t* info)
{
	int ret;
	int fd;
	//初始化SPI
	fd = open(info->spi_name, 0);
	if (fd < 0)
	{
		TASK_LOG("***open %s error,errno:%d\r\n",info->spi_name,errno);
	}
	else
	{
		TASK_LOG("***open %s ok\n",info->spi_name);
		  info->spi_fd=fd;
	}


	/* 设置传输模式 */
	int mode = SPI_MODE_0;
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置频率 */
	int speed = 500*1000;
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置数据长度 */
	int bitsperword = 8;
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsperword);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	TASK_LOG("bits per word: %d \n", bitsperword);
	TASK_LOG("spi mode: 0x%x \n", (mode & 0x3));
	TASK_LOG("max speed: %d Hz (%d KHz) \n", speed, speed/1000);

    return;
    err:
	       TASK_LOG("  [%s]:%d errno\n", __func__,__LINE__,errno);
}

static void spi_lock(const sfud_spi *spi)
{

}

static void spi_unlock(const sfud_spi *spi)
{

}

/**
 * SPI write data then read data
 */
static sfud_err spi_write_read(const sfud_spi *spi, const uint8_t *write_buf, size_t write_size, uint8_t *read_buf,size_t read_size)
{
    spi_info_t* spi_dev = (spi_info_t*) spi->user_data;
    unsigned char buf[write_size+read_size];

    memset(buf,0xff,sizeof(buf));
    memcpy(buf,write_buf,write_size);

    if(write_buf!=NULL)
    	write(spi_dev->spi_fd,buf,write_size+read_size);
    if(read_buf!=NULL)
    	read(spi_dev->spi_fd,buf,write_size+read_size);

    memcpy(read_buf,buf+write_size,read_size);

    return SFUD_SUCCESS;
}

//static sfud_err spi_write_read(const sfud_spi *spi, const uint8_t *write_buf, size_t write_size, uint8_t *read_buf,size_t read_size)
//{
//    spi_info_t* spi_dev = (spi_info_t*) spi->user_data;
//    unsigned char buf[write_size+read_size];
//    memset(buf,0xff,sizeof(buf));
//    memcpy(buf,write_buf,write_size);
//
//    if(write_buf!=NULL)
//    	if(write(spi_dev->spi_fd,buf,write_size+read_size)<0)
//    	{
//    		printf("\t [%s]:%d spi_fd:%d\r\n",__func__,__LINE__,spi_dev->spi_fd);
//    	}
//    	else
//    	{
//    		printf("\t [%s]:%d spi_fd:%d\r\n",__func__,__LINE__,spi_dev->spi_fd);
//    		Show_buf("tx",buf,sizeof(buf));
//    	}
//    memset(buf,0,sizeof(buf));
//    if(read_buf!=NULL)
//    	read(spi_dev->spi_fd,buf,write_size+read_size);
//    Show_buf("  rx",buf,sizeof(buf));
//    memcpy(read_buf,buf+write_size,read_size);
//
//      return SFUD_SUCCESS;
//}
static void _delay_us(int us)
{
    UINT64 start_time,end_time;
    start_time=TTOS_GetCurrentSystemCount();
    end_time=TTOS_GetCurrentSystemCount();
    while(TTOS_GetCurrentSystemSubTime(start_time, end_time, TTOS_US_UNIT)<us)
    {
    	end_time=TTOS_GetCurrentSystemCount();
    }
}
/* about 100 microsecond delay */
static void retry_delay_100us(void)
{
	_delay_us(100);
}


#ifdef SFUD_USING_QSPI
/**
 * read flash data by QSPI
 */
static sfud_err qspi_read(const struct __sfud_spi *spi, uint32_t addr, sfud_qspi_read_cmd_format *qspi_read_cmd_format,
        uint8_t *read_buf, size_t read_size) {
    sfud_err result = SFUD_SUCCESS;

    /**
     * add your qspi read flash data code
     */

    return result;
}
#endif /* SFUD_USING_QSPI */

sfud_err sfud_spi_port_init(sfud_flash *flash) {
    sfud_err result = SFUD_SUCCESS;

     /* RCC 初始化 */
     rcc_configuration(&spi_info[flash->index]);
     /* GPIO 初始化 */
     gpio_configuration(&spi_info[flash->index]);
     /* SPI 外设初始化 */
     spi_configuration(&spi_info[flash->index]);
     /* 同步 Flash 移植所需的接口及数据 */
    flash->spi.wr = spi_write_read;
    flash->spi.lock = spi_lock;
    flash->spi.unlock = spi_unlock;
    flash->spi.user_data = &spi_info[flash->index];
    /* about 100 microsecond delay */
    flash->retry.delay = retry_delay_100us;
    /* adout 60 seconds timeout */
    flash->retry.times = 60 * 10000;

    return result;
}

/**
 * This function is print debug info.
 *
 * @param file the file which has call this function
 * @param line the line number which has call this function
 * @param format output format
 * @param ... args
 */
void sfud_log_debug(const char *file, const long line, const char *format, ...) {
    va_list args;

    /* args point to the first variable parameter */
    va_start(args, format);
    printf("[SFUD](%s:%ld) ", file, line);
    /* must use vprintf to print */
    vsnprintf(log_buf, sizeof(log_buf), format, args);
    printf("%s\n", log_buf);
    va_end(args);
}

/**
 * This function is print routine info.
 *
 * @param format output format
 * @param ... args
 */
void sfud_log_info(const char *format, ...) {
    va_list args;

    /* args point to the first variable parameter */
    va_start(args, format);
    printf("[SFUD]");
    /* must use vprintf to print */
    vsnprintf(log_buf, sizeof(log_buf), format, args);
    printf("%s\n", log_buf);
    va_end(args);
}
