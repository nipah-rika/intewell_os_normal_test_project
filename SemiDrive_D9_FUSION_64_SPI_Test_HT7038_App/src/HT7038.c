/************************头 文 件******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sysGpio.h>
#include <sysSpi.h>
#include "pthread.h"
/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/
#include "HT7038.h"
#define TASK_LOG(...) printf(__VA_ARGS__)
//#define TASK_LOG(...)
#define ARRAY_SIZE(array)  (sizeof(array)/sizeof(array[0]))

#define SPI_MODE           SPI_MODE_3
#define SPI_BITRATE       (500*1000)
#define SPI_NAME           "/SPI_4"
union UN_RMS{
//       unsigned char   volChar[4]; //电压字节数组
       unsigned int   volFloat;  //电压浮点数
    };

 typedef   struct  {
    	char *spi_name;
    	int spi_fd;

    	char *rst_pin_name;
    	int rst_pin_fd;
    	pthread_t testId;
}spi_info_t;

    spi_info_t spi_info[]={
    {
    	.spi_name=SPI_NAME,
    	.rst_pin_name="/OSPI2_DATA2",
    }
};
    //us 级延时
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

static int _tranfer(spi_info_t *info,void *write_buf,void *read_buf,int len)
{
	if(write_buf!=NULL)
	write(info->spi_fd,write_buf,len);

	if(read_buf!=NULL)
	read(info->spi_fd,read_buf,len);
  return len;
}
//写寄存器
static unsigned int _read(spi_info_t *info,unsigned char cmd)
{
  unsigned char sendBuf[4];
  unsigned char recvBuf[4];
  unsigned int data;

  memset(sendBuf,0,sizeof(sendBuf));
  memset(recvBuf,0,sizeof(recvBuf));
  sendBuf[0]=cmd & 0x7f;//最高位清0表示读
  _tranfer(info,sendBuf,recvBuf,4); //发送命令
  data=(recvBuf[1]<<16) | (recvBuf[2]<<8) | (recvBuf[3]<<0) ;

  return data;
}

//读取寄存器
static void _write(spi_info_t *info,unsigned char cmd,unsigned int data)
{
  unsigned char sendBuf[4];

  memset(sendBuf,0,sizeof(sendBuf));
  sendBuf[0]=0x80|(cmd&0x7f);//最高位置1表示写
//  sendBuf[0]=cmd;//最高位置1表示写
  sendBuf[1]=(data>>16)&0xff;
  sendBuf[2]=(data>>8)&0xff;
  sendBuf[3]=(data>>0)&0xff;
  _tranfer(info,sendBuf,NULL,4);
}
//初始化SPI,RST引脚
static void _setup(spi_info_t *info)
{
	int ret;
	int fd;
	T_DR_GpioConfigTable config;
	//设置RST引脚
	fd= open(info->rst_pin_name, 0);//GPIO_3B0
	if (fd < 0)
	{
		TASK_LOG("open %s fd:%d,errno = %d\n",info->rst_pin_name,fd, errno);
		goto err;
	}
	else
	{
		TASK_LOG("open %s fd:%d ok\n",info->rst_pin_name,fd);
	}
    //设置RST推挽输出模式
	ioctl(fd, UIO_GET_CFG, &config);
	config.direction = GPIO_OUTPUT;
	config.config=PIN_CONFIG_DRIVE_PUSH_PULL;
	ioctl(fd, UIO_SET_CFG, &config);
	info->rst_pin_fd=fd;
	write(fd,"1",1);
	//初始化SPI
	fd = open(info->spi_name, 0);
	if (fd < 0)
	{
		TASK_LOG("***open %s error,errno:%d\r\n",info->spi_name,errno);
	}
	else
	{
		TASK_LOG("***open %s ok\n",info->spi_name);
	}
	  info->spi_fd=fd;

	/* 设置传输模式 */
	int mode = SPI_MODE;
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置频率 */
	int speed = SPI_BITRATE;
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	/* 设置数据长度 */
	int bitsperword = 8;
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsperword);
	if (ret < 0)
	{
		TASK_LOG("ioctl errno = %x\n", errno);
		goto err;
	}

	TASK_LOG("bits per word: %d \n", bitsperword);
	TASK_LOG("spi mode: 0x%x \n", (mode & 0x3));
	TASK_LOG("max speed: %d Hz (%d KHz) \n", speed, speed/1000);

    return;
    err:
	       TASK_LOG("  [%s]:%d errno\n", __func__,__LINE__,errno);
        	close(fd);
}
static void _sample_temp_sensor(spi_info_t *info);
//初始化函数
//static void _init(spi_info_t *info)
//{
//	const T_BYTE high[]="1";
//	const T_BYTE low[]="0";
//	//硬件复位RST
//	write(info->rst_pin_fd,low,1);
//	TTOS_SleepTask(10);
//	write(info->rst_pin_fd,high,1);
//
//	// _write(info,0xC3,0x000000);					//清校表数据
//	//********
//	// _write(info,0xD3,0X000000);//软件复位
//	   _write(info,0xC9,0x00005A);					//设置可以写入校表寄存器的参数
//	//	delay_ms(1);
//	//
//		_write(info,w_ModeCfg,0xF954);//开启电压通道ADC	,更新速率为慢速0xF9FE
//		_write(info,w_EMCfg,0x0003);//设置三相三线模式0x0111
//		_write(info,w_EMUIE,0xFFFF);
//		_write(info,w_ModuleCFG,0x3404);//0x3404
//		_write(info,w_ModuleCFG,0x3537);//测温度
//	 _write(info,w_PGACtrl,0x0000);	//ADC增益配置为三相电压通道ADC增益放大2倍 bit09和bit08为设置电压通道增益位
//
//	//  _write(info,w_UaRmsoffse,0x0062);//A相电压有效值offset校正
//	//  _write(info,w_UbRmsoffse,0x0062);//B相电压有效值offset校正
//	//
//	//	_write(info,w_UcRmsoffse,0x0062);//C相电压有效值offset校正0xAa9e
//
//		_write(info,w_EMUCfg,0x0201);	//EMU模块配置寄存器0x0201
//		//_write(info,w_EMUCfg,0XF804);	//EMU模块配置寄存器0x0201
//		//_write(info,w_FailVoltage,0x0010);//原设置好的
//	//	_write(info,w_FailVoltage,0xd200);
//
//		_write(info,w_UgainA,0x8454);//Uab电压增益0x8684
//		_write(info,w_UgainC,0x845F);//Ubc电压增益0x8684
//		_write(info,w_UgainB,0x845A);//Uac相电压增益需单独计算，不与A相C相相同
//
//	 _write(info,0xC9,0x000000);	//	*********
//	 _write(info,0xC6,0x000000); //设置可以读计量寄存器的参数
//	// date= Read7038(rChkSum);
//	// printf("data=%lx\r\n",date);
//	// _write(info,0xD3,0X000000);//软件复位
//	// _write(info,0xC9,0x00005A);					//设置可以写入校表寄存器的参数
//	_write(info,w_EMUCfg,0x0201);	//EMU模块配置寄存器0x0201
//	// _write(info,w_EMCfg,0x0001);//设置三相三线模式0x0111
//	_write(info,w_ModeCfg,0xF954);//开启电压通道ADC	,更新速率为慢速0xF9FE
//
//}

static void _init(spi_info_t *info)
{
	const T_BYTE high[]="1";
	const T_BYTE low[]="0";
	//硬件复位RST
	write(info->rst_pin_fd,low,1);
	TTOS_SleepTask(10);
	write(info->rst_pin_fd,high,1);
	TTOS_SleepTask(10);

	 _write(info,0xC3,0x000000);					//清校表数据
	 TTOS_SleepTask(10);
	//	//********
     _write(info,0xD3,0X000000);//软件复位
     TTOS_SleepTask(10);
	 _write(info,0xC9,0x00005A);   //设置可以写入校表寄存器的参数
	 _write(info,0xC6,0x00005A); //设置可以读计量寄存器的参数


	 _write(info,w_ModeCfg,0xF954);//开启电压通道ADC ,更新速率为慢速0xF9FE
	 _write(info,w_EMCfg,0x0003);//设置三相三线模式0x0111
	 _write(info,w_EMUIE,0xFFFF);
	 _write(info,w_ModuleCFG,0x3537);//0x3404
	 _write(info,w_PGACtrl,0x0000); //ADC增益配置为三相电压通道ADC增益放大2倍 bit09和bit08为设置电压通道增益位

	 _write(info,w_EMUCfg,0x0201); //EMU模块配置寄存器0x0201

	 _write(info,w_UgainA,0x022E);//Uab电压增益
	 _write(info,w_UgainC,0x022E);//Ubc电压增益
	 _write(info,w_UgainB,0x022E);//Uac相电压增益需单独计算，不与A相C相相同

	 _write(info,0xC9,0x0000FF);  //关闭写校表寄存器
	   TASK_LOG("   %s Read Reserverd=0x%06X\t w_ModeCfg=0x%06X\t w_EMUCfg=0x%06X \r\n",info->spi_name,_read(info,0x00),_read(info,w_ModeCfg),_read(info,w_EMUCfg));
	   TASK_LOG("   %s Read w_EMCfg=0x%06X\t w_EMUIE=0x%06X\t w_ModuleCFG=0x%06X \r\n",info->spi_name,_read(info,w_EMCfg),_read(info,w_EMUIE),_read(info,w_ModuleCFG));
	   TASK_LOG("   %s Read w_PGACtrl=0x%06X\t\r\n",info->spi_name,_read(info,w_PGACtrl));
	   TASK_LOG("   %s Read w_UgainA=0x%06X\t w_UgainC=0x%06X\t w_UgainB=0x%06X \r\n",info->spi_name,_read(info,w_UgainA),_read(info,w_UgainC),_read(info,w_UgainB));
	 _write(info,0xC6,0x000000); //设置可以读计量寄存器的参数
}
//读取设备ID，芯片ID
static void _read_id(spi_info_t *info)
{
	//DeviceID:0x7126A0
	//ChipID:0x7026E0
    TASK_LOG("   %s Read DeviceID=0x%06X\t ChipID=0x%06X\r\n",info->spi_name,_read(info,rDeviceID),_read(info,rChipID));
}
static int _convert_to_int32(int value)
{
	value=value<<8;
	value=value>>24;

	return value;
}
static void _sample_temp_sensor(spi_info_t *info)
{
	int  rData=0;
	int TM;
	float temp=0;

 	rData = _read(info,rTPSD);    //读取内部传感器输出
 	TM=(rData & 0x0000ff);
 	if(TM>128)
 	{
 		TM=TM-256;
 	}
 	temp=25-TM*0.726;
    TASK_LOG("  \tHT7038 temp=%.2f,TM:%d:rData:0x%08X\t\r\n",temp,TM,rData);
}
//采样函数
static void _sample_test(spi_info_t *info)
{
     float  uab;
     float  ubc;
     float  uac;
     union UN_RMS u_rms;
     int  rData=0;

     TASK_LOG("  \tHT7038 rSampleUA=%d\t  rSampleUB=%d\t rSampleUC=%d\t\r\n",_read(info,rSampleUA),_read(info,rSampleUB),_read(info,rSampleUC));

 	rData = _read(info,rUaRms);    //读取Uab电压
    u_rms.volFloat=_convert_to_int32(rData) ;
    uab=(float)u_rms.volFloat/8192;

    rData = _read(info,rUbRms);    //读取Uac电压 内部计算得出
    u_rms.volFloat=_convert_to_int32(rData) ;

    uac=(float)u_rms.volFloat/8192;  //长整型强制转换成浮点型，否者液晶显示数据为0

    rData = _read(info,rUcRms);    //读取Ubc电压
    u_rms.volFloat=_convert_to_int32(rData) ;
    ubc=(float)u_rms.volFloat/8192;

    TASK_LOG("  HT7038 Uab=%.2f\t  Ubc=%.2f\t Uac=%.2f\t\r\n",uab,ubc,uac);
 }

static void _deinit(spi_info_t *info)
{
	T_WORD ret = 0;

	ret = close(info->spi_fd);
	if (ret < 0)
	{
		TASK_LOG("close %s errno = %d\n",info->spi_name, errno);
	}
	ret = close(info->rst_pin_fd);
	if (ret < 0)
	{
		TASK_LOG("close %s errno = %d\n",info->rst_pin_name, errno);
	}
}
//任务函数
static void* _task(void *p_data)
{
	spi_info_t *info = (spi_info_t *)p_data;

	TASK_LOG("  goto %s :%s\r\n",__func__, info->spi_name);
	_setup(info);//初始化SPI,RST
	_init(info);//复位,设置相关寄存器
	while(1)
	{
		_read_id(info);
		_sample_test(info);
	    _sample_temp_sensor(info);
		TTOS_SleepTask(100);
	}
	_deinit(info);

	TASK_LOG("      end %s %s\r\n",__func__,info->spi_name);
	return TTOS_OK;
}


T_VOID HT7038_Test(T_VOID)
{
	int ret;
	int i;
	TASK_LOG("   %s\r\n",__func__);
	for( i=0;i<ARRAY_SIZE(spi_info);i++)
	{
		ret = pthread_create(&(spi_info[i].testId), NULL, _task, (void*) &spi_info[i]);
		if(ret<0)
		{
			TASK_LOG("create %s task errer  errno = %d ret=%d\r\n",spi_info[i].spi_name,errno,ret);
		}
	}

	while (1) {
		TTOS_SleepTask(100);
	}
}
int userAppInit(void)
{

		TASK_LOG("\r\n\r\n    Reboot\r\n");

	HT7038_Test();

}
