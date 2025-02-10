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
#include <netif_adapter.h>
#include <devinfo.h>
#include "lwip/netif.h"

#define DATA "123456789" // ���͵�����
/**************************** ʵ�ֲ��� ***************************************/

/*
 * 	˵����
 * 	ͨ��lwip�ṩ�ĺ���������ip��gateway��netmask�����޸�
 * 	������IDE������Ŀ����������ｫ����ip��gateway��netmask���ú�
 * 	Ȼ����UDPЭ����PC�������ݣ�PCʹ��NetAssist������Թ��߽���
 * 	ʹ����غ����޸�ip��gateway��netmask������PC��������
 * 	������PC��ping�޸Ĺ����ip
 *
 * */

int userAppInit(void) {
	struct netif *pnetif;		// ����ӿ�
	ip4_addr_t ipaddr;			// ip��ַ
	ip4_addr_t gwaddr;		// gateway��ַ
	ip4_addr_t netmask;		// netmask��ַ
	u16_t port = 27016;				// �˿ں�
	int nSockFd, fd, ret, len;
	struct sockaddr_in remote_addr;		//socket����
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

	// ����UDP�׽���
	nSockFd = socket(AF_INET, SOCK_DGRAM, 0);
	if (nSockFd < 0) {
		printf("###sock err 1\n");
		return -4;
	}

	// Ŀ��ip����
	memset(&remote_addr, 0, sizeof(remote_addr));
	remote_addr.sin_family = AF_INET;									//���紫��
	remote_addr.sin_addr.s_addr = inet_addr("192.168.1.141");			//�����ip
	remote_addr.sin_port = htons(port);							//������תΪ����Ķ˿ں�

	printf("remote_addr('%d.%d.%d.%d', %d)\n", remote_addr.sin_addr.s_addr & 0xFF,
			(remote_addr.sin_addr.s_addr >> 8) & 0xFF,
			(remote_addr.sin_addr.s_addr >> 16) & 0xFF,
			(remote_addr.sin_addr.s_addr >> 24) & 0xFF,
			ntohs(remote_addr.sin_port));

	int m = 10;
	printk("first send\n");
	// �޸���������֮ǰ����Ŀ��ip��������
	while(m--){
		ret = sendto(nSockFd, DATA, sizeof(DATA), 0, (struct sockaddr*) &remote_addr, sizeof(remote_addr));
		if (ret < 0) {
			printf("sendto error, ret:%d\n", ret);
			return -1;
		}
		TTOS_SleepTask(500);
	}
	printk("send end\r\n");

    char  ip_name[4];
	 for(i = 1; i < (nic_num+1); i++)
	{
		 // ��ȡ������
		 if_indextoname(i, ip_name);
	}
	 printk("ipname:%s\n",ip_name);

    printk("\r\nbefore change\r\n");
	//  �޸�֮ǰ����ʾϵͳȫ������ӿ���Ϣ
	if_show();

	// ͨ������ӿ�����ȡ����ӿ�
    pnetif = netif_find(ip_name);

    // ������ʹ�����޸��������ã���Ҫ�Ƚ��������ӿ�
	netif_set_down(pnetif);

	// ���ַ���ipת��������
	ipaddr_aton("10.10.8.70", &ipaddr);
	// ���ַ���gatewayת��������
	ipaddr_aton("10.10.8.1", &gwaddr);
	// ���ַ���netmaskת��������
	ipaddr_aton("255.255.255.0", &netmask);

	// ������ʹ���У�ʵ��IP���޸�
	netif_set_ipaddr(pnetif, &ipaddr);
	/// ������ʹ���У�ʵ��netmask���޸�
	netif_set_gw(pnetif, &gwaddr);
	// ������ʹ���У�ʵ��gateway���޸�
	netif_set_netmask(pnetif, &netmask);

    // ������ϣ���������ӿ�
	netif_set_up(pnetif);

    printk("\r\nafter change\r\n");
	//  �޸�֮����ʾϵͳȫ������ӿ���Ϣ
	if_show();

	remote_addr.sin_addr.s_addr = inet_addr("10.10.8.141");			// �޸ĸ������ú�����ͬ���ε�ip��������

	m = 20;
	printk("second send\n");
	// �޸���������֮����Ŀ��ip��������
	while(m--){
		ret = sendto(nSockFd, DATA, sizeof(DATA), 0, (struct sockaddr*) &remote_addr, sizeof(remote_addr));
		if (ret < 0) {
			printf("sendto error, ret:%d\n", ret);
			return -1;
		}

		TTOS_SleepTask(500);
	}
	printk("send end\r\n");

	closesocket(nSockFd);									//��Ҫ�ر�����

	return 0;
}



