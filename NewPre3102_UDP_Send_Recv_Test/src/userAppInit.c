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

/**************************** 引用部分 ***************************************/
#include "lwip/sockets.h"
#include <ttos.h>
#include <test.h>
#include <netif_adapter.h>
#include <devinfo.h>
#include "lwip/netif.h"

#define BUFF_SIZE 10
static uint8_t recvBuff[BUFF_SIZE];		//接收数据缓冲区
/**************************** 实现部分 ***************************************/

int userAppInit(void) {
	u16_t port = 27016;				// 端口号
	int nSockFd, fd, ret, len;
	struct sockaddr_in local_addr;		//socket对象
	const struct nic_name *p = NULL;				// 创建nic_name结构体指针存放网卡名
	T_ULONG nic_num = 0;			// 网卡数量
	int i;										// 循环迭代数
	/*获取网卡名列表(目的是为了修改IP的时候使用)*/
	p = TTOS_GetNicNameList(&nic_num);
	if (NULL != p) {
		for (i = 0; i < nic_num; i++) {
			printf("p[%d]=%s\n", i, &p[i]);
		}
	}

	// 建立套接字文件描述符
	nSockFd = socket(AF_INET, SOCK_DGRAM, 0);
	if (nSockFd < 0) {
		printf("###sock err 1\n");
		return -4;
	}

	// 本地ip配置
	local_addr.sin_len = sizeof(local_addr);							//地址长度
	local_addr.sin_family = AF_INET;									//网络传输
	local_addr.sin_addr.s_addr = inet_addr("192.168.1.221");			//服务端ip
	local_addr.sin_port = htons(port);							//本机的转为网络的端口号

	// bing()对套接字进行地址和端口绑定
	if (bind(nSockFd, (struct sockaddr*) &local_addr, sizeof(local_addr))) {
		printf("###sock err 2\n");
		return -5;
	}

	printf("local_addr('%d.%d.%d.%d', %d)\n", local_addr.sin_addr.s_addr & 0xFF,
			(local_addr.sin_addr.s_addr >> 8) & 0xFF,
			(local_addr.sin_addr.s_addr >> 16) & 0xFF,
			(local_addr.sin_addr.s_addr >> 24) & 0xFF,
			ntohs(local_addr.sin_port));

	len = sizeof(local_addr);

	while (1) {
		recvfrom(nSockFd, recvBuff, BUFF_SIZE, 0,
				(struct sockaddr*) &local_addr, (socklen_t*) &len);
		printf("read:%s \n", recvBuff);
	}
	closesocket(nSockFd);									//必要关闭网卡
	closesocket(fd);									//关闭socket

	return 0;
}

