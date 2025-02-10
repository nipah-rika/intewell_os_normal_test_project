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

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

/** ���н����
 1. �����ȼ��̳б���������£�3���̵߳�����˳��
 	 lowTask-->midTask-->lowTask-->highTask
 	 ���̽��ͣ�
 	 �����ȼ�����ʼ���У�Ȼ�������ȼ�������ռ���У�����û�����ȼ��̳б����������ȼ������һֱ����ֱ��������ɣ�
 	 Ȼ�󵽵����ȼ�����������У�ֱ�������ȼ���������ͷ�����Դ�󣬸����ȼ�����ſ�ʼ���С�

 2. �����ȼ��̳б���������£�3���̵߳�����˳��Ӧ���ǣ�
	lowTask-->midTask-->lowTask-->highTask-->midTask
 	���̽��ͣ�
 	�����ȼ����������У�Ȼ�������ȼ�������ռ���У�ֱ�������ȼ��������󻥳�����Դ�� �������ȼ��̳б�����
 	�Ὣ�����ȼ���������ȼ������������ȼ��������ȼ�������ɺ��ͷŻ�������Դ�����Ÿ����ȼ�����ʼ���У�
 	�����ȼ�������ɺ��ͷ�����Դ�������ȼ������������ֱ��������ɡ�

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

	// pthread_setaffinity_np����3���߳���ָ��cpu�����У�pthread_self()���ڻ�ȡ��ǰ����id
	pthread_setaffinity_np(pthread_self(), sizeof(set), &set);

	//�ȴ��߳����ϣ�ʹ�߳�ͬ������
	pthread_barrier_wait(&bt);

	//��ȡ������A��Դ
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
	res = pthread_mutex_unlock(&Amutex); // �������ȼ��ָ������Իᵼ�¸����ȼ��ȴ�ӡ�ͷ����ɹ�
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

	// pthread_setaffinity_np����3���߳���ָ��cpu�����У�pthread_self()���ڻ�ȡ��ǰ����id
	pthread_setaffinity_np(pthread_self(), sizeof(set), &set);

	// �ȴ��߳����ϣ�ʹ�߳�ͬ������
	pthread_barrier_wait(&bt);

	pthread_delay(200); // ��������ȼ���ʼ���У������˳���֤�����ȼ�������

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

	// pthread_setaffinity_np����3���߳���ָ��cpu�����У�pthread_self()���ڻ�ȡ��ǰ����id
	pthread_setaffinity_np(pthread_self(), sizeof(set), &set);

	//�ȴ��߳����ϣ�ʹ�߳�ͬ������
	pthread_barrier_wait(&bt);

	pthread_delay(500);         // ������ȼ��ó�CPU, ��֤�����ȼ��ȿ�ʼ����
	printk("high-task reques muext Amutex\n");

	//��ȡ������A��Դ
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
	res = pthread_mutex_unlock(&Amutex);//�ͷ�A��Դ
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
	pthread_mutexattr_t mutexattr;/*	�������ĳ�ʼ������	*/

	//��ʼ���߳�����
	pthread_barrier_init(&bt, NULL, 4);

	pthread_mutexattr_init(&mutexattr);/* 	��ʼ���̻߳�������������	*/
	pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_NORMAL);/* �����ظ��������໥����ʱ���ᱨ��Ҳ����������	 */
	pthread_mutexattr_setprotocol(&mutexattr, PTHREAD_PRIO_INHERIT); /*  ���ȼ��̳�	   */

	//��������ʼ��
	pthread_mutex_init(&Amutex, &mutexattr);

	//��������ʹ��Ĭ��ֵ��ʼ��һ���������Զ��� attr����ʼ��Ĭ��ֵ����ϵͳȷ����
	pthread_attr_init(&thread_attr1);
	pthread_attr_init(&thread_attr2);
	pthread_attr_init(&thread_attr3);

	//���õ����ȼ��߳�����
	thread_attr1.stackaddr = NULL;/*	����ջ��ַ	   */
	thread_attr1.stacksize = PTHREAD_STACK_MIN * 2; /*	����ջ��С		*/
	thread_attr1.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	����ĵ��Ȳ��Լ������������������Զ�������	*/
	thread_attr1.schedpolicy = SCHED_RR;/*	���ȼ���ռ�ĵ��Ȳ���: �������ȼ����Ȳ�����ͬ���ȼ����������ʱ��Ƭ��ת����	*/
	thread_attr1.schedparam.sched_priority = 100;/*	������������ȼ�	 */
	thread_attr1.name = "low";/*	�������ƣ�ΪNULLʱʹ��ϵͳ�������������	*/

	//���������ȼ��߳�����
	thread_attr2.stackaddr = NULL;/*	����ջ��ַ	   */
	thread_attr2.stacksize = PTHREAD_STACK_MIN * 2; /*	����ջ��С		*/
	thread_attr2.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	����ĵ��Ȳ��Լ������������������Զ�������	*/
	thread_attr2.schedpolicy = SCHED_RR;/*	���ȼ���ռ�ĵ��Ȳ���: �������ȼ����Ȳ�����ͬ���ȼ����������ʱ��Ƭ��ת����	*/
	thread_attr2.schedparam.sched_priority = 110;/*	������������ȼ�	 */
	thread_attr2.name = "mid";/*	�������ƣ�ΪNULLʱʹ��ϵͳ�������������	*/

	//���ø����ȼ��߳�����
	thread_attr3.stackaddr = NULL;/*	����ջ��ַ	   */
	thread_attr3.stacksize = PTHREAD_STACK_MIN * 2; /*	����ջ��С		*/
	thread_attr3.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	����ĵ��Ȳ��Լ������������������Զ�������	*/
	thread_attr3.schedpolicy = SCHED_RR;/*	���ȼ���ռ�ĵ��Ȳ���: �������ȼ����Ȳ�����ͬ���ȼ����������ʱ��Ƭ��ת����	*/
	thread_attr3.schedparam.sched_priority = 120;/*	������������ȼ�	 */
	thread_attr3.name = "high";/*	�������ƣ�ΪNULLʱʹ��ϵͳ�������������	*/


	status = -1;

	// �������ȼ��߳�
	status = pthread_create(&thread_id1, &thread_attr1, lowTask, NULL);
	if (status == 0) {
		printk("low-task create succesful\n");

	} else {
		printk("low-task create Failed\n");
		return -1;
	}

	status = -1;

	// ���������ȼ��߳�
	status = pthread_create(&thread_id2, &thread_attr2, midTask, NULL);
	if (status == 0) {
		printk("mid-task create succesful\n");

	} else {
		printk("mid-task create Failed\n");
		return -1;
	}

	status = -1;

	// ���������ȼ��߳�
	status = pthread_create(&thread_id3, &thread_attr3, highTask, NULL);
	if (status == 0) {
		printk("high-task create succesful\n");

	} else {
		printk("high-task create Failed\n");
		return -1;
	}

	//�ȴ��߳����ϣ�ʹ�߳�ͬ������
	pthread_barrier_wait(&bt);

	return 0;
}
