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
		{("pageRamSpace"),(0xa17e0000ull),(0xa17e0000ull),(0x1600000ull),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("taRamSpace"),(0xa0000000ull),(0xa0000000ull),(0x80000ull),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("kernelRamSpace"),(0xa02e0000ull),(0xa02e0000ull),(0x1400000ull),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("ethShareRamSpace"),(0xa0080000ull),(0xa0080000ull),(0x260000ull),(MM_DEFAULT_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("vectorSpace"),(0xa16e0000ull),(0xa16e0000ull),(0x100000ull),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("heap"),(0xa2de1000ull),(0xa2de1000ull),(0x441f000ull),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("spinApic"),(0xa2de0000ull),(0xa2de0000ull),(0x1000ull),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("configtableSpace"),(0xaf900000ull),(0xaf900000ull),(0x8000ull),(MM_DEFAULT_USER_RDONLY_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("virtualDevice"),(0xa7200000ull),(0xa7200000ull),(0x900000ull),(MM_DEFAULT_USER_DATA_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("shmRamSpace"),(0xa7b00000ull),(0xa7b00000ull),(0x4000000ull),(MM_DEFAULT_USER_DATA_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("IOSpace"),(0x28000000ull),(0x28000000ull),(0x10000000ull),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("PCIE_CONF_1"),(0x40000000ull),(0x40000000ull),(0x40000000ull),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0ull,0ull,0ull,0ull,0ull}		}


/*�����ռ�����*/


/*����rootAgent����*/
#define CONFIG_VM_SPACEBLOCKS_rootAgent    {\
		{("rootAgentRamSpace"),(0xfffffff400000000ull),(0xb0000000ull),(0x8000000ull),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0ull,0ull,0ull,0ull,0ull}		}


/*����vm1����*/
#define CONFIG_VM_SPACEBLOCKS_vm1    {\
		{("vm1RamSpace"),(0xfffffff400000000ull),(0xb8000000ull),(0x8000000ull),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0ull,0ull,0ull,0ull,0ull}		}


/*��������*/
#define CONFIG_VMK_VM_NUMBER 2


#endif

