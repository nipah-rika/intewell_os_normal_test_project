/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

#include <commonTypes.h>
#include <stdio.h>
#include <ttos.h>

/************************宏 定 义******************************/
#define ONE_SECOND_TIMER_INTERVAL  1  // 一秒定时器（每秒触发）
#define TEN_SECOND_TIMER_INTERVAL 10 // 十秒定时器（每10秒触发）

/************************类型定义******************************/
T_MODULE TIMER_ID g_one_second_timer_id;   // 一秒定时器ID
T_MODULE TIMER_ID g_ten_second_timer_id;   // 十秒定时器ID

/************************模块变量******************************/
static int one_second_trigger_count = 0;   // 一秒定时器触发次数
static int ten_second_trigger_count = 0;   // 十秒定时器触发次数

/************************实现*******************************/

// 一秒定时器回调（每秒触发）
T_MODULE T_VOID one_second_timer_callback()
{
    one_second_trigger_count++;  // 每次触发时，增加一秒定时器触发次数
    printk("One second timer triggered %d times.\n", one_second_trigger_count);
}

// 十秒定时器回调（每10秒触发）
T_MODULE T_VOID ten_second_timer_callback()
{
    ten_second_trigger_count++;  // 每次触发时，增加十秒定时器触发次数
    printk("Ten second timer triggered %d times.\n", ten_second_trigger_count);
}

int userAppInit(void)
{
    T_TTOS_ReturnCode ret;
    T_UWORD one_second_timer_count = 0;  // 一秒定时器触发次数（此处为无限次）
    T_UWORD ten_second_timer_count = 0;  // 十秒定时器触发次数（此处为无限次）

    printk("************ Begin to test ***************\n");

    // 创建一秒定时器（每秒触发）并直接激活
    ret = TTOS_CreateTimerEx(TRUE, 100, 5, NULL, one_second_timer_callback, &g_one_second_timer_id);
    if (ret != 0)
    {
        printk("Create One Second Timer Fail!\n");
        return -1;
    }

    // 创建十秒定时器（每10秒触发）并直接激活
    ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate() * TEN_SECOND_TIMER_INTERVAL, 10, NULL, ten_second_timer_callback, &g_ten_second_timer_id);
    if (ret != 0)
    {
        printk("Create Ten Second Timer Fail!\n");
        return -1;
    }

    // 直接激活定时器
    ret = TTOS_ActiveTimer(g_one_second_timer_id);
    if (ret != 0) {
        printf("Failed to activate One Second Timer.\n");
        return -1;
    }

    ret = TTOS_ActiveTimer(g_ten_second_timer_id);
    if (ret != 0) {
        printf("Failed to activate Ten Second Timer.\n");
        return -1;
    }

    sleep(50);
//    // 定义最大睡眠次数限制
//    const int sleep_limit = 5;  // 限制最大睡眠次数为5次
//    int sleep_count = 0;         // 当前睡眠次数
//
//    // 运行主循环，最多执行5次，每次休眠5秒
//    while (sleep_count < sleep_limit)
//    {
//        TTOS_SleepTask(5000);  // 挂起当前任务5秒
//        sleep_count++;         // 增加睡眠计数
//    }
//
//    // 停止定时器
//    TTOS_StopTimer(g_one_second_timer_id);
//    TTOS_StopTimer(g_ten_second_timer_id);

    printf("Task sleep limit reached. Exiting...\n");

    return 0;
}
