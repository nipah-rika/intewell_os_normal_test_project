/****************************************************************************
 *    科东（广州）软件技术有限公司 版权所有
 * Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 *
 ***************************************************************************/
 
/* <EXECL>
需求标识：
XXX
测试用例标识：
gpio_test
目标机类型：
iTOP-RK3588
测试目的:
验证GPIO输出输入高低电平功能
测试类型：
功能测试
先决条件：
实时系统运行正常
测试步骤：
1、配置项目配置打开的GPIO组；
2、打开对应的两个GPIO口；
3、一个GPIO口作输出写操作，一个GPIO口作输入读操作；
4、将读到的数据打印出来；
预期结果：
GIOP口读写正常。
评价准则：
与预期结果一致
假设和约束：
操作系统可运行
设计者：
XXX
设计时间：
XXXX-XX-XX
</EXECL>
 */

/**************************** 引用部分 *****************************************/
 
#include <components/modbusIO.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "test.h"
#include <sysGpio.h>

T_VOID gpio_test(T_VOID)
{
	T_WORD fd = -1;
    T_WORD fd2 = -1;
	T_WORD ret = 0;
	T_BYTE buf[20] = {0};
    T_BYTE high[]="1";
    T_BYTE low[]="0";
	int i=0;
	int flag=1;
	T_BYTE array_high[20];
	T_BYTE array_low[20];

	/* 打开GPIO_2C4 作为输出*/
	fd = open("/GPIO_2C4", 0);
	if (fd < 0)
	{
		printf("open errno = %d\n", errno);
		flag = 0;
	}
	/* 打开GPIO_2C3 作为输入*/
	fd2 = open("/GPIO_2C3", 0);
	if (fd < 0)
	{
		printf("open errno = %d\n", errno);
		flag = 0;
	}
	while(1)
	{
	i++;
	if(i>20)
	{
		break;
	}
	/* 测试gpio输出高电平 */
	write(fd, high, 1);
	TTOS_SleepTask(TTOS_GetSysClkRate());
    
	/* 测试gpio读 */
	ret = read(fd2, buf, 1);
	if (ret != 1)
	{
		TEST_ERRPRINT(ret);
		flag = 0;
		return;
	}
	
	array_high[i-1] = buf[0];
	printf("write 1 read buf = %s\n", buf);
	printf("array_high = %c\n", array_high[i-1]);
    
    /* 测试gpio输出低电平 */
	write(fd, low, 0);
    
	TTOS_SleepTask(TTOS_GetSysClkRate());
	/* 测试gpio读 */
	ret = read(fd2, buf, 1);
	if (ret != 1)
	{
		TEST_ERRPRINT(ret);
		flag = 0;
		return;
	}
    

	printf("write 0 read buf = %s\n", buf);
	array_low[i-1] = buf[0];
	printf("array_low = %c\n", array_low[i-1]);
	}
	
	for(i=0;i<20;i++)
	{
		if(array_high[i] != '1')
		{
			TEST_FAILRINT();
			flag = 0;
     		return;
		}
	}
	
	for(i=0;i<20;i++)
	{
		if(array_low[i] != '0')
		{
			TEST_FAILRINT();
			flag = 0;
     		return;
		}
	}
	
	if(flag==1)
	{
		TEST_OKPRINT();
	}
	
	TTOS_SleepTask(TTOS_GetSysClkRate());
	/* 关闭gpio */
	ret = close(fd);
	if (ret < 0)
	{
		TEST_ERRPRINT(ret);
	}

}
