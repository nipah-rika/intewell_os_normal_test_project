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
#include <partition.h>
#include <commonTypes.h>
#include<vbsp.h>
#include<ttos.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

/*	虚拟中断处理程序	*/
T_VOID Handler6()
{
	printk("vm2 recv service int 6\n");
}
/*	虚拟中断处理程序	*/
T_VOID Handler7()
{
	printk("vm2 recv service int 7\n");
}
/*	虚拟中断处理程序	*/
T_VOID Handler9()
{
	printk("vm2 recv service int 9\n");
}
/*	虚拟中断处理程序	*/
T_VOID Handler11()
{
	printk("vm2 recv service int 11\n");
}



int userAppInit(void)
{
	T_VBSP_ReturnCode ret;

	printk(">>>vm2 entry\n");

	printk("InstallVintHandler..... \n");
	/* vm2安装服务请求中断，中断号为6，虚拟中断处理程序为Handler6 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 6, Handler6,TTOS_VINT_USERDEFINE);
    if (ret != VBSP_OK) {

    	printk("TTOS_InstallVintHandler  ret %d\n",ret);
    }
	/* vm2安装服务请求中断，中断号为7，虚拟中断处理程序为Handler7 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 7, Handler7,TTOS_VINT_USERDEFINE);
    if (ret != VBSP_OK) {
    	printk("TTOS_InstallVintHandler  ret %d\n",ret);
    }
	/* vm2安装服务请求中断，中断号为9，虚拟中断处理程序为Handler9 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 9, Handler9,TTOS_VINT_USERDEFINE);
    if (ret != VBSP_OK) {

    	printk("TTOS_InstallVintHandler  ret %d\n",ret);
    }
	/* vm2安装服务请求中断，中断号为11，虚拟中断处理程序为Handler11 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 11, Handler11,TTOS_VINT_USERDEFINE);
    if (ret != VBSP_OK) {

    	printk("TTOS_InstallVintHandler  ret %d\n",ret);
    }

    printk("vm2 InstallVintHandler over !!!\n");
	return 0;
}

