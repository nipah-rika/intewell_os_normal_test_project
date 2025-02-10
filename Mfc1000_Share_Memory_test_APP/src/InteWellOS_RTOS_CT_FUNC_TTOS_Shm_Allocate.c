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

T_VOID InteWellOS_RTOS_CT_FUNC_TTOS_Shm_Allocate() {
	// ���������ڴ�ָ�����
	void *Shm_addr = NULL;
	// д���ڴ���ַ�������
	T_CHAR write_buf[] = "Hello world!!!";

	// ���乲���ڴ�
	Shm_addr = allocate_shared_memory("shm", sizeof(write_buf),
			SHM_CACHE_DEFAULT);

	if (Shm_addr != NULL) {
		// ���ַ���write_buf�������ڴ���
		memcpy(Shm_addr, write_buf, sizeof(write_buf));
		printk("\nallocate write: %s\n", write_buf);
	} else {
		printk("\nallocate write failed\n");
	}

}
