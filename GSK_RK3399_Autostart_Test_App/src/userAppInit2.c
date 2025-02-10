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
static uint8_t  recvBuff[BUFF_SIZE];		//�������ݻ�����
static uint8_t  VM12Buff[BUFF_SIZE] = "0123456789";
static uint8_t  VM21Buff[20]="Login Successful";
static uint8_t  VM211Buff[60]="START handcontrol state='8' type='Reboot' check='120' END";

    int status;
	u16_t port = 4600;				// �˿ں�
	int nSockFd, fd2, ret, len;
	struct sockaddr_in local_addr, remote_addr;		//socket����
	const struct nic_name *p = NULL;				// ����nic_name�ṹ��ָ����������
	T_ULONG nic_num = 0;			// ��������
	int i;										// ѭ��������




    FILE *fd = NULL;
    int num = 0;
    int newNum = 0;
    char filename[256] = FS_ROOT;
    char buffer[50];
    int iRet;
    int err = 0;

    strcat(filename, "/test3.txt"); // ���ļ�·��ƴ������

    printk("%s",filename);



    // ���ļ�����ȡ����
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

    // ��������һ
    printk("num=%d",num);

    newNum = num + 1;

    // ���´��ļ���д���µ�����
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

    // ������
    printf("New number written to file: %d\n", newNum);

cleanup:
    // �ر��ļ���������Դ


if (fd != NULL) {
        fclose(fd);
    }
    // ������Ҫɾ���ļ������Թ�����ʹ��
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

    	// ����ip����
    	local_addr.sin_len = sizeof(local_addr);							//��ַ����
    	local_addr.sin_family = AF_INET;									//���紫��
    	local_addr.sin_addr.s_addr = inet_addr("192.168.0.99");			//�����ip
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
    	fd2= accept(nSockFd, (struct sockaddr *) &remote_addr, (socklen_t *) &len);			//remote_addr�ͷ��˵ĵ�ַ������˽���һ���������
    	 printf("accept() = %d;0x%x\n", fd,remote_addr.sin_addr.s_addr);
    	printk("%d\n",fd2);

    	TTOS_SleepTask(TTOS_GetSysClkRate());														//�ȴ��ͻ��˷������

    	sleep(2);
    	int f;
    	f= send(fd2, VM21Buff,20,0);
    	printk("%d",f);
    	sleep(2);
    	send(fd2, VM211Buff,60,0);//���ճɹ�������ͻ��˷�������

    	closesocket(nSockFd);//��Ҫ�ر�����
    	closesocket(fd);//�ر�socket



    return err; // ���ش��������0��ʾ�ɹ�����0��ʾʧ��
}



