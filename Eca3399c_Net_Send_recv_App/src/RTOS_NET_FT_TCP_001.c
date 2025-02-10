/****************************************************************************
 *				科东（广州）软件技术有限公司 版权所有
 *
 * 		 Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 ***************************************************************************/
/* <EXECL>
【需求标识】:
网络

【测试用例标识】
RTOS_NET_FT_TCP_001

【目标机类型】:
工业服务器

【测试目的】
测试通过tcp协议的主机端和客户端能否通过send和recv发送、接收数据。

【测试类型】
功能测试

【先决条件】
1、启动并建立主机和目标机之间的连接。
2、配置vm1为TCP客户端，vm2为TCP服务端。

【测试步骤】
1、vm1向vm2发送数据；
2、vm2接收数据之后，再向vm1发送数据；
3、vm1接收数据；
4、查看同时进行上述通信时，数据包接收与发送是否一致。

【预期结果】
成功接收和发送数据。

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

#include <ttos.h>
#include <test.h>
#include <netif_adapter.h>
#include <devinfo.h>
#include <sys/socket.h>
#include <arch/sys/sys_os.h>


#define BUFF_SIZE 64
static uint8_t  recvBuff[BUFF_SIZE];
static uint8_t  VM12Buff[BUFF_SIZE] = "0123456789abcdefg, from client.";
/**************************** 实现部分 ***************************************/


int RTOS_NET_FT_TCP_001(void)
{
	u16_t port = 27016;
	int nSockFd, status, ret;
	struct sockaddr_in remote_addr;
	int i;
	const struct nic_name *p = NULL;
	T_ULONG nic_num = 0;
    char  ip_name[4];
	/*获取网卡名列表(目的是为了修改IP的时候使用)*/
	p = TTOS_GetNicNameList(&nic_num);
	if(NULL != p)
	{
		 for(i = 0; i < nic_num; i++)
		{
			printf("p[%d]=%s\n",i,&p[i]);
		}
	}
	 for(i = 1; i < (nic_num+1); i++)
	{
		 if_indextoname(i, ip_name);
	}
	ret = ifconfig(ip_name, TTOS_IP_vm1, "255.255.255.0");

	if (ret != OS_OK)
	{
		TEST_FAILPRINT("IFCONFIG TEST FAILED");
		return PTS_FAIL;
	}

	for(i=0;i<BUFF_SIZE;i++)
	{
		recvBuff[i]='\0';
	}

	nSockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (nSockFd < 0)
	{
		printf("###sock err 1\n");
		return -4;
	}

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

	send(nSockFd, VM12Buff, 31, 0);
	TTOS_SleepTask(TTOS_GetSysClkRate());
	ret = recv(nSockFd, recvBuff, BUFF_SIZE, 0);
	if(ret < BUFF_SIZE){
		recvBuff[ret] = 0;
	}else{
		recvBuff[BUFF_SIZE -1] = 0;
	}

	printf("\n\r vm1(client) recv from server: %s\n", recvBuff);
	TEST_OKPRINT();


	return 0;
}
    


