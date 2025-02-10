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

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

/** 运行结果：
 1. 无优先级继承保护的情况下，3个线程的运行顺序：
 	 lowTask-->midTask-->lowTask-->highTask
 	 过程解释：
 	 低优先级任务开始运行，然后被中优先级任务抢占运行，由于没有优先级继承保护，中优先级任务会一直运行直到任务完成，
 	 然后到低优先级任务继续运行，直到低优先级任务完成释放锁资源后，高优先级任务才开始运行。

 2. 有优先级继承保护的情况下，3个线程的运行顺序应该是：
	lowTask-->midTask-->lowTask-->highTask-->midTask
 	过程解释：
 	低优先级任务先运行，然后被中优先级任务抢占运行，直到高优先级任务请求互斥量资源， 由于优先级继承保护，
 	会将低优先级任务的优先级提升到高优先级，低优先级任务完成后释放互斥量资源，接着高优先级任务开始运行，
 	高优先级任务完成后释放锁资源，中优先级任务继续运行直到任务完成。

 */

static pthread_mutex_t Amutex;
static pthread_barrier_t bt;
static pthread_t thread_id1;
static pthread_t thread_id2;
static pthread_t thread_id3;
static pthread_attr_t thread_attr1;
static pthread_attr_t thread_attr2;
static pthread_attr_t thread_attr3;


static void* lowTask(void *arg) {
	cpu_set_t set = 1;
	int i = 0, j = 0;
	int res;

	// pthread_setaffinity_np设置3个线程在指定cpu上运行，pthread_self()用于获取当前任务id
	pthread_setaffinity_np(pthread_self(), sizeof(set), &set);

	//等待线程屏障，使线程同步运行
	pthread_barrier_wait(&bt);

	//获取互斥量A资源
	res = -1;
	res = pthread_mutex_lock(&Amutex);

	if (res == 0) {
		printk("low-task Get Amutex succesful\n");

	} else {
		printk("low-task Get Amutex Failed\n");
		return -1;
	}

	printk("low-task Get Amutex and running\n");

	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 100000; j++);
		for (j = 0; j < 10000; j++);
		if (i % 100 == 0) {
			printk("low-task is running\n");
		}
	}

	res = -1;
	res = pthread_mutex_unlock(&Amutex); // 会有优先级恢复，所以会导致高优先级先打印释放锁成功
	if (res == 0) {
		printk("low-task Release Amutex succesful\n");

	} else {
		printk("low-task Release Amutex Failed\n");
		return -1;
	}

	return NULL;
}

static void* midTask(void *arg) {
	cpu_set_t set = 1;
	int i = 0, j = 0;

	// pthread_setaffinity_np设置3个线程在指定cpu上运行，pthread_self()用于获取当前任务id
	pthread_setaffinity_np(pthread_self(), sizeof(set), &set);

	// 等待线程屏障，使线程同步运行
	pthread_barrier_wait(&bt);

	pthread_delay(200); // 如果中优先级开始运行，我们退出保证低优先级先运行

	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 100000; j++);
		for (j = 0; j < 10000; j++);
		if (i % 100 == 0) {
			printk("mid-task is running\n");
		}
	}

	return NULL;
}

void* highTask(void *arg) {
	cpu_set_t set = 1;
	int i = 0;
	int res;

	// pthread_setaffinity_np设置3个线程在指定cpu上运行，pthread_self()用于获取当前任务id
	pthread_setaffinity_np(pthread_self(), sizeof(set), &set);

	//等待线程屏障，使线程同步运行
	pthread_barrier_wait(&bt);

	pthread_delay(500);         // 最高优先级让出CPU, 保证低优先级先开始运行
	printk("high-task reques muext Amutex\n");

	//获取互斥量A资源
	res = -1;
	res = pthread_mutex_lock(&Amutex);
	if (res == 0) {
		printk("high-task Get Amutex succesful\n");

	} else {
		printk("high-task Get Amutex Failed\n");
	}

	for (i = 0; i < 10000; i++) {
		if (i % 1000 == 0) {
			printk("high-task Get Amutex and running\n");
		}
	}

	res = -1;
	res = pthread_mutex_unlock(&Amutex);//释放A资源
	if (res == 0) {
		printk("high-task Release Amutex succesful\n");

	} else {
		printk("high-task Release Amutex Failed\n");
		return -1;
	}

	return NULL;
}

int userAppInit(void) {
	int status = -1;
	pthread_mutexattr_t mutexattr;/*	互斥量的初始化属性	*/

	//初始化线程屏障
	pthread_barrier_init(&bt, NULL, 4);

	pthread_mutexattr_init(&mutexattr);/* 	初始化线程互斥锁属性配置	*/
	pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_NORMAL);/* 任务重复锁定该类互斥量时不会报错，也不会检查死锁	 */
	pthread_mutexattr_setprotocol(&mutexattr, PTHREAD_PRIO_INHERIT); /*  优先级继承	   */

	//互斥量初始化
	pthread_mutex_init(&Amutex, &mutexattr);

	//创建任务，使用默认值初始化一个任务属性对象 attr，初始化默认值是由系统确定的
	pthread_attr_init(&thread_attr1);
	pthread_attr_init(&thread_attr2);
	pthread_attr_init(&thread_attr3);

	//设置低优先级线程属性
	thread_attr1.stackaddr = NULL;/*	任务栈地址	   */
	thread_attr1.stacksize = PTHREAD_STACK_MIN * 2; /*	任务栈大小		*/
	thread_attr1.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	任务的调度策略及调度属性由任务属性对象设置	*/
	thread_attr1.schedpolicy = SCHED_RR;/*	优先级抢占的调度策略: 进行优先级调度并且相同优先级的任务进行时间片轮转调度	*/
	thread_attr1.schedparam.sched_priority = 100;/*	设置任务的优先级	 */
	thread_attr1.name = "low";/*	任务名称，为NULL时使用系统分配的任务名字	*/

	//设置中优先级线程属性
	thread_attr2.stackaddr = NULL;/*	任务栈地址	   */
	thread_attr2.stacksize = PTHREAD_STACK_MIN * 2; /*	任务栈大小		*/
	thread_attr2.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	任务的调度策略及调度属性由任务属性对象设置	*/
	thread_attr2.schedpolicy = SCHED_RR;/*	优先级抢占的调度策略: 进行优先级调度并且相同优先级的任务进行时间片轮转调度	*/
	thread_attr2.schedparam.sched_priority = 110;/*	设置任务的优先级	 */
	thread_attr2.name = "mid";/*	任务名称，为NULL时使用系统分配的任务名字	*/

	//设置高优先级线程属性
	thread_attr3.stackaddr = NULL;/*	任务栈地址	   */
	thread_attr3.stacksize = PTHREAD_STACK_MIN * 2; /*	任务栈大小		*/
	thread_attr3.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	任务的调度策略及调度属性由任务属性对象设置	*/
	thread_attr3.schedpolicy = SCHED_RR;/*	优先级抢占的调度策略: 进行优先级调度并且相同优先级的任务进行时间片轮转调度	*/
	thread_attr3.schedparam.sched_priority = 120;/*	设置任务的优先级	 */
	thread_attr3.name = "high";/*	任务名称，为NULL时使用系统分配的任务名字	*/


	status = -1;

	// 创建低先级线程
	status = pthread_create(&thread_id1, &thread_attr1, lowTask, NULL);
	if (status == 0) {
		printk("low-task create succesful\n");

	} else {
		printk("low-task create Failed\n");
		return -1;
	}

	status = -1;

	// 创建中优先级线程
	status = pthread_create(&thread_id2, &thread_attr2, midTask, NULL);
	if (status == 0) {
		printk("mid-task create succesful\n");

	} else {
		printk("mid-task create Failed\n");
		return -1;
	}

	status = -1;

	// 创建高优先级线程
	status = pthread_create(&thread_id3, &thread_attr3, highTask, NULL);
	if (status == 0) {
		printk("high-task create succesful\n");

	} else {
		printk("high-task create Failed\n");
		return -1;
	}

	//等待线程屏障，使线程同步运行
	pthread_barrier_wait(&bt);

	return 0;
}
