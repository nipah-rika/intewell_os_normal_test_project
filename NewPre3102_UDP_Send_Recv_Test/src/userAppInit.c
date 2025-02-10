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
static uint8_t recvBuff[BUFF_SIZE];		//�������ݻ�����
/**************************** ʵ�ֲ��� ***************************************/

int userAppInit(void) {
	u16_t port = 27016;				// �˿ں�
	int nSockFd, fd, ret, len;
	struct sockaddr_in local_addr;		//socket����
	const struct nic_name *p = NULL;				// ����nic_name�ṹ��ָ����������
	T_ULONG nic_num = 0;			// ��������
	int i;										// ѭ��������
	/*��ȡ�������б�(Ŀ����Ϊ���޸�IP��ʱ��ʹ��)*/
	p = TTOS_GetNicNameList(&nic_num);
	if (NULL != p) {
		for (i = 0; i < nic_num; i++) {
			printf("p[%d]=%s\n", i, &p[i]);
		}
	}

	// �����׽����ļ�������
	nSockFd = socket(AF_INET, SOCK_DGRAM, 0);
	if (nSockFd < 0) {
		printf("###sock err 1\n");
		return -4;
	}

	// ����ip����
	local_addr.sin_len = sizeof(local_addr);							//��ַ����
	local_addr.sin_family = AF_INET;									//���紫��
	local_addr.sin_addr.s_addr = inet_addr("192.168.1.221");			//�����ip
	local_addr.sin_port = htons(port);							//������תΪ����Ķ˿ں�

	// bing()���׽��ֽ��е�ַ�Ͷ˿ڰ�
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
	closesocket(nSockFd);									//��Ҫ�ر�����
	closesocket(fd);									//�ر�socket

	return 0;
}

