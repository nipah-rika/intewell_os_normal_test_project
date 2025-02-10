/*****************************************************************************
 *              科东(广州)软件科技有限公司 版权所有
 *   Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
 *****************************************************************************/

/*
 * 修改历史：
 * 2021-09-08    彭元志，科东（广州）软件科技有限公司
 *               创建该文件。
 */

/*
 * @file: shm_api.h
 * @brief:
 *    <li>共享内存区API接口声明</li>
 */
#ifndef _SHM_API_H_
#define _SHM_API_H_

/************************头文件********************************/
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************宏定义********************************/

/* 共享内存打开超时宏定义 */
#define NO_WAIT ((time_t)0)

/* 共享内存CACHE属性设置 */
typedef enum shm_cache_state
{
	/* 默认属性，开启cache */
	SHM_CACHE_DEFAULT = 0,	

	/* 开启cache */
	SHM_CACHE_ENABLE = 1,
}shm_cache_state_t;

/************************类型定义******************************/

/***********************接口声明******************************/
void *allocate_shared_memory (char *name, uint32_t size, shm_cache_state_t flag);
void *open_shared_memory ( char *name, time_t milliseconds, uint32_t *size );
void shm_show ( void );

#ifdef __cplusplus
}
#endif

#endif /* _SHM_API_H_ */
