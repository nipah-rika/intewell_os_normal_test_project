/************************************************************************
 *              科东(广州)软件科技有限公司 版权所有
 *   Copyright (C) 2020 Intewell Inc. All Rights Reserved.
 ***********************************************************************/

/*
 * 修改历史：
 * 2023-11-20    陈丹鹏，科东(广州)软件科技有限公司
 *               创建该文件。
*/

#ifndef SYSTMR_H_
#define SYSTMR_H_

/************************头文件********************************/
#include <commonTypes.h>
#include <ttos.h>
#include <vmkIO.h>
#include <configTableUtils.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
/************************类型定义******************************/

/*定时器模式*/
typedef enum 
{
	EM_TMR_MODE_NONE = 0,
    EM_TMR_MODE_PERIOD = 1,/*周期定时器模式*/
    EM_TMR_MODE_CAPTURE = 2,/*输入捕获模式*/
    EM_TMR_MODE_ALL_USE = 3 /*使用所有模式*/
}EM_TMR_MODE;

typedef enum {
	EM_TMR_HF_CLK = 0,//400MHz
	EM_TMR_AHF_CLK,//400MHz，建议用EM_TMR_AHF_CLK，精度高
	EM_TMR_LP_CLK,//24HMz
	EM_TMR_ERR_CLK
} EM_TMR_CLK_SRC_E;

typedef enum {
	EM_TMR_ID_G0,	//通用定时器G0
	EM_TMR_ID_G1,	//通用定时器G1
	EM_TMR_ID_A,	//定时器通道A，芯驰D9板级每个外部定时器有4个通道，可用于捕捉也可用于周期定时
	EM_TMR_ID_B,	//定时器通道B
	EM_TMR_ID_C,	//定时器通道C
	EM_TMR_ID_D,	//定时器通道D
	EM_TMR_ID_MAX_NUM
} EM_TMR_ID;

typedef enum {
	EM_TMR_CH_ID_A,	//定时器通道A，芯驰D9板级每个外部定时器有4个通道，可用于捕捉也可用于周期定时
	EM_TMR_CH_ID_B,	//定时器通道B
	EM_TMR_CH_ID_C,	//定时器通道C
	EM_TMR_CH_ID_D,	//定时器通道D
	EM_TMR_CH_ID_MAX_NUM
} EM_TMR_CH_ID;

//定时器周期状态
typedef enum{
	EM_TMR_PERIOD_TIMER_STATUS_STOP = 0,	//定时器停止
	EM_TMR_PERIOD_TIMER_STATUS_START = 1	//定时器开始
}EM_TMR_PERIOD_TIMER_STATUS;

//捕获模式配置中关于捕获信号的类别
typedef enum{
	EM_TMR_CPT_CFG_TRIG_MODE_RISING_EDGE = 0,	    //上升沿
	EM_TMR_CPT_CFG_TRIG_MODE_FALLING_EDGE = 1,		//下降沿
	EM_TMR_CPT_CFG_TRIG_MODE_SIGNAL_TOGGLE = 2		//双边沿
}EM_TMR_CPT_CFG_TRIG_MODE;

//捕获模式时钟源选择
typedef enum{
	EM_TMR_CPT_CFG_CNT_SEL_G0 = 0,			//G0通用定时器源
	EM_TMR_CPT_CFG_CNT_SEL_G0_G1 = 1,	//G0+G1通用定时器源
	EM_TMR_CPT_CFG_CNT_SEL_LOCAL = 2,	//功能通道自身源,建议选这个
}EM_TMR_CPT_CFG_CNT_SEL;

//捕获模式中对于连续捕获事件的配置，如果开启此模式，对于了连续2次捕获会中生成一个捕获事件
//且该模式仅仅在single_mode=1（oneshot_mode=1）的情况下生效
typedef enum{
	EM_TMR_CPT_CFG_DUAL_CPT_MODE_NONE = 0,
	EM_TMR_CPT_CFG_DUAL_CPT_MODE_OPEN = 1
}EM_TMR_CPT_CFG_DUAL_CPT_MODE;

//捕获模式配置中，如果该枚举为1，只会生成一个时间捕获事件，然后自动清除使能位
//如果该枚举为0，会连续捕获，直到切换的时候才会清除使能位
typedef enum{
	EM_TMR_CPT_CFG_ONESHOUT_MODE_NONE = 0,
	EM_TMR_CPT_CFG_ONESHOUT_MODE_OPEN = 1
}EM_TMR_CPT_CFG_ONESHOUT_MODE;




/*******************控制参数定义开始*******************************/
/*
 * 	控制项定义：TMR_IOC_SETCONFIG
 * 	控制项功能：设置定时器，包括周期定时功能以及捕获功能
 * 	控制项参数：T_DR_TMRConfig结构体
 */
#define TMR_IOC_SETCONFIG 							(FIOLAST + 10)//设置定时器，包括周期定时功能以及捕获功能
#define TMR_IOC_GETCONFIG							(FIOLAST + 11)//预留

/*
 * 	控制项定义：TMR_IOC_TIMER_START
 * 	控制项功能：定时器开始工作
 * 	控制项参数：T_DR_TMRControlConfig结构体
 */
#define TMR_IOC_TIMER_START							(FIOLAST + 22)//定时器开始工作

/*
 * 	控制项定义：TMR_IOC_TIMER_STOP
 * 	控制项功能：定时器停止工作
 * 	控制项参数：T_DR_TMRControlConfig结构体
 */
#define TMR_IOC_TIMER_STOP							(FIOLAST + 23)//定时器停止工作

/*
 * 	控制项定义：TMR_IOC_GET_TIMER_CHN_ORIGIN_CNT
 * 	控制项功能：获取当前定时器通道的周期计数值
 * 	控制项参数：T_DR_TMRChannelInfo结构体
 */
#define TMR_IOC_GET_TIMER_CHN_ORIGIN_CNT			(FIOLAST + 24)//获取当前定时器通道的周期计数值

/*
 * 	控制项定义：TMR_IOC_GET_TIMER_CHN_DURATION
 * 	控制项功能：获取当前定时器通道origin计数值到现在的微秒间隔
 * 	控制项参数：T_DR_TMRChannel_CntTimeIntervalInfo结构体
 */
#define TMR_IOC_GET_TIMER_CHN_DURATION    		(FIOLAST + 25)//获取当前定时器通道origin计数值到现在的微秒间隔

/*
 * 	控制项定义：TMR_IOC_TIMER_CHN_DELAY_ORIGIN
 * 	控制项功能：从微秒定时器origin计数延迟us时间，延迟期间屏蔽中断
 * 	控制项参数：T_DR_TMRChannel_DelayOriginCntInfo结构体
 */
#define TMR_IOC_TIMER_CHN_DELAY_ORIGIN				(FIOLAST + 26)//从微秒定时器origin计数延迟us时间

/*******************控制参数定义结束*******************************/
/*定时器周期回调结构体*/
typedef struct
{
	void (*irq_tmr_callback)(void *args);//周期定时回调函数
	void *args;							 //回函函数参数值，可以为结构体也可以为变量
}T_DR_TmrIrqCallback;


/*定时器通道捕获功能配置结构体*/
typedef struct
{
	EM_TMR_CPT_CFG_CNT_SEL							cpt_cnt_sel;		//设置捕获功能时钟源，一般是设置当前自己通道
	EM_TMR_CPT_CFG_TRIG_MODE						trig_mode;			//信号捕捉的模式，比如说是要捕捉上升沿还是下降沿
	EM_TMR_CPT_CFG_DUAL_CPT_MODE					dual_cpt_mode;	//对于连续2次捕获，只生成一个捕获时间。只能用于SINGLE_MODE=1的情况
	EM_TMR_CPT_CFG_ONESHOUT_MODE					oneshot_mode;	//只生成一个时间捕获事件，然后自动清除EN位
	u8							filter_dis;			//捕获过滤设置使能
	u8							filter_width;		//捕获过滤设置，主要是设置过滤带宽
	u32						first_cpt_rst_en;	//设置该配置时候，CNT_LOCAL_X通过比较或捕获事件重置，具体查看0x24寄存器
	u8							sse_enable;		//合成引擎功能使能
	u8							sse_cmp_chn;		//预留，可不设置
	u8         				dma_enable;		//预留，可不设置
	u8        			 		fifo_wml;			//预留，可不设置
}T_DR_TMRChannelConfig_Capture;

/*定时器通道配置结构体*/
typedef struct
{
		EM_TMR_MODE mode;			//当前定时器模式
		u32 ovf_cnt;						//周期溢出计数值
		u32 init_cnt;  						//初始计数值
}T_DR_TMRChannelConfig;

/*定时器通道计数值信息结构体*/
typedef struct
{
		EM_TMR_CH_ID 		chn_id_input;				//要获取定时器信息的通道ID，注意，该参数为输入参数
		u32 						cur_cnt_output;			//当前定时器功能通道计数值
}T_DR_TMRChannelInfo;

/*获取两个计数之间的微秒间隔*/
typedef struct
{
		EM_TMR_CH_ID 		chn_id_input;				//要获取定时器信息的通道ID，注意，该参数为输入参数
		u32						origin_cnt_input;			//要计算的计数值，这个计数值不能大于当前通道的溢出值设置
		u32						cur_cnt_output;			//当前定时器功能通道计数值
		u32						timeInterVal_us_output;	//origin_cnt_input到cur_cnt_output的时间间隔，单位us
}T_DR_TMRChannel_CntTimeIntervalInfo;

/*从某个时间原点开始延迟*/
typedef struct
{
		EM_TMR_CH_ID 		chn_id_input;				//要获取定时器信息的通道ID，注意，该参数为输入参数
		u32						origin_cnt_input;			//要延时的时间原点，这个计数值不能大于当前通道的溢出值设置
		u32						delay_us_input;			//从要延时的时间原点开始需要延迟的时间，单位us
}T_DR_TMRChannel_DelayOriginCntInfo;

/*延时结构体*/
typedef struct
{
		EM_TMR_CH_ID 		chn_id_input;				//要获取定时器信息的通道ID，注意，该参数为输入参数
		u32						delay_us_input;			//延迟的时间，单位us
}T_DR_TMRChannel_DelayInfo;

/*定时器整体配置结构体*/
typedef struct
{
		u32 ovf_cnt;						//周期溢出计数值
		u32 init_cnt;						//初始计数值
		u32 time_out;						//周期溢出计数值
		EM_TMR_CLK_SRC_E clk_sel;//当前定时器时钟晶振设置
		float cnt_per_ns;					//用于表示每两个计数之前相差的微秒值
		u32 clk_frq;						//定时器频率，这里实际没起作用，做预留用
		u32 clk_div;						//分频系数涉及到了定时器精度，一般推荐分频系数等于3或者等于39
		u32 cascase_mode;				//G0和G1定时器连级模式，设置后将G0和G1当64位计数使用，我们当前不用，设置为false即可
		EM_TMR_ID tmr_id;				//当前要使用的定时器ID
		T_DR_TMRChannelConfig 					channel_cfg[EM_TMR_CH_ID_MAX_NUM];
		T_DR_TmrIrqCallback 						callback[EM_TMR_CH_ID_MAX_NUM];	//回调函数
		T_DR_TMRChannelConfig_Capture 		channel_cpt_info[EM_TMR_CH_ID_MAX_NUM];//捕获模式设置
		T_DR_TmrIrqCallback 						callback_func_capture[EM_TMR_CH_ID_MAX_NUM];	//捕获功能回调函数
}T_DR_TMRConfig;


/*用来控制定时器启动或者是停止的结构体*/
typedef struct
{
	EM_TMR_ID 		tmr_id;			//当前要控制的定时器通道ID
	u32 					time_out;		//计数溢出值
}T_DR_TMRControlConfig;

typedef struct
{
    T_BYTE name[DEVICE_NAME_SIZE];
    T_WORD index;
	
} T_DR_TMRConfigTable;

/*定时器控制状态结构体*/
typedef struct
{
    T_UWORD flags;
    T_WORD major;
    T_WORD minor;
    T_UWORD status;
    T_DR_TMRConfigTable config;
} T_DR_TmrControl;



/************************接口声明******************************/
/*
 * 函数名称： tmr_initialize
 * 函数说明：定时器初始化作函数。在内核态使用
 * 参数说明：
 *			major  驱动设备句柄
 *			minor  子设备句柄
 *			arg    参数指针，可以为结构体指针，也可以为变量指针
 * 返回值：
 * 			函数执行结果
 *注意说明：
 *          无
 * */
extern INT32 tmr_initialize(T_WORD major, T_WORD minor, T_VOID *arg);

/*
 * 函数名称： tmr_open
 * 函数说明：定时器打开函数。在用户态使用
 * 参数说明：
 *			arg	   		驱动设备句柄，但是在用户态posix接口中不开放
 *			fileName    设备文件名，一般为“/TMR_3”的字符串，表示定时器外设TMR3
 *			flags       设备操作标志，一般可以填DM_FLAGS_READ_WRITE，表示可读可写
 *			mode		模式，暂时不填
 * 返回值：
 * 			函数执行结果
 *注意说明：
 *          无
 * */
extern INT32 tmr_open(void *arg, UINT8 *fileName, INT32 flags, INT32 mode);

/*
 * 函数名称： tmr_close
 * 函数说明：定时器关闭函数。在用户态使用
 * 参数说明：
 *			arg	   		驱动设备句柄
 * 返回值：
 * 			函数执行结果
 *注意说明：
 *          无
 * */
extern INT32 tmr_close(T_VOID *arg);

/*预留函数，暂时不使用*/
extern INT32 tmr_read(T_VOID *arg, T_BYTE *buffer, T_UWORD maxbytes);

/*预留函数，暂时不使用*/
extern INT32 tmr_write(T_VOID *arg, T_BYTE *buffer, T_UWORD nbytes);

/*
 * 函数名称： tmr_control
 * 函数说明：定时器关闭函数。在用户态使用
 * 参数说明：
 *			args	   		驱动设备句柄
 *			function		具体的操作指令
 *			arg				参数指针，可以传入结构体指针或者是变量指针
 * 返回值：
 * 			函数执行结果
 *注意说明：
 *          无
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
