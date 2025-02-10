/****************************************************************************
 *				�ƶ������ݣ�����������޹�˾ ��Ȩ����
 *
 * 		 Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 ***************************************************************************/
/* <EXECL>
�������ʶ��:
����

������������ʶ��
RTOS_NET_FT_TCP_001

��Ŀ������͡�:
��ҵ������

������Ŀ�ġ�
����ͨ��tcpЭ��������˺Ϳͻ����ܷ�ͨ��send��recv���͡��������ݡ�

���������͡�
���ܲ���

���Ⱦ�������
1������������������Ŀ���֮������ӡ�
2������vm1ΪTCP�ͻ��ˣ�vm2ΪTCP����ˡ�

�����Բ��衿
1��vm1��vm2�������ݣ�
2��vm2��������֮������vm1�������ݣ�
3��vm1�������ݣ�
4���鿴ͬʱ��������ͨ��ʱ�����ݰ������뷢���Ƿ�һ�¡�

��Ԥ�ڽ����
�ɹ����պͷ������ݡ�

������׼��
��Ԥ�ڽ��һ��

�������Լ����
����ϵͳ������

������ߡ�:
XXX

�����ʱ�䡿:
2020-01-18

</EXECL> */
/**************************** ���ò��� ***************************************/

#include <ttos.h>
#include <test.h>
#include <netif_adapter.h>
#include <devinfo.h>
#include <sys/socket.h>
#include <arch/sys/sys_os.h>


#define BUFF_SIZE 64
static uint8_t  recvBuff[BUFF_SIZE];
static uint8_t  VM12Buff[BUFF_SIZE] = "0123456789abcdefg, from client.";
/**************************** ʵ�ֲ��� ***************************************/


int RTOS_NET_FT_TCP_001(void)
{
	u16_t port = 27016;
	int nSockFd, status, ret;
	struct sockaddr_in remote_addr;
	int i;
	const struct nic_name *p = NULL;
	T_ULONG nic_num = 0;
    char  ip_name[4];
	/*��ȡ�������б�(Ŀ����Ϊ���޸�IP��ʱ��ʹ��)*/
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
    


