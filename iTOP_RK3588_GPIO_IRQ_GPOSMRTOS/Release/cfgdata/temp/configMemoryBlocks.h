/***************************************************************************
*				�ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
* 	 Copyright (C) 2011 CoreTek Systems Inc. All Rights Reserved.
***************************************************************************/
/**
* @file: configMemoryBlocks.h
* @brief:
*        <li>�ռ����ö���<li>
* @implements:
*/
#ifndef _CONFIGMEMORYBLOCK_H
#define _CONFIGMEMORYBLOCK_H


/************************ͷ �� ��******************************/


/************************�ⲿ����******************************/


/************************ģ�����******************************/


/************************ȫ�ֱ���******************************/


/************************�� �� ��******************************/

/*���Ŀռ�����*/
#define CONFIG_VMK_SPACEBLOCKS    {\
		{("pageRamSpace"),(0x417e0000),(0x417e0000ull),(0x1600000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("taRamSpace"),(0x40000000),(0x40000000ull),(0x80000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("kernelRamSpace"),(0x402e0000),(0x402e0000ull),(0x1400000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("ethShareRamSpace"),(0x40080000),(0x40080000ull),(0x260000),(MM_DEFAULT_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("vectorSpace"),(0x416e0000),(0x416e0000ull),(0x100000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("heap"),(0x42de1000),(0x42de1000ull),(0x2000000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("spinApic"),(0x42de0000),(0x42de0000ull),(0x1000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("configtableSpace"),(0x4f900000),(0x4f900000ull),(0x8000),(MM_DEFAULT_USER_RDONLY_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("virtualDevice"),(0x44de1000),(0x44de1000ull),(0x900000),(MM_DEFAULT_USER_DATA_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("shmRamSpace"),(0x456e1000),(0x456e1000ull),(0x4000000),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("IOSpace"),(0xf0000000),(0xf0000000ull),(0xfff0000),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*�����ռ�����*/


/*����rootAgent����*/
#define CONFIG_VM_SPACEBLOCKS_rootAgent    {\
		{("rootAgentRamSpace"),(0x100000),(0x50000000ull),(0xc800000),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*����vm1����*/
#define CONFIG_VM_SPACEBLOCKS_vm1    {\
		{("vm1RamSpace"),(0x100000),(0x5c800000ull),(0xc800000),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*��������*/
#define CONFIG_VMK_VM_NUMBER 2


#endif

