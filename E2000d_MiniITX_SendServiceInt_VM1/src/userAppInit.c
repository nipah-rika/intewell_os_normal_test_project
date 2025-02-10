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
#include <partition.h>
#include<vmkVint.h>
#include<ttos.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/
/*	虚拟中断处理程序	*/
T_VOID Handler1() {
	printk("vm1 recv service int 1\n");
}
/*	虚拟中断处理程序	*/
T_VOID Handler2() {
	printk("vm1 recv service int 2\n");
}
/*	虚拟中断处理程序	*/
T_VOID Handler4() {
	printk("vm1recv service int 4\n");
}
/*	虚拟中断处理程序	*/
T_VOID Handler5() {
	printk("vm1 recv service int 5\n");
}

int userAppInit(void) {
	T_VBSP_ReturnCode ret;
	T_UWORD vm1ID;
	T_UWORD vm2ID;

	printk(">>>vm1 entry\n");

	printk("InstallVintHandler..... \n");

	/* 安装服务请求中断，中断号为1，虚拟中断处理程序为Handler1 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 1, Handler1,TTOS_VINT_USERDEFINE);
	if (ret != VBSP_OK) {

		printk("TTOS_InstallVintHandler  ret %d\n", ret);
	}
	/* 安装服务请求中断，中断号为2，虚拟中断处理程序为Handler2 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 2, Handler2,TTOS_VINT_USERDEFINE);
	if (ret != VBSP_OK) {

		printk("TTOS_InstallVintHandler  ret %d\n", ret);
	}
	/* 安装服务请求中断，中断号为4，虚拟中断处理程序为Handler4 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 4, Handler4,TTOS_VINT_USERDEFINE);
	if (ret != VBSP_OK) {

		printk("TTOS_InstallVintHandler  ret %d\n", ret);
	}
	/* 安装服务请求中断，中断号为5，虚拟中断处理程序为Handler5 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 5, Handler5,TTOS_VINT_USERDEFINE	);
	if (ret != VBSP_OK) {

		printk("TTOS_InstallVintHandler  ret %d\n", ret);
	}

	printk("InstallVintHandler over\n");

	/*	获取vm1的ID	*/
	ret = VMK_GetVMID("vm1", &vm1ID);
	if (ret != VMK_OK) {
		printk("get id fail\n");
	}
	/*	获取vm2的ID	*/
	ret = VMK_GetVMID("vm2", &vm2ID);
	if (ret != VMK_OK) {
		printk("get id fail\n");
	}

	/*		向vm1发送虚拟服务中断，中断号为1	*/
	printk("send service int 1...\n");
	ret = VMK_SendServiceInt(vm1ID, 1);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	/*		向vm1发送虚拟服务中断，中断号为2	*/
	printk("send service int 2...\n");
	ret = VMK_SendServiceInt(vm1ID, 2);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	/*		向vm1发送虚拟服务中断，中断号为4	*/
	printk("send service int 4...\n");
	ret = VMK_SendServiceInt(vm1ID, 4);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	/*		向vm1发送虚拟服务中断，中断号为5	*/
	printk("send service int 5...\n");
	ret = VMK_SendServiceInt(vm1ID, 5);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}

	/*		向vm2发送虚拟服务中断，中断号为6	*/
	ret = VMK_SendServiceInt(vm2ID, 6);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	else{

	printk("send service int 6...\n");
	}
	/*		向vm2发送虚拟服务中断，中断号为7	*/
	ret = VMK_SendServiceInt(vm2ID, 7);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	else{

	printk("send service int 7...\n");
	}
	/*		向vm2发送虚拟服务中断，中断号为9	*/
	ret = VMK_SendServiceInt(vm2ID, 9);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	else{

	printk("send service int 9...\n");
	}
	/*		向vm2发送虚拟服务中断，中断号为11	*/
	ret = VMK_SendServiceInt(vm2ID, 11);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	else{

	printk("send service int 11...\n");
	}

	printk("send service int over \n");
	return 0;
}

