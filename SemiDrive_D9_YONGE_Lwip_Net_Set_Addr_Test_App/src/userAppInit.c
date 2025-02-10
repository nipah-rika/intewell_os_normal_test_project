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
#include <netif_adapter.h>
#include <devinfo.h>
#include "lwip/netif.h"

#define DATA "123456789" // 发送的数据
/**************************** 实现部分 ***************************************/

/*
 * 	说明：
 * 	通过lwip提供的函数对网络ip、gateway、netmask进行修改
 * 	首先在IDE配置项目虚拟机配置里将网卡ip、gateway、netmask配置好
 * 	然后以UDP协议向PC发送数据，PC使用NetAssist网络调试工具接收
 * 	使用相关函数修改ip、gateway、netmask，再向PC发送数据
 * 	或者在PC端ping修改过后的ip
 *
 * */

int userAppInit(void) {
	struct netif *pnetif;		// 网络接口
	ip4_addr_t ipaddr;			// ip地址
	ip4_addr_t gwaddr;		// gateway地址
	ip4_addr_t netmask;		// netmask地址
	u16_t port = 27016;				// 端口号
	int nSockFd, fd, ret, len;
	struct sockaddr_in remote_addr;		//socket对象
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

	// 创建UDP套接字
	nSockFd = socket(AF_INET, SOCK_DGRAM, 0);
	if (nSockFd < 0) {
		printf("###sock err 1\n");
		return -4;
	}

	// 目标ip配置
	memset(&remote_addr, 0, sizeof(remote_addr));
	remote_addr.sin_family = AF_INET;									//网络传输
	remote_addr.sin_addr.s_addr = inet_addr("192.168.1.141");			//服务端ip
	remote_addr.sin_port = htons(port);							//本机的转为网络的端口号

	printf("remote_addr('%d.%d.%d.%d', %d)\n", remote_addr.sin_addr.s_addr & 0xFF,
			(remote_addr.sin_addr.s_addr >> 8) & 0xFF,
			(remote_addr.sin_addr.s_addr >> 16) & 0xFF,
			(remote_addr.sin_addr.s_addr >> 24) & 0xFF,
			ntohs(remote_addr.sin_port));

	int m = 10;
	printk("first send\n");
	// 修改网络配置之前，向目标ip发送数据
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
		 // 获取网卡名
		 if_indextoname(i, ip_name);
	}
	 printk("ipname:%s\n",ip_name);

    printk("\r\nbefore change\r\n");
	//  修改之前，显示系统全部网络接口信息
	if_show();

	// 通过网络接口名获取网络接口
    pnetif = netif_find(ip_name);

    // 在网络使用中修改网络配置，需要先禁用网卡接口
	netif_set_down(pnetif);

	// 将字符串ip转换成数字
	ipaddr_aton("10.10.8.70", &ipaddr);
	// 将字符串gateway转换成数字
	ipaddr_aton("10.10.8.1", &gwaddr);
	// 将字符串netmask转换成数字
	ipaddr_aton("255.255.255.0", &netmask);

	// 在网络使用中，实现IP的修改
	netif_set_ipaddr(pnetif, &ipaddr);
	/// 在网络使用中，实现netmask的修改
	netif_set_gw(pnetif, &gwaddr);
	// 在网络使用中，实现gateway的修改
	netif_set_netmask(pnetif, &netmask);

    // 配置完毕，启用网络接口
	netif_set_up(pnetif);

    printk("\r\nafter change\r\n");
	//  修改之后，显示系统全部网络接口信息
	if_show();

	remote_addr.sin_addr.s_addr = inet_addr("10.10.8.141");			// 修改改完配置后，向相同网段的ip发送数据

	m = 20;
	printk("second send\n");
	// 修改网络配置之后，向目标ip发送数据
	while(m--){
		ret = sendto(nSockFd, DATA, sizeof(DATA), 0, (struct sockaddr*) &remote_addr, sizeof(remote_addr));
		if (ret < 0) {
			printf("sendto error, ret:%d\n", ret);
			return -1;
		}

		TTOS_SleepTask(500);
	}
	printk("send end\r\n");

	closesocket(nSockFd);									//必要关闭网卡

	return 0;
}



