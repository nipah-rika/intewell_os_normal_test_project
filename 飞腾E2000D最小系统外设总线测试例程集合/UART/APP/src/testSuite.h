/***********************************************************************
*	  北京科银京成技术有限公司版权所有
* 	 Copyright (C) 2000-2012 CoreTek Systems Inc. All Rights Reserved.
***********************************************************************/

/**
* @brief
 *	<li>定义自动测试平台所需宏和结构体</li>
 * @author 	caob
 * @date 	2012-12-25
 * <p>部门：三室
 */

/*用于和主机端交换的数据*/

#include <errno.h>
//#include <fstest.h>
typedef struct
{
    int isPass;              //测试结果TEST_PASS~TEST_UNRESOLVED
    char retValue[100];            //测试中接口真实返回值
}T_TestResults;
#define printf printk
T_TestResults c_Results;
/*定义数学库特殊值*/
#define NaN 0.0/0.0
#define MATH_PI 3.14159265358
#define MATH_PINF 1.0/0.0
#define MATH_NINF -1.0/0.0

/*定义测试返回值*/
#define PTS_PASS         0
#define PTS_FAIL         1
#define PTS_ERROR        13467
#define AFILE_SUCCESS 0
#define TSTDEF_FAIL()	printk("***Test Failed,error: %d,filename: %s line: %d***\r\n",errno,__FILE__, __LINE__);
#define TSTDEF_FAILPRINT(err)	printk("***Test Failed,error: %d,filename: %s line: %d***\r\n",errno,__FILE__, __LINE__);
#define TEST_OKPRINT()			printk("***Test Pass***\r\n");
#define TEST_ERRFPRINT()  	printk("***Test Failed, error: %d, filename: %s line: %d***\r\n", errno, __FILE__, __LINE__);
#define DEFAULT_TASK_SIZE	0x2000
