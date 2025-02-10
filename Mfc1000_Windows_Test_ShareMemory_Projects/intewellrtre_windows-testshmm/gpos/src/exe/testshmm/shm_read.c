/*
 * shm_read.c
 *
 *  Created on: 2021Äê9ÔÂ17ÈÕ
 *      Author: yuezeyu
 */

#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "shm_api.h"

#define SHM_W (2)
#define SHM_R (1)
#define SHM_WAIT (0)

void shm_write(void)
{
	uint32_t shm_size_w = 0;
	uint32_t shm_size_r = 0;
	unsigned char *shm_w_ptr = (unsigned char *)open_shared_memory("shm_w", INFINITE, &shm_size_w);
	unsigned char *shm_r_ptr = (unsigned char *)open_shared_memory("shm_r", INFINITE, &shm_size_r);

	if (NULL == shm_w_ptr) {

		printf("shm_w open failed!!!\r\n");
		return;
	}
	else {

		printf("shm_w open success!!!\r\n");
		printf("shm_w_ptr: %p\n", shm_w_ptr);
	}

	if (NULL == shm_r_ptr) {

		printf("shm_r open failed!!!\r\n");
		return;
	}
	else {

		printf("shm_r open success!!!\r\n");
		printf("shm_r_ptr: %p\n", shm_r_ptr);
	}

	if (shm_size_w != shm_size_r) {

		printf("Test Failed!!!\r\n");
	}

	while (1) {

		while (*shm_w_ptr != SHM_W);
		*shm_w_ptr = SHM_WAIT;

		memcpy(shm_r_ptr, shm_w_ptr, shm_size_w);

		*shm_r_ptr = SHM_R;
	}
}


VOID __cdecl
main(
	_In_ ULONG argc,
	_In_reads_(argc) PCHAR argv[]
)
//void shm_write (void)
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	shm_write();
}


