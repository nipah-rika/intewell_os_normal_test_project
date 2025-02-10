/****************************************************************************
 *				科东（广州）软件技术有限公司 版权所有
 *
 * 		 Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 ***************************************************************************/
 
/* <EXECL>
【需求标识】:
网络UDP组播功能

【测试用例标识】
IntewellOS_NET_MULTICAST_001

【目标机类型】:
工业服务器

【测试目的】
测试UDP组播的收发能否成功。

【测试类型】
功能测试

【先决条件】
1、启动并建立主机和目标机之间的连接；
2、配置vm1为UDP组播发送方，vm2为UDP组播接收方,2个分区使用同一pf的不同vf；
3、下载用例到目标机，并运行。

【测试步骤】
1、vm1以一定时间间隔循环对外发送UDP组播数据；
3、vm2加入多播组，循环接收组播数据；
4、查看同时进行上述通信时，数据包接收与发送是否一致。

【预期结果】
vm2接收vm1发送的多播组数据,接收数据正确。

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
#define MCAST_INTERVAL			200									//发送间隔时间
#define BUFF_SIZE					256									//接收缓冲区大小

static char  sendBuff_vm1[BUFF_SIZE] = "0123456789";

/**************************** 实现部分 ***************************************/

int IntewellOS_NET_MULTICAST_001(void)
{
	struct sockaddr_in addr;
	int recfd,sendfd, nbytes, addrlen;
	struct ip_mreq mreq;
	char msgbuf[BUFF_SIZE];
	int ret = 0;
    int j  = 0xff, i  = 0xff,n = 0xff;
	char* bufferAddress[512] = {0};
	int bufferIndex = 0;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
	/* 创建接收套接字 */
	recfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(recfd < 0)
	{
		printf("recfd socket err\n");
		TEST_FAILRINT();
		return -1;
	}

	/* 创建发送套接字 */
	sendfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sendfd < 0)
	{
		printf("sendfd socket err\n");
		TEST_FAILRINT();
		return -1;
	}

	/* 设置本地回环 */
	int yes = 1;
	if(setsockopt(recfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
	{
		printf("Reusing ADDR err\n");
		TEST_FAILRINT();
		return -1;
	}

	memset(&addr, 0, sizeof(addr));

	/* 设置接收套接字 */
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(MCAST_PORT);

	ret = bind(recfd, (struct sockaddr *)&addr, sizeof(addr));
	if(ret < 0)
	{
		printf("bind err\n");
		TEST_FAILRINT();
		return -1;
	}

	/* 设置多播参数 */
	mreq.imr_multiaddr.s_addr = inet_addr(MCAST_ADDR);
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);

	/* 加入多播组 */
	int socketRet = setsockopt(recfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
	if(socketRet < 0)
	{
		printf("\nsetsockopt failed, ret:%d\n", socketRet);
		TEST_FAILRINT();
		return -1;
	}

	addrlen = sizeof(addr);

	for(j = 1; j < 41; j++)
	{
			memset(msgbuf, 0, BUFF_SIZE);
			nbytes = recvfrom(recfd, msgbuf, BUFF_SIZE, 0, (struct sockaddr *)&addr, (socklen_t *)&addrlen);
			bufferAddress[bufferIndex] = malloc(nbytes + 1);
			memset(bufferAddress[bufferIndex] , 0, nbytes + 1);
			memcpy(bufferAddress[bufferIndex], msgbuf, nbytes);
			bufferIndex++;

		}



	for (i =0 ; i < 512; i++)
	{
		if (bufferAddress[i] != NULL)
		{
			if (0 == memcmp(bufferAddress[i], sendBuff_vm1,strlen(sendBuff_vm1)))		//比较接收缓冲区中的数据与发送的数据包是否一致
			{
				count1++;
			}
			else
			{
				printk(" bufferAddress[%d] %s  len %d \n", i, bufferAddress[i], strlen(bufferAddress[i]));
				printk(" sendBuff_vm1 %s len %d \n", sendBuff_vm1, strlen(sendBuff_vm1));
				count3++;
			}
		}
	}


	if (count1 == 0 )
	{
		TEST_FAILRINT();
		printk(" count1 %d \n", count1);
		printk(" count3 %d \n", count3);
	}
	else if (count1 == 40)
	{

		TEST_OKPRINT();
	}
	else
	{
		TEST_FAILRINT();
		printk(" count1 %d \n", count1);
		printk(" count3 %d \n", count3);
	}

	for (i =0 ; i < 512; i++)
	{
		if (bufferAddress[i] != NULL)		//比较接收缓冲区中的数据与发送的数据包是否一致
		{
			free(bufferAddress[i] );
		}
	}

	setsockopt(recfd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));   //退出多播组

	closesocket(sendfd);
	closesocket(recfd);


	return 0;
}
    


