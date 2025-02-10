/****************************************************************************
 *				�ƶ������ݣ�����������޹�˾ ��Ȩ����
 *
 * 		 Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 ***************************************************************************/
 
/* <EXECL>
�������ʶ��:
����UDP�鲥����

������������ʶ��
IntewellOS_NET_MULTICAST_001

��Ŀ������͡�:
��ҵ������

������Ŀ�ġ�
����UDP�鲥���շ��ܷ�ɹ���

���������͡�
���ܲ���

���Ⱦ�������
1������������������Ŀ���֮������ӣ�
2������vm1ΪUDP�鲥���ͷ���vm2ΪUDP�鲥���շ�,2������ʹ��ͬһpf�Ĳ�ͬvf��
3������������Ŀ����������С�

�����Բ��衿
1��vm1��һ��ʱ����ѭ�����ⷢ��UDP�鲥���ݣ�
3��vm2����ಥ�飬ѭ�������鲥���ݣ�
4���鿴ͬʱ��������ͨ��ʱ�����ݰ������뷢���Ƿ�һ�¡�

��Ԥ�ڽ����
vm2����vm1���͵Ķಥ������,����������ȷ��

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
#include "lwip/sockets.h"
#include <ttos.h>
#include <test.h>

#define MCAST_PORT 				12345
#define MCAST_ADDR 				"224.1.1.10"						//һ���ֲ����Ӷಥ��ַ��·����������ת��
#define MCAST_INTERVAL			200									//���ͼ��ʱ��
#define BUFF_SIZE					256									//���ջ�������С

static char  sendBuff_vm1[BUFF_SIZE] = "0123456789";

/**************************** ʵ�ֲ��� ***************************************/

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
	/* ���������׽��� */
	recfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(recfd < 0)
	{
		printf("recfd socket err\n");
		TEST_FAILRINT();
		return -1;
	}

	/* ���������׽��� */
	sendfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sendfd < 0)
	{
		printf("sendfd socket err\n");
		TEST_FAILRINT();
		return -1;
	}

	/* ���ñ��ػػ� */
	int yes = 1;
	if(setsockopt(recfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
	{
		printf("Reusing ADDR err\n");
		TEST_FAILRINT();
		return -1;
	}

	memset(&addr, 0, sizeof(addr));

	/* ���ý����׽��� */
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

	/* ���öಥ���� */
	mreq.imr_multiaddr.s_addr = inet_addr(MCAST_ADDR);
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);

	/* ����ಥ�� */
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
			if (0 == memcmp(bufferAddress[i], sendBuff_vm1,strlen(sendBuff_vm1)))		//�ȽϽ��ջ������е������뷢�͵����ݰ��Ƿ�һ��
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
		if (bufferAddress[i] != NULL)		//�ȽϽ��ջ������е������뷢�͵����ݰ��Ƿ�һ��
		{
			free(bufferAddress[i] );
		}
	}

	setsockopt(recfd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));   //�˳��ಥ��

	closesocket(sendfd);
	closesocket(recfd);


	return 0;
}
    


