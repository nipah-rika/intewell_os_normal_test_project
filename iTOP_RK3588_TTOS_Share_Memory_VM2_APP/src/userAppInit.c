/*********************************************************************************
*				                                         科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * 修改历史：
 * 2023-8-1     xx, 科东（广州）软件科技有限公司
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
#include <ttos.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

int userAppInit(void)
{
	T_TTOS_ReturnCode ret;
	SHM_ID Shm_id;
	T_UWORD Shm_addr;
	T_CHAR ch[2];

	printk("in vm2\n");

	// 以读写方式创建共享内存
	ret = TTOS_CreateShm("test1", 10, TTOS_SHM_RW, &Shm_id, &Shm_addr);
	if (ret != TTOS_OK) {
		printk("***Test Failed, filename: %s line: %d***\r\n", __FILE__, __LINE__);
	}

	// 读取vm1写入共享内存的数据
	ret = TTOS_ReadShm(Shm_id, ch, 2);
	if (ret != 2) {// 读取共享内存成功返回2，返回结果不为2则读取共享内存失败
		printk("***Test Failed, filename: %s line: %d***\r\n", __FILE__, __LINE__);
		return -1;
	}

	printk("vm2 read shm:%s \n", ch);

	return 0;
}

