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
#include <test.h>
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/
int userAppInit(void) {

	FILE *fd = NULL;							// 文件指针
	char str[20] = "hello world!!";		// 需要写入文件的字符串
	char filename[256] = FS_ROOT;	// 写入的文件根路径
	char readbuf[50];						// 接收读取的字符串
	int iRet;
	int err = 0;

	strcat(filename, "/test.txt");			// 将文件路径拼接完整

	remove(filename);						// 若已有文件，则移除原有文件

	fd = fopen(filename, "w");			// 打开文件，文件不存在会自动创建

	printk("\n***Test start***\nstart of write file		write: %s\n", str);
	iRet = fwrite(str, sizeof(char), strlen(str), fd);	// 将str数据写入文件
	if (iRet != strlen(str)) {				// 判断文件是否完整写入成功
		printf("ERROR\n");
		TEST_FAILRINT();
		err++;
	}
	fclose(fd);									// 关闭文件

	fd = fopen(filename, "r");

	iRet = fread(readbuf, sizeof(char), strlen(str), fd);// 读取数据，读取到的数据存入readbuf中
	if (iRet != strlen(str)) {				// 判断文件是否完整读取成功
		printf("ERROR\n");

		TEST_FAILRINT();
		err++;
	}

	printk("\nend of read file		read: %s \n", readbuf);
	fclose(fd);									// 关闭文件
	remove(filename);						// 删除文件

	if(err!=0){

		printk("***Test Failed, error: %d, filename: %s line: %d***\r\n",errno, __FILE__, __LINE__);
	}else{

		printk("***Test Pass, filename: %s ***\r\n", __FILE__);
	}

	return 0;
}

