/***********************************************************************
*	  �����������ɼ������޹�˾��Ȩ����
* 	 Copyright (C) 2000-2012 CoreTek Systems Inc. All Rights Reserved.
***********************************************************************/

/**
* @brief
 *	<li>�����Զ�����ƽ̨�����ͽṹ��</li>
 * @author 	caob
 * @date 	2012-12-25
 * <p>���ţ�����
 */

/*���ں������˽���������*/

#include <errno.h>
//#include <fstest.h>
typedef struct
{
    int isPass;              //���Խ��TEST_PASS~TEST_UNRESOLVED
    char retValue[100];            //�����нӿ���ʵ����ֵ
}T_TestResults;
#define printf printk
T_TestResults c_Results;
/*������ѧ������ֵ*/
#define NaN 0.0/0.0
#define MATH_PI 3.14159265358
#define MATH_PINF 1.0/0.0
#define MATH_NINF -1.0/0.0

/*������Է���ֵ*/
#define PTS_PASS         0
#define PTS_FAIL         1
#define PTS_ERROR        13467
#define AFILE_SUCCESS 0
#define TSTDEF_FAIL()	printk("***Test Failed,error: %d,filename: %s line: %d***\r\n",errno,__FILE__, __LINE__);
#define TSTDEF_FAILPRINT(err)	printk("***Test Failed,error: %d,filename: %s line: %d***\r\n",errno,__FILE__, __LINE__);
#define TEST_OKPRINT()			printk("***Test Pass***\r\n");
#define TEST_ERRFPRINT()  	printk("***Test Failed, error: %d, filename: %s line: %d***\r\n", errno, __FILE__, __LINE__);
#define DEFAULT_TASK_SIZE	0x2000
