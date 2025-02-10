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
		{("pageRamSpace"),(0x817e0000),(0x817e0000ull),(0x1600000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("taRamSpace"),(0x80000000),(0x80000000ull),(0x80000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("kernelRamSpace"),(0x802e0000),(0x802e0000ull),(0x1400000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("ethShareRamSpace"),(0x80080000),(0x80080000ull),(0x260000),(MM_DEFAULT_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("vectorSpace"),(0x816e0000),(0x816e0000ull),(0x100000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("heap"),(0x82de1000),(0x82de1000ull),(0x441f000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("spinApic"),(0x82de0000),(0x82de0000ull),(0x1000),(MM_DEFAULT_SYSTEM_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("configtableSpace"),(0x8f900000),(0x8f900000ull),(0x8000),(MM_DEFAULT_USER_RDONLY_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("virtualDevice"),(0x87200000),(0x87200000ull),(0x300000),(MM_DEFAULT_USER_DATA_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("shmRamSpace"),(0x87500000),(0x87500000ull),(0x4000000),(MM_DEFAULT_USER_DATA_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("IOSpace"),(0x28000000),(0x28000000ull),(0x10000000),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{("PCIE_CONF_1"),(0x40000000),(0x40000000ull),(0x40000000),(MM_DEFAULT_USER_IOADDR_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*分区空间配置*/


/*分区vm1配置*/
#define CONFIG_VM_SPACEBLOCKS_vm1    {\
		{("vm1RamSpace"),(0xc0000000),(0x90000000ull),(0x10000000),(MM_DEFAULT_USER_ATTR),(MM_PAGE_SIZE_4KB)}\
		,{"null",0,0,0,0,0}		}


/*分区数量*/
#define CONFIG_VMK_VM_NUMBER 1


#endif

