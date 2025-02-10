#ifndef __HT7038_H__
#define __HT7038_H__
#include "pthread.h"
#include <sysGpio.h>
#include <sysSpi.h>
/* AD7616 CORE */
#define AD7616_REG_PCORE_VERSION		0x400
#define AD7616_REG_ID					0x404
#define AD7616_REG_UP_SCRATCH			0x408
#define AD7616_REG_UP_IF_TYPE			0x40C
#define AD7616_REG_UP_CTRL				0x440
#define AD7616_REG_UP_CONV_RATE			0x444
#define AD7616_REG_UP_BURST_LENGTH		0x448
#define AD7616_REG_UP_READ_DATA			0x44C
#define AD7616_REG_UP_WRITE_DATA		0x450

/* AD7616_REG_UP_CTRL */
#define AD7616_CTRL_RESETN				(1 << 0)
#define AD7616_CTRL_CNVST_EN			(1 << 1)

#define AD7616_REG_CONFIG				0x02
#define AD7616_REG_CHANNEL				0x03
#define AD7616_REG_INPUT_RANGE_A1		0x04
#define AD7616_REG_INPUT_RANGE_A2		0x05
#define AD7616_REG_INPUT_RANGE_B1		0x06
#define AD7616_REG_INPUT_RANGE_B2		0x07
#define AD7616_REG_SEQUENCER_STACK(x)	(0x20 + (x))

/* AD7616_REG_CONFIG */
#define AD7616_SDEF						(1 << 7)
#define AD7616_BURSTEN					(1 << 6)
#define AD7616_SEQEN					(1 << 5)
#define AD7616_OS(x)					(((x) & 0x7) << 2)
#define AD7616_STATUSEN					(1 << 1)
#define AD7616_CRCEN					(1 << 0)

/* AD7616_REG_INPUT_RANGE */
#define AD7616_INPUT_RANGE(ch, x)		(((x) & 0x3) << (((ch) & 0x3) * 2))

/* AD7616_REG_SEQUENCER_STACK(x) */
#define AD7616_ADDR(x)					(((x) & 0x7F) << 9)
#define AD7616_SSREN					(1 << 8)
#define AD7616_BSEL(x)					(((x) & 0xF) << 4)
#define AD7616_ASEL(x)					(((x) & 0xF) << 0)

/* AD7616_REG_STATUS */
#define AD7616_STATUS_A(x)				(((x) & 0xF) << 12)
#define AD7616_STATUS_B(x)				(((x) & 0xF) << 8)
#define AD7616_STATUS_CRC(x)			(((x) & 0xFF) << 0)

enum ad7616_ch {
	AD7616_VA0        			 =0,
	AD7616_VA1        			 =1,
	AD7616_VA2        			 =2,
	AD7616_VA3        			 =3,
	AD7616_VA4        			 =4,
	AD7616_VA5       			 =5,
	AD7616_VA6        			 =6,
	AD7616_VA7        			 =7,
	AD7616_VAVCC      		     =8,
	AD7616_VALDO            	 =9,
	AD7616_VA_SELF_TEST     =11,

	AD7616_VB0        		 	 =0 <<4,
	AD7616_VB1        			 =1 <<4,
	AD7616_VB2        			 =2 <<4,
	AD7616_VB3        			 =3 <<4,
	AD7616_VB4        			 =4 <<4,
	AD7616_VB5       			 =5 <<4,
	AD7616_VB6        			 =6 <<4,
	AD7616_VB7        			 =7 <<4,
	AD7616_VBVCC      		     =8 <<4,
	AD7616_VBLDO           	 =9 <<4,
	AD7616_VB_SELF_TEST     =11 <<4,
};

enum ad7616_range {
	AD7616_2V5 = 1,
	AD7616_5V  = 2,
	AD7616_10V = 3,
};

enum ad7616_osr {
	AD7616_OSR_0,
	AD7616_OSR_2,
	AD7616_OSR_4,
	AD7616_OSR_8,
	AD7616_OSR_16,
	AD7616_OSR_32,
	AD7616_OSR_64,
	AD7616_OSR_128,
};

T_VOID AD7616_Test(T_VOID);
typedef   struct  {
   	char *spi_name;
   	int spi_fd;
	T_DR_SpiControl *spi_cblk;

   	char *rst_pin_name;
   	int rst_pin_fd;
   	T_DR_GpioControl *rst_pin_cblk;

   	char *busy_pin_name;
   	int busy_pin_fd;
   	T_DR_GpioControl *busy_pin_cblk;

   	char *convst_pin_name;
   	int convst_pin_fd;
   	T_DR_GpioControl *convst_pin_cblk;

   	pthread_t testId;
	short channels_a_adc[11];
	short channels_b_adc[11];
	float channels_a_voltage[11];
	float channels_b_voltage[11];
	unsigned int sample_cnt;
   }ad7616_info_t;

   int ad7616_rd(u16 cs, u16 addr);//返回读取到的值,低24位有效
   int ad7616_wr(u16 cs, u16 addr, u16 data);//成功返回0，失败返回-1
   void ad7616_reset_chip(void);//完全复位AD7616
   int ad7616_set_oversampling_ratio(u8 osr);//设置过采样率
   int ad7616_config_soft_seq(u8 squence,u8 a_channel,u8 b_channel,bool is_last_channel);//配置序列化通道
   int ad7616_set_burst_mode(void);//设置为突发模式，突发模式一定使能了序列化模式
   int ad7616_set_squence_mode(void);//设置为序列模式
   int ad7616_set_basic_mode(void);//设置为基本采样模式，设置1次通道，读取1次数据
   int ad7616_set_config(u16 config);//设置配置寄存器
   int adc_set_range(u8 channel,u8 range );//设置通道电源电压范围
   bool adc_init(void);//ADC初始化

   void ad7616_sample_test(ad7616_info_t *info);
#endif
