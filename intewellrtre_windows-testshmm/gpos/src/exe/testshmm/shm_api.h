/*****************************************************************************
 *              �ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
 *   Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
 *****************************************************************************/

/*
 * �޸���ʷ��
 * 2021-09-08    ��Ԫ־���ƶ������ݣ�����Ƽ����޹�˾
 *               �������ļ���
 */

/*
 * @file: shm_api.h
 * @brief:
 *    <li>�����ڴ���API�ӿ�����</li>
 */
#ifndef _SHM_API_H_
#define _SHM_API_H_

/************************ͷ�ļ�********************************/
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************�궨��********************************/

/* �����ڴ�򿪳�ʱ�궨�� */
#define NO_WAIT ((time_t)0)

/* �����ڴ�CACHE�������� */
typedef enum shm_cache_state
{
	/* Ĭ�����ԣ�����cache */
	SHM_CACHE_DEFAULT = 0,	

	/* ����cache */
	SHM_CACHE_ENABLE = 1,
}shm_cache_state_t;

/************************���Ͷ���******************************/

/***********************�ӿ�����******************************/
void *allocate_shared_memory (char *name, uint32_t size, shm_cache_state_t flag);
void *open_shared_memory ( char *name, time_t milliseconds, uint32_t *size );
void shm_show ( void );

#ifdef __cplusplus
}
#endif

#endif /* _SHM_API_H_ */
