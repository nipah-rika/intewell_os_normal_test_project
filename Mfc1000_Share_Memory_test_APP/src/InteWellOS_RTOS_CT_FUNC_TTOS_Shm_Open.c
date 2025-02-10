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

T_VOID InteWellOS_RTOS_CT_FUNC_TTOS_Shm_Open() {
	// 创建共享内存指针变量
	void *Shm_addr;
	// 虚拟机ID
	T_UWORD vmID;
	// 读内存数据
	T_CHAR read_buf[10];

	// 超时限制时间
	T_CHAR time_out = 8;

	// 存储共享内存大小
	unsigned int readsize = 0;

	// 打开共享内存
	Shm_addr = open_shared_memory("shm", INFINITE, &readsize);

	do {
		TTOS_SleepTask(1 * VMK_GetSysClkRate());
		// 将内存中的数据拷贝到read_buf
		memcpy(read_buf, Shm_addr, sizeof("Hello world!!!"));
		// 判断拷贝的数据是否与写入内存的数据一致，数据一致或者超时则跳出循环
	} while ((strcmp(read_buf, "Hello world!!!") != 0) && (--time_out != 0));

	if (time_out != 0) {

		printk("open read: %s\n", read_buf);
	} else {

		printk("open read failed\n", read_buf);
	}

	VMK_GetVMID((T_UBYTE*) "vm2", &vmID);
	VMK_StopVM(vmID);

}

