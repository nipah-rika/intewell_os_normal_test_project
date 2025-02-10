/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

/************************头 文 件******************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/************************宏 定 义******************************/
#define THREAD_STACK_SIZE 512
#define THREAD_TIMESLICE 5
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
static int cnt = 0;

/************************实   现*******************************/
// 线程互斥锁
pthread_mutex_t mutex;

// 线程入口函数
void* thread_entry(void* parameter)
{
    int no = (int)parameter;
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);
        cnt += no;
        // 解锁
        pthread_mutex_unlock(&mutex);

        printf("Thread[%d]'s counter is %d\n", no, cnt);
        sleep(no * 10); // 延时
    }
    return NULL;
}

int userAppInit(void)
{
    pthread_t thread1, thread2;

    // 初始化互斥锁
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("Mutex init failed\n");
        return -1;
    }

    // 创建线程1
    if (pthread_create(&thread1, NULL, thread_entry, (void*)10) != 0)
    {
        printf("Thread1 creation failed\n");
        return -1;
    }

    // 创建线程2
    if (pthread_create(&thread2, NULL, thread_entry, (void*)20) != 0)
    {
        printf("Thread2 creation failed\n");
        return -1;
    }

    // 等待线程结束
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 销毁互斥锁
    pthread_mutex_destroy(&mutex);

    return 0;
}
