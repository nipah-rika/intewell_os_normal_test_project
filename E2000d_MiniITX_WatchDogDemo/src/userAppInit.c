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


/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

int userAppInit(void)
{
	/*设置喂狗时间, 单位为系统tick*/
	T_UWORD max_dog_time = 0x2fff;
	T_VMK_ReturnCode vmk_rc;
	/*数据段*/
	 static int data_val[4] = {0, 1, 2, 3};

	 printk("data_val  primary data %d,%d,%d,%d \n", data_val[0], data_val[1], data_val[2], data_val[3]);
	 data_val[0] = 0x1234;
	 printk("data_val %d,%d,%d,%d \n", data_val[0], data_val[1], data_val[2], data_val[3]);

	/*未喂狗max_dog_time将超时，超时后的执行策略为FALSE表示超时后重启TTOS*/
	vmk_rc = TTOS_StartWatchdog(max_dog_time, FALSE);
	if (VMK_OK != vmk_rc)
	{
		printk("\nTTOS_StartWatchdog failed!\n");
		return TTOS_FAIL;
	}

	printk("\nTTOS_StartWatchdog successful!\n");

	return TTOS_OK;

}

