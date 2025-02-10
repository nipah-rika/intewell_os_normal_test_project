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
#include<pthread.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

static pthread_barrier_t bt;
static pthread_t thread_id1;
static pthread_t thread_id2;
static pthread_attr_t thread_attr1;
static pthread_attr_t thread_attr2;

/*	��������Ĺ��Ӻ���	*/
void* add_task_hook() {
	printk("add_task_hook run\n");
}
/*	�л�����Ĺ��Ӻ���	*/
void* switch_task_hook() {
	printk("switch_task_hook run\n");
}
/*	ɾ������Ĺ��Ӻ���	*/
void* close_task_hook() {
	printk("delete_task_hook run\n");
}
/*	test task1	*/
void* task1() {
	// �ȴ��߳����ϣ�ʹ�߳�ͬ��
	pthread_barrier_wait(&bt);
	printk("task1 running...\n");
	printk("task1 running...\n");
	printk("task1 running...\n");

}
/*	test task2	*/
void* task2() {
	// �ȴ��߳����ϣ�ʹ�߳�ͬ��
	pthread_barrier_wait(&bt);
	printk("task2 running...\n");
	printk("task2 running...\n");
	printk("task2 running...\n");

}


int userAppInit(void) {
	int status;

	/*	������񴴽��Ĺ��Ӻ��������񴴽��Ĺ��Ӻ����б�	*/
	status = pthread_create_hook_add(add_task_hook);
	if (status != 0) {
		printk("add create hook failed....status:%d\n", status);
	}

	/*	��������л��Ĺ��Ӻ����������л��Ĺ��Ӻ����б�	*/
	status = pthread_switch_hook_add(switch_task_hook);
	if (status != 0) {
		printk("add switch hook failed....status:%d\n", status);
	}

	/*	�������ɾ���Ĺ��Ӻ���������ɾ���Ĺ��Ӻ����б�	*/
	status = pthread_close_hook_add(close_task_hook);
	if (status != 0) {
		printk("add close hook failed....status:%d\n", status);
	}

	// ��ʼ���߳�����
	pthread_barrier_init(&bt, NULL, 3);

	//��������ʹ��Ĭ��ֵ��ʼ��һ���������Զ��� attr����ʼ��Ĭ��ֵ����ϵͳȷ����
	pthread_attr_init(&thread_attr1);
	pthread_attr_init(&thread_attr2);

	//����task1�߳�����
	thread_attr1.stackaddr = NULL;/*	����ջ��ַ	   */
	thread_attr1.stacksize = PTHREAD_STACK_MIN * 2; /*	����ջ��С		*/
	thread_attr1.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	����ĵ��Ȳ��Լ������������������Զ�������	*/
	thread_attr1.schedpolicy = SCHED_RR;/*	���ȼ���ռ�ĵ��Ȳ���: �������ȼ����Ȳ�����ͬ���ȼ����������ʱ��Ƭ��ת����	*/
	thread_attr1.schedparam.sched_priority = 100;/*	������������ȼ�	 */
	thread_attr1.name = "task1";/*	�������ƣ�ΪNULLʱʹ��ϵͳ�������������	*/

	//����task2�߳�����
	thread_attr2.stackaddr = NULL;/*	����ջ��ַ	   */
	thread_attr2.stacksize = PTHREAD_STACK_MIN * 2; /*	����ջ��С		*/
	thread_attr2.inheritsched = PTHREAD_EXPLICIT_SCHED;/*	����ĵ��Ȳ��Լ������������������Զ�������	*/
	thread_attr2.schedpolicy = SCHED_RR;/*	���ȼ���ռ�ĵ��Ȳ���: �������ȼ����Ȳ�����ͬ���ȼ����������ʱ��Ƭ��ת����	*/
	thread_attr2.schedparam.sched_priority = 100;/*	������������ȼ�	 */
	thread_attr2.name = "task2";/*	�������ƣ�ΪNULLʱʹ��ϵͳ�������������	*/

	// ����task1�߳�
	status = pthread_create(&thread_id1, &thread_attr1, task1, NULL);
	if (status == 0) {
		printk("task1 create succesful\n");

	} else {
		printk("task1 create Failed\n");
		return -1;
	}

	// ����task2�߳�
	status = pthread_create(&thread_id2, &thread_attr2, task2, NULL);
	if (status == 0) {
		printk("task2 create succesful\n");

	} else {
		printk("task2 create Failed\n");
		return -1;
	}

	// �ȴ��߳����ϣ�ʹ�߳�ͬ��
	pthread_barrier_wait(&bt);

	// �����������ֱ��task1��ֹ
	pthread_join(thread_id1, NULL);
	// �����������ֱ��task2��ֹ
	pthread_join(thread_id2, NULL);

	/*	�������л��Ĺ��Ӻ����б�ɾ��ָ���Ĺ��Ӻ���	*/
	status = pthread_switch_hook_delete(switch_task_hook);
	if (status != 0) {
		printk("switch del failed....status:%d\n", status);
	}

	/*	�����񴴽��Ĺ��Ӻ����б�ɾ��ָ���Ĺ��Ӻ���	*/
	status = pthread_create_hook_delete(add_task_hook);
	if (status != 0) {
		printk("create del failed....status:%d\n", status);
	}

	/*	������ɾ���Ĺ��Ӻ����б�ɾ��ָ���Ĺ��Ӻ���	*/
	status = pthread_close_hook_delete(close_task_hook);
	if (status != 0) {
		printk("close del failed....status:%d\n", status);
	}
	printk("deleted all hook\n");
	return 0;
}

