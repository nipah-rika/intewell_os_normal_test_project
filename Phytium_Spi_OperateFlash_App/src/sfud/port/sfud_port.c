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
static char log_buf[256];

void sfud_log_debug(const char *file, const long line, const char *format, ...);
extern spi_info_t spi_info[];

/**
 * @brief
 * 		rcc configuration
 * @param[in]: info:  the spi controller information
 *	@return:
 *			no return value.
 */
static void rcc_configuration(spi_info_t* info)
{

}

/**
 * @brief
 * 		gpio configuration
 * @param[in]: info:  the spi controller information
 *	@return:
 *			no return value.
 */
static void gpio_configuration(spi_info_t* info)
{

}

/**
 * @brief
 * 		SPI configuration
 * @param[in]: info:  the spi controller information
 *	@return:
 *			no return value.
 */
static void spi_configuration(spi_info_t* info)
{
	int ret;
	int fd;
	//初始化SPI
	fd = open(info->spi_name, 0);
	if (fd < 0)
	{
		printf("***open %s error,errno:%d\r\n",info->spi_name,errno);
	}
	else
	{
		printf("***open %s ok\n",info->spi_name);
		  info->spi_fd=fd;
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
	int speed = 500*1000;
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

    return;
    err:
	       printf("  [%s]:%d errno is %d\n", __func__,__LINE__,errno);
}

/**
 * @brief
 * 		spi lock
 * @param[in]: spi:  the sfud spi information
 *	@return:
 *			no return value.
 */
static void spi_lock(const sfud_spi *spi)
{

}

/**
 * @brief
 * 		spi unlock
 * @param[in]: spi:  the sfud spi information
 *	@return:
 *			no return value.
 */
static void spi_unlock(const sfud_spi *spi)
{

}

/**
 * @brief
 * 		SPI write data then read data
 * @param[in]: spi:  the spi controller
 * @param[in]: write_buf: write data address
 * @param[in]: write_size: write data size
 * @param[in]: read_buf: buffer to store data
 * @param[in]: read_size: data length
 *	@return:
 *			success: return result; failed: return errno
 *
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

/**
 * @brief
 *  	 microsecond delay
 * @param[in]: us: delay us count
 * @return:
 * 			no return value.
 * */
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

/**
 * @brief
 *  	about 100 microsecond delay
 * @return:
 * 			no return value.
 * */
static void retry_delay_100us(void)
{
	_delay_us(100);
}


#ifdef SFUD_USING_QSPI
/**
 * @brief
 * 		read flash data by QSPI
 * @param[in]: spi:  the spi controller
 * @param[in]: addr: read data address
 * @param[in]: qspi_read_cmd_format: spi read cmd format
 * @param[in]: read_buf: buffer to store data
 * @param[in]: read_size: data length
 *	@return:
 *			success: return result; failed: return errno
 *
 */
static sfud_err qspi_read(const struct __sfud_spi *spi, uint32_t addr, sfud_qspi_read_cmd_format *qspi_read_cmd_format,
        uint8_t *read_buf, size_t read_size)
{
    sfud_err result = SFUD_SUCCESS;

    /**
     * add your qspi read flash data code
     */

    return result;
}
#endif /* SFUD_USING_QSPI */

/**
 * @brief
 * 		initialize the spi port
 * @param[in]: flash:  the flash device
 * @return:
 * 			success: return result; failed: return errno
 */
sfud_err sfud_spi_port_init(sfud_flash *flash)
{
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
 * @brief
 * 		This function is print debug info.
 * @param[in]: file:  the file which has call this function
 * @param[in]:  line:  the line number which has call this function
 * @param[in]: format:  output format
 * @param ... args
 * @return:
 * 			no return value.
 */
void sfud_log_debug(const char *file, const long line, const char *format, ...)
{
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
 * @brief
 * 		This function is print routine info.
 * @param[in]: format: output format
 * @param ... args
 * @return
 * 			no return value
 */
void sfud_log_info(const char *format, ...)
{
    va_list args;

    /* args point to the first variable parameter */
    va_start(args, format);
    printf("[SFUD]");
    /* must use vprintf to print */
    vsnprintf(log_buf, sizeof(log_buf), format, args);
    printf("%s\n", log_buf);
    va_end(args);
}
