#include <components/modbusIO.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sysCan.h>

#define CAN0_NAME "/CAN0"

#define write_cf_num  100

void can_rx(void *arg)
{
	int ret=0, i=0, j;
	int fd = -1;

	static int count = 0;

	/* 在任务中不断接收数据 */
	fd = (int)arg;

	struct can_frame *frame = (struct can_frame *)malloc(sizeof(struct can_frame));

	/* 开始接收数据 */
	while(1)
	{
		ret = read(fd, frame, sizeof(struct can_frame));
		if(ret>0)
		{
			ret = ret / sizeof(struct can_frame);
			for(j=0;j<ret;j++)
			{
				printk(" recv can_id:0x%08x  ",frame[j].can_id);
				printk("recv len:%02x\ndata: \n",frame[j].can_dlc);
				for(i=0;i<frame[j].can_dlc;i++)
				{
					printk(" 0x%02x",frame[j].data[i]);
				}
			printk("\n");
			}
			memset(frame, 0, sizeof(struct can_frame));
			printk("Recv cnt sum: --- %d ---\n", ++count);
		}
		TTOS_SleepTask(500);
	}

}

void can_tx(void *arg)
{
	int ret=0, i=0, j;
	int fd = -1;

	static int count = 0;

	/* 在任务中不断接收数据 */
	fd = (int)arg;

	struct can_frame write_cf[8];

	/* 开始发送数据 */
	printk("start write\n");
	for (i = 0; i < write_cf_num; i++) {
		write_cf[0].can_id = 0x123 + i;
		write_cf[0].can_dlc = 8;
		write_cf[0].data[0] = i;
		write_cf[0].data[1] = 0x11 + i;
		write_cf[0].data[2] = 0x22;
		write_cf[0].data[3] = 0x33;
		write_cf[0].data[4] = 0x44;
		write_cf[0].data[5] = 0x55;
		write_cf[0].data[6] = 0x66;
		write_cf[0].data[7] = 0x77;
		ret = write(fd, &write_cf[0], sizeof(write_cf[0]));
		//printk("write return ret:%d\n",ret);
		printk("Send %d times!, ret:%d. \n", i, ret);
		TTOS_SleepTask(100);
	}

}

int userAppInit() {
	T_WORD ret = 0;
	int i, j,fd,count = 0;

	struct can_filter filter;
	T_WORD bitrate;

	/*打开的设备名*/
	char *name = "/CAN0";

	/*阻塞 超时方式，超时时间 5000 个tick*/
	T_WORD wait_ticks = 5000;

	TASK_ID task_id1, task_id2;

	 /*读写方式打开*/
	fd = open(name, DM_FLAGS_READ_WRITE);
	if (fd < 0) {
		printk("{%s}[%d], open %s failed = %d.......\n", __FUNCTION__, __LINE__,
				name, errno);
		return 1;
	} else {
		printk("open %s succeed! fd: %d.\n", name, fd);
	}

	/* 设置波特率  */
	bitrate = 500000;
	ret = ioctl(fd, CAN_IOC_WR_BITTIMING, &bitrate);
	if (ret < 0) {
		printk("{%s}[%d], ioctl ret = %d, fd: %d.\n", __FUNCTION__, __LINE__,
				ret, fd);
		return ret;
	}

	/* 设置过滤器 */
	filter.can_id = (12 & CAN_SFF_MASK);
	filter.can_mask = ~CAN_SFF_MASK;
	ioctl(fd, CAN_IOC_WR_FILTER, &filter);

	/* 设置读wait_ticks */
	ret = ioctl(fd, CAN_IOC_WR_RDTMO, &wait_ticks);
	if (ret < 0) {
		printk("{%s}[%d], ioctl ret = %d\n", __FUNCTION__, __LINE__, ret);
		return ret;
	}
	/* 设置写wait_ticks */
	ret = ioctl(fd, CAN_IOC_WR_WRTMO, &wait_ticks);
	if (ret < 0) {
		printk("{%s}[%d], ioctl ret = %d\n", __FUNCTION__, __LINE__, ret);
		return ret;
	}

	/* 启动CAN  */
	ret = ioctl(fd, CAN_IOC_UP, NULL);
	if (ret < 0) {
		printk("{%s}[%d], ioctl ret = %d, fd: %d.\n", __FUNCTION__, __LINE__,
				ret, fd);
		return ret;
	}


	/* 创建读任务1 */
    ret = TTOS_CreateTaskEx("CanTestRead_task1", 2, TRUE, TRUE, can_rx, (T_VOID *)fd, 0x8000, &task_id1);
    if (TTOS_OK != ret)
    {
    	printk("func:%s,line:%d,TTOS_CreateTask ,ret %d!\n", __FUNCTION__, __LINE__,ret);
    }
    else
    {
    	printk("%s: %d\n", __func__, __LINE__);
    	printk("TTOS_CreateTaskEx for can_read_test_rouine! \n");
	}

	/* 创建写任务2 */
    ret = TTOS_CreateTaskEx("CanTestRead_task2", 2, TRUE, TRUE, can_tx, (T_VOID *)fd, 0x8000, &task_id2);
    if (TTOS_OK != ret)
    {
    	printk("func:%s,line:%d,TTOS_CreateTask ,ret %d!\n", __FUNCTION__, __LINE__,ret);
    }
    else
    {
    	printk("%s: %d\n", __func__, __LINE__);
    	printk("TTOS_CreateTaskEx for can_read_test_rouine! \n");
	}


    while(1){
    	TTOS_SleepTask(100);
    }
	return 0;
}

