/****************************************************************************
 *				科东（广州）软件技术有限公司 版权所有
 *
 * 		 Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 ***************************************************************************/
 
/* <EXECL>
【需求标识】:
网络UDP组播功能

【测试用例标识】
IntewellOS_NET_FT_MULTICAST_001

【目标机类型】:
工业服务器

【测试目的】
测试UDP组播的收发能否成功。

【测试类型】
功能测试

【先决条件】
1、启动并建立主机和目标机之间的连接；
2、配置vm1为UDP组播发送方，vm2为UDP组播接收方，vm3同为UDP组播接收方,3个分区使用同一pf的不同vf；
3、下载用例到目标机，并运行。

【测试步骤】
1、vm1以一定时间间隔循环对外发送UDP组播数据；
2、vm2加入多播组，循环接收组播数据，并将数据进行反转，再对外发送UDP组播数据；
3、vm3加入多播组，循环接收组播数据；
4、查看同时进行上述通信时，数据包接收与发送是否一致。

【预期结果】
vm2接收vm1发送的多播组数据，vm3接收vm1和vm2发送的多播组数据，两个数据是反的。

【评价准则】
与预期结果一致

【假设和约束】
操作系统可运行

【设计者】:
XXX

【设计时间】:
2020-01-18

</EXECL> */
/**************************** 引用部分 ***************************************/
#include "lwip/sockets.h"
#include <ttos.h>
#include <test.h>

#define MCAST_PORT 				12345
#define MCAST_ADDR 				"224.1.1.10"						//一个局部连接多播地址，路由器不进行转发
#define MCAST_DATA				"0123456789"			//多播发送的数据
#define MCAST_INTERVAL			150									//发送间隔时间  200ticks
/**************************** 实现部分 ***************************************/


int IntewellOS_NET_FT_MULTICAST_001(void)
{
	int fd, ret;
	int j  = 0xff;
	struct sockaddr_in mcast_addr;
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd == -1)
	{
		printf("sock error\n");
		return -1;
	}

	memset(&mcast_addr, 0, sizeof(mcast_addr));										//初始化IP多播地址为0
	mcast_addr.sin_family = AF_INET;															//设置协议族类行为AF
	mcast_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);							//设置多播IP地址
	mcast_addr.sin_port = htons(MCAST_PORT);											//设置多播端口

	/*向多播地址发送数据*/
	while(1)
	{
		ret = sendto(fd, MCAST_DATA, sizeof(MCAST_DATA), 0, (struct sockaddr*)&mcast_addr, sizeof(mcast_addr));
		if(ret < 0)
		{
			printf("sendto error, ret:%d\n", ret);
			return -1;
		}
		TTOS_SleepTask(MCAST_INTERVAL);												//等待一段时间（单位：ticks）
	}
	closesocket(fd);
	return 0;
}
    


