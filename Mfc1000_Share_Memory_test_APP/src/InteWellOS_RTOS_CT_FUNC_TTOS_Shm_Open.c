/*
 * InteWellOS_RTOS_CT_FUNC_TTOS_Shm_001.c
 *
 *  Created on: 2023��8��22��
 *      Author: zlw
 *      Share memory test
 */

/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include<stdio.h>
#include <ttos.h>
#include <shm_api.h>

T_VOID InteWellOS_RTOS_CT_FUNC_TTOS_Shm_Open() {
	// ���������ڴ�ָ�����
	void *Shm_addr;
	// �����ID
	T_UWORD vmID;
	// ���ڴ�����
	T_CHAR read_buf[10];

	// ��ʱ����ʱ��
	T_CHAR time_out = 8;

	// �洢�����ڴ��С
	unsigned int readsize = 0;

	// �򿪹����ڴ�
	Shm_addr = open_shared_memory("shm", INFINITE, &readsize);

	do {
		TTOS_SleepTask(1 * VMK_GetSysClkRate());
		// ���ڴ��е����ݿ�����read_buf
		memcpy(read_buf, Shm_addr, sizeof("Hello world!!!"));
		// �жϿ����������Ƿ���д���ڴ������һ�£�����һ�»��߳�ʱ������ѭ��
	} while ((strcmp(read_buf, "Hello world!!!") != 0) && (--time_out != 0));

	if (time_out != 0) {

		printk("open read: %s\n", read_buf);
	} else {

		printk("open read failed\n", read_buf);
	}

	VMK_GetVMID((T_UBYTE*) "vm2", &vmID);
	VMK_StopVM(vmID);

}

