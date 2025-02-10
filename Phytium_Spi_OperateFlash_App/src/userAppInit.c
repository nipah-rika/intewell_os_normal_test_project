/*********************************************************************************
*				                                         科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * 修改历史：
 * 2017-05-10     李燕, 科东（广州）软件科技有限公司
 *                创建该文件。
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


#define ARRAY_SIZE(array)  (sizeof(array)/sizeof(array[0]))

/*spi_info数组数量 要与 flash_table 数量要相等*/
 spi_info_t spi_info[] =
 {
		 [0].spi_name =  "/SPI0",
		 [0].spi_fd = -1
 };

sfud_flash flash_table[] =
{
		[0].name = "W25Q64CV",
};

/*
 * @brief:
 *    SPI控制器初始化
 * @param[in]: info: SPI控制器信息
 * @return:
 * 			无返回值
 */
static void _init(spi_info_t *info)
{
     int i;

     for(i=0;i<ARRAY_SIZE(spi_info);i++)
     {
    	 spi_info[i].flash= &flash_table[i];
    	 flash_table[i].spi.name=spi_info[i].spi_name;
     }
}

/*
 * @brief:
 *    打印读写测试时的数据
 * @param[in]: str: 表明是读测试或写测试
 * @param[in]: buf: 数据的地址
 * @param[in]: len: 数据的长度
 * @return:
 * 			无返回值
 */
void Show_buf(char *str,unsigned char *buf,int len)
{

	int i=0;
	printf("%s len:%d\r\n",str,len);


	for(i=0;i<len;i++)
	{
		printf("   0x%02X",buf[i]);

		if((i+1)%10==0)
		{
			printf("\r\n");

		}
	}

	printf("\r\n");
}

/*
 * @brief:
 *    flash设备的读,写测试
 * @param[in]: info: SPI控制器信息
 * @return:
 * 			成功返回 true, 失败返回false
 */
static bool _read_write_test(spi_info_t* info )
{
    sfud_err result;
    bool res=true;
    int i=0;
    char name_buf[64];
    unsigned char  read_data[100];
    unsigned char  write_data[100];
    sfud_flash *sfud_dev = info->flash;

    memset(read_data, 0, sizeof(read_data));
    memset(write_data, 0, sizeof(write_data));

    /* 擦除从 0 开始的 4096 字节 */
    result = sfud_erase(sfud_dev, 0, 4096);
    if (result == SFUD_SUCCESS)
    {
    	printf("%s Erase success\n",info->spi_name);

    }
    else
    {
     	printf("%s Erase Fail\n",info->spi_name);
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
    	printf("%s Write success.\n",info->spi_name);

    }
    else
    {
    	printf("%s Write Fail.\n",info->spi_name);
    	return false;
	}

    sprintf(name_buf, "%s wirte",info->spi_name);
    Show_buf(name_buf,write_data,sizeof(write_data));

    /* 读取从0开始的100字节 */
    result = sfud_read(sfud_dev, 0, sizeof(read_data), read_data);
    if (result == SFUD_SUCCESS)
    {
    	printf(" %s Read success.\n ",info->spi_name);

    }
    else
    {
    	printf(" %s Read Fail.\n ",info->spi_name);

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
    	printf("%s _read_write_test Pass\r\n\r\n",info->spi_name);

    }
    else
    {
    	printf("%s _read_write_test Fail i=%d\r\n\r\n",info->spi_name, i);

    }

   return res;
}

/*
 * @brief:
 *    实现flash设备测试的SFUD demo
 * @param[in]: info: SPI控制器信息
 * @param[in]: addr: flash设备测试的起始地址
 * @param[in]: size: 待测试的大小
 * @param[in]: data: 存放Flash测试时用到的数据
 * @return:
 * 			无返回值
 */
static void _sfud_demo(spi_info_t* info,uint32_t addr, size_t size, uint8_t *data) {

    sfud_err result = SFUD_SUCCESS;
    const sfud_flash *flash = info->flash;
    size_t i;

    /* prepare write data */
    for (i = 0; i < size; i++)
    {
        data[i] = i;
    }

    /* erase test */
    result = sfud_erase(flash, addr, size);
    if (result == SFUD_SUCCESS)
    {
    	printf("Erase the %s flash data finish. Start from 0x%08X, size is %ld.\r\n", flash->name, addr,
                size);
    }
    else
    {
    	printf("Erase the %s flash data failed.\r\n", flash->name);
        return;
    }

    /* write test */
    result = sfud_write(flash, addr, size, data);
    if (result == SFUD_SUCCESS)
    {
    	printf("Write the %s flash data finish. Start from 0x%08X, size is %ld.\r\n", flash->name, addr,
                size);
    }
    else
    {
    	printf("Write the %s flash data failed.\r\n", flash->name);
        return;
    }

    /* read test */
    result = sfud_read(flash, addr, size, data);
    if (result == SFUD_SUCCESS)
    {

        for (i = 0; i < size; i++)
        {
            if (i % 16 == 0)
            {
            	printf("[%08X] ", addr + i);
            }
            printf("%02X ", data[i]);
            if (((i + 1) % 16 == 0) || i == size - 1)
            {
            	printf("\r\n");
            }
        }
        printf("\r\n");
    }
    else
    {
    	printf("Read the %s flash data failed.\r\n", flash->name);
    }

    /* data check */
    for (i = 0; i < size; i++)
    {
        if (data[i] != i % 256)
        {
        	printf("Read and check write data has an error. Write the %s flash data failed.\r\n", flash->name);
			break;
        }
    }
    if (i == size)
    {
    	printf("The %s flash test is success.\r\n", flash->name);
    }
}

/*
 * @brief:
 *    实现测试程序的任务函数
 * @param[in]: p_data: SPI控制器信息
 * @return:
 * 			无返回值
 */
static void* _task(void *p_data)
{
	int cnt=1;
	spi_info_t *info = (spi_info_t *)p_data;

	printf("  goto %s :%s\r\n",__func__, info->spi_name);


	sfud_init();
	_init(info);
	while(1)
	{
		/*Flash擦除次数有限，百万次级别，不要过频繁擦擦，以免损坏器件*/
		if(cnt<=20)
		{
			printf("\t _read_write_test cnt:%d\r\n",cnt++);

			_read_write_test(info);
		}
		TTOS_SleepTask(1000);
	}


	printf("end %s %s\r\n",__func__,info->spi_name);

	return TTOS_OK;
}

/*
 * @brief:
 *    实现SPI接口操作Flash的测试程序
 * @return
 * 		无返回值
 */
T_VOID Spi_Flash_Test(T_VOID)
{
	int ret;
	int i;

	printf("   %s\r\n",__func__);

	for( i=0;i<ARRAY_SIZE(spi_info);i++)
	{
		ret = pthread_create(&(spi_info[i].testId), NULL, _task, (void*) &spi_info[i]);
		if(ret<0)
		{
			printf("create %s task errer  errno = %d ret=%d\r\n",spi_info[i].spi_name,errno,ret);
		}
	}

	while (1)
	{
		TTOS_SleepTask(100);
	}
}

/*
 * @brief:
 *    实现SPI接口操作Flash的测试程序
 * @return:
 *    成功返回值为 0
 */
int userAppInit(void)
{
	printf("\r\n\r\n    Reboot\r\n");

	Spi_Flash_Test();
	return 0;
}
/*要把这个下面这个文件禁止编译，不要删掉这里*/
#define INCLUDE_SFUD
#include <sfud/src/sfud.c>
