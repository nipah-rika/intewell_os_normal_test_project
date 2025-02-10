/***************************************************************************
*				�ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
* 	 Copyright (C) 2000-2023 CoreTek Systems Inc. All Rights Reserved.
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

extern T_CHAR _sidata_start[];
extern T_CHAR store__sidata_size[];
extern T_CHAR _sidata_size[];
extern T_CHAR load__sidata_start[];

extern T_CHAR _data_start[];
extern T_CHAR store__sidata_size[];
extern T_CHAR _sidata_size[];
extern T_CHAR load__data_start[];

extern T_CHAR _bss_start[];
extern T_CHAR store__bss_size[];
extern T_CHAR _bss_size[];
extern T_CHAR load__bss_start[];

extern T_CHAR init_stack_start[];
extern T_CHAR store_init_stack_size[];
extern T_CHAR init_stack_size[];
extern T_CHAR load_init_stack_start[];

/************************ȫ�ֱ���******************************/

/*ӳ��ͷ����*/
T_TA_ImageInfo g_imageHeader __attribute__((__section__(".image_info"))) = 
{
	"NewPre3102_TCP_Send_Recv_Test_Server",/*ӳ����*/  
	"Version1",/*ӳ��汾*/  
	IMAGERUNTYPE_RAM,/*����λ��*/  
	1,/*ӳ������*/  
	5,  /*������*/  
	0x40000000,  /*���е�ַ*/  
	IM_MAGIC_HEAD_NUMBER,  /*ħ��*/  
	/*������*/  
	{           
		/*������  �Ƿ���ص��ڴ�  ���ص��ڴ��еĵ�ַ(�����ַ)  ���е�ַ(�߼���ַ)  �洢�δ�С(bin�ļ���ռ�Ŀռ�)*/  
		{".text", TRUE,(T_ULONG)load__text_start, (T_ULONG)_text_start,(T_ULONG)store__text_size},
		{".sidata", FALSE,(T_ULONG)load__sidata_start, (T_ULONG)_sidata_start,(T_ULONG)store__sidata_size},
		{".data", TRUE,(T_ULONG)load__data_start, (T_ULONG)_data_start,(T_ULONG)store__sidata_size},
		{".bss", FALSE,(T_ULONG)load__bss_start, (T_ULONG)_bss_start,(T_ULONG)store__bss_size},
		{"init_stack", FALSE,(T_ULONG)load_init_stack_start, (T_ULONG)init_stack_start,(T_ULONG)init_stack_size}
	}
};

#endif
