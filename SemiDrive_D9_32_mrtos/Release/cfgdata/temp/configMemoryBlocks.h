/***************************************************************************
*				科东(广州)软件科技有限公司 版权所有
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
		{("pageRamSpace"),(0x717e0000),(0x717e0000ull),(0x1600000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("taRamSpace"),(0x70000000),(0x70000000ull),(0x80000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("kernelRamSpace"),(0x702e0000),(0x702e0000ull),(0x1400000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("ethShareRamSpace"),(0x70080000),(0x70080000ull),(0x260000),(MM_DEFAULT_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("vectorSpace"),(0x716e0000),(0x716e0000ull),(0x100000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("heap"),(0x72de1000),(0x72de1000ull),(0x2000000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("spinApic"),(0x72de0000),(0x72de0000ull),(0x1000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("configtableSpace"),(0x7f900000),(0x7f900000ull),(0x8000),(MM_DEFAULT_USER_RDONLY_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("virtualDevice"),(0x74de1000),(0x74de1000ull),(0x900000),(MM_DEFAULT_USER_DATA_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("shmRamSpace"),(0x756e1000),(0x756e1000ull),(0x4000000),(MM_DEFAULT_USER_DATA_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("IOSpace"),(0x30000000),(0x30000000ull),(0xc500000),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*分区空间配置*/


/*分区rootAgent配置*/
#define CONFIG_VM_SPACEBLOCKS_rootAgent    {\
		{("rootAgentRamSpace"),(0xc0000000),(0x80000000ull),(0x18000000),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*分区vm1配置*/
#define CONFIG_VM_SPACEBLOCKS_vm1    {\
		{("vm1RamSpace"),(0xc0000000),(0x98000000ull),(0x6400000),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*分区vm2配置*/
#define CONFIG_VM_SPACEBLOCKS_vm2    {\
		{("vm2RamSpace"),(0xc0000000),(0x9e400000ull),(0x6400000),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*分区数量*/
#define CONFIG_VMK_VM_NUMBER 3


#endif

