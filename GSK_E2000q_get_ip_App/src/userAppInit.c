
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
#include "lwip/stats.h"
//#define BUFF_SIZE 10
/**************************** 实现部分 ***************************************/

int userAppInit(void) {
	find_netif(NULL, NULL);
	return 0;
}

