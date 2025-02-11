/************************头 文 件******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <ttos.h>

/************************宏 定 义******************************/
// 定义线程数量为4
#define THREAD_COUNT 4
// 定义信号量的初始值为2，允许两个线程并发访问
#define SEM_INIT_VALUE 2

/************************类型定义******************************/
T_MODULE g_TaskID[THREAD_COUNT];  // 用于存储创建的每个线程的 ID
T_MODULE g_Sema;  // 信号量，控制并发线程数

/************************模块变量******************************/
static int thread_ids[THREAD_COUNT];  // 线程 ID 数组，用于存储每个线程的 ID

/************************实现*******************************/

/*
 * 编程风格：
 *         函数linux/类unix风格
 *         局部变量：匈牙利命名法
 *         全局变量：匈牙利命名法
 *         宏定义：linux风格 大写
 */

/* 说明：
 * 程序清单：信号量与多线程模拟
 *
 * 该程序创建并启动 4 个线程，使用一个计数信号量来控制并发执行：
 * - 每个线程在执行任务时都会获取信号量，执行任务后释放信号量；
 * - 每个线程会执行 5 次任务，每次任务包括等待信号量、执行任务、释放信号量。
 * - 信号量的初始值为 2，最多允许 2 个线程并发执行任务。
 */

/**
 * 线程函数，模拟每个线程执行任务
 * 每个线程获取信号量，执行任务后释放信号量
 * 每个线程执行 5 次任务
 *
 * @param arg 线程的参数，即线程的 ID
 */
void TTOS_thread_function(void* arg) {
    int id = *(int*)arg;  // 获取线程 ID
    int i;

    // 每个线程执行 5 次任务
    for (i = 0; i < 5; i++) {
        // 等待信号量，若信号量为 0，则阻塞，直到信号量可用
        TTOS_ObtainSema(g_Sema, TTOS_SEMA_WAIT_FOREVER);

        // 成功获取信号量后，模拟执行任务
        printf("Thread %d acquired semaphore. Running task...\n", id);
        TTOS_SleepTask(TTOS_GetSysClkRate() * (rand() % 10)); // 随机模拟任务执行时间

        // 任务完成后，释放信号量
        printf("Thread %d releasing semaphore.\n", id);
        TTOS_ReleaseSema(g_Sema); // 释放信号量，允许其他线程继续执行

        // 线程执行完任务后，随机休息一段时间
        TTOS_SleepTask(TTOS_GetSysClkRate() * (rand() % 5)); // 随机休息时间
    }
}

/**
 * 初始化信号量
 * 设置信号量的初始值，创建计数信号量
 */
void init_sema(void) {
    T_TTOS_ReturnCode status;  // 存储返回值
    T_TTOS_ConfigSema semaParam;  // 信号量配置结构体

    // 初始化信号量配置
    status = TTOS_InitSemaConfig(&semaParam);
    if (status != TTOS_OK) {
        printf("Semaphore initialization failed\n");
        return;  // 初始化失败，退出函数
    }

    // 设置信号量的名称和初始值
    strcpy((T_BYTE *)semaParam.cfgSemaName, (T_CONST T_BYTE *)"SEMA_DEMO");  // 设置信号量名称
    semaParam.initValue = SEM_INIT_VALUE;  // 设置信号量的初始值为 2，允许最多两个线程并发
    semaParam.attributeSet = TTOS_COUNTING_SEMAPHORE;  // 设置信号量为计数信号量
    semaParam.priorityCeiling = 0;  // 不设置优先级限制

    // 创建信号量
    status = TTOS_CreateSema(&semaParam, &g_Sema);
    if (status != TTOS_OK) {
        printf("Failed to create semaphore\n");
        return;  // 创建信号量失败，退出函数
    }
}

/**
 * 用户应用初始化函数
 * 创建并启动 4 个线程，初始化信号量，并开始执行任务
 */
int userAppInit(void) {
    T_TTOS_ReturnCode ret;  // 存储函数的返回值
    int i;

    init_sema();  // 初始化信号量

    // 创建 4 个线程，每个线程执行 TTOS_thread_function
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i + 1;  // 线程 ID 从 1 开始，避免线程 ID 为 0
        ret = TTOS_CreateTaskEx(
            (T_UBYTE *)"Task",  // 任务名称
            250,                // 任务优先级设置为 250
            TRUE,               // 是否允许启动任务
            TRUE,               // 启用任务
            (T_TTOS_TaskRoutine)TTOS_thread_function,  // 任务执行的函数
            &thread_ids[i],     // 任务参数（传递线程 ID）
            TTOS_MINIMUM_STACK_SIZE,  // 任务堆栈大小
            &g_TaskID[i]        // 存储任务 ID 的地址
        );
        // 检查任务创建是否成功
        if (ret != TTOS_OK) {
            printf("Failed to create task %d\n", i);  // 创建失败时输出错误信息
        }
    }

    return 0;  // 返回 0 表示初始化完成
}
