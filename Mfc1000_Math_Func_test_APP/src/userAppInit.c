/*********************************************************************************
 *				                                         �ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
 * 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
 **********************************************************************************/

/*
 * �޸���ʷ��
 * 2017-05-10     ����, �ƶ������ݣ�����Ƽ����޹�˾
 *                �������ļ���
 *                
 */

/*
 * @file��userAppInit.c
 * @brief��
 *	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
 * @implements��
 */

/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include<stdio.h>
#include<math.h>

/************************�� �� ��******************************/
#define PI 3.1415926
#define RAD PI/180

/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/


int userAppInit(void) {
	double x = 45 * RAD; // ����
	double sinx = sin(x);		// ��������ֵ
	double cosx = cos(x);		// ��������ֵ
	double asinx = asin(sinx);//���㷴����ֵ
	double acosx = acos(sinx);//���㷴����ֵ
	double atanx = atan(sinx);//���㷴����ֵ

	printf("sinx : %f\n", sinx);
	printf("cosx : %f\n", cosx);
	printf("asinx : %f\n", asinx);
	printf("acosx : %f\n", acosx);
	printf("atanx : %f\n", atanx);
	if (x != PI / 2) {
		double tanx = tan(x);		// ��������ֵ
		printf("tanx : %f\n", tanx);
	} else {
		printf(" error tan 90 is not exist\n");

	}

	printf("squared : %f\n",pow(4, 2)); 		// 4��ƽ��
	printf("%f\n",pow(4, 3)); 		// 4������
	printf("%f\n",sqrt(1024)); 		// 1024��ƽ����
	printf("%f\n", fabs(-3434351));		// ����ֵ
	printf("%f\n", ceil(-0.55));		// ����ȡ��
	printf("%f\n", floor(-0.55));	// ����ȡ��
	printf("%f\n", fmod(10, 3));	// ȡ�ࣨģ���㣩
	printf("%f\n", log(8));	// �����

	return 0;
}

