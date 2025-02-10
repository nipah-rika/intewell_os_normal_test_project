/***************************************************************************
*				科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2011 CoreTek Systems Inc. All Rights Reserved.
***************************************************************************/
/**
* @file: configHACL.h
* @brief:
*        <li>hacl配置宏定义<li>
* @implements:
*/
#ifndef _CONFIGHACL_H
#define _CONFIGHACL_H


/************************头 文 件******************************/


/************************宏 定 义******************************/

#ifndef	_ARM_
#define	_ARM_
#endif

#define	CONFIG_HACL_TIMER_ONESHOT	FALSE
#define	CONFIG_HACL_TIMER_MICROSECOND_PERTICKS	0x000003e8
#define	CONFIG_CPU_NUM	12
#define	CONFIG_CPU_BIT	32
#define	CONFIG_CPU_SMP	TRUE

/************************外部声明******************************/


/************************模块变量******************************/


/************************全局变量******************************/

#endif
