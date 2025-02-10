/*
 * shm_write.c
 *
 *  Created on: 2021年9月17日
 *      Author: yuezeyu
 */

#include <stdio.h>
#include <shm_api.h>

#include <ttos.h>

#define SHM_W (2)
#define SHM_R (1)
#define SHM_WAIT (0)
#define SHM_SIZE (20)

T_UWORD shm_err_cnt = 0;

//void main (void)
void shm_write (void)
{

	printf("shm_write cache SHM_CACHE_DISABLE xxx  \r\n");

    unsigned char *shm_w_ptr = (unsigned char *)allocate_shared_memory("shm_w", SHM_SIZE + 1, SHM_CACHE_ENABLE);
    unsigned char *shm_r_ptr = (unsigned char *)allocate_shared_memory("shm_r", SHM_SIZE + 1, SHM_CACHE_ENABLE);
    unsigned char *shm_data_w = shm_w_ptr + 1;
    unsigned char *shm_data_r = shm_r_ptr + 1;

    unsigned char i = 0;

    printf("shm_write cache SHM_CACHE_DISABLE 333 \r\n");

    if (NULL == shm_w_ptr) {

        printf("shm_w allocate failed!!!\r\n");
        return;
    } else {

        printf("shm_w allocate success!!!\r\n");
        printf("shm_w_ptr: 0x%lx\n", (unsigned long)shm_w_ptr);
    }

    if (NULL == shm_r_ptr) {

        printf("shm_r allocate failed!!!\r\n");
        return;
    } else {

        printf("shm_r allocate success!!!\r\n");
        printf("shm_r_ptr: 0x%lx\n", (unsigned long)shm_r_ptr);
    }

    memset(shm_w_ptr, 0, SHM_SIZE + 1);
    memset(shm_r_ptr, 0, SHM_SIZE + 1);
	
    while (1) {

        sprintf((char *)shm_data_w, "hello world %u\n\0", i);
        printf("write: %s", shm_data_w);
        *shm_w_ptr = SHM_W;
        printf("shm_w_ptr = %d\n", *shm_w_ptr);
        /* 等待接收数据 */
        do {

            TTOS_SleepTask(TTOS_GetSysClkRate() / 5);
        } while (*shm_r_ptr != SHM_R);
        *shm_r_ptr = SHM_WAIT;

        /* 写读数据对比 */
        if (0 != memcmp(shm_data_w, shm_data_r, SHM_SIZE)) {

            /* 数据不一致的情况 */
            printf(">>>>>> data read err: %s\n", shm_data_r);
        } else {

            printf("read: %s\n", shm_data_r);
        }

        i++;
    }
}


