/*
 * iwdg.c
 *
 *  Created on: 2023年12月5日
 *      Author: kyland289
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sysGpio.h>
#define TASK_LOG   printk
#define WATCH_DOG_WDI_PIN_NAME           "/GPIO_B5"
#define WATCH_DOG_WD_EN_PIN_NAME      "/GPIO_B4"
typedef struct{
	T_BOOL status;
	T_BOOL is_initialed;
	T_WORD fd_wd_en;
	T_WORD fd_wd_wdi;
}T_DR_GPIO_WatchDogControl;

static T_DR_GPIO_WatchDogControl watchdog;

T_VMK_ReturnCode GPIO_StartWatchdog(T_UWORD maxFeeddogTime, T_BOOL timeout_stop)
{
	const T_BYTE high[]="1";
	const T_BYTE low[]="0";
	T_WORD fd = -1;
	T_DR_GpioConfigTable config;

	(T_VOID)maxFeeddogTime;
	(T_VOID)timeout_stop;

	//初始化WD_EN引脚,WD_EN高电平使能，硬件看门狗超时时间1300ms
	fd = open(WATCH_DOG_WD_EN_PIN_NAME, 0);//GPIO_B4
	if (fd < 0)
	{
		printf("open %s error fd:%d\t errno = %d\n", WATCH_DOG_WD_EN_PIN_NAME,fd,errno);
		return TTOS_FAIL;
	}

	if(ioctl(fd, UIO_GET_CFG, &config)<0)
	{
		return TTOS_FAIL;
	}

	config.direction = GPIO_OUTPUT;
	config.config=PIN_CONFIG_BIAS_PULL_UP;
	if(ioctl(fd, UIO_SET_CFG, &config)<0)
	{
		return TTOS_FAIL;
	}

	watchdog.fd_wd_en=fd;
	if(write(fd,high,1)<0)//看门狗使能
	{
		return TTOS_FAIL;
	}

	//初始化WDI引脚,WDI引脚翻转喂狗，硬件看门狗超时时间1300ms
	fd = open(WATCH_DOG_WDI_PIN_NAME, 0);//GPIO_B5
	if (fd < 0)
	{
		printf("open %s error fd:%d\t errno = %d\n", WATCH_DOG_WDI_PIN_NAME,fd,errno);
		return TTOS_FAIL;
	}

	if(ioctl(fd, UIO_GET_CFG, &config)<0)
	{
		return TTOS_FAIL;
	}

	config.direction = GPIO_OUTPUT;
	config.config=PIN_CONFIG_BIAS_PULL_UP;
	if(ioctl(fd, UIO_SET_CFG, &config)<0)
	{
		return TTOS_FAIL;
	}
	watchdog.fd_wd_wdi=fd;

	watchdog.is_initialed=TRUE;
	watchdog.status=TRUE;

	return (TTOS_OK);
}

T_VMK_ReturnCode GPIO_FeedWatchdog(T_VOID)
{
   const T_BYTE high[]="1";
   const T_BYTE low[]="0";

    if(watchdog.is_initialed)
    {
    	if(watchdog.status)
    	{
    		 write(watchdog.fd_wd_wdi, low, 1);
    	}
    	else
    	{
    		 write(watchdog.fd_wd_wdi, high, 1);
		}
    	watchdog.status=!watchdog.status;
    }
    else
    {
    	return TTOS_FAIL;
	}

	return (TTOS_OK);
}

T_VMK_ReturnCode GPIO_StopWatchdog(T_VOID)
{
	if(watchdog.is_initialed)
	{
		if(close(watchdog.fd_wd_wdi))
		{
			return TTOS_FAIL;
		}
		watchdog.fd_wd_wdi=-1;
		if(close(watchdog.fd_wd_en))
		{
			return TTOS_FAIL;
		}
		watchdog.fd_wd_wdi=-1;
		watchdog.is_initialed=FALSE;
	}

	return (TTOS_OK);
}
