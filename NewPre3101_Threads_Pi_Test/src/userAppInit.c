/*
* @file：userAppInit.c
* @brief：用户入口文件，userAppInit()是用户的入口函数。
*/
/************************头 文 件******************************/
#include <commonTypes.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sched.h>
#include <errno.h>
/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

/*
 * 编程风格：
 *         函数：采用 Linux/类 UNIX 风格。
 *         局部变量：采用匈牙利命名法。
 *         全局变量：采用匈牙利命名法。
 *         宏定义：采用大写字母命名风格。
 */

/* 说明：
 * 程序清单：工作线程和 CPU 亲和性管理
 *
 * 该程序创建并启动工作线程，并执行计算任务。每个线程通过 `set_cpu_affinity()` 设置其 CPU 亲和性，
 * 并在循环中进行计算，直到停止标志被设置。主线程会等待一段时间后停止工作线程。
 *
 * - 工作线程每次执行 5 次计算任务，模拟高负载计算。
 * - 程序创建并启动的线程数由 THREAD_NUM 参数控制。
 *
 * 程序运行结束时，会打印出所有线程完成工作的信息。
 */

#define THREAD_NUM 1           // 线程数
#define WORKLOAD 5000000       // 每个工作单元的工作量

/* 工作函数的前向声明 */
void do_work(unsigned granularity_top);
void set_cpu_affinity(int cpu);
void* thread_fn(void* param);

/* 假定任务停止的标志 */
volatile int stop_flag = 0;

/* 互斥锁定义 */
pthread_mutex_t mutex;

/* 线程数组定义 */
pthread_t threads[THREAD_NUM];

/* 工作函数：执行简单的计算任务 */
void do_work(unsigned granularity_top) {
    unsigned granularity_cnt, i;
    unsigned dummy = 0;

    /* 进行多次计算，避免优化掉循环 */
    for (granularity_cnt = 0; granularity_cnt < granularity_top; granularity_cnt++) {
        for (i = 0; i < WORKLOAD; i++) {
            dummy = i | dummy;  // 简单的计算任务
        }
    }
}

/* 设置线程的 CPU 亲和性 */
void set_cpu_affinity(int cpu) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);       // 清空 cpuset
    CPU_SET(cpu, &cpuset);   // 设置指定的 CPU

    int rc = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
    if (rc != 0) {
        perror("pthread_setaffinity_np failed");
        exit(EXIT_FAILURE);
    }
}

/* 工作线程函数：执行计算任务并设置 CPU 亲和性 */
void* thread_fn(void* param) {
    int cpu = *((int*)param);
    set_cpu_affinity(cpu);  // 设置线程的 CPU 亲和性

    /* 执行工作直到停止标志被设置 */
    while (!stop_flag) {
        do_work(5);  // 执行计算任务
    }
    free(param);  // 释放 CPU ID 内存
    return NULL;
}

/* 用户应用初始化：创建线程并初始化互斥锁 */
int userAppInit(void) {
    int i;

    /* 打印线程创建信息 */
    printf("Creating %d threads...\n", THREAD_NUM);

    /* 初始化互斥锁 */
    pthread_mutex_init(&mutex, NULL);

    /* 创建 THREAD_NUM 个线程 */
    for (i = 0; i < THREAD_NUM; i++) {
        int *cpu_id = malloc(sizeof(int));  // 为每个线程分配 CPU ID
        if (!cpu_id) {
            perror("malloc failed");
            continue;
        }
        *cpu_id = i;

        /* 创建线程并设置其优先级 */
        pthread_create(&threads[i], NULL, thread_fn, cpu_id);
        struct sched_param param;
        param.sched_priority = 3;  // 设置线程优先级
        pthread_setschedparam(threads[i], SCHED_FIFO, &param);
    }

    /* 主线程休眠 10 秒，模拟主线程等待 */
    sleep(10);

    /* 设置停止标志，通知线程结束 */
    stop_flag = 1;

    /* 等待所有线程结束 */
    for (i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    /* 打印工作完成信息 */
    printf("All threads finished work\n");

    /* 销毁互斥锁 */
    pthread_mutex_destroy(&mutex);

    return 0;
}
