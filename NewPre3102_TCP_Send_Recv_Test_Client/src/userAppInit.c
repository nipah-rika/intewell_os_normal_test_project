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

/************************ͷ �� ��******************************/
#include"lwip/sockets.h"
#include <commonTypes.h>
#include<ttos.h>
#include<test.h>
#include<netif_adapter.h>
#include<devinfo.h>
#include"lwip/netif.h"


/************************�� �� ��******************************/
#define BUFF_SIZE 10
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
static uint8_t recvBuff[BUFF_SIZE];	//�������ݻ�����
static uint8_t VM12Buff[BUFF_SIZE] = "0123456789";
static uint8_t VM21Buff[BUFF_SIZE] = "abcdefghij";

/************************ʵ   ��*******************************/


/*	�ͻ��˲��Գ���	*/
int userAppInit(void)
{
	u16_t port = 27016;								// �˿ں�
	int nSockFd, status, ret;
	struct sockaddr_in remote_addr;			// ����socket_in�ṹ�����
	const struct nic_name *p = NULL;			// ����nic_name�ṹ��ָ����������
	T_ULONG nic_num = 0;							// ��������
	int i;														// ѭ��������


	p = TTOS_GetNicNameList(&nic_num);		// ��ȡ�������б�

	if(NULL != p){
		for(i = 0; i < nic_num; i++){
			printf("\np[%d] = %s \n", i, &p[i]);

		}
	}

	// �����׽����ļ�������
	nSockFd = socket(AF_INET, SOCK_STREAM, 0);
	if(nSockFd < 0){
		printf("###sock err 1\n");
		return -4;
	}

	// �����ip����
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
    	// ���ӷ����
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

    // �����˷���VM12Buff
	send(nSockFd, VM12Buff, sizeof(VM12Buff), 0);
	TTOS_SleepTask(TTOS_GetSysClkRate());

	// ���ܷ���˷��ص���Ϣ����֤��Ϣ��ȷ��
	recv(nSockFd, recvBuff, BUFF_SIZE, 0);
	ret = memcmp(recvBuff, VM21Buff, sizeof(VM21Buff));									//�ȽϽ��ջ������е������뷢�͵����ݰ��Ƿ�һ��
	if(0 == ret)		// ret=0˵�����ܵ����Է���˵���Ϣ��ȷ������ͨ��
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

