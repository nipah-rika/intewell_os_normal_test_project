/*********************************************************************************
*				                                         �ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
* 	 Copyright (C) 2023 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * �޸���ʷ��
 * 2023-12-14     �µ���, �ƶ������ݣ�����Ƽ����޹�˾
 *                �������ļ���
 *
*/

/*
* @file��TMR_TEST_001.c
* @brief��
*	    <li>��ʱ����������������TMR_TEST_START()���û�����ں�����</li>
* @implements��
*/


/************************ͷ �� ��******************************/
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
/************************���֪ʶ�ռ�******************************/
/*һ����ɭ������Ŀо��D9�弶�ⲿ��ʱ��Ӳ��ԭ��ͼ���������
 * 1��TMR1��TMR2:  safe��ȫ��ר�ã����ɲ�����
 * 2��TMR3:  4��ͨ��������SPI6���źŲ�׽
 * 3��TMR4:  ͨ��A��B����UART9���źŲ�׽��ͨ��C��D���࣬ͨ��C��D���������ڶ�ʱ������
 * 4��TMR5:  ͨ��A��B����I2C9���źŲ�׽��ͨ��C��D���࣬ͨ��C��D���������ڶ�ʱ������
 * 5��TMR6:  ͨ��A��B����UART13���źŲ�׽��ͨ��C��D���࣬ͨ��C��D���������ڶ�ʱ������
 * 6��TMR7:  ͨ��A����GPSƵ�ʲ��ԣ�ͨ��B��C��D����GPIOͨ����׽
 * 7��TMR8:  ͨ��A��B����RGMII2���źŲ�׽��ͨ��C��D���࣬ͨ��C��D���������ڶ�ʱ������
 *
 *
 *������ɭ������Ŀо��D9�弶�ⲿ��ʱ��Ӳ��BSP����ʵ��ʹ�������
 * 1��TMR4:  ͨ��C��D���������ڶ�ʱ������,��ɭ�°���ͨ��A��ͬ������Ƶ��
 * 2��TMR5:  ͨ��A��B����GPS�źŲ�׽
 * 3��TRM7:  ͨ��A����Ƶ�ʲ�������
 *
 * ������ǰ����������ʱ��ʹ�������
 *1�����ڶ�ʱ�����ܣ�
 *��1��156us��ʱ���ܣ�ʹ��TMR4��ͨ��C
 *��2��5ms��ʱ���ܣ� ʹ��TMR4��ͨ��D
 *2����׽���ܣ�
 *��1��GPS�źŲ���ʹ��TMR5��ͨ��A��B
 *��2���������źŲ���
 *��2-1���ɰ棺ʹ��TMR7��ͨ��A
 *��2-2���°棺ʹ��TMR7��ͨ��A��TMR4��ͨ��A
 *
 *�ġ�ע�����
 * ���ڹٷ����̲���ʹ��G0��G1ͨ�ö�ʱ����Ϊ���ڶ�ʱʹ�ã�����Ҳ��ʹ��G0��G1��ʱ�������ⲻ��Ҫ���鷳
 *����ȵ����°汾������������GPS�ź�TMR4ͨ��A��ʹ��
 *
 * */


/************************�� �� ��******************************/
//��Ƶϵ��Ϊ40(��clk_divΪ39�����)��ʱ��Ϊ400Mhz������£�һ��ʱ�Ӽ�����100.5025ns��Ҳ��˵0.5025ns�����
//���Խ����Ƶϵ��Ϊ40��ʱ��Ϊ400Mhz������£�5000ms�ļ����������Ϊ5000000/1005.025 = 49750, 156.25us�ļ����������Ϊ156250/100.5025=1555

//�����÷�Ƶϵ��Ϊ4������Ϊ��һЩ
//��Ƶϵ��Ϊ4(��clk_divΪ3�����)��ʱ��Ϊ400Mhz������£�һ��ʱ�Ӽ�����10.05025ns��Ҳ��˵0.00005025ms�����
//���Խ����Ƶϵ��Ϊ40��ʱ��Ϊ400Mhz������£�5000ms�ļ����������Ϊ5000000/10.05025 = 497500, 156.25us�ļ����������Ϊ156250/10.05025=15547
//���ǽ�ϵ������ݣ�����ȷ�ļ���ֵ���£�
//5000ms�ļ����������492300 - 1
//156.25us�ļ����������Ϊ15541-1�ȽϺ���

#define APP_OVF_CNT_5MS   492300 - 1
#define APP_OVF_CNT_156US   15541-1


//�������ڼ����ص��Ľṹ��
struct tPeriodCntInfo
{
	u32 				irqCnt;					//�жϼ���
	T_UDWORD 	uwStartTimetamp;	//��һ�������жϵ�ʱ���
	T_UDWORD 	uwEndTimetamp;		//�ڶ��������жϵ�ʱ���
	T_UDWORD 	uwTime_us;			//���β�������ʱ��������λΪus
};


/************************���Ͷ���******************************/
#define APP_TMR_DEBUG 0 //����ʱ��ɴ�
#ifdef APP_TMR_DEBUG
#define APP_TMR_DEBUG_PRINTK(fmt, args...) printk (fmt , ## args)
#define APP_TMR_INFO_PRINTK(fmt, args...) printk(fmt , ## args)
#define APP_TMR_ERROR_PRINTK(fmt, args...) printk(fmt , ## args)
#else
#define APP_TMR_DEBUG_PRINTK(fmt, args...)
#define APP_TMR_INFO_PRINTK(fmt, args...) printk(fmt , ## args)
#define APP_TMR_ERROR_PRINTK(fmt, args...) printk(fmt , ## args)
#endif

/************************�ⲿ����******************************/
/************************ǰ������******************************/
static struct  tPeriodCntInfo		g_tPeriodCntInfo_156us[1];	//���ڶ�ʱ���ص�ʹ��
static int		g_iTmrFd_period;				//������156us��5ms���ڼ���
/********************************�ͻ����ƺ�����ʼ***************************************************/
/*
 *   ������pit_156us_isr
 *   ���ܣ�156us���ڼ�����ʱ������ص�������
 *   ������
 *   	   data ����������û�������Ĳ���ָ�룬����˵���Դ�һ���ṹ�������������㵱ǰ���ж�������������־��ӡ
 *   ���أ�
 *              ��
 */
int _Cnt=0;
void pit_156us_isr(void *data)
{
	ad7616_info_t *info = (ad7616_info_t *)data;
	printk("\t pit_156us_isr cnt:%d\r\n",_Cnt++);
	ad7616_sample_test(info);
}

/********************************�ͻ����ƺ�������***************************************************/

/************************ģ�����******************************/

/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

//�������ڶ�ʱ�����ܣ���������156us��5ms���ڼ�����ʱ������
int TMR_SET_TMR_156us(ad7616_info_t *info)
{
		int l_iRet = 0;
		printk("[app][%s]%d  start\n", __func__,__LINE__);
		T_DR_TMRConfig l_stTmrConfig[1] = {0};
		T_DR_TMRControlConfig l_stTmrControlConfig[2] = {0};

		//�����ö�ʱ��3��ͨ��1��ͨ��2�����ڶ�ʱ
		g_iTmrFd_period =  open("/TMR_4", DM_FLAGS_READ_WRITE);
		if( -1 == g_iTmrFd_period)
		{
			printk("[app][%s]%d g_iTmrFd_period open err\n", __func__,__LINE__);
		}
		printk("[app][%s]%d g_iTmrFd_period  :%d\n", __func__,__LINE__, g_iTmrFd_period );

		//������ͨ������
		l_stTmrConfig[0].clk_frq= 400000000;
		l_stTmrConfig[0].clk_div= 3;
	    l_stTmrConfig[0].clk_sel = EM_TMR_AHF_CLK;//��ʱ��ʱ��Ƶ��
		l_stTmrConfig[0].cascase_mode = false;

		//����ͨ��Cͨ������,��Ϊ156us��ʱ������
		l_stTmrConfig[0].channel_cfg[EM_TMR_CH_ID_C].mode =  EM_TMR_MODE_PERIOD;
		l_stTmrConfig[0].callback[EM_TMR_CH_ID_C].irq_tmr_callback = pit_156us_isr;
		l_stTmrConfig[0].callback[EM_TMR_CH_ID_C].args = info;
		l_stTmrConfig[0].channel_cfg[EM_TMR_CH_ID_C].init_cnt = 0;
		l_stTmrConfig[0].channel_cfg[EM_TMR_CH_ID_C].ovf_cnt= APP_OVF_CNT_156US;


		//�������ã�����ʼ��ʱ��
		l_iRet = ioctl(g_iTmrFd_period, TMR_IOC_SETCONFIG , l_stTmrConfig);
		printk("[app][%s]%d  ioctl( TMR_IOC_SETCONFIG)=>l_iRet :%d\n", __func__,__LINE__, l_iRet );

		g_tPeriodCntInfo_156us[0].uwStartTimetamp =  TTOS_GetCurrentSystemCount();

		//�����������ڶ�ʱ��
		l_stTmrControlConfig[0].tmr_id = EM_TMR_ID_C;
		l_stTmrControlConfig[0].time_out =APP_OVF_CNT_156US;
		l_iRet = ioctl(g_iTmrFd_period, TMR_IOC_TIMER_START, &l_stTmrControlConfig[0] );
		printk("[app][%s]%d  ioctl( TMR_IOC_TIMER_START)=>TMR_CH_ID_C l_iRet :%d\n", __func__,__LINE__, l_iRet );

		return 0;
}

