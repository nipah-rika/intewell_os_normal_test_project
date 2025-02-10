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
#include <ttos.h>


/*获取TimeBase*/
/*//#define BUS_MHZ 66.0
//#define VMK_GET_TIME(v)((T_FLOAT)(v)/((T_FLOAT)BUS_MHZ/4.0))
//#define VMK_GET_TIMEBASEL() ({T_UWORD rval;\
//asm volatile("mftbl %0":"=r"(rval));rval;})*/

#define MSEC_PER_SEC			1000L
#define USEC_PER_MSEC			1000L
#define NSEC_PER_USEC			1000L
#define NSEC_PER_MSEC			1000000L
#define USEC_PER_SEC			1000000L
#define NSEC_PER_SEC			1000000000L
#define FSEC_PER_SEC			1000000000000000LL
#define HPET_ID					0x000
#define HPET_PERIOD				0x004
#define HPET_CFG				0x010
#define HPET_STATUS				0x020
#define HPET_COUNTER			0x0f0
#define cup_tick_time (double)1/2.8
#define TICK_TIME   ((double)0.3571)  /*每一个时钟脉冲的时间,单位是ns,与主频无关*/
//static  unsigned long long timerCountGet(void)
//{
//	 unsigned long long timeCount = *(volatile unsigned long long *)HP_TS_MN_CNTR;
//
//	return timeCount;
//}
//
//static  unsigned long long timeNsGet(unsigned long long deltaTime)
//{
//	unsigned long long tick_time = *(volatile unsigned long long *)(HPET_TIMESTAMP + HPET_PERIOD);
//	printf("tick_time = 0x%x\n",tick_time);
//
//	unsigned long long timeNs = deltaTime*tick_time/(FSEC_PER_SEC/NSEC_PER_SEC);
//	return timeNs;
//}
//#define printf printk
/*定义数学库特殊值*/
#define NaN 0.0/0.0
#define MATH_PI 3.14159265358
#define MATH_PINF 1.0/0.0
#define MATH_NINF -1.0/0.0
#define DEFAULT_TASK_SIZE 0x2000
/*定义测试返回值*/
#define PTS_PASS         11356
#define PTS_FAIL         15698
#define PTS_ERROR        13467

/*核心空间*/
#define KERNEL_RAM_START			0x400000
#define PAGE_RAM_START				0x600000


/*应用分区空间*/
#define P1_RAM_START				0xA000000
#define P2_RAM_START				0xB000000

#define P1_RAM_LOGIC_START			0x40000000
#define P2_RAM_LOGIC_START			0x40000000

#define P1_SHARE_MEM_LOGIC_START	0x4e000000
#define P2_SHARE_MEM_LOGIC_START	0x4e000000

#define P1_RAM_RDONLY_START				0x4d000000   //只读空间地址
#define P2_RAM_RDONLY_START				0x4d000000

#define T_VMK_VMStatus T_UWORD
/*共享内存*/
#define SHARE_MEM_START			0x1D2001000

#define TEST_OKPRINT()			printk("***Test Pass***\r\n");
#define TEST_ERRFPRINT(err)  	printk("***Test Failed, error: %d, filename: %s line: %d***\r\n", err, __FILE__, __LINE__);
#define TEST_FAILRINT()  	printk("***Test Failed, filename: %s line: %d***\r\n",  __FILE__, __LINE__);
