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
#include<pthread.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

static pthread_barrier_t bt;
static pthread_t thread_id1;
static pthread_t thread_id2;
static pthread_attr_t thread_attr1;
static pthread_attr_t thread_attr2;

/*	创建任务的钩子函数	*/
void* add_task_hook() {
	printk("add_task_hook run\n");
}
/*	切换任务的钩子函数	*/
void* switch_task_hook() {
	printk("switch_task_hook run\n");
}
/*	删除任务的钩子函数	*/
void* close_task_hook() {
	printk("delete_task_hook run\n");
}
/*	test task1	*/
void* task1() {
	// 等待线程屏障，使线程同步
	pthread_barrier_wait(&bt);
	printk("task1 running...\n");
	printk("task1 running...\n");
	printk("task1 running...\n");

}
/*	test task2	*/
void* task2() {
	// 等待线程屏障，使线程同步
	pthread_barrier_wait(&bt);
	printk("task2 running...\n");
	printk("task2 running...\n");
	printk("task2 running...\n");

}


int userAppInit(void) {
	int status;

	/*	添加任务创建的钩子函数至任务创建的钩子函数列表	*/
	status = pthread_create_hook_add(add_task_hook);
	if (status != 0) {
		printk("add create hook failed....status:%d\n", status);
	}

	/*	添加任务切换的钩子函数至任务切换的钩子函数列表	*/
	status = pthread_switch_hook_add(switch_task_hook);
	if (status != 0) {
		printk("add switch hook failed....status:%d\n", status);
	}

	/*	添加任务删除的钩子函数至任务删除的钩子函数列表	*/
	status = pthread_close_hook_add(close_task_hook);
	if (status != 0) {
		printk("add close hook failed....status:%d\n", status);
	}

	// 初始化线程屏障
	pthread_barrier_init(&bt, NULL, 3);

	//创建任务，使用默认值初始化一个任务属性对象 attr，初始化默认值是由系统确定的
	pthread_attr_init(&thread_attr1);
	pthread_attr_init(&thread_attr2);

	//设置task1线程属性
	thread_attr1.stackaddr = NULL;/*	任务栈地址	   */
	thread_attr1.stacksize = PTHREAD_STACK_MIN * 2; /*	任务栈大小		*/
	thread_attr1.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	任务的调度策略及调度属性由任务属性对象设置	*/
	thread_attr1.schedpolicy = SCHED_RR;/*	优先级抢占的调度策略: 进行优先级调度并且相同优先级的任务进行时间片轮转调度	*/
	thread_attr1.schedparam.sched_priority = 100;/*	设置任务的优先级	 */
	thread_attr1.name = "task1";/*	任务名称，为NULL时使用系统分配的任务名字	*/

	//设置task2线程属性
	thread_attr2.stackaddr = NULL;/*	任务栈地址	   */
	thread_attr2.stacksize = PTHREAD_STACK_MIN * 2; /*	任务栈大小		*/
	thread_attr2.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	任务的调度策略及调度属性由任务属性对象设置	*/
	thread_attr2.schedpolicy = SCHED_RR;/*	优先级抢占的调度策略: 进行优先级调度并且相同优先级的任务进行时间片轮转调度	*/
	thread_attr2.schedparam.sched_priority = 100;/*	设置任务的优先级	 */
	thread_attr2.name = "task2";/*	任务名称，为NULL时使用系统分配的任务名字	*/

	// 创建task1线程
	status = pthread_create(&thread_id1, &thread_attr1, task1, NULL);
	if (status == 0) {
		printk("task1 create succesful\n");

	} else {
		printk("task1 create Failed\n");
		return -1;
	}

	// 创建task2线程
	status = pthread_create(&thread_id2, &thread_attr2, task2, NULL);
	if (status == 0) {
		printk("task2 create succesful\n");

	} else {
		printk("task2 create Failed\n");
		return -1;
	}

	// 等待线程屏障，使线程同步
	pthread_barrier_wait(&bt);

	// 挂起调用任务，直到task1终止
	pthread_join(thread_id1, NULL);
	// 挂起调用任务，直到task2终止
	pthread_join(thread_id2, NULL);

	/*	从任务切换的钩子函数列表删除指定的钩子函数	*/
	status = pthread_switch_hook_delete(switch_task_hook);
	if (status != 0) {
		printk("switch del failed....status:%d\n", status);
	}

	/*	从任务创建的钩子函数列表删除指定的钩子函数	*/
	status = pthread_create_hook_delete(add_task_hook);
	if (status != 0) {
		printk("create del failed....status:%d\n", status);
	}

	/*	从任务删除的钩子函数列表删除指定的钩子函数	*/
	status = pthread_close_hook_delete(close_task_hook);
	if (status != 0) {
		printk("close del failed....status:%d\n", status);
	}
	printk("deleted all hook\n");
	return 0;
}

