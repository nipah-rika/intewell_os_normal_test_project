/*
* @file��userAppInit.c
* @brief���û�����ļ���userAppInit()���û�����ں�����
*/
/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sched.h>
#include <errno.h>
/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

/*
 * ��̷��
 *         ���������� Linux/�� UNIX ���
 *         �ֲ�������������������������
 *         ȫ�ֱ�����������������������
 *         �궨�壺���ô�д��ĸ�������
 */

/* ˵����
 * �����嵥�������̺߳� CPU �׺��Թ���
 *
 * �ó��򴴽������������̣߳���ִ�м�������ÿ���߳�ͨ�� `set_cpu_affinity()` ������ CPU �׺��ԣ�
 * ����ѭ���н��м��㣬ֱ��ֹͣ��־�����á����̻߳�ȴ�һ��ʱ���ֹͣ�����̡߳�
 *
 * - �����߳�ÿ��ִ�� 5 �μ�������ģ��߸��ؼ��㡣
 * - ���򴴽����������߳����� THREAD_NUM �������ơ�
 *
 * �������н���ʱ�����ӡ�������߳���ɹ�������Ϣ��
 */

#define THREAD_NUM 1           // �߳���
#define WORKLOAD 5000000       // ÿ��������Ԫ�Ĺ�����

/* ����������ǰ������ */
void do_work(unsigned granularity_top);
void set_cpu_affinity(int cpu);
void* thread_fn(void* param);

/* �ٶ�����ֹͣ�ı�־ */
volatile int stop_flag = 0;

/* ���������� */
pthread_mutex_t mutex;

/* �߳����鶨�� */
pthread_t threads[THREAD_NUM];

/* ����������ִ�м򵥵ļ������� */
void do_work(unsigned granularity_top) {
    unsigned granularity_cnt, i;
    unsigned dummy = 0;

    /* ���ж�μ��㣬�����Ż���ѭ�� */
    for (granularity_cnt = 0; granularity_cnt < granularity_top; granularity_cnt++) {
        for (i = 0; i < WORKLOAD; i++) {
            dummy = i | dummy;  // �򵥵ļ�������
        }
    }
}

/* �����̵߳� CPU �׺��� */
void set_cpu_affinity(int cpu) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);       // ��� cpuset
    CPU_SET(cpu, &cpuset);   // ����ָ���� CPU

    int rc = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
    if (rc != 0) {
        perror("pthread_setaffinity_np failed");
        exit(EXIT_FAILURE);
    }
}

/* �����̺߳�����ִ�м����������� CPU �׺��� */
void* thread_fn(void* param) {
    int cpu = *((int*)param);
    set_cpu_affinity(cpu);  // �����̵߳� CPU �׺���

    /* ִ�й���ֱ��ֹͣ��־������ */
    while (!stop_flag) {
        do_work(5);  // ִ�м�������
    }
    free(param);  // �ͷ� CPU ID �ڴ�
    return NULL;
}

/* �û�Ӧ�ó�ʼ���������̲߳���ʼ�������� */
int userAppInit(void) {
    int i;

    /* ��ӡ�̴߳�����Ϣ */
    printf("Creating %d threads...\n", THREAD_NUM);

    /* ��ʼ�������� */
    pthread_mutex_init(&mutex, NULL);

    /* ���� THREAD_NUM ���߳� */
    for (i = 0; i < THREAD_NUM; i++) {
        int *cpu_id = malloc(sizeof(int));  // Ϊÿ���̷߳��� CPU ID
        if (!cpu_id) {
            perror("malloc failed");
            continue;
        }
        *cpu_id = i;

        /* �����̲߳����������ȼ� */
        pthread_create(&threads[i], NULL, thread_fn, cpu_id);
        struct sched_param param;
        param.sched_priority = 3;  // �����߳����ȼ�
        pthread_setschedparam(threads[i], SCHED_FIFO, &param);
    }

    /* ���߳����� 10 �룬ģ�����̵߳ȴ� */
    sleep(10);

    /* ����ֹͣ��־��֪ͨ�߳̽��� */
    stop_flag = 1;

    /* �ȴ������߳̽��� */
    for (i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    /* ��ӡ���������Ϣ */
    printf("All threads finished work\n");

    /* ���ٻ����� */
    pthread_mutex_destroy(&mutex);

    return 0;
}
