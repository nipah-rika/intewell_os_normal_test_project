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

/************************头 文 件******************************/
#include <commonTypes.h>
//#include <test.h>
//#include <test1.h>
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "lwip/sockets.h"
#include <ttos.h>
#include <netif_adapter.h>
#include <devinfo.h>
//#include <test3.h>
#include "lwip/netif.h"




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int userAppInit(void) {

#define BUFF_SIZE 10
static uint8_t  recvBuff[BUFF_SIZE];		//接收数据缓冲区
static uint8_t  VM12Buff[BUFF_SIZE] = "0123456789";
static uint8_t  VM21Buff[20]="Login Successful";
static uint8_t  VM211Buff[60]="START handcontrol state='8' type='Reboot' check='120' END";

    int status;
	u16_t port = 4600;				// 端口号
	int nSockFd, fd2, ret, len;
	struct sockaddr_in local_addr, remote_addr;		//socket对象
	const struct nic_name *p = NULL;				// 创建nic_name结构体指针存放网卡名
	T_ULONG nic_num = 0;			// 网卡数量
	int i;										// 循环迭代数




    FILE *fd = NULL;
    int num = 0;
    int newNum = 0;
    char filename[256] = FS_ROOT;
    char buffer[50];
    int iRet;
    int err = 0;

    strcat(filename, "/test3.txt"); // 将文件路径拼接完整

    printk("%s",filename);



    // 打开文件并读取整数
    fd = fopen(filename, "r");
    if (fd == NULL) {
        perror("Error opening file for reading");
        err++;
        goto cleanup;
    }
    iRet = fscanf(fd, "%d", &num);
    if (iRet != 1) {
        printf("ERROR: Failed to read integer from file.\n");
        err++;
        goto cleanup;
    }

    // 将整数加一
    printk("num=%d",num);

    newNum = num + 1;

    // 重新打开文件以写入新的整数
    fclose(fd);
    fd = fopen(filename, "w");
    if (fd == NULL) {
        perror("Error opening file for writing");
        err++;
        goto cleanup;
    }
    fprintf(fd, "%d", newNum);
    printk("newNum=%d", newNum);
    fclose(fd);

    // 输出结果
    printf("New number written to file: %d\n", newNum);

cleanup:
    // 关闭文件并清理资源


if (fd != NULL) {
        fclose(fd);
    }
    // 根据需要删除文件或保留以供后续使用
    // remove(filename);

    if (err != 0) {
        printf("***Test Failed, error: %d***\n", errno);
    } else {
        printf("***Test Pass***\n");
    }








    p = TTOS_GetNicNameList(&nic_num);
    	if(NULL != p)
    	{
    		 for(i = 0; i < nic_num; i++)
    		{
    			printf("p[%d]=%s\n",i,&p[i]);
    		}
    	}


    	nSockFd = socket(AF_INET, SOCK_STREAM, 0);
    	if (nSockFd < 0)
    	{
    		printf("###sock err 1\n");
    		return -4;
    	}

    	// 本地ip配置
    	local_addr.sin_len = sizeof(local_addr);							//地址长度
    	local_addr.sin_family = AF_INET;									//网络传输
    	local_addr.sin_addr.s_addr = inet_addr("192.168.0.99");			//服务端ip
    	local_addr.sin_port = htons(port);									//本机的转为网络的端口号

    	// bing()对套接字进行地址和端口绑定
    	if (bind(nSockFd, (struct sockaddr *) &local_addr, sizeof(local_addr)))
    	{
    		printf("###sock err 2\n");
    		return -5;
    	}

    	if (listen(nSockFd, 5))						//5代表最大连接数，代表服务端可以工作了，做好只要有客服端请求，就可以派发相应操作的 准备
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
    	fd2= accept(nSockFd, (struct sockaddr *) &remote_addr, (socklen_t *) &len);			//remote_addr客服端的地址，服务端接受一个请求服务
    	 printf("accept() = %d;0x%x\n", fd,remote_addr.sin_addr.s_addr);
    	printk("%d\n",fd2);

    	TTOS_SleepTask(TTOS_GetSysClkRate());														//等待客户端发送完成

    	sleep(2);
    	int f;
    	f= send(fd2, VM21Buff,20,0);
    	printk("%d",f);
    	sleep(2);
    	send(fd2, VM211Buff,60,0);//接收成功，再向客户端发送数据

    	closesocket(nSockFd);//必要关闭网卡
    	closesocket(fd);//关闭socket



    return err; // 返回错误计数，0表示成功，非0表示失败
}



