/***************************************************************************
*				�ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
* 	 Copyright (C) 2000-2022 CoreTek Systems Inc. All Rights Reserved.
***************************************************************************/
/**
* @file: imgHeader.h
* @brief:
*        <li>ӳ��ͷ����<li>
* @implements:
*/

#ifndef _IMHEADER_H
#define _IMHEADER_H

/************************ͷ �� ��******************************/

#include <imImageInfo.h>

/************************�� �� ��******************************/

/************************���Ͷ���******************************/

/************************�ⲿ��������******************************/


extern T_CHAR _text_start[];
extern T_CHAR store__text_size[];
extern T_CHAR _text_size[];
extern T_CHAR load__text_start[];

extern T_CHAR _data_start[];
extern T_CHAR store__data_size[];
extern T_CHAR _data_size[];
extern T_CHAR load__data_start[];

extern T_CHAR _bss_start[];
extern T_CHAR store__bss_size[];
extern T_CHAR _bss_size[];
extern T_CHAR load__bss_start[];

extern T_CHAR init_stack_start[];
extern T_CHAR store_init_stack_size[];
extern T_CHAR init_stack_size[];
extern T_CHAR load_init_stack_start[];

extern T_CHAR __exidx_start[];
extern T_CHAR store___exidx_size[];
extern T_CHAR __exidx_size[];
extern T_CHAR load___exidx_start[];

/************************ȫ�ֱ���******************************/

/*ӳ��ͷ����*/
T_TA_ImageInfo g_imageHeader __attribute__((__section__(".image_info"))) = 
{
	"rootAgent",/*ӳ����*/  
	"Version1",/*ӳ��汾*/  
	IMAGERUNTYPE_RAM,/*����λ��*/  
	1,/*ӳ������*/  
	5,  /*������*/  
	0x100000,  /*���е�ַ*/  
	IM_MAGIC_HEAD_NUMBER,  /*ħ��*/  
	/*������*/  
	{           
		/*������  �Ƿ���ص��ڴ�  ���ص��ڴ��еĵ�ַ(�����ַ)  ���е�ַ(�߼���ַ)  �洢�δ�С(bin�ļ���ռ�Ŀռ�)*/  
		{".text", TRUE,(T_ULONG)load__text_start, (T_ULONG)_text_start,(T_ULONG)store__text_size},
		{".data", TRUE,(T_ULONG)load__data_start, (T_ULONG)_data_start,(T_ULONG)store__data_size},
		{".bss", FALSE,(T_ULONG)load__bss_start, (T_ULONG)_bss_start,(T_ULONG)store__bss_size},
		{"init_stack", FALSE,(T_ULONG)load_init_stack_start, (T_ULONG)init_stack_start,(T_ULONG)store_init_stack_size},
		{".ARM", FALSE,(T_ULONG)load___exidx_start, (T_ULONG)__exidx_start,(T_ULONG)__exidx_size}
	}
};

#endif
