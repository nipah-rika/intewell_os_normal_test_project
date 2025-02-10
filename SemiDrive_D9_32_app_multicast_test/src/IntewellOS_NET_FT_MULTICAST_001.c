/****************************************************************************
 *				�ƶ������ݣ�����������޹�˾ ��Ȩ����
 *
 * 		 Copyright (C) 2020-2024 Kyland Systems Inc. All Rights Reserved.
 ***************************************************************************/
 
/* <EXECL>
�������ʶ��:
����UDP�鲥����

������������ʶ��
IntewellOS_NET_FT_MULTICAST_001

��Ŀ������͡�:
��ҵ������

������Ŀ�ġ�
����UDP�鲥���շ��ܷ�ɹ���

���������͡�
���ܲ���

���Ⱦ�������
1������������������Ŀ���֮������ӣ�
2������vm1ΪUDP�鲥���ͷ���vm2ΪUDP�鲥���շ���vm3ͬΪUDP�鲥���շ�,3������ʹ��ͬһpf�Ĳ�ͬvf��
3������������Ŀ����������С�

�����Բ��衿
1��vm1��һ��ʱ����ѭ�����ⷢ��UDP�鲥���ݣ�
2��vm2����ಥ�飬ѭ�������鲥���ݣ��������ݽ��з�ת���ٶ��ⷢ��UDP�鲥���ݣ�
3��vm3����ಥ�飬ѭ�������鲥���ݣ�
4���鿴ͬʱ��������ͨ��ʱ�����ݰ������뷢���Ƿ�һ�¡�

��Ԥ�ڽ����
vm2����vm1���͵Ķಥ�����ݣ�vm3����vm1��vm2���͵Ķಥ�����ݣ����������Ƿ��ġ�

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
#define MCAST_DATA				"0123456789"			//�ಥ���͵�����
#define MCAST_INTERVAL			150									//���ͼ��ʱ��  200ticks
/**************************** ʵ�ֲ��� ***************************************/


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

	memset(&mcast_addr, 0, sizeof(mcast_addr));										//��ʼ��IP�ಥ��ַΪ0
	mcast_addr.sin_family = AF_INET;															//����Э��������ΪAF
	mcast_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);							//���öಥIP��ַ
	mcast_addr.sin_port = htons(MCAST_PORT);											//���öಥ�˿�

	/*��ಥ��ַ��������*/
	while(1)
	{
		ret = sendto(fd, MCAST_DATA, sizeof(MCAST_DATA), 0, (struct sockaddr*)&mcast_addr, sizeof(mcast_addr));
		if(ret < 0)
		{
			printf("sendto error, ret:%d\n", ret);
			return -1;
		}
		TTOS_SleepTask(MCAST_INTERVAL);												//�ȴ�һ��ʱ�䣨��λ��ticks��
	}
	closesocket(fd);
	return 0;
}
    


