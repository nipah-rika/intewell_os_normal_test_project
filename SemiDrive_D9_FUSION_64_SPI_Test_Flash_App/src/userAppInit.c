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
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sysGpio.h>
#include <sysSpi.h>
#include "pthread.h"
#include <sfud/inc/sfud_cfg.h>
#include <sfud/inc/sfud_def.h>
#include <sfud/inc/sfud_flash_def.h>
#include <sfud/inc/sfud.h>
#include <main.h>
/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/
#define TASK_LOG(...) printf(__VA_ARGS__)
//#define TASK_LOG(...)
#define ARRAY_SIZE(array)  (sizeof(array)/sizeof(array[0]))
//spi_info数组数量 要与 flash_table 数量要相等
 spi_info_t spi_info[] = {

				 [0].spi_name =  "/SPI_7",
				 [0].spi_fd = -1

 };

sfud_flash flash_table[] =  {
		  [0].name = "W25Q64CV",
		  };

static void _init(spi_info_t *info)
{
     int i;

     for(i=0;i<ARRAY_SIZE(spi_info);i++)
     {
    	 spi_info[i].flash= &flash_table[i];
    	 flash_table[i].spi.name=spi_info[i].spi_name;
     }
}
void Show_buf(char *str,unsigned char *buf,int len)
{
	int i=0;
	TASK_LOG("%s len:%d\r\n",str,len);
	for(i=0;i<len;i++)
	{
		TASK_LOG("   0x%02X",buf[i]);
		if((i+1)%10==0)
		{
			TASK_LOG("\r\n");
		}
	}
	TASK_LOG("\r\n");
}
static bool _read_write_test(spi_info_t* info )
{
    sfud_err result;
    bool res=true;
    int i=0;
    char name_buf[64];
    unsigned char  read_data[100];//读取到的数据
    unsigned char  write_data[100];//将要写入的数据
    sfud_flash *sfud_dev = info->flash;

    memset(read_data, 0, sizeof(read_data));
    memset(write_data, 0, sizeof(write_data));

    /* 擦除从 0 开始的 4096 字节 */
    result = sfud_erase(sfud_dev, 0, 4096);
    if (result == SFUD_SUCCESS)
    {
    	TASK_LOG("%s Erase success\n",info->spi_name);
    }
    else
    {
     	TASK_LOG("%s Erase Fail\n",info->spi_name);
       	return false;
	}
    for( i=0;i<sizeof(write_data);i++)
    {
    	write_data[i]=i+1;
    }
    /* 写入从 0 开始的 100 字节, 1->100 */
    result = sfud_write(sfud_dev, 0, sizeof(write_data), write_data);
    if (result == SFUD_SUCCESS)
    {
    	TASK_LOG("%s Write success.\n",info->spi_name);
    }
    else
    {
    	TASK_LOG("%s Write Fail.\n",info->spi_name);
    	return false;
	}
    sprintf(name_buf, "%s wirte",info->spi_name);
    Show_buf(name_buf,write_data,sizeof(write_data));
    /* 读取从0开始的100字节 */
    result = sfud_read(sfud_dev, 0, sizeof(read_data), read_data);
    if (result == SFUD_SUCCESS)
    {
    	TASK_LOG("Read success.\n ",info->spi_name);
    }
    else
    {
    	TASK_LOG("Read Fail.\n ",info->spi_name);
    	return false;
	}
    sprintf(name_buf, "%s read",info->spi_name);
    Show_buf(name_buf,read_data,sizeof(read_data));
    for(i=0;i<sizeof(write_data);i++)
    {
    	if(write_data[i] != read_data[i])
    	{
    		res=false;
    		break;
    	}
    }
    if(res==true)
    {
    	TASK_LOG("%s _read_write_test Pass\r\n\r\n",info->spi_name);
    }
    else
    {
    	TASK_LOG("%s _read_write_test Fail i=%d\r\n\r\n",i,info->spi_name);
    }

   return res;
}
/**
 * SFUD demo for the first flash device test.
 *
 * @param addr flash start address
 * @param size test flash size
 * @param size test flash data buffer
 */
static void _sfud_demo(spi_info_t* info,uint32_t addr, size_t size, uint8_t *data) {
    sfud_err result = SFUD_SUCCESS;
    const sfud_flash *flash = info->flash;
    size_t i;
    /* prepare write data */
    for (i = 0; i < size; i++) {
        data[i] = i;
    }
    /* erase test */
    result = sfud_erase(flash, addr, size);
    if (result == SFUD_SUCCESS) {
    	TASK_LOG("Erase the %s flash data finish. Start from 0x%08X, size is %ld.\r\n", flash->name, addr,
                size);
    } else {
    	TASK_LOG("Erase the %s flash data failed.\r\n", flash->name);
        return;
    }
    /* write test */
    result = sfud_write(flash, addr, size, data);
    if (result == SFUD_SUCCESS) {
    	TASK_LOG("Write the %s flash data finish. Start from 0x%08X, size is %ld.\r\n", flash->name, addr,
                size);
    } else {
    	TASK_LOG("Write the %s flash data failed.\r\n", flash->name);
        return;
    }
    /* read test */
    result = sfud_read(flash, addr, size, data);
    if (result == SFUD_SUCCESS) {
    	TASK_LOG("Read the %s flash data success. Start from 0x%08X, size is %ld. The data is:\r\n", flash->name, addr,
                size);
        TASK_LOG("Offset (h) 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\r\n");
        for (i = 0; i < size; i++) {
            if (i % 16 == 0) {
            	TASK_LOG("[%08X] ", addr + i);
            }
            TASK_LOG("%02X ", data[i]);
            if (((i + 1) % 16 == 0) || i == size - 1) {
            	TASK_LOG("\r\n");
            }
        }
        TASK_LOG("\r\n");
    } else {
    	TASK_LOG("Read the %s flash data failed.\r\n", flash->name);
    }
    /* data check */
    for (i = 0; i < size; i++) {
        if (data[i] != i % 256) {
        	TASK_LOG("Read and check write data has an error. Write the %s flash data failed.\r\n", flash->name);
			break;
        }
    }
    if (i == size) {
    	TASK_LOG("The %s flash test is success.\r\n", flash->name);
    }
}
//任务函数
static void* _task(void *p_data)
{
	int cnt=1;
	spi_info_t *info = (spi_info_t *)p_data;

	TASK_LOG("  goto %s :%s\r\n",__func__, info->spi_name);

	sfud_init();
	_init(info);
	while(1)
	{
		//Flash擦除次数有限，百万次级别，不要过频繁擦擦，以免损坏器件
		if(cnt<=20)
		{
			TASK_LOG("\t _read_write_test cnt:%d\r\n",cnt++);
			_read_write_test(info);
		}

		TTOS_SleepTask(1000);
	}


	TASK_LOG("      end %s %s\r\n",__func__,info->spi_name);
	return TTOS_OK;
}


T_VOID Spi_Flash_Test(T_VOID)
{
	int ret;
	int i;
	TASK_LOG("   %s\r\n",__func__);
	for( i=0;i<ARRAY_SIZE(spi_info);i++)
	{
		ret = pthread_create(&(spi_info[i].testId), NULL, _task, (void*) &spi_info[i]);
		if(ret<0)
		{
			TASK_LOG("create %s task errer  errno = %d ret=%d\r\n",spi_info[i].spi_name,errno,ret);
		}
	}

	while (1) {
		TTOS_SleepTask(100);
	}
}

int userAppInit(void)
{
	TASK_LOG("\r\n\r\n    Reboot\r\n");

	Spi_Flash_Test();
}
//要把这个下面这个文件禁止编译，不要删掉这里
#define INCLUDE_SFUD
#include <sfud/src/sfud.c>
