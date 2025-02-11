/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

/************************头 文件******************************/
#include <stdio.h>     // 标准输入输出头文件
#include <stdlib.h>    // 标准库头文件
#include <pthread.h>   // POSIX线程库头文件
#include <unistd.h>    // 提供sleep等系统调用

/************************宏 定 义******************************/
#define THREAD_STACK_SIZE 512  // 定义线程栈大小
#define THREAD_TIMESLICE 5    // 定义线程时间片

/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
static int cnt = 0;  // 全局变量，用于线程间共享计数

/************************实   现*******************************/
/* 说明：
 * 程序清单：互斥锁使用例程
 *
 * 互斥锁用于保护共享资源（如全局变量cnt），防止多个线程同时访问导致数据竞争。
 * 在访问共享资源之前，线程必须先获取互斥锁（pthread_mutex_lock），访问完成后释放互斥锁（pthread_mutex_unlock）。
 * 如果一个线程已经获取了互斥锁，其他线程尝试获取该锁时会被阻塞，直到锁被释放。
 *
 * 编程风格：
 *         函数：Linux/类Unix风格
 *         局部变量：下划线命名法
 *         全局变量：下划线命名法
 *         宏定义：Linux风格（大写）
 */

// 线程互斥锁
pthread_mutex_t mutex;  // 互斥锁变量，用于保护共享资源

// 线程入口函数
void* thread_entry(void* parameter)
{
    int no = (int)parameter;  // 局部变量，表示线程编号
    while (1)
    {
        // 加锁：获取互斥锁，保护共享资源cnt
        pthread_mutex_lock(&mutex);
        cnt += no;  // 修改共享资源
        // 解锁：释放互斥锁，允许其他线程访问共享资源
        pthread_mutex_unlock(&mutex);

        printf("Thread[%d]'s counter is %d\n", no, cnt);  // 打印当前线程的计数值
        sleep(no * 10);  // 延时，模拟线程工作负载
    }
    return NULL;  // 返回值为NULL，表示线程正常结束
}

int userAppInit(void)
{
    pthread_t thread1, thread2;  // 定义两个线程变量

    // 初始化互斥锁
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("Mutex init failed\n");  // 初始化失败时打印错误信息
        return -1;  // 返回错误码
    }

    // 创建线程1
    if (pthread_create(&thread1, NULL, thread_entry, (void*)10) != 0)
    {
        printf("Thread1 creation failed\n");  // 创建失败时打印错误信息
        return -1;  // 返回错误码
    }

    // 创建线程2
    if (pthread_create(&thread2, NULL, thread_entry, (void*)20) != 0)
    {
        printf("Thread2 creation failed\n");  // 创建失败时打印错误信息
        return -1;  // 返回错误码
    }

    // 等待线程1结束
    pthread_join(thread1, NULL);
    // 等待线程2结束
    pthread_join(thread2, NULL);

    // 销毁互斥锁
    pthread_mutex_destroy(&mutex);

    return 0;  // 返回成功码
}
