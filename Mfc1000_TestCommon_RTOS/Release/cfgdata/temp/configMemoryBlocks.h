/***************************************************************************
*				北京科银京成技术有限公司 版权所有
* 	 Copyright (C) 2011 CoreTek Systems Inc. All Rights Reserved.
***************************************************************************/
/**
* @file: configMemoryBlocks.h
* @brief:
*        <li>空间配置定义<li>
* @implements:
*/
#ifndef _CONFIGMEMORYBLOCK_H
#define _CONFIGMEMORYBLOCK_H


/************************头 文 件******************************/


/************************外部声明******************************/


/************************模块变量******************************/


/************************全局变量******************************/


/************************宏 定 义******************************/

/*核心空间配置*/
#define CONFIG_VMK_SPACEBLOCKS    {\
		{("pageRamSpace"),(0x1900000),(0x1900000ull),(0x1600000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("taRamSpace"),(0x120000),(0x120000ull),(0x80000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("kernelRamSpace"),(0x400000),(0x400000ull),(0x1400000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("ethShareRamSpace"),(0x1a0000),(0x1a0000ull),(0x260000),(MM_DEFAULT_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("VgaSpace"),(0xb8000),(0xb8000ull),(0x10000),(MM_DEFAULT_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("smparg"),(0x1000),(0x1000ull),(0x1000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("localApic"),(0xfee00000),(0xfee00000ull),(0x1000),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("IOAPIC"),(0xfec00000),(0xfec00000ull),(0x1000),(MM_DEFAULT_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("cpuentry"),(0x42000),(0x42000ull),(0x1000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("vectorSpace"),(0x1800000),(0x1800000ull),(0x100000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("heap"),(0x2f01000),(0x2f01000ull),(0x2000000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("spinApic"),(0x2f00000),(0x2f00000ull),(0x1000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("configtableSpace"),(0xba20000),(0xba20000ull),(0x8000),(MM_DEFAULT_USER_RDONLY_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("hpetSpace"),(0xfed00000),(0xfed00000ull),(0x4000),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("virtualDevice"),(0x4f01000),(0x4f01000ull),(0x300000),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*分区空间配置*/


/*分区vm1配置*/
#define CONFIG_VM_SPACEBLOCKS_vm1    {\
		{("vm1RamSpace"),(0x40000000),(0x40000000ull),(0x1f400000),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*分区数量*/
#define CONFIG_VMK_VM_NUMBER 1


#endif

