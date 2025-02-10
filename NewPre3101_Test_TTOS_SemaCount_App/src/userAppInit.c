/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

/************************头 文 件******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <ttos.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

#define THREAD_COUNT 4  // 线程数量
#define SEM_INIT_VALUE 2 // 允许的最大并发线程数

T_MODULE g_TaskID[THREAD_COUNT];  // 任务 ID 数组
T_MODULE g_Sema;  // 信号量

void TTOS_thread_function(void* arg) {
    int id = *(int*)arg;
    int i;

    for (i = 0; i < 5; i++) { // 每个线程执行 5 次任务
        // 等待信号量
        TTOS_ObtainSema(g_Sema, TTOS_SEMA_WAIT_FOREVER);

        printf("Thread %d acquired semaphore. Running task...\n", id);
        TTOS_SleepTask(TTOS_GetSysClkRate() * (rand() % 10)); // 模拟任务执行

        printf("Thread %d releasing semaphore.\n", id);
        TTOS_ReleaseSema(g_Sema); // 释放信号量

        TTOS_SleepTask(TTOS_GetSysClkRate() * (rand() % 5)); // 休息一段时间
    }
}

void init_sema(void) {
    T_TTOS_ReturnCode status;
    T_TTOS_ConfigSema semaParam;

    status = TTOS_InitSemaConfig(&semaParam);
    if (status != TTOS_OK) {
        printf("Semaphore initialization failed\n");
        return;
    }

    // 设置信号量名称和初始值
    strcpy((T_BYTE *)semaParam.cfgSemaName, (T_CONST T_BYTE *)"SEMA_DEMO");
    semaParam.initValue = SEM_INIT_VALUE;  // 允许两个线程并发访问
    semaParam.attributeSet = TTOS_COUNTING_SEMAPHORE;  // 计数信号量
    semaParam.priorityCeiling = 0;  // 优先级限制为 0

    // 创建信号量
    status = TTOS_CreateSema(&semaParam, &g_Sema);
    if (status != TTOS_OK) {
        printf("Failed to create semaphore\n");
        return;
    }
}

int userAppInit(void) {
    int thread_ids[THREAD_COUNT];
    T_TTOS_ReturnCode ret;
    int i;

    init_sema();  // 初始化信号量

    // 创建任务（线程）
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i + 1; // 线程 ID 从 1 开始
        ret = TTOS_CreateTaskEx(
            (T_UBYTE *)"Task",  // 任务名称
            250,                // 任务优先级
            TRUE,               // 是否允许启动
            TRUE,               // 是否启用
            (T_TTOS_TaskRoutine)TTOS_thread_function,  // 任务函数
            &thread_ids[i],     // 任务函数参数（线程 ID）
            TTOS_MINIMUM_STACK_SIZE,  // 任务堆栈大小
            &g_TaskID[i]        // 任务 ID
        );
        if (ret != TTOS_OK) {
            printf("Failed to create task %d\n", i);
        }
    }

    return 0;
}
