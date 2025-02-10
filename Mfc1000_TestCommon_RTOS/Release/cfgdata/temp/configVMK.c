/***************************************************************************
*				�����������ɼ������޹�˾ ��Ȩ����
* 	 Copyright (C) 2011 CoreTek Systems Inc. All Rights Reserved.
***************************************************************************/
/**
* @file:configVMK.c
* @brief:
*        <li>SSK�ں�ȫ�����ݽṹ����<li>
* @implements:
*/

/************************ͷ �� ��******************************/

#include <svmk.h>
#include <hacl.h>
#include "configHACL.h"
#include "configTTS.h"
#include "configMemoryBlocks.h"

/************************�ⲿ����******************************/


/*�ж��ɷ�������*/
T_EXTERN T_UWORD vmkConfigIntDispatchTable[192];


/*hacl���ñ�*/
T_EXTERN T_VMK_ConfigKbsp configHaclTable;


/************************�� �� ��******************************/


/************************ģ�����******************************/

T_MODULE T_VMK_MemoryBlock vmkConfigSpaceBlocks[16]= CONFIG_VMK_SPACEBLOCKS;

/* ʱ�����ȵ����� */
#ifndef CONFIG_VMK_TTS_NUMBER
	#define CONFIG_VMK_TTS_NUMBER 0
	#define CONFIG_VMK_TTS_AUTO_START_NUMBER 0
	T_MODULE T_VMK_ConfigTTSTable vmkConfigTTSTable[0];
	T_MODULE T_VMK_TTSControlBlock vmkTTSCB[0];
	T_MODULE T_VMK_ConfigAutoStartedTTSTable vmkConfigAutoStartedTTS[0];
#else
	/*ʱ����������*/
	T_EXTERN T_VMK_ConfigTTSTable vmkConfigTTSTable[1];
	T_EXTERN T_VMK_ConfigAutoStartedTTSTable vmkConfigAutoStartedTTS[CONFIG_VMK_TTS_AUTO_START_NUMBER];
	T_MODULE T_VMK_TTSControlBlock vmkTTSCB[CONFIG_VMK_TTS_NUMBER];
#endif

/*�������ƽṹ*/
#ifndef CONFIG_VMK_VM_NUMBER
	#define CONFIG_VMK_VM_NUMBER 0
	T_MODULE T_VMK_ConfigUserVMTable vmkConfigUserVMTable[0];
	T_VMK_VMControlBlockWithStack vmkUserVCB[0];
#else
	/*�������ñ�*/
	T_EXTERN T_VMK_ConfigUserVMTable vmkConfigUserVMTable[1];
	T_VMK_VMControlBlockWithStack vmkUserVCB[CONFIG_VMK_VM_NUMBER]; 
#endif



/**
 *�ں�ȫ�����ñ�
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

