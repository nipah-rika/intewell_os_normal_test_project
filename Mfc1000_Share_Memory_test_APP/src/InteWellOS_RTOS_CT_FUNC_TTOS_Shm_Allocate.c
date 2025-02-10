/*
 * InteWellOS_RTOS_CT_FUNC_TTOS_Shm_001.c
 *
 *  Created on: 2023年8月22日
 *      Author: zlw
 *      Share memory test
 */

/************************头 文 件******************************/
#include <commonTypes.h>
#include<stdio.h>
#include <ttos.h>
#include <shm_api.h>

T_VOID InteWellOS_RTOS_CT_FUNC_TTOS_Shm_Allocate() {
	// 创建共享内存指针变量
	void *Shm_addr = NULL;
	// 写入内存的字符串变量
	T_CHAR write_buf[] = "Hello world!!!";

	// 分配共享内存
	Shm_addr = allocate_shared_memory("shm", sizeof(write_buf),
			SHM_CACHE_DEFAULT);

	if (Shm_addr != NULL) {
		// 将字符串write_buf拷贝到内存中
		memcpy(Shm_addr, write_buf, sizeof(write_buf));
		printk("\nallocate write: %s\n", write_buf);
	} else {
		printk("\nallocate write failed\n");
	}

}
