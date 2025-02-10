/***************************************************************************
*				科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2000-2024 CoreTek Systems Inc. All Rights Reserved.
***************************************************************************/
/**
* @file: imgHeader.h
* @brief:
*        <li>映像头定义<li>
* @implements:
*/

#ifndef _IMHEADER_H
#define _IMHEADER_H

/************************头 文 件******************************/

#include <imImageInfo.h>

/************************宏 定 义******************************/

/************************类型定义******************************/

/************************外部变量声明******************************/


extern T_CHAR _text_start[];
extern T_CHAR store__text_size[];
extern T_CHAR _text_size[];
extern T_CHAR load__text_start[];

extern T_CHAR _data_start[];
extern T_CHAR store__data_size[];
extern T_CHAR _data_size[];
extern T_CHAR load__data_start[];

extern T_CHAR _stack_origin[];
extern T_CHAR store__stack_size[];
extern T_CHAR _stack_size[];
extern T_CHAR load__stack_origin[];

/************************全局变量******************************/

/*映像头定义*/
T_TA_ImageInfo g_imageHeader __attribute__((__section__(".image_info"))) = 
{
	"cfghv",/*映像名*/  
	"Version1",/*映像版本*/  
	IMAGERUNTYPE_RAM,/*运行位置*/  
	0,/*映像类型*/  
	3,  /*段总数*/  
	0x8f908000,  /*运行地址*/  
	IM_MAGIC_HEAD_NUMBER,  /*魔数*/  
	/*段属性*/  
	{           
		/*段名称  是否加载到内存  加载到内存中的地址(物理地址)  运行地址(逻辑地址)  存储段大小(bin文件中占的空间)*/  
		{".text", TRUE,(T_ULONG)load__text_start, (T_ULONG)_text_start,(T_ULONG)store__text_size},
		{".data", TRUE,(T_ULONG)load__data_start, (T_ULONG)_data_start,(T_ULONG)store__data_size},
		{"init_stack", FALSE,(T_ULONG)load__stack_origin, (T_ULONG)_stack_origin,(T_ULONG)_stack_size}
	}
};

#endif
