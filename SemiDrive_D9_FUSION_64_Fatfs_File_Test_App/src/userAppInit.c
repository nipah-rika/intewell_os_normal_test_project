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
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/



int userAppInit(void) {

	int fd;						// �ļ�ָ��
	char fileName[50] = "/mount/fatfs_C";	// д����ļ���·��
	char newName[50] = "/mount/fatfs_C";
	char readbuf[50];						// ���ն�ȡ���ַ���
	int iRet;
	int err = 0;

	char str[20] = "hello world";		// ��Ҫд���ļ����ַ���

	mode_t mode = S_IRWXU|S_IRWXG|S_IRWXO;	// ����ӵ���ߡ��顢�����û��ɶ���д��ִ�С�����

	strcat(fileName, "/test1.txt");			// ���ļ�·��ƴ������

	remove(fileName);						// �������ļ������Ƴ�ԭ���ļ�

	printk("create file name:%s\n",fileName);
	fd = creat(fileName,mode);			// �����ļ���mode�����ļ����Ȩ��
	if(fd == -1){
		printk("create file error\n");
		err++;
	}
	close(fd);									// �������ļ��� ��Ҫ�ر��ļ��ٽ�����������


	fd=open(fileName, O_WRONLY);// ��д�ķ�ʽ���ļ����ļ������ڻ��Զ�����

	printk("\n***Test start***\nstart of write file		write: %s\n", str);
	iRet = write(fd, str, strlen(str));	// ��str����д���ļ�
	if (iRet != strlen(str)) {				// �ж��ļ��Ƿ�����д��ɹ�
		printk("***Test Failed, filename: %s line: %d***\r\n",  __FILE__, __LINE__);
		err++;
	}
	close(fd);									// �ر��ļ�


	fd = open(fileName, O_RDONLY);// �Զ��ķ�ʽ���ļ����ļ������ڻ��Զ�����

	iRet = read(fd, readbuf, strlen(str));// ��ȡ���ݣ���ȡ�������ݴ���readbuf��
	if (iRet != strlen(str)) {				// �ж��ļ��Ƿ�������ȡ�ɹ�
		printk("***Test Failed, filename: %s line: %d***\r\n",  __FILE__, __LINE__);
		err++;
	}
	printk("\nend of read file		read: %s \n", readbuf);
	close(fd);									// �ر��ļ�

	strcat(newName, "/test2.txt");			// ���ļ�·��ƴ������

	printk("rename file name:%s\n", newName);
	iRet = rename(fileName, newName);// ���ļ�������
	if(iRet == -1){
		printk("rename file fail\n");
		err++;
	}

	printk("remove file name:%s\n", newName);
	iRet = remove(newName);						// ɾ���ļ�
	if(iRet == -1){
		printk("remove file fail\n");
		err++;
	}


	if(err!=0){

		printk("***Test Failed, error: %d, filename: %s line: %d***\r\n",errno, __FILE__, __LINE__);
	}else{

		printk("***Test Pass, filename: %s ***\r\n", __FILE__);
	}

	return 0;
}

