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
#include <test.h>
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

	FILE *fd = NULL;							// �ļ�ָ��
	char str[20] = "hello world!!";		// ��Ҫд���ļ����ַ���
	char filename[256] = FS_ROOT;	// д����ļ���·��
	char readbuf[50];						// ���ն�ȡ���ַ���
	int iRet;
	int err = 0;

	strcat(filename, "/test.txt");			// ���ļ�·��ƴ������

	remove(filename);						// �������ļ������Ƴ�ԭ���ļ�

	fd = fopen(filename, "w");			// ���ļ����ļ������ڻ��Զ�����

	printk("\n***Test start***\nstart of write file		write: %s\n", str);
	iRet = fwrite(str, sizeof(char), strlen(str), fd);	// ��str����д���ļ�
	if (iRet != strlen(str)) {				// �ж��ļ��Ƿ�����д��ɹ�
		printf("ERROR\n");
		TEST_FAILRINT();
		err++;
	}
	fclose(fd);									// �ر��ļ�

	fd = fopen(filename, "r");

	iRet = fread(readbuf, sizeof(char), strlen(str), fd);// ��ȡ���ݣ���ȡ�������ݴ���readbuf��
	if (iRet != strlen(str)) {				// �ж��ļ��Ƿ�������ȡ�ɹ�
		printf("ERROR\n");

		TEST_FAILRINT();
		err++;
	}

	printk("\nend of read file		read: %s \n", readbuf);
	fclose(fd);									// �ر��ļ�
	remove(filename);						// ɾ���ļ�

	if(err!=0){

		printk("***Test Failed, error: %d, filename: %s line: %d***\r\n",errno, __FILE__, __LINE__);
	}else{

		printk("***Test Pass, filename: %s ***\r\n", __FILE__);
	}

	return 0;
}

