/*********************************************************************************
*				                                         科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * 修改历史：
 * 2017-05-10     李燕, 科东（广州）软件科技有限公司
 *                创建该文件。
 *                
*/

/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

/************************头 文 件******************************/
#include"lwip/sockets.h"
#include <commonTypes.h>
#include<ttos.h>
#include<test.h>
#include<netif_adapter.h>
#include<devinfo.h>
#include"lwip/netif.h"


/************************宏 定 义******************************/
#define BUFF_SIZE 10
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
static uint8_t recvBuff[BUFF_SIZE];	//接收数据缓冲区
static uint8_t VM12Buff[BUFF_SIZE] = "0123456789";
static uint8_t VM21Buff[BUFF_SIZE] = "abcdefghij";

/************************实   现*******************************/


/*	客户端测试程序	*/
int userAppInit(void)
{
	u16_t port = 27016;								// 端口号
	int nSockFd, status, ret;
	struct sockaddr_in remote_addr;			// 创建socket_in结构体对象
	const struct nic_name *p = NULL;			// 创建nic_name结构体指针存放网卡名
	T_ULONG nic_num = 0;							// 网卡数量
	int i;														// 循环迭代数


	p = TTOS_GetNicNameList(&nic_num);		// 获取网卡名列表

	if(NULL != p){
		for(i = 0; i < nic_num; i++){
			printf("\np[%d] = %s \n", i, &p[i]);

		}
	}

	// 建立套接字文件描述符
	nSockFd = socket(AF_INET, SOCK_STREAM, 0);
	if(nSockFd < 0){
		printf("###sock err 1\n");
		return -4;
	}

	// 服务端ip配置
	remote_addr.sin_len = sizeof(remote_addr);
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_addr.s_addr = inet_addr(TTOS_IP_vm2);
	remote_addr.sin_port = htons(port);

    printf("connect('%d.%d.%d.%d', %d)\n",
    		remote_addr.sin_addr.s_addr & 0xFF,
           (remote_addr.sin_addr.s_addr >> 8) & 0xFF,
           (remote_addr.sin_addr.s_addr >> 16) & 0xFF,
           (remote_addr.sin_addr.s_addr >> 24) & 0xFF,
		   ntohs(remote_addr.sin_port) );

    while(1)
    {
    	// 连接服务端
		status = connect(nSockFd, (struct sockaddr *) &remote_addr, sizeof(remote_addr));
		if(status<0)
		{
			closesocket(nSockFd);
			nSockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if (nSockFd < 0)
				{
					printf("###sock err 1\n");
				}
		}
		else{
			break;
		}
    }

    // 向服务端发送VM12Buff
	send(nSockFd, VM12Buff, sizeof(VM12Buff), 0);
	TTOS_SleepTask(TTOS_GetSysClkRate());

	// 接受服务端返回的信息并验证消息正确性
	recv(nSockFd, recvBuff, BUFF_SIZE, 0);
	ret = memcmp(recvBuff, VM21Buff, sizeof(VM21Buff));									//比较接收缓冲区中的数据与发送的数据包是否一致
	if(0 == ret)		// ret=0说明接受到来自服务端的消息正确，测试通过
	{
		printf("vm1(client) recv success!\n");
		printf("***Test Pass, filename: %s ***\r\n", __FILE__);
	}
	else
	{
		printf("***Test Failed, error: %d, filename: %s line: %d***\r\n",errno, __FILE__, __LINE__);
	}

    return 0;
}

