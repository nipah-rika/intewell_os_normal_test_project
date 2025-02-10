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

	int fd;						// 文件指针
	char fileName[50] = "/mount/fatfs_C";	// 写入的文件根路径
	char newName[50] = "/mount/fatfs_C";
	char readbuf[50];						// 接收读取的字符串
	int iRet;
	int err = 0;

	char str[20] = "hello world";		// 需要写入文件的字符串

	mode_t mode = S_IRWXU|S_IRWXG|S_IRWXO;	// 设置拥有者、组、其他用户可读、写、执行、查找

	strcat(fileName, "/test1.txt");			// 将文件路径拼接完整

	remove(fileName);						// 若已有文件，则移除原有文件

	printk("create file name:%s\n",fileName);
	fd = creat(fileName,mode);			// 创建文件，mode设置文件相关权限
	if(fd == -1){
		printk("create file error\n");
		err++;
	}
	close(fd);									// 创建完文件后， 需要关闭文件再进行其他操作


	fd=open(fileName, O_WRONLY);// 以写的方式打开文件，文件不存在会自动创建

	printk("\n***Test start***\nstart of write file		write: %s\n", str);
	iRet = write(fd, str, strlen(str));	// 将str数据写入文件
	if (iRet != strlen(str)) {				// 判断文件是否完整写入成功
		printk("***Test Failed, filename: %s line: %d***\r\n",  __FILE__, __LINE__);
		err++;
	}
	close(fd);									// 关闭文件


	fd = open(fileName, O_RDONLY);// 以读的方式打开文件，文件不存在会自动创建

	iRet = read(fd, readbuf, strlen(str));// 读取数据，读取到的数据存入readbuf中
	if (iRet != strlen(str)) {				// 判断文件是否完整读取成功
		printk("***Test Failed, filename: %s line: %d***\r\n",  __FILE__, __LINE__);
		err++;
	}
	printk("\nend of read file		read: %s \n", readbuf);
	close(fd);									// 关闭文件

	strcat(newName, "/test2.txt");			// 将文件路径拼接完整

	printk("rename file name:%s\n", newName);
	iRet = rename(fileName, newName);// 给文件重命名
	if(iRet == -1){
		printk("rename file fail\n");
		err++;
	}

	printk("remove file name:%s\n", newName);
	iRet = remove(newName);						// 删除文件
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

