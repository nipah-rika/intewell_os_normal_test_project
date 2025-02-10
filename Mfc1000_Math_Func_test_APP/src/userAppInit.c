/*********************************************************************************
 *				                                         科东(广州)软件科技有限公司 版权所有
 * 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
 **********************************************************************************/

/*
 * 修改历史：
 * 2017-05-10     李燕, 科东（广州）软件科技有限公司
 *                创建该文件。
 *                
 */

/*
 * @file：userAppInit.c
 * @brief：
 *	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
 * @implements：
 */

/************************头 文 件******************************/
#include <commonTypes.h>
#include<stdio.h>
#include<math.h>

/************************宏 定 义******************************/
#define PI 3.1415926
#define RAD PI/180

/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/


int userAppInit(void) {
	double x = 45 * RAD; // 弧度
	double sinx = sin(x);		// 计算正弦值
	double cosx = cos(x);		// 计算余弦值
	double asinx = asin(sinx);//计算反正弦值
	double acosx = acos(sinx);//计算反余弦值
	double atanx = atan(sinx);//计算反正切值

	printf("sinx : %f\n", sinx);
	printf("cosx : %f\n", cosx);
	printf("asinx : %f\n", asinx);
	printf("acosx : %f\n", acosx);
	printf("atanx : %f\n", atanx);
	if (x != PI / 2) {
		double tanx = tan(x);		// 计算正切值
		printf("tanx : %f\n", tanx);
	} else {
		printf(" error tan 90 is not exist\n");

	}

	printf("squared : %f\n",pow(4, 2)); 		// 4的平方
	printf("%f\n",pow(4, 3)); 		// 4的立方
	printf("%f\n",sqrt(1024)); 		// 1024开平方根
	printf("%f\n", fabs(-3434351));		// 绝对值
	printf("%f\n", ceil(-0.55));		// 向上取整
	printf("%f\n", floor(-0.55));	// 向下取整
	printf("%f\n", fmod(10, 3));	// 取余（模运算）
	printf("%f\n", log(8));	// 求对数

	return 0;
}

