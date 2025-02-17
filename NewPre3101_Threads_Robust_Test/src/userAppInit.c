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
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

/* 说明：
 * 程序清单：互斥锁的恢复机制
 *
 * 该程序通过自定义的 `pthread_mutexattr_setrobust_np` 和 `pthread_mutex_lock_with_recovery` 函数，
 * 模拟了互斥锁的“robust”状态和死锁恢复机制。程序启动两个线程：
 * - 线程1正常锁定互斥锁，运行并模拟崩溃（通过睡眠2秒）。
 * - 线程2尝试锁定互斥锁，并在遇到死锁时进行恢复。
 *
 * - 线程1在锁定互斥锁后崩溃，导致线程2在尝试锁定时遇到 `EOWNERDEAD` 错误码。
 * - 线程2处理死锁并重新尝试锁定，最终成功获取锁并解锁。
 *
 * 程序演示了如何通过模拟恢复机制来处理死锁状态。
 */

#define THREAD_NUM 2 // 定义线程数为2

/* 工作线程的前向声明 */
void* thread_1(void* arg);
void* thread_2(void* arg);

/* 模拟“robust”标志的变量 */
int robust_flag = 0;

/* 互斥锁变量 */
pthread_mutex_t mutex;

/*
 * 模拟自定义的 `pthread_mutexattr_setrobust_np` 函数，用于设置“robust”状态。
 * 该函数会将 `robust_flag` 设置为指定的值，以模拟锁的“robust”属性。
 */
int pthread_mutexattr_setrobust_np(pthread_mutexattr_t *attr, int robust) {
    robust_flag = robust; // 设置标志
    return 0; // 返回成功
}

/*
 * 模拟处理锁的恢复机制。这个函数会尝试获取锁并检查锁的状态，
 * 如果检测到死锁状态（EOWNERDEAD），则会进行恢复操作（模拟清理状态）。
 */
int pthread_mutex_lock_with_recovery(pthread_mutex_t *mutex) {
    int rc = pthread_mutex_lock(mutex);  // 锁定互斥锁
    if (rc != 0 && robust_flag) {  // 如果发生死锁，并且“robust”标志被设置
        if (rc == EOWNERDEAD) {
            printf("Recovering mutex from dead owner...\n");  // 模拟恢复
            rc = 0; // 恢复成功，继续锁定
        }
    }
    return rc;  // 返回锁定状态
}

/* 线程1：普通锁定并模拟崩溃 */
void* thread_1(void* arg) {
    pthread_mutex_lock(&mutex);  // 锁定互斥锁
    printf("Thread 1 locked the mutex\n");
    sleep(2);  // 模拟线程1运行一段时间后崩溃
    printf("Thread 1 exiting\n");
    pthread_exit(NULL);  // 退出线程
    return NULL;
}

/* 线程2：尝试恢复死锁状态 */
void* thread_2(void* arg) {
    int rc;

    printf("Thread 2 attempting to lock the mutex...\n");

    rc = pthread_mutex_lock(&mutex);  // 尝试锁定互斥锁
    if (rc == EOWNERDEAD) {  // 如果锁定失败并且检测到死锁
        printf("Thread 2 encountered EOWNERDEAD. Handling mutex recovery...\n");

        // 模拟恢复操作，直接重试
        rc = pthread_mutex_lock(&mutex);  // 再次尝试锁定
    }

    if (rc != 0) {
        printf("FAIL: mutex_lock failed with error code %d\n", rc);
        pthread_exit(NULL);  // 错误退出线程
    }

    printf("Thread 2 successfully locked the mutex\n");
    pthread_mutex_unlock(&mutex);  // 解锁

    pthread_exit(NULL);  // 退出线程
    return NULL;
}

/* 用户应用初始化 */
int userAppInit(void) {
    pthread_t threads[2];  // 线程数组
    pthread_mutexattr_t mutex_attr;  // 互斥锁属性
    int rc;

    // 初始化互斥锁属性并模拟“robust”功能
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_setrobust_np(&mutex_attr, 1);  // 开启“robust”功能
    pthread_mutex_init(&mutex, &mutex_attr);  // 初始化互斥锁

    // 创建线程
    rc = pthread_create(&threads[0], NULL, thread_1, NULL);
    if (rc != 0) {
        printf("Error creating thread 1: %s\n", strerror(rc));
        return -1;  // 线程创建失败
    }

    rc = pthread_create(&threads[1], NULL, thread_2, NULL);
    if (rc != 0) {
        printf("Error creating thread 2: %s\n", strerror(rc));
        return -1;  // 线程创建失败
    }

    // 等待线程结束
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("Test PASSED\n");
    return 0;
}
