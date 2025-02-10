/***************************************************************************
*				�ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
* 	 Copyright (C) 2000-2024 CoreTek Systems Inc. All Rights Reserved.
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

extern T_CHAR _stack_origin[];
extern T_CHAR store__stack_size[];
extern T_CHAR _stack_size[];
extern T_CHAR load__stack_origin[];

/************************ȫ�ֱ���******************************/

/*ӳ��ͷ����*/
T_TA_ImageInfo g_imageHeader __attribute__((__section__(".image_info"))) = 
{
	"cfghv",/*ӳ����*/  
	"Version1",/*ӳ��汾*/  
	IMAGERUNTYPE_RAM,/*����λ��*/  
	0,/*ӳ������*/  
	3,  /*������*/  
	0x8f908000,  /*���е�ַ*/  
	IM_MAGIC_HEAD_NUMBER,  /*ħ��*/  
	/*������*/  
	{           
		/*������  �Ƿ���ص��ڴ�  ���ص��ڴ��еĵ�ַ(�����ַ)  ���е�ַ(�߼���ַ)  �洢�δ�С(bin�ļ���ռ�Ŀռ�)*/  
		{".text", TRUE,(T_ULONG)load__text_start, (T_ULONG)_text_start,(T_ULONG)store__text_size},
		{".data", TRUE,(T_ULONG)load__data_start, (T_ULONG)_data_start,(T_ULONG)store__data_size},
		{"init_stack", FALSE,(T_ULONG)load__stack_origin, (T_ULONG)_stack_origin,(T_ULONG)_stack_size}
	}
};

#endif
