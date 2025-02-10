/************************************************************************
 *              �ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
 *   Copyright (C) 2020 Intewell Inc. All Rights Reserved.
 ***********************************************************************/

/*
 * �޸���ʷ��
 * 2023-11-20    �µ������ƶ�(����)����Ƽ����޹�˾
 *               �������ļ���
*/

#ifndef SYSTMR_H_
#define SYSTMR_H_

/************************ͷ�ļ�********************************/
#include <commonTypes.h>
#include <ttos.h>
#include <vmkIO.h>
#include <configTableUtils.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
/************************���Ͷ���******************************/

/*��ʱ��ģʽ*/
typedef enum 
{
	EM_TMR_MODE_NONE = 0,
    EM_TMR_MODE_PERIOD = 1,/*���ڶ�ʱ��ģʽ*/
    EM_TMR_MODE_CAPTURE = 2,/*���벶��ģʽ*/
    EM_TMR_MODE_ALL_USE = 3 /*ʹ������ģʽ*/
}EM_TMR_MODE;

typedef enum {
	EM_TMR_HF_CLK = 0,//400MHz
	EM_TMR_AHF_CLK,//400MHz��������EM_TMR_AHF_CLK�����ȸ�
	EM_TMR_LP_CLK,//24HMz
	EM_TMR_ERR_CLK
} EM_TMR_CLK_SRC_E;

typedef enum {
	EM_TMR_ID_G0,	//ͨ�ö�ʱ��G0
	EM_TMR_ID_G1,	//ͨ�ö�ʱ��G1
	EM_TMR_ID_A,	//��ʱ��ͨ��A��о��D9�弶ÿ���ⲿ��ʱ����4��ͨ���������ڲ�׽Ҳ���������ڶ�ʱ
	EM_TMR_ID_B,	//��ʱ��ͨ��B
	EM_TMR_ID_C,	//��ʱ��ͨ��C
	EM_TMR_ID_D,	//��ʱ��ͨ��D
	EM_TMR_ID_MAX_NUM
} EM_TMR_ID;

typedef enum {
	EM_TMR_CH_ID_A,	//��ʱ��ͨ��A��о��D9�弶ÿ���ⲿ��ʱ����4��ͨ���������ڲ�׽Ҳ���������ڶ�ʱ
	EM_TMR_CH_ID_B,	//��ʱ��ͨ��B
	EM_TMR_CH_ID_C,	//��ʱ��ͨ��C
	EM_TMR_CH_ID_D,	//��ʱ��ͨ��D
	EM_TMR_CH_ID_MAX_NUM
} EM_TMR_CH_ID;

//��ʱ������״̬
typedef enum{
	EM_TMR_PERIOD_TIMER_STATUS_STOP = 0,	//��ʱ��ֹͣ
	EM_TMR_PERIOD_TIMER_STATUS_START = 1	//��ʱ����ʼ
}EM_TMR_PERIOD_TIMER_STATUS;

//����ģʽ�����й��ڲ����źŵ����
typedef enum{
	EM_TMR_CPT_CFG_TRIG_MODE_RISING_EDGE = 0,	    //������
	EM_TMR_CPT_CFG_TRIG_MODE_FALLING_EDGE = 1,		//�½���
	EM_TMR_CPT_CFG_TRIG_MODE_SIGNAL_TOGGLE = 2		//˫����
}EM_TMR_CPT_CFG_TRIG_MODE;

//����ģʽʱ��Դѡ��
typedef enum{
	EM_TMR_CPT_CFG_CNT_SEL_G0 = 0,			//G0ͨ�ö�ʱ��Դ
	EM_TMR_CPT_CFG_CNT_SEL_G0_G1 = 1,	//G0+G1ͨ�ö�ʱ��Դ
	EM_TMR_CPT_CFG_CNT_SEL_LOCAL = 2,	//����ͨ������Դ,����ѡ���
}EM_TMR_CPT_CFG_CNT_SEL;

//����ģʽ�ж������������¼������ã����������ģʽ������������2�β����������һ�������¼�
//�Ҹ�ģʽ������single_mode=1��oneshot_mode=1�����������Ч
typedef enum{
	EM_TMR_CPT_CFG_DUAL_CPT_MODE_NONE = 0,
	EM_TMR_CPT_CFG_DUAL_CPT_MODE_OPEN = 1
}EM_TMR_CPT_CFG_DUAL_CPT_MODE;

//����ģʽ�����У������ö��Ϊ1��ֻ������һ��ʱ�䲶���¼���Ȼ���Զ����ʹ��λ
//�����ö��Ϊ0������������ֱ���л���ʱ��Ż����ʹ��λ
typedef enum{
	EM_TMR_CPT_CFG_ONESHOUT_MODE_NONE = 0,
	EM_TMR_CPT_CFG_ONESHOUT_MODE_OPEN = 1
}EM_TMR_CPT_CFG_ONESHOUT_MODE;




/*******************���Ʋ������忪ʼ*******************************/
/*
 * 	������壺TMR_IOC_SETCONFIG
 * 	������ܣ����ö�ʱ�����������ڶ�ʱ�����Լ�������
 * 	�����������T_DR_TMRConfig�ṹ��
 */
#define TMR_IOC_SETCONFIG 							(FIOLAST + 10)//���ö�ʱ�����������ڶ�ʱ�����Լ�������
#define TMR_IOC_GETCONFIG							(FIOLAST + 11)//Ԥ��

/*
 * 	������壺TMR_IOC_TIMER_START
 * 	������ܣ���ʱ����ʼ����
 * 	�����������T_DR_TMRControlConfig�ṹ��
 */
#define TMR_IOC_TIMER_START							(FIOLAST + 22)//��ʱ����ʼ����

/*
 * 	������壺TMR_IOC_TIMER_STOP
 * 	������ܣ���ʱ��ֹͣ����
 * 	�����������T_DR_TMRControlConfig�ṹ��
 */
#define TMR_IOC_TIMER_STOP							(FIOLAST + 23)//��ʱ��ֹͣ����

/*
 * 	������壺TMR_IOC_GET_TIMER_CHN_ORIGIN_CNT
 * 	������ܣ���ȡ��ǰ��ʱ��ͨ�������ڼ���ֵ
 * 	�����������T_DR_TMRChannelInfo�ṹ��
 */
#define TMR_IOC_GET_TIMER_CHN_ORIGIN_CNT			(FIOLAST + 24)//��ȡ��ǰ��ʱ��ͨ�������ڼ���ֵ

/*
 * 	������壺TMR_IOC_GET_TIMER_CHN_DURATION
 * 	������ܣ���ȡ��ǰ��ʱ��ͨ��origin����ֵ�����ڵ�΢����
 * 	�����������T_DR_TMRChannel_CntTimeIntervalInfo�ṹ��
 */
#define TMR_IOC_GET_TIMER_CHN_DURATION    		(FIOLAST + 25)//��ȡ��ǰ��ʱ��ͨ��origin����ֵ�����ڵ�΢����

/*
 * 	������壺TMR_IOC_TIMER_CHN_DELAY_ORIGIN
 * 	������ܣ���΢�붨ʱ��origin�����ӳ�usʱ�䣬�ӳ��ڼ������ж�
 * 	�����������T_DR_TMRChannel_DelayOriginCntInfo�ṹ��
 */
#define TMR_IOC_TIMER_CHN_DELAY_ORIGIN				(FIOLAST + 26)//��΢�붨ʱ��origin�����ӳ�usʱ��

/*******************���Ʋ����������*******************************/
/*��ʱ�����ڻص��ṹ��*/
typedef struct
{
	void (*irq_tmr_callback)(void *args);//���ڶ�ʱ�ص�����
	void *args;							 //�غ���������ֵ������Ϊ�ṹ��Ҳ����Ϊ����
}T_DR_TmrIrqCallback;


/*��ʱ��ͨ�����������ýṹ��*/
typedef struct
{
	EM_TMR_CPT_CFG_CNT_SEL							cpt_cnt_sel;		//���ò�����ʱ��Դ��һ�������õ�ǰ�Լ�ͨ��
	EM_TMR_CPT_CFG_TRIG_MODE						trig_mode;			//�źŲ�׽��ģʽ������˵��Ҫ��׽�����ػ����½���
	EM_TMR_CPT_CFG_DUAL_CPT_MODE					dual_cpt_mode;	//��������2�β���ֻ����һ������ʱ�䡣ֻ������SINGLE_MODE=1�����
	EM_TMR_CPT_CFG_ONESHOUT_MODE					oneshot_mode;	//ֻ����һ��ʱ�䲶���¼���Ȼ���Զ����ENλ
	u8							filter_dis;			//�����������ʹ��
	u8							filter_width;		//����������ã���Ҫ�����ù��˴���
	u32						first_cpt_rst_en;	//���ø�����ʱ��CNT_LOCAL_Xͨ���Ƚϻ򲶻��¼����ã�����鿴0x24�Ĵ���
	u8							sse_enable;		//�ϳ����湦��ʹ��
	u8							sse_cmp_chn;		//Ԥ�����ɲ�����
	u8         				dma_enable;		//Ԥ�����ɲ�����
	u8        			 		fifo_wml;			//Ԥ�����ɲ�����
}T_DR_TMRChannelConfig_Capture;

/*��ʱ��ͨ�����ýṹ��*/
typedef struct
{
		EM_TMR_MODE mode;			//��ǰ��ʱ��ģʽ
		u32 ovf_cnt;						//�����������ֵ
		u32 init_cnt;  						//��ʼ����ֵ
}T_DR_TMRChannelConfig;

/*��ʱ��ͨ������ֵ��Ϣ�ṹ��*/
typedef struct
{
		EM_TMR_CH_ID 		chn_id_input;				//Ҫ��ȡ��ʱ����Ϣ��ͨ��ID��ע�⣬�ò���Ϊ�������
		u32 						cur_cnt_output;			//��ǰ��ʱ������ͨ������ֵ
}T_DR_TMRChannelInfo;

/*��ȡ��������֮���΢����*/
typedef struct
{
		EM_TMR_CH_ID 		chn_id_input;				//Ҫ��ȡ��ʱ����Ϣ��ͨ��ID��ע�⣬�ò���Ϊ�������
		u32						origin_cnt_input;			//Ҫ����ļ���ֵ���������ֵ���ܴ��ڵ�ǰͨ�������ֵ����
		u32						cur_cnt_output;			//��ǰ��ʱ������ͨ������ֵ
		u32						timeInterVal_us_output;	//origin_cnt_input��cur_cnt_output��ʱ��������λus
}T_DR_TMRChannel_CntTimeIntervalInfo;

/*��ĳ��ʱ��ԭ�㿪ʼ�ӳ�*/
typedef struct
{
		EM_TMR_CH_ID 		chn_id_input;				//Ҫ��ȡ��ʱ����Ϣ��ͨ��ID��ע�⣬�ò���Ϊ�������
		u32						origin_cnt_input;			//Ҫ��ʱ��ʱ��ԭ�㣬�������ֵ���ܴ��ڵ�ǰͨ�������ֵ����
		u32						delay_us_input;			//��Ҫ��ʱ��ʱ��ԭ�㿪ʼ��Ҫ�ӳٵ�ʱ�䣬��λus
}T_DR_TMRChannel_DelayOriginCntInfo;

/*��ʱ�ṹ��*/
typedef struct
{
		EM_TMR_CH_ID 		chn_id_input;				//Ҫ��ȡ��ʱ����Ϣ��ͨ��ID��ע�⣬�ò���Ϊ�������
		u32						delay_us_input;			//�ӳٵ�ʱ�䣬��λus
}T_DR_TMRChannel_DelayInfo;

/*��ʱ���������ýṹ��*/
typedef struct
{
		u32 ovf_cnt;						//�����������ֵ
		u32 init_cnt;						//��ʼ����ֵ
		u32 time_out;						//�����������ֵ
		EM_TMR_CLK_SRC_E clk_sel;//��ǰ��ʱ��ʱ�Ӿ�������
		float cnt_per_ns;					//���ڱ�ʾÿ��������֮ǰ����΢��ֵ
		u32 clk_frq;						//��ʱ��Ƶ�ʣ�����ʵ��û�����ã���Ԥ����
		u32 clk_div;						//��Ƶϵ���漰���˶�ʱ�����ȣ�һ���Ƽ���Ƶϵ������3���ߵ���39
		u32 cascase_mode;				//G0��G1��ʱ������ģʽ�����ú�G0��G1��64λ����ʹ�ã����ǵ�ǰ���ã�����Ϊfalse����
		EM_TMR_ID tmr_id;				//��ǰҪʹ�õĶ�ʱ��ID
		T_DR_TMRChannelConfig 					channel_cfg[EM_TMR_CH_ID_MAX_NUM];
		T_DR_TmrIrqCallback 						callback[EM_TMR_CH_ID_MAX_NUM];	//�ص�����
		T_DR_TMRChannelConfig_Capture 		channel_cpt_info[EM_TMR_CH_ID_MAX_NUM];//����ģʽ����
		T_DR_TmrIrqCallback 						callback_func_capture[EM_TMR_CH_ID_MAX_NUM];	//�����ܻص�����
}T_DR_TMRConfig;


/*�������ƶ�ʱ������������ֹͣ�Ľṹ��*/
typedef struct
{
	EM_TMR_ID 		tmr_id;			//��ǰҪ���ƵĶ�ʱ��ͨ��ID
	u32 					time_out;		//�������ֵ
}T_DR_TMRControlConfig;

typedef struct
{
    T_BYTE name[DEVICE_NAME_SIZE];
    T_WORD index;
	
} T_DR_TMRConfigTable;

/*��ʱ������״̬�ṹ��*/
typedef struct
{
    T_UWORD flags;
    T_WORD major;
    T_WORD minor;
    T_UWORD status;
    T_DR_TMRConfigTable config;
} T_DR_TmrControl;



/************************�ӿ�����******************************/
/*
 * �������ƣ� tmr_initialize
 * ����˵������ʱ����ʼ�������������ں�̬ʹ��
 * ����˵����
 *			major  �����豸���
 *			minor  ���豸���
 *			arg    ����ָ�룬����Ϊ�ṹ��ָ�룬Ҳ����Ϊ����ָ��
 * ����ֵ��
 * 			����ִ�н��
 *ע��˵����
 *          ��
 * */
extern INT32 tmr_initialize(T_WORD major, T_WORD minor, T_VOID *arg);

/*
 * �������ƣ� tmr_open
 * ����˵������ʱ���򿪺��������û�̬ʹ��
 * ����˵����
 *			arg	   		�����豸������������û�̬posix�ӿ��в�����
 *			fileName    �豸�ļ�����һ��Ϊ��/TMR_3�����ַ�������ʾ��ʱ������TMR3
 *			flags       �豸������־��һ�������DM_FLAGS_READ_WRITE����ʾ�ɶ���д
 *			mode		ģʽ����ʱ����
 * ����ֵ��
 * 			����ִ�н��
 *ע��˵����
 *          ��
 * */
extern INT32 tmr_open(void *arg, UINT8 *fileName, INT32 flags, INT32 mode);

/*
 * �������ƣ� tmr_close
 * ����˵������ʱ���رպ��������û�̬ʹ��
 * ����˵����
 *			arg	   		�����豸���
 * ����ֵ��
 * 			����ִ�н��
 *ע��˵����
 *          ��
 * */
extern INT32 tmr_close(T_VOID *arg);

/*Ԥ����������ʱ��ʹ��*/
extern INT32 tmr_read(T_VOID *arg, T_BYTE *buffer, T_UWORD maxbytes);

/*Ԥ����������ʱ��ʹ��*/
extern INT32 tmr_write(T_VOID *arg, T_BYTE *buffer, T_UWORD nbytes);

/*
 * �������ƣ� tmr_control
 * ����˵������ʱ���رպ��������û�̬ʹ��
 * ����˵����
 *			args	   		�����豸���
 *			function		����Ĳ���ָ��
 *			arg				����ָ�룬���Դ���ṹ��ָ������Ǳ���ָ��
 * ����ֵ��
 * 			����ִ�н��
 *ע��˵����
 *          ��
 * */
extern INT32 tmr_control(T_VOID *args, T_WORD function, ADDRESS arg);
//extern T_WORD BSP_TMRGetDeviceNum(T_VOID);
//extern T_DR_TMRConfigTable* BSP_TMRGetConfigTable(T_VOID);

#define DR_TMR_DRIVER_ENTRY \
  { (T_DM_DeviceDriverInitEntry)tmr_initialize, (T_DM_DeviceDriverEntry)tmr_open, (T_DM_DeviceDriverEntry)tmr_close, \
    (T_DM_DeviceDriverEntry)tmr_read, (T_DM_DeviceDriverEntry)tmr_write, (T_DM_DeviceDriverEntry)tmr_control }

#ifdef __cplusplus
}
#endif /*__cplusplus*/
	
#endif /* SYSTMR_H_ */
