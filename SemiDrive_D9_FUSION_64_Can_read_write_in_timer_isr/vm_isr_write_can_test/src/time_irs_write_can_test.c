
#include <commonTypes.h>
#include <compConfig.h>
#include <ttosInit.h>
#include <ftpApi.h>

#include "pthread.h"

#include <components/modbusIO.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#include <sysCan.h>
#include <sysTmr.h>
#define CAN0_ENABLE  1
#define CAN1_ENABLE  0

#define APP_OVF_CNT_5MS   (492300 - 1)
#define APP_OVF_CNT_156US   (15541-1)
struct test_can_info {
	char *name;
	int fd;
	int bitrate;
	pthread_t can_tx;
	pthread_t can_rx;
	pthread_t can_display;
	uint32_t tx_count;
	uint32_t rx_count;
	uint32_t err_count;
	uint32_t rx_len;  /*�����ݳ���*/
	struct can_frame *frame;
	T_DR_CanControl *can_cblk;
};

typedef struct test_can_info can_info_t;

//�������ڼ����ص��Ľṹ��
struct tPeriodCntInfo
{
	u32 				irqCnt;					//�жϼ���
	T_UDWORD 	uwStartTimetamp;	//��һ�������жϵ�ʱ���
	T_UDWORD 	uwEndTimetamp;		//�ڶ��������жϵ�ʱ���
	T_UDWORD 	uwTime_us;			//���β�������ʱ��������λΪus
};

int temp = 0;
static struct  tPeriodCntInfo		g_tPeriodCntInfo_156us[1];	//���ڶ�ʱ���ص�ʹ��
static int		g_iTmrFd_period;				//������156us��5ms���ڼ���
/**
 * @method open_can
 * ��CAN�豸��
 * @param {char *} name CAN�豸����
 * @param {int} bitrate ������
 *
 * @return {can_info_t *} CAN�豸��Ϣ��
 */
can_info_t *open_can(char *name, int bitrate) {
	int fd = -1;
	int flags;
	int i = 0;

	int read_timeout;
	int write_timeout;
	struct can_filter filter;
	struct can_bittiming bittiming;

	can_info_t *can_info = malloc(sizeof(can_info_t));
	if (can_info == NULL) {
		return NULL;
	}

	memset(can_info, 0, sizeof(can_info_t));

	can_info->fd = open(name, DM_FLAGS_READ_WRITE);
	if (can_info->fd < 0) {
		printf("can open error:errno =%d  port_name : %s\n", errno, name);
		perror("open");
		return NULL;
	}

	/*
	 * �豸�ɶ�д
	 */
	ioctl(can_info->fd, CAN_IOC_RD_FLAGS, &flags);
	flags |= CAN_FLAGS_NO_ECHO;
	ioctl(can_info->fd, CAN_IOC_WR_FLAGS, &flags);

	read_timeout = 0;
	ioctl(can_info->fd, CAN_IOC_WR_RDTMO, &read_timeout);

	write_timeout = 50;
	ioctl(can_info->fd, CAN_IOC_WR_WRTMO, &write_timeout);

	if (0 > ioctl(can_info->fd, CAN_IOC_RD_BITTIMING, &bittiming)) {
		printf("ioctl [CAN_IOC_RD_BITTIMING] error :errno =%d \n", errno);
		perror("CAN_IOC_RD_BITTIMING");
		return NULL;
	}

	/*ֻ���� 0x0B ��׼֡*/
	filter.can_id = (11 & CAN_SFF_MASK);
	filter.can_mask = ~CAN_SFF_MASK;

	ioctl(can_info->fd, CAN_IOC_WR_FILTER, &filter);
	ioctl(can_info->fd, CAN_IOC_RESTART, NULL);

	if (0 > ioctl(can_info->fd, CAN_IOC_RD_BITTIMING, &bittiming)) {
		printf("ioctl [CAN_IOC_RD_BITTIMING] error :errno =%d \n", errno);
		perror("CAN_IOC_RD_BITTIMING");
		return NULL;
	}

	if (0 > ioctl(can_info->fd, CAN_IOC_WR_BITTIMING, &bitrate)) {
		printf("ioctl [CAN_IOC_WR_BITTIMING] error :errno =%d \n", errno);
		perror("CAN_IOC_WR_BITTIMING");
		return NULL;
	}

	can_info->bitrate = bitrate;

	if (0 > ioctl(can_info->fd, CAN_IOC_RESTART, &flags)) {
		printf("ioctl [CAN_IOC_RESTART] error :errno =%d \n", errno);
		perror("CAN_IOC_RESTART");
		return NULL;
	}

	can_info->name = name;
	can_info->frame = (struct can_frame *)malloc(sizeof(struct can_frame) * 1024);   /*�����ڴ�*/
	can_info->rx_len = 0;
	can_info->can_cblk = can_get_control_block(can_info->name);   /*�ýӿڲ�֧�����ж��е���*/
	printf("open success %s @ baud %d\n", can_info->name, can_info->bitrate);

	return can_info;
}

void* can_rx(void *p_data) {
	can_info_t *can_info = (can_info_t *)p_data;
	printf("recv @ %s fd %d\n", can_info->name, can_info->fd);
	uint32_t recv_count = 0;
	int ret = 0;
	int i = 0;

	struct can_frame *frame = (struct can_frame *)malloc(sizeof(struct can_frame) * 1024);

	while (1) {

		/*
		 * ��һ���������ڣ���ȡ��ȫ��������
		 */
		ret = read(can_info->fd, frame, sizeof(struct can_frame) * 1024);
		if (ret > 0) {
			ret = ret / sizeof(struct can_frame);
			for (i = 0; i < ret; i++) {
				if (frame[i].can_dlc != 1 || frame[i].data[0] != 0x11) {
					can_info->err_count ++;
					printf("%s id:%08X dlc: %d ", can_info->name, frame[i].can_id, frame[i].can_dlc);
					printf("data:");
					int  j = 0;
					for (j = 0; j < frame[i].can_dlc; j++) {
						printf("%02X",  frame[i].data[j]);
					}
					printf("\n");
				}
			}
			can_info->rx_count += ret;
			memset(frame, 0, sizeof(struct can_frame) * 1024);
		}

		TTOS_SleepTask(1);
	}

	return NULL;
}

void* isr_can_rx(void *p_data) {
	can_info_t *can_info = (can_info_t *)p_data;
	uint32_t ret = 0;
	/*
	 * ��һ���������ڣ���ȡ��ȫ��������
	 */
	can_info->rx_len = can_read(can_info->can_cblk, can_info->frame, sizeof(struct can_frame) * 1024);
	if(can_info->rx_len > 0){
		ret = can_info->rx_len / sizeof(struct can_frame);
		can_info->rx_count = can_info->rx_count + ret;
	}
	return NULL;
}
void* can_tx(void *p_data) {
	int ret = 0;
	can_info_t *can_info = (can_info_t *)p_data;

	unsigned char buff_send[8] = { 0 };
	struct can_frame frame_sff = { 0 };

	buff_send[0] = 0x08;
	buff_send[1] = 0x07;
	buff_send[2] = 0x06;
	buff_send[3] = 0x05;
	buff_send[4] = 0x04;
	buff_send[5] = 0x03;
	buff_send[6] = 0x02;
	buff_send[7] = 0x01;
	frame_sff.can_id = 0x123;
	frame_sff.can_dlc = 8;
	memcpy(frame_sff.data, buff_send, 8);

	struct can_frame frame_eff = { 0 };

	buff_send[0] = 0x01;
	buff_send[1] = 0x02;
	buff_send[2] = 0x03;
	buff_send[3] = 0x04;
	buff_send[4] = 0x05;
	buff_send[5] = 0x06;
	buff_send[6] = 0x07;
	buff_send[7] = 0x08;
	frame_eff.can_id = 0x123|CAN_EFF_FLAG;
	frame_eff.can_dlc = 8;
	memcpy(frame_eff.data, buff_send, 8);

	while (1) {
		TTOS_SleepTask(500);
		ret = write(can_info->fd, &frame_sff, sizeof(frame_sff));
		if (ret < 0) {
			printf("send error; ret = %d\n", ret);
		} else {
			can_info->tx_count++;
		}

		ret = write(can_info->fd, &frame_eff, sizeof(frame_eff));
		if (ret < 0) {
			printf("send error; ret = %d\n", ret);
		} else {
			can_info->tx_count++;
		}
	}

	return NULL;
}
void* isr_can_tx(void *p_data) {
	int ret = 0;
	can_info_t *can_info = (can_info_t *)p_data;
	unsigned char buff_send[8] = { 0 };
	struct can_frame frame_sff = { 0 };

	buff_send[0] = 0x08;
	buff_send[1] = 0x07;
	buff_send[2] = 0x06;
	buff_send[3] = 0x05;
	buff_send[4] = 0x04;
	buff_send[5] = 0x03;
	buff_send[6] = 0x02;
	buff_send[7] = 0x01;
	frame_sff.can_id = 0x123;
	frame_sff.can_dlc = 8;
	memcpy(frame_sff.data, buff_send, 8);

	struct can_frame frame_eff = { 0 };

	buff_send[0] = 0x01;
	buff_send[1] = 0x02;
	buff_send[2] = 0x03;
	buff_send[3] = 0x04;
	buff_send[4] = 0x05;
	buff_send[5] = 0x06;
	buff_send[6] = 0x07;
	buff_send[7] = 0x08;
	frame_eff.can_id = 0x123|CAN_EFF_FLAG;
	frame_eff.can_dlc = 8;
	memcpy(frame_eff.data, buff_send, 8);
	ret = can_write(can_info->can_cblk, &frame_sff, sizeof(frame_sff));
	if (ret < 0) {
		printf("send error; ret = %d\n", ret);
	} else {
		can_info->tx_count++;
	}
#if 0
	ret = can_write(can_info->can_cblk, &frame_eff, sizeof(frame_eff));
	if (ret < 0) {
		printf("send error; ret = %d\n", ret);
	} else {
		can_info->tx_count++;
	}
#endif
	return NULL;
}
void* can_info_display(void *p_data) {
	can_info_t *can_info = (can_info_t *)p_data;
	printf("can_info_display @ %s fd %d\n", can_info->name, can_info->fd);

	while (1) {
		printf("%s rx_count:%d\n", can_info->name, can_info->rx_count);
		printf("%s tx_count:%d\n", can_info->name, can_info->tx_count);
		printf("%s err_count:%d\n", can_info->name, can_info->err_count);

		TTOS_SleepTask(5000);
	}

	return NULL;
}

void* isr_can_info_display(void *p_data) {
	can_info_t *can_info = (can_info_t *)p_data;
	uint32_t i,ret;
	printf("can_info_display @ %s fd %d\n", can_info->name, can_info->fd);
	while (1) {
		printf("can_info_display @ %s fd %d\n", can_info->name, can_info->fd);
		printf("%s rx_count:%d\n", can_info->name, can_info->rx_count);
		printf("%s tx_count:%d\n", can_info->name, can_info->tx_count);
		printf("%s err_count:%d\n", can_info->name, can_info->err_count);
		if (can_info->rx_len) {
				ret = can_info->rx_len / sizeof(struct can_frame);
				for (i = 0; i < ret; i++) {
						printf("%s id:%08X dlc: %d ", can_info->name,can_info->frame[i].can_id,can_info->frame[i].can_dlc);
						printf("data:");
						int  j = 0;
						for (j = 0; j <can_info-> frame[i].can_dlc; j++) {
							printf("%02X", can_info-> frame[i].data[j]);
						}
						printf("\n");
				}
			memset(can_info->frame, 0, sizeof(struct can_frame) * 1024);
			can_info->rx_len = 0;
		}
		TTOS_SleepTask(1000);
	}
	return NULL;
}
int can_test(int agrc, char *agrv[]) {
	int ret = 0;
	can_info_t *can0;
	can_info_t *can1;
#if CAN0_ENABLE
	can0 = open_can("/CAN0", 250000);

#endif
#if CAN1_ENABLE
	can1 = open_can("/CAN1", 250000);
#endif

#if CAN0_ENABLE
	ret = pthread_create(&can0->can_tx, NULL, can_tx, (void*) can0);

	ret = pthread_create(&can0->can_rx, NULL, can_rx, (void *)can0);

	ret = pthread_create(&can0->can_display, NULL, can_info_display, (void *)can0);
#endif
#if CAN1_ENABLE
	ret = pthread_create(&can1->can_tx, NULL, can_tx, (void*) can1);

	ret = pthread_create(&can1->can_rx, NULL, can_rx, (void *)can1);

	ret = pthread_create(&can1->can_display, NULL, can_info_display, (void *)can1);
#endif
	while (1) {
		sleep(1);
	}

	return 0;
}
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
//	isr_can_tx(data);
	isr_can_rx(data);
	//can_sample_test(info);
}
//�������ڶ�ʱ�����ܣ���������156us��5ms���ڼ�����ʱ������
int TMR_SET_TMR_156us(can_info_t *info)
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
		l_stTmrControlConfig[0].time_out =APP_OVF_CNT_5MS;           /*��ʱ������Ϊ5ms*/
		l_iRet = ioctl(g_iTmrFd_period, TMR_IOC_TIMER_START, &l_stTmrControlConfig[0] );
		printk("[app][%s]%d  ioctl( TMR_IOC_TIMER_START)=>TMR_CH_ID_C l_iRet :%d\n", __func__,__LINE__, l_iRet );

		return 0;
}

void time_irs_write_can_test(void)
{
	printf("TTOS test for time_irs_write_can_test\n");
	int ret = 0;
	can_info_t *can0;
	can0 = open_can("/CAN0", 250000);
	ret = pthread_create(&can0->can_display, NULL, isr_can_info_display, (void *)can0);
	TMR_SET_TMR_156us(can0);
	while(1){
		TTOS_SleepTask(1000);
	}
}
