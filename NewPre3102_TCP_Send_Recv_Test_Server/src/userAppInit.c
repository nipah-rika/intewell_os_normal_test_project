/*********************************************************************************
*				                                         �ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
* 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * �޸���ʷ��
 * 2017-05-10     ����, �ƶ������ݣ�����Ƽ����޹�˾
 *                �������ļ���
 *                
*/

/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

/**************************** ���ò��� ***************************************/
#include "lwip/sockets.h"
#include <ttos.h>
#include <test.h>
#include <netif_adapter.h>
#include <devinfo.h>
#include "lwip/netif.h"


#define BUFF_SIZE 10
static uint8_t  recvBuff[BUFF_SIZE];		//�������ݻ�����
static uint8_t  VM12Buff[BUFF_SIZE] = "0123456789";
static uint8_t  VM21Buff[BUFF_SIZE]="abcdefghij";
/**************************** ʵ�ֲ��� ***************************************/


/*	����˲��Գ���	*/
int userAppInit(void)
{
	u16_t port = 27016;				// �˿ں�
	int nSockFd, fd, ret, len;
	struct sockaddr_in local_addr, remote_addr;		//socket����
	const struct nic_name *p = NULL;				// ����nic_name�ṹ��ָ����������
	T_ULONG nic_num = 0;			// ��������
	int i;										// ѭ��������
	/*��ȡ�������б�(Ŀ����Ϊ���޸�IP��ʱ��ʹ��)*/
	p = TTOS_GetNicNameList(&nic_num);
	if(NULL != p)
	{
		 for(i = 0; i < nic_num; i++)
		{
			printf("p[%d]=%s\n",i,&p[i]);
		}
	}

	// �����׽����ļ�������
	nSockFd = socket(AF_INET, SOCK_STREAM, 0);
	if (nSockFd < 0)
	{
		printf("###sock err 1\n");
		return -4;
	}

	// ����ip����
	local_addr.sin_len = sizeof(local_addr);							//��ַ����
	local_addr.sin_family = AF_INET;									//���紫��
	local_addr.sin_addr.s_addr = inet_addr(TTOS_IP_vm2);			//�����ip
	local_addr.sin_port = htons(port);									//������תΪ����Ķ˿ں�

	// bing()���׽��ֽ��е�ַ�Ͷ˿ڰ�
	if (bind(nSockFd, (struct sockaddr *) &local_addr, sizeof(local_addr)))
	{
		printf("###sock err 2\n");
		return -5;
	}

	if (listen(nSockFd, 5))						//5����������������������˿��Թ����ˣ�����ֻҪ�пͷ������󣬾Ϳ����ɷ���Ӧ������ ׼��
	{
		printf("###sock err 3\n");
		return -6;
	}
    printf("listen('%d.%d.%d.%d', %d)\n",
    		local_addr.sin_addr.s_addr & 0xFF,
           (local_addr.sin_addr.s_addr >> 8) & 0xFF,
           (local_addr.sin_addr.s_addr >> 16) & 0xFF,
           (local_addr.sin_addr.s_addr >> 24) & 0xFF,
		   ntohs(local_addr.sin_port) );

	len = sizeof(remote_addr);
	fd = accept(nSockFd, (struct sockaddr *) &remote_addr, (socklen_t *) &len);			//remote_addr�ͷ��˵ĵ�ַ������˽���һ���������
	// printf("accept() = %d;0x%x\n", fd,remote_addr.sin_addr.s_addr);

	TTOS_SleepTask(TTOS_GetSysClkRate());														//�ȴ��ͻ��˷������

	recv(fd, recvBuff, BUFF_SIZE, 0);
	ret = memcmp(recvBuff, VM12Buff, sizeof(VM12Buff));									//�ȽϽ��ջ������е������뷢�͵����ݰ��Ƿ�һ��
	if(0 == ret)		// ret=0˵�����ܵ����Կͻ��˵���Ϣ��ȷ
	{
		printf("vm2(server) recv success!\n");
		send(fd, VM21Buff,10,0);																			//���ճɹ�������ͻ��˷�������
	}
	else
	{
		printf("***Test Failed, error: %d, filename: %s line: %d***\r\n",errno, __FILE__, __LINE__);
	}

	closesocket(nSockFd);//��Ҫ�ر�����
	closesocket(fd);//�ر�socket

	return 0;
}

