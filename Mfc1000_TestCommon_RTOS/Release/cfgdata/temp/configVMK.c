/***************************************************************************
*				北京科银京成技术有限公司 版权所有
* 	 Copyright (C) 2011 CoreTek Systems Inc. All Rights Reserved.
***************************************************************************/
/**
* @file:configVMK.c
* @brief:
*        <li>SSK内核全局数据结构定义<li>
* @implements:
*/

/************************头 文 件******************************/

#include <svmk.h>
#include <hacl.h>
#include "configHACL.h"
#include "configTTS.h"
#include "configMemoryBlocks.h"

/************************外部声明******************************/


/*中断派发表配置*/
T_EXTERN T_UWORD vmkConfigIntDispatchTable[192];


/*hacl配置表*/
T_EXTERN T_VMK_ConfigKbsp configHaclTable;


/************************宏 定 义******************************/


/************************模块变量******************************/

T_MODULE T_VMK_MemoryBlock vmkConfigSpaceBlocks[16]= CONFIG_VMK_SPACEBLOCKS;

/* 时间表调度的配置 */
#ifndef CONFIG_VMK_TTS_NUMBER
	#define CONFIG_VMK_TTS_NUMBER 0
	#define CONFIG_VMK_TTS_AUTO_START_NUMBER 0
	T_MODULE T_VMK_ConfigTTSTable vmkConfigTTSTable[0];
	T_MODULE T_VMK_TTSControlBlock vmkTTSCB[0];
	T_MODULE T_VMK_ConfigAutoStartedTTSTable vmkConfigAutoStartedTTS[0];
#else
	/*时间表调度配置*/
	T_EXTERN T_VMK_ConfigTTSTable vmkConfigTTSTable[1];
	T_EXTERN T_VMK_ConfigAutoStartedTTSTable vmkConfigAutoStartedTTS[CONFIG_VMK_TTS_AUTO_START_NUMBER];
	T_MODULE T_VMK_TTSControlBlock vmkTTSCB[CONFIG_VMK_TTS_NUMBER];
#endif

/*分区控制结构*/
#ifndef CONFIG_VMK_VM_NUMBER
	#define CONFIG_VMK_VM_NUMBER 0
	T_MODULE T_VMK_ConfigUserVMTable vmkConfigUserVMTable[0];
	T_VMK_VMControlBlockWithStack vmkUserVCB[0];
#else
	/*分区配置表*/
	T_EXTERN T_VMK_ConfigUserVMTable vmkConfigUserVMTable[1];
	T_VMK_VMControlBlockWithStack vmkUserVCB[CONFIG_VMK_VM_NUMBER]; 
#endif



/**
 *内核全局配置表
 */
T_VMK_ConfigTable  vmkConfigTable __attribute__((__section__(".vmk_info"))) = 
{
	vmkConfigSpaceBlocks,
	vmkConfigUserVMTable,
	vmkConfigTTSTable,
	NULL,
	CONFIG_VMK_TTS_AUTO_START_NUMBER,
	vmkConfigAutoStartedTTS,
	vmkConfigIntDispatchTable,
	CONFIG_VMK_VM_NUMBER,
	vmkUserVCB,
	CONFIG_VMK_TTS_NUMBER,
	vmkTTSCB,
	&configHaclTable
};

