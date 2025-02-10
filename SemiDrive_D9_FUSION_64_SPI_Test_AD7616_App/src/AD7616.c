/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sysGpio.h>
#include <sysSpi.h>
#include "pthread.h"
#include "stdbool.h"
/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/
#include "AD7616.h"
#define SPI_MODE           SPI_MODE_3
#define SPI_BITRATE       (40*1000*1000)
#define SPI_NAME           "/SPI_5"
#define ARRAY_SIZE(array)  (sizeof(array)/sizeof(array[0]))
#define TASK_LOG(...) printk(__VA_ARGS__)
#define USE_DUMP_REGS (1)
//#define TASK_LOG(...)
#define VOLTAGE_REF   4.096 //��׼Դ�ο���ѹ

#define GET_BIT(x,n)        ((x & ((1U)<<n)))//��ȡ1λ
#define SET_BIT(x,n)        ((x |  ((1U)<<n)))//����1λ
#define CLEAR_BIT(x,n)    (x & (~((1U)<<n)))//���1λ

#define GET_BITS(x,offset,width)            ((x & ((((1U)<<width)-1)<<offset))>>offset)//��ȡwidthλ
#define CLEAR_BITS(x,offset,width)        (x & (~((((1U)<<width)-1)<<offset)))//���widthλ
#define SET_BITS(x,offset,width,value)    ((x & (~((((1U)<<width)-1)<<offset))) | ((value & (((1U)<<width)-1))<<offset))//����widthλ
#define CS_PIN  0
/*
 *ѡ�����º�Կ���ģʽ����ѡ��
 *  ���Է������л�+ͻ��ģʽ ����ͨ��8(VCC),9(ALDO)�����쳣������ֵ��������ʱ仯��������ͨ������ʱ׼ȷ�ġ�
 */
//#define AD7616_CONFIG_MODE            (AD7616_OS(AD7616_OSR_0)) //��ֹ������������ģʽ
//#define AD7616_CONFIG_MODE            (AD7616_OS(AD7616_OSR_0) | AD7616_SEQEN) //��ֹ�����������л�ģʽ
#define AD7616_CONFIG_MODE           (AD7616_OS(AD7616_OSR_0) | AD7616_SEQEN | AD7616_BURSTEN) //��ֹ�����������л�+ͻ��ģʽ

ad7616_info_t ad7616_info[]={
    {
    		.spi_name=SPI_NAME,
			.rst_pin_name="/OSPI2_DATA3",
			.busy_pin_name="/OSPI2_SS1",
			.convst_pin_name="/OSPI2_DQS",
    }
};
static unsigned short 	_Config=AD7616_CONFIG_MODE;
static int _open_gpio(char* name,char direction,int mode )
{
	int fd=-1;

	T_DR_GpioConfigTable config;

	//����RST����
	fd= open(name, 0);//GPIO_3B0
	if (fd < 0)
	{
		TASK_LOG("open %s fd:%d,errno = %d\n",name,fd, errno);
		return -1;
	}
	else
	{
		TASK_LOG("open %s fd:%d ok\n",name,fd);
	}

	ioctl(fd, UIO_GET_CFG, &config);
	config.direction = direction;
	config.config=mode;
	ioctl(fd, UIO_SET_CFG, &config);

	return fd;
}
static int _open_spi(char* name,int mode,int speed,int bitsperword)
{
	int ret;
	int fd = open(name, 0);
	if (fd < 0)
	{
		TASK_LOG("***open %s error,errno:%d\r\n",name,errno);
	}
	else
	{
		TASK_LOG("***open %s ok\n",name);
	}
	/* ���ô���ģʽ */
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	/* ����Ƶ�� */
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	/* �������ݳ��� */
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsperword);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	TASK_LOG("%s\t bits per word: %d \n", name,bitsperword);
	TASK_LOG("%s\t spi mode: 0x%x \n", name,(mode & 0x3));
	TASK_LOG("%s\t max speed: %d Hz (%d KHz) \n",name, speed, speed/1000);

    return fd;
err:
    TASK_LOG("  [%s]:%d errno\n", __func__,__LINE__,errno);
    close(fd);
    return -1;
}

static int _hardware_init(ad7616_info_t *info)
{
	info->rst_pin_fd=_open_gpio(info->rst_pin_name,GPIO_OUTPUT,PIN_CONFIG_DRIVE_PUSH_PULL);
	info->convst_pin_fd=_open_gpio(info->convst_pin_name,GPIO_OUTPUT,PIN_CONFIG_DRIVE_PUSH_PULL);
	info->busy_pin_fd=_open_gpio(info->busy_pin_name,GPIO_INPUT,PIN_CONFIG_BIAS_PULL_UP);
	info->spi_fd=_open_spi(info->spi_name,SPI_MODE,SPI_BITRATE,8);

	if(info->rst_pin_fd<0)
		return -1;
	if(info->busy_pin_fd<0)
		return -1;
	if(info->convst_pin_fd<0)
		return -1;
	if(info->spi_fd<0)
		return -1;
	return 0;
}

static int _spi_tranfer(ad7616_info_t *info,void *write_buf,void *read_buf,int len)
{
	if(write_buf!=NULL)
		write(info->spi_fd,write_buf,len);

	if(read_buf!=NULL)
		read(info->spi_fd,read_buf,len);
  return len;
}

//us ����ʱ
static void _delay_us(int us)
{
	UINT64 start_time,end_time;
	 start_time=TTOS_GetCurrentSystemCount();
	 end_time=TTOS_GetCurrentSystemCount();
	 while(TTOS_GetCurrentSystemSubTime(start_time, end_time, TTOS_US_UNIT)<us)
	 {
		 end_time=TTOS_GetCurrentSystemCount();
	 }
}
//ns ����ʱ��׼
static void _delay_ns(u64 ns)
{
	register u64 temp=ns;
	while(temp)
	{
		temp--;
	}
}
//����ת��
static bool _start_convert(ad7616_info_t *info)
{
	write(info->convst_pin_fd,"1",1);
	_delay_ns(200);//�ֲ�Ҫ����������50ns,������ʱ��׼
	write(info->convst_pin_fd,"0",1);

	return true;
}

//�ȴ��������
//δ��⵽BUSY�ź��б�ߣ�оƬ�ڲ��Ƿ��ǿ�©
static bool _wait_for_sample_compeleted(ad7616_info_t *info)
{
	 UINT64 start_time,end_time;
	 char buf[2];
	 bool ret=false;

	 start_time=TTOS_GetCurrentSystemCount();

	 do{
		 _delay_ns(100);//�ֲ���Ҫ������ת����ת����ɵ���ֵҪ475ns,����Ҫ�ӳ�32ns����ȥ��ȡbusy Tbusydelay���Ϊ32ns
		 read(info->busy_pin_fd,buf,1);
		 if(buf[0]=='0')
		 {
			 ret=true;
			 break;
		 }
		 end_time=TTOS_GetCurrentSystemCount();
	 }while(TTOS_GetCurrentSystemSubTime(start_time, end_time, TTOS_US_UNIT)<10000);

	 if(ret==false)
	 {
		    TASK_LOG(" [%s]:%d time out\n", __func__,__LINE__);
	 }
		return ret;
}
//��ȫ��λоƬ
static void _reset_chip(ad7616_info_t *info)
{
	write(info->rst_pin_fd,"0",1);
	TTOS_SleepTask(20);
	write(info->rst_pin_fd,"1",1);//��λ
	TTOS_SleepTask(150);//ADI��������ô��ʱ��  �ֲ����ϵ絽ִ��ת��15ms
}
//16������ʾ���������
void ShowBuf(char *str,unsigned char *buf,int len)
{
	int i;
	TASK_LOG("%s len:%d\t\t",str,len);
	for(i=0;i<len;i++)
	{
		TASK_LOG("  0x%02X",buf[i]);
		if((i+1)%10==0)
		{
			TASK_LOG("\r\n");
		}
	}
	TASK_LOG("\r\n");
}
//��ȡ�Ĵ�������
static  unsigned short _read_reg(ad7616_info_t *info,unsigned char addr)
{
	unsigned short readData=0;
	char buf[2];
    char recvbuf[2];
    memset(recvbuf,0,sizeof(recvbuf));
	buf[0] = 0x00 | ((addr & 0x3F) << 1);
	buf[1] = 0x00;
	_spi_tranfer(info, buf,NULL, 2);

	buf[0] = 0x00 | ((addr & 0x3F) << 1);
	buf[1] = 0x00;
    _spi_tranfer(info, buf, recvbuf,2);
	readData = (recvbuf[0] << 8) | recvbuf[1];

	return readData;
}

//д��Ĵ�������
static  int _write_reg(ad7616_info_t *info,unsigned char addr,unsigned short data)
{
	char buf[2];
    char recvbuf[2];
    int ret;
	buf[0] = 0x80 | ((addr & 0x3F) << 1) | ((data & 0x100) >> 8);//���λ��1��ʾд
	buf[1] = (data & 0xFF);

	ret=_spi_tranfer(info,buf,recvbuf,sizeof(recvbuf));
	return (ret==sizeof(recvbuf))?0:-1;//д��ɹ�����0��д��ʧ�ܷ���-1
}
//д��Ĵ���
//����ʹ�����л��Ķ�ͨ��Ҫ���ô�API
//@para:addr �´β�����Ҫ���õĵ�ַ
//@para:addr �´β�����Ҫ���õ�����
static  void _read_config_channel(ad7616_info_t *info,unsigned char addr,unsigned short data,short *channel_a_adc,short *channel_b_adc)
{
	char buf[4];
    char recvbuf[4];

	buf[0]=0;
	buf[1]=0;
	buf[2] = 0x80 | ((addr & 0x3F) << 1) | ((data & 0x100) >> 8);//���λ��1��ʾд
	buf[3] = (data & 0xFF);

	_spi_tranfer(info,buf,recvbuf,sizeof(recvbuf));
	*channel_a_adc = (recvbuf[0]  << 8) | recvbuf[1];
	*channel_b_adc = (recvbuf[2]  << 8) | recvbuf[3];
}
//д��Ĵ���
//����ʹ�����л��Ķ�ͨ��Ҫ���ô�API
//@para:addr �´β�����Ҫ���õĵ�ַ
//@para:addr �´β�����Ҫ���õ�����
static  void _read_squence_channel(ad7616_info_t *info,short *channel_a_adc,short *channel_b_adc)
{
	char buf[4];
    char recvbuf[4];

    memset(buf,0,sizeof(buf));

	_spi_tranfer(info,buf,recvbuf,sizeof(recvbuf));
	*channel_a_adc = (recvbuf[0]  << 8) | recvbuf[1];
	*channel_b_adc = (recvbuf[2]  << 8) | recvbuf[3];
}
//ͻ�����л�ģʽʱ��һ�ζ�ȡ�������л�ͨ������
static  void _read_squence_muti_channels(ad7616_info_t *info,short *channel_a_adc,short *channel_b_adc,int n)
{
	char buf[n*2*2];
    char recvbuf[n*2*2];

    memset(buf,0,sizeof(buf));
	_spi_tranfer(info,buf,recvbuf,sizeof(recvbuf));
//	ShowBuf("rx", recvbuf, sizeof(recvbuf));
}

//���2��ͨ���Ĳ�������
static void _flash_channel_data(ad7616_info_t *info)
{
	 short channel_a_adc,channel_b_adc;

	_start_convert(info);
	_wait_for_sample_compeleted(info);//����ת�����
	_read_config_channel(info,AD7616_REG_CHANNEL,0,&channel_a_adc,&channel_b_adc);
}
/*
 *  @para:channel  ����ͨ����
 *  @adc_code      ADCֵ
 *  @ת��ADCֵΪ��ѹ����λΪmv
 */
static float _calc_vlotage(int channel,short adc_code)
{
	float voltage;

	if(channel==0x08)//�ڲ�����ͨ��,�����ڲ���VCC
	{
		voltage =(1000*VOLTAGE_REF*adc_code*5/32768+1000*VOLTAGE_REF)/4;
	}
	else if(channel==0x09)//�ڲ�����ͨ��,�����ڲ���ALDO
	{
		voltage =(1000*VOLTAGE_REF*adc_code*10/32768+1000*7*VOLTAGE_REF)/10;
	}
	else
	{
		voltage=adc_code*5*1000/32768;
	}
	return voltage;
}

static void _display_channel_info(ad7616_info_t *info)
{
	 int  channel=0;
	 char strfix[32];
	 if(_Config & AD7616_SEQEN)//���������л�ģʽ
	 {
		 if(_Config & AD7616_BURSTEN) //ͻ��ģʽ
		 {
			 sprintf(strfix, "%s","Burst Squence");
		 }
		 else
		 {
			 sprintf(strfix, "%s","Squence");
		}
	 }
	 else
	 {
		 sprintf(strfix, "%s","");
	 }

	 for(channel=0;channel<8;channel++)
	 {
		    TASK_LOG("   %s channel A%d\t adc_value=0x%04X\t voltage:%.2f\t\t  channel B%d\t adc_value=0x%04X\t voltage:%.2f\r\n",strfix,
												 channel,(unsigned short)info->channels_a_adc[channel],info->channels_a_voltage[channel],
												 channel,(unsigned short)info->channels_b_adc[channel],info->channels_b_voltage[channel]);//1�ζ�1��ͨ��
	 }

	 channel=8;
	    TASK_LOG("   %s channel A%d\t adc_value=%d\t VCC:%.2f\t\t  channel B%d\t adc_value=%d\t VCC:%.2f\t. this channel is VCC,adc_code is about 25000\r\n",strfix,
											 channel,info->channels_a_adc[channel],info->channels_a_voltage[channel],
											 channel,info->channels_b_adc[channel],info->channels_b_voltage[channel]);//1�ζ�1��ͨ��
	 channel=9;
		    TASK_LOG("   %s channel A%d\t adc_value=%d\t ALDO:%.2f\t\t  channel B%d\t adc_value=%d\t ALDO:%.2f\t. this channel is VCC,adc_code is about -7700\r\n",strfix,
												 channel,info->channels_a_adc[channel],info->channels_a_voltage[channel],
												 channel,info->channels_b_adc[channel],info->channels_b_voltage[channel]);//1�ζ�1��ͨ��
	 channel=11;
			    TASK_LOG("   %s channel A%d\t adc_value=0x%04X\t\t\t\t channel B%d\t adc_value=0x%04X\t  this is fixed 0XAAAA and 0X5555\r\n",strfix,
													 channel,(unsigned short)info->channels_a_adc[channel-1],
													 channel,(unsigned short)info->channels_b_adc[channel-1]);//1�ζ�1��ͨ��
}
//��������
static void _sample_test(ad7616_info_t *info)
{
	 int  channel=0,current_adc_channel;
	 short channel_a_adc,channel_b_adc;

	 TASK_LOG("\r\n");
	 if(_Config & AD7616_SEQEN)//���������л�ģʽ
	 {
		 for(channel=0;channel<11;channel++)
		 {
			 if(_Config & AD7616_BURSTEN) //ͻ��ģʽ
			 {
			    	if(channel==0)
			    	{
						_start_convert(info);//ͻ��ģʽֻ������ת��һ��
					    _wait_for_sample_compeleted(info);//����ת�����
//				    	_read_squence_muti_channels(info,&info->channels_a_adc[channel],&info->channels_b_adc[channel],ARRAY_SIZE(info->channels_b_adc));//1�ΰ�����ͨ������
			    	}
			    	_read_squence_channel(info,&channel_a_adc,&channel_b_adc);//��ȡ˳��ͨ����
			    	info->channels_a_adc[channel]=channel_a_adc;
			    	info->channels_b_adc[channel]=channel_b_adc;
			    	info->channels_a_voltage[channel]=_calc_vlotage(channel,info->channels_a_adc[channel]);
			    	info->channels_b_voltage[channel]=_calc_vlotage(channel,info->channels_b_adc[channel]);
			   }
			   else
			   {
			    	_start_convert(info);//ͻ��ģʽֻ������ת��һ��
				    _wait_for_sample_compeleted(info);//����ת�����
				    _read_squence_channel(info,&channel_a_adc,&channel_b_adc);//��ȡ˳��ͨ����
			    	info->channels_a_adc[channel]=channel_a_adc;
			    	info->channels_b_adc[channel]=channel_b_adc;
			    	info->channels_a_voltage[channel]=_calc_vlotage(channel,channel_a_adc);
			    	info->channels_b_voltage[channel]=_calc_vlotage(channel,channel_b_adc);
				}
		 }
	 }
	 else
	 {
		 for(channel=0;channel<12;channel++)
		 {
			 _start_convert(info);//����ת��
			 _wait_for_sample_compeleted(info);//����ת�����
			 _read_config_channel(info,AD7616_REG_CHANNEL,AD7616_BSEL(channel) | AD7616_ASEL(channel),&channel_a_adc,&channel_b_adc);//��ȡͨ������

			 current_adc_channel=(channel-2+11)%11;//��β������������Ƕ�Ӧǰ2�����õ�ͨ����
			 if(info->sample_cnt==0 && current_adc_channel<2)//��1�β���,ǰ2������ʱ��Ч��,���ֲ����Ӧ����1��������Ч
				 continue;
		     info->channels_a_adc[current_adc_channel]=channel_a_adc;
		     info->channels_b_adc[current_adc_channel]=channel_b_adc;
		     info->channels_a_voltage[current_adc_channel]=_calc_vlotage(current_adc_channel,channel_a_adc);
		     info->channels_b_voltage[current_adc_channel]=_calc_vlotage(current_adc_channel,channel_b_adc);
		 }
	}
	 info->sample_cnt++;
	 _display_channel_info(info);
}
//оƬ�ڲ���ʼ��
static void _setup(ad7616_info_t *info)
{
	_reset_chip(info);//оƬ��λ
	ad7616_wr(CS_PIN,AD7616_REG_CONFIG,0x00);
	ad7616_wr(CS_PIN,AD7616_REG_INPUT_RANGE_A1,0XAA);//��2.5V
	ad7616_wr(CS_PIN,AD7616_REG_INPUT_RANGE_A2,0XAA);//��2.5V
	ad7616_wr(CS_PIN,AD7616_REG_INPUT_RANGE_B1,0XAA);//��2.5V
	ad7616_wr(CS_PIN,AD7616_REG_INPUT_RANGE_B2,0XAA);//��2.5V

	if(_Config & AD7616_SEQEN)//���������л�ģʽ
	 {
			ad7616_wr(CS_PIN,0x20,0X00);//���к�ͨ��V0A/V0B
			ad7616_wr(CS_PIN,0x21,0X11);//���к�ͨ��V1A/V1B
			ad7616_wr(CS_PIN,0x22,0X22);//���к�ͨ��V2A/V2B
			ad7616_wr(CS_PIN,0x23,0X33);//���к�ͨ��V3A/V3B
			ad7616_wr(CS_PIN,0x24,0X44);//���к�ͨ��V4A/V4B
			ad7616_wr(CS_PIN,0x25,0X55);//���к�ͨ��V5A/V5B
			ad7616_wr(CS_PIN,0x26,0X66);//���к�ͨ��V6A/V6B
			ad7616_wr(CS_PIN,0x27,0X77);//���к�ͨ��V7A/V7B
			ad7616_wr(CS_PIN,0x28,0X88);//���к�ͨ��V8A/V8B
			ad7616_wr(CS_PIN,0x29,0X99);//���к�ͨ��V9A/V9B
			ad7616_wr(CS_PIN,0x2a,0X1bb);//���к�ͨ��VBA/VBB
	 }

	ad7616_wr(CS_PIN,AD7616_REG_CONFIG,_Config);
	_flash_channel_data(info);//���ǰ���������2���ֽ�����
}
//��ȡ�Ĵ�����ֵ
int ad7616_rd(u16 cs, u16 addr)
{
	(void)cs;
	return _read_reg(&ad7616_info[0], addr);
}
//д��ɹ�����0��д��ʧ�ܷ���-1
//д��Ĵ�����ֵ
int ad7616_wr(u16 cs, u16 addr, u16 data)
{
	(void)cs;
	return _write_reg(&ad7616_info[0], addr,data);
}
//д��ɹ�����0��д��ʧ�ܷ���-1
void ad7616_reset_chip(void)
{
	_reset_chip(&ad7616_info[0]);//оƬ��λ
}
//���ù�������
//����ֵ�� 0 �ɹ�   1 ʧ��
int ad7616_set_oversampling_ratio(u8 osr)
{
	u16 mode;
	mode=ad7616_rd(CS_PIN,AD7616_REG_CONFIG);
	mode=SET_BITS(mode,2,3,osr);
	ad7616_wr(CS_PIN,AD7616_REG_CONFIG,mode);
}
//�������л�ͨ�� �ڲ���2��ADC,ͬʱ����Aͨ����Bͨ��
//����ֵ�� 0 �ɹ�   1 ʧ��
int ad7616_config_soft_seq(u8 squence,u8 a_channel,u8 b_channel,bool is_last_channel)
{
	u16 reg=0x20+squence;
	u16 value=a_channel|b_channel;

	if(is_last_channel)
	{
		value=SET_BIT(value,8);//��8λΪ1�������һ������
	}

	return ad7616_wr(CS_PIN,reg,value);
}
//����Ϊͻ��ģʽ��ͻ��ģʽһ��ʹ�������л�ģʽ
//����ֵ�� 0 �ɹ�   1 ʧ��
int ad7616_set_burst_mode(void)
{
	u16 mode;
	mode=ad7616_rd(CS_PIN,AD7616_REG_CONFIG);
	mode=SET_BIT(mode,5);
	mode=SET_BIT(mode,6);
	return ad7616_wr(CS_PIN,AD7616_REG_CONFIG,mode);
}
//�������üĴ���
//����ֵ�� 0 �ɹ�   1 ʧ��
int ad7616_set_squence_mode(void)
{
	u16 mode;
	mode=ad7616_rd(CS_PIN,AD7616_REG_CONFIG);
	mode=SET_BIT(mode,5);
	mode=CLEAR_BIT(mode,6);
	return ad7616_wr(CS_PIN,AD7616_REG_CONFIG,mode);
}

//����Ϊ����ģʽ ������1��ͨ������ȡ1������
//����ֵ�� 0 �ɹ�   1 ʧ��
int ad7616_set_basic_mode(void)
{
	u16 mode;
	mode=ad7616_rd(CS_PIN,AD7616_REG_CONFIG);
	mode=CLEAR_BIT(mode,5);
	mode=CLEAR_BIT(mode,6);
	return ad7616_wr(CS_PIN,AD7616_REG_CONFIG,mode);
}
//�������üĴ���
//����ֵ�� 0 �ɹ�   1 ʧ��
int ad7616_set_config(u16 config)
{
	return ad7616_wr(CS_PIN,AD7616_REG_CONFIG,config);
}
//����ͨ����Դ��ѹ��Χ
//����ֵ�� 0 �ɹ�   1 ʧ��
int adc_set_range(u8 channel,u8 range )
{
	int ret=-1;
	u8 reg_index=channel/4;
	u8 channel_index=channel%4;
    u16 mode;

	switch(reg_index)
	{
		case  0:
			mode =ad7616_rd(CS_PIN,AD7616_REG_INPUT_RANGE_A1);
			mode=SET_BITS(mode,channel_index*2,2,range);
			ret = ad7616_wr(CS_PIN,AD7616_REG_INPUT_RANGE_A1,mode);
			break;
		case  1:
			mode =ad7616_rd(CS_PIN,AD7616_REG_INPUT_RANGE_A2);
			mode=SET_BITS(mode,channel_index*2,2,range);
			ret = ad7616_wr(CS_PIN,AD7616_REG_INPUT_RANGE_A2,mode);
			break;
		case  2:
			mode =ad7616_rd(CS_PIN,AD7616_REG_INPUT_RANGE_B1);
			mode=SET_BITS(mode,channel_index*2,2,range);
			ret = ad7616_wr(CS_PIN,AD7616_REG_INPUT_RANGE_B1,mode);
			break;
		case  3:
			mode =ad7616_rd(CS_PIN,AD7616_REG_INPUT_RANGE_B2);
			mode=SET_BITS(mode,channel_index*2,2,range);
			ret = ad7616_wr(CS_PIN,AD7616_REG_INPUT_RANGE_B2,mode);
			break;
		default:
			break;
	}
	return ret;
}
static void _dump_regs()
{

	TASK_LOG(" AD7616_REG_CONFIG 0x%02X \r\n",_read_reg(&ad7616_info[0], AD7616_REG_CONFIG));
	TASK_LOG(" AD7616_REG_CHANNEL 0x%02X \r\n",_read_reg(&ad7616_info[0], AD7616_REG_CHANNEL));
	TASK_LOG(" AD7616_REG_INPUT_RANGE_A1 0x%02X \r\n",_read_reg(&ad7616_info[0], AD7616_REG_INPUT_RANGE_A1));
	TASK_LOG(" AD7616_REG_INPUT_RANGE_A2 0x%02X \r\n",_read_reg(&ad7616_info[0], AD7616_REG_INPUT_RANGE_A2));
	TASK_LOG(" AD7616_REG_INPUT_RANGE_B1 0x%02X \r\n",_read_reg(&ad7616_info[0], AD7616_REG_INPUT_RANGE_B1));
	TASK_LOG(" AD7616_REG_INPUT_RANGE_B2 0x%02X \r\n",_read_reg(&ad7616_info[0], AD7616_REG_INPUT_RANGE_B2));
	TASK_LOG(" AD7616_REG_0x20 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x20));
	TASK_LOG(" AD7616_REG_0x21 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x21));
	TASK_LOG(" AD7616_REG_0x22 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x22));
	TASK_LOG(" AD7616_REG_0x23 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x23));
	TASK_LOG(" AD7616_REG_0x24 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x24));
	TASK_LOG(" AD7616_REG_0x25 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x25));
	TASK_LOG(" AD7616_REG_0x26 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x26));
	TASK_LOG(" AD7616_REG_0x27 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x27));
	TASK_LOG(" AD7616_REG_0x28 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x28));
	TASK_LOG(" AD7616_REG_0x29 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x29));
	TASK_LOG(" AD7616_REG_0x2a 0x%02X \r\n",_read_reg(&ad7616_info[0], 0x2a));
}
bool adc_init(void)
{
	int i=0;

	ad7616_reset_chip();
	ad7616_set_config(0x00);
//	ad7616_wr(AD7616_REG_INPUT_RANGE_A1,0XAA);//��2.5V
//	ad7616_wr(AD7616_REG_INPUT_RANGE_A2,0XAA);//��2.5V
//	ad7616_wr(AD7616_REG_INPUT_RANGE_B1,0XAA);//��2.5V
//	ad7616_wr(AD7616_REG_INPUT_RANGE_B2,0XAA);//��2.5V
	for(i=0;i<16;i++)
	{
		adc_set_range(i,AD7616_2V5);//��2.5V
#if USE_DUMP_REGS>0
		TASK_LOG(" channel i=%d,A1:0x%04X\t A2:0x%04X\t B1:0x%04X\t B2:0x%04X\t \r\n",i,_read_reg(&ad7616_info[0], AD7616_REG_INPUT_RANGE_A1),
				_read_reg(&ad7616_info[0], AD7616_REG_INPUT_RANGE_A2),
				_read_reg(&ad7616_info[0], AD7616_REG_INPUT_RANGE_B1),
				_read_reg(&ad7616_info[0], AD7616_REG_INPUT_RANGE_B2));
#endif //End Of !USE_DUMP_REGS
	}

	if(_Config & AD7616_SEQEN)//���������л�ģʽ
	 {
		ad7616_config_soft_seq(0,AD7616_VA0,AD7616_VB0,false);//���к�ͨ��V0A/V0B
		ad7616_config_soft_seq(1,AD7616_VA1,AD7616_VB1,false);//���к�ͨ��V1A/V1B
		ad7616_config_soft_seq(2,AD7616_VA2,AD7616_VB2,false);//���к�ͨ��V2A/V2B
		ad7616_config_soft_seq(3,AD7616_VA3,AD7616_VB3,false);//���к�ͨ��V3A/V3B
		ad7616_config_soft_seq(4,AD7616_VA4,AD7616_VB4,false);//���к�ͨ��V4A/V4B
		ad7616_config_soft_seq(5,AD7616_VA5,AD7616_VB5,false);//���к�ͨ��V5A/V5B
		ad7616_config_soft_seq(6,AD7616_VA6,AD7616_VB6,false);//���к�ͨ��V6A/V6B
		ad7616_config_soft_seq(7,AD7616_VA7,AD7616_VB7,false);//���к�ͨ��V7A/V7B
		ad7616_config_soft_seq(8,AD7616_VAVCC,AD7616_VBVCC,false);//���к�ͨ��V8A/V8B
		ad7616_config_soft_seq(9,AD7616_VALDO,AD7616_VBLDO,false);//���к�ͨ��V9A/V9B
		ad7616_config_soft_seq(10,AD7616_VA_SELF_TEST,AD7616_VB_SELF_TEST,TRUE);//���к�ͨ��VBA/VBA
	 }
	ad7616_set_oversampling_ratio(GET_BITS(_Config,2,3));//���ù�����
	if(_Config & AD7616_BURSTEN)//������ͻ��ģʽ
	{
		 ad7616_set_burst_mode();
	}
	else 	if(_Config & AD7616_SEQEN)//���������л�ģʽ
	{
		 ad7616_set_squence_mode();
	}
	else
	{
		ad7616_set_basic_mode();
	}
#if USE_DUMP_REGS>0
	_dump_regs();//��ӡ���ԼĴ���
#endif //End Of !USE_DUMP_REGS
//	ad7616_set_config(_Config);//ֱ������ȫ������
	_flash_channel_data(&ad7616_info[0]);//���ǰ���������2���ֽ�����

	return 0;
}
void ad7616_sample_test(ad7616_info_t *info)
{
	_sample_test(info);
}
//extern	int TMR_SET_TMR_156us(ad7616_info_t *info);
static void* _task(void *p_data)
{
	ad7616_info_t *info = (ad7616_info_t *)p_data;

	TASK_LOG("  goto %s :%s\r\n",__func__, info->spi_name);
	_hardware_init(info);
//	_setup(info);
	adc_init();
//	TMR_SET_TMR_156us(info);
	while(1)
	{
		TTOS_SleepTask(100);
		_sample_test(info);
	}
	TASK_LOG("      end %s %s\r\n",__func__,info->spi_name);
	return NULL;
}


T_VOID AD7616_Test(T_VOID)
{
	int ret;
	int i;
	TASK_LOG("   %s\r\n",__func__);
	for( i=0;i<ARRAY_SIZE(ad7616_info);i++)
	{
		ret = pthread_create(&(ad7616_info[i].testId), NULL, _task, (void*) &ad7616_info[i]);
		if(ret<0)
		{
			TASK_LOG("create %s task errer  errno = %d ret=%d\r\n",ad7616_info[i].spi_name,errno,ret);
		}
	}

	while (1)
	{
		TTOS_SleepTask(100);
	}
}

int userAppInit(void)
{
	TASK_LOG("\r\n\r\n    Reboot 1\r\n");
	TTOS_SleepTask(10*1000);
	TASK_LOG("\r\n\r\n    Reboot 2\r\n");

	AD7616_Test();
}



