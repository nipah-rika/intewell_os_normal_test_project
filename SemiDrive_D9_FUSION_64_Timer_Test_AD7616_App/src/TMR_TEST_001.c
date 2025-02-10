/*********************************************************************************
*				                                         科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2023 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * 修改历史：
 * 2023-12-14     陈丹鹏, 科东（广州）软件科技有限公司
 *                创建该文件。
 *
*/

/*
* @file：TMR_TEST_001.c
* @brief：
*	    <li>定时器驱动测试用例，TMR_TEST_START()是用户的入口函数。</li>
* @implements：
*/


/************************头 文 件******************************/
#include <commonTypes.h>
#include <commonTypes.h>
#include <compConfig.h>
#include <common.h>
#include <ttosInit.h>
#include <ftpApi.h>

#include "pthread.h"

#include <components/modbusIO.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sysTmr.h>
#include "AD7616.h"
/************************相关知识普及******************************/
/*一、菲森电力项目芯驰D9板级外部定时器硬件原理图整理情况：
 * 1、TMR1和TMR2:  safe安全域专用，不可操作；
 * 2、TMR3:  4个通道都用于SPI6的信号捕捉
 * 3、TMR4:  通道A和B用于UART9的信号捕捉，通道C和D空余，通道C和D可用于周期定时器功能
 * 4、TMR5:  通道A和B用于I2C9的信号捕捉，通道C和D空余，通道C和D可用于周期定时器功能
 * 5、TMR6:  通道A和B用于UART13的信号捕捉，通道C和D空余，通道C和D可用于周期定时器功能
 * 6、TMR7:  通道A用于GPS频率测试，通道B和C和D用于GPIO通道捕捉
 * 7、TMR8:  通道A和B用于RGMII2的信号捕捉，通道C和D空余，通道C和D可用于周期定时器功能
 *
 *
 *二、菲森电力项目芯驰D9板级外部定时器硬件BSP适配实际使用情况：
 * 1、TMR4:  通道C和D可用于周期定时器功能,菲森新版用通道A来同步测量频率
 * 2、TMR5:  通道A和B用于GPS信号捕捉
 * 3、TRM7:  通道A用于频率测量功能
 *
 * 三、当前测试用例定时器使用情况：
 *1、周期定时器功能：
 *（1）156us定时功能：使用TMR4的通道C
 *（2）5ms定时功能： 使用TMR4的通道D
 *2、捕捉功能：
 *（1）GPS信号捕获：使用TMR5的通道A和B
 *（2）交流电信号捕获：
 *（2-1）旧版：使用TMR7的通道A
 *（2-2）新版：使用TMR7的通道A和TMR4的通道A
 *
 *四、注意事项：
 * 由于官方例程不用使用G0和G1通用定时器作为周期定时使用，这里也不使用G0和G1定时器，避免不必要的麻烦
 *这里等调试新版本再新增交流电GPS信号TMR4通道A的使用
 *
 * */


/************************宏 定 义******************************/
//分频系数为40(即clk_div为39的情况)，时钟为400Mhz的情况下，一个时钟计数是100.5025ns，也就说0.5025ns的误差
//所以建议分频系数为40且时钟为400Mhz的情况下，5000ms的计数溢出配置为5000000/1005.025 = 49750, 156.25us的计数溢出配置为156250/100.5025=1555

//建议用分频系数为4，精度为高一些
//分频系数为4(即clk_div为3的情况)，时钟为400Mhz的情况下，一个时钟计数是10.05025ns，也就说0.00005025ms的误差
//所以建议分频系数为40且时钟为400Mhz的情况下，5000ms的计数溢出配置为5000000/10.05025 = 497500, 156.25us的计数溢出配置为156250/10.05025=15547
//但是结合调试数据，更精确的计数值如下：
//5000ms的计数溢出配置492300 - 1
//156.25us的计数溢出配置为15541-1比较合适

#define APP_OVF_CNT_5MS   492300 - 1
#define APP_OVF_CNT_156US   15541-1


//用来周期计数回调的结构体
struct tPeriodCntInfo
{
	u32 				irqCnt;					//中断计数
	T_UDWORD 	uwStartTimetamp;	//第一次周期中断的时间戳
	T_UDWORD 	uwEndTimetamp;		//第二次周期中断的时间戳
	T_UDWORD 	uwTime_us;			//两次捕获相差的时间间隔，单位为us
};


/************************类型定义******************************/
#define APP_TMR_DEBUG 0 //调试时候可打开
#ifdef APP_TMR_DEBUG
#define APP_TMR_DEBUG_PRINTK(fmt, args...) printk (fmt , ## args)
#define APP_TMR_INFO_PRINTK(fmt, args...) printk(fmt , ## args)
#define APP_TMR_ERROR_PRINTK(fmt, args...) printk(fmt , ## args)
#else
#define APP_TMR_DEBUG_PRINTK(fmt, args...)
#define APP_TMR_INFO_PRINTK(fmt, args...) printk(fmt , ## args)
#define APP_TMR_ERROR_PRINTK(fmt, args...) printk(fmt , ## args)
#endif

/************************外部声明******************************/
/************************前向声明******************************/
static struct  tPeriodCntInfo		g_tPeriodCntInfo_156us[1];	//周期定时器回调使用
static int		g_iTmrFd_period;				//用来做156us和5ms周期计数
/********************************客户定制函数开始***************************************************/
/*
 *   函数：pit_156us_isr
 *   功能：156us周期计数定时器捕获回调函数。
 *   参数：
 *   	   data 输入参数，用户层输入的参数指针，比如说可以传一个结构体数组用来计算当前的中断数量，用于日志打印
 *   返回：
 *              无
 */
int _Cnt=0;
void pit_156us_isr(void *data)
{
	ad7616_info_t *info = (ad7616_info_t *)data;
	printk("\t pit_156us_isr cnt:%d\r\n",_Cnt++);
	ad7616_sample_test(info);
}

/********************************客户定制函数结束***************************************************/

/************************模块变量******************************/

/************************全局变量******************************/
/************************实   现*******************************/

//设置周期定时器功能，用来配置156us和5ms周期计数定时器功能
int TMR_SET_TMR_156us(ad7616_info_t *info)
{
		int l_iRet = 0;
		printk("[app][%s]%d  start\n", __func__,__LINE__);
		T_DR_TMRConfig l_stTmrConfig[1] = {0};
		T_DR_TMRControlConfig l_stTmrControlConfig[2] = {0};

		//这里用定时器3的通道1和通道2做周期定时
		g_iTmrFd_period =  open("/TMR_4", DM_FLAGS_READ_WRITE);
		if( -1 == g_iTmrFd_period)
		{
			printk("[app][%s]%d g_iTmrFd_period open err\n", __func__,__LINE__);
		}
		printk("[app][%s]%d g_iTmrFd_period  :%d\n", __func__,__LINE__, g_iTmrFd_period );

		//先配置通用配置
		l_stTmrConfig[0].clk_frq= 400000000;
		l_stTmrConfig[0].clk_div= 3;
	    l_stTmrConfig[0].clk_sel = EM_TMR_AHF_CLK;//定时器时钟频率
		l_stTmrConfig[0].cascase_mode = false;

		//配置通道C通用配置,做为156us定时器配置
		l_stTmrConfig[0].channel_cfg[EM_TMR_CH_ID_C].mode =  EM_TMR_MODE_PERIOD;
		l_stTmrConfig[0].callback[EM_TMR_CH_ID_C].irq_tmr_callback = pit_156us_isr;
		l_stTmrConfig[0].callback[EM_TMR_CH_ID_C].args = info;
		l_stTmrConfig[0].channel_cfg[EM_TMR_CH_ID_C].init_cnt = 0;
		l_stTmrConfig[0].channel_cfg[EM_TMR_CH_ID_C].ovf_cnt= APP_OVF_CNT_156US;


		//进行配置，并开始定时器
		l_iRet = ioctl(g_iTmrFd_period, TMR_IOC_SETCONFIG , l_stTmrConfig);
		printk("[app][%s]%d  ioctl( TMR_IOC_SETCONFIG)=>l_iRet :%d\n", __func__,__LINE__, l_iRet );

		g_tPeriodCntInfo_156us[0].uwStartTimetamp =  TTOS_GetCurrentSystemCount();

		//启动周期周期定时器
		l_stTmrControlConfig[0].tmr_id = EM_TMR_ID_C;
		l_stTmrControlConfig[0].time_out =APP_OVF_CNT_156US;
		l_iRet = ioctl(g_iTmrFd_period, TMR_IOC_TIMER_START, &l_stTmrControlConfig[0] );
		printk("[app][%s]%d  ioctl( TMR_IOC_TIMER_START)=>TMR_CH_ID_C l_iRet :%d\n", __func__,__LINE__, l_iRet );

		return 0;
}

