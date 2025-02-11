/************************头 文 件******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <ttos.h>

// 宏定义：定时器的触发间隔
#define ONE_SECOND_TIMER_INTERVAL  1  // 一秒定时器（每秒触发）
#define TEN_SECOND_TIMER_INTERVAL 10 // 十秒定时器（每10秒触发）

/************************类型定义******************************/
// 一秒定时器ID（全局变量，用于标识一秒定时器）
T_MODULE TIMER_ID g_one_second_timer_id;
// 十秒定时器ID（全局变量，用于标识十秒定时器）
T_MODULE TIMER_ID g_ten_second_timer_id;

/************************模块变量******************************/
// 一秒定时器触发次数（初始为0）
static int one_second_trigger_count = 0;
// 十秒定时器触发次数（初始为0）
static int ten_second_trigger_count = 0;

/************************实现*******************************/

/*
 * 编程风格：
 *         函数linux/类unix风格
 *         局部变量：匈牙利命名法
 *         全局变量：匈牙利命名法
 *         宏定义：linux风格 大写
 */

/* 说明：
 * 程序清单：定时器触发计数器
 *
 * 该程序创建并启动两个定时器，并记录它们的触发次数：
 * - 一秒定时器：每秒触发一次，记录并输出触发的次数；
 * - 十秒定时器：每十秒触发一次，记录并输出触发的次数；
 *
 * 在每个定时器触发时，程序将打印出触发的次数，并在50秒后退出。
 */

/*
 * 一秒定时器回调函数
 * 每秒触发一次，输出触发的次数
 */
T_MODULE T_VOID one_second_timer_callback()
{
    one_second_trigger_count++;  // 每次触发时，增加一秒定时器触发次数
    printk("One second timer triggered %d times.\n", one_second_trigger_count);
}

/*
 * 十秒定时器回调函数
 * 每十秒触发一次，输出触发的次数
 */
T_MODULE T_VOID ten_second_timer_callback()
{
    ten_second_trigger_count++;  // 每次触发时，增加十秒定时器触发次数
    printk("Ten second timer triggered %d times.\n", ten_second_trigger_count);
}

/*
 * 用户入口函数
 * 初始化定时器，启动定时器并记录它们的触发次数
 */
int userAppInit(void)
{
    T_TTOS_ReturnCode ret;  // 用于存储函数的返回值

    // 定义一秒和十秒定时器的触发次数（初始化为0）
    T_UWORD one_second_timer_count = 0;
    T_UWORD ten_second_timer_count = 0;

    // 打印开始测试的信息
    printk("************ Begin to test ***************\n");

    /* 创建并启动一秒定时器 */
    // 创建一秒定时器，定时器触发间隔为系统时钟频率 * 1秒
    ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate() * ONE_SECOND_TIMER_INTERVAL, one_second_timer_count, NULL, one_second_timer_callback, &g_one_second_timer_id);
    if (ret != 0) {
        printk("Create One Second Timer Fail!\n");
        return -1;  // 如果定时器创建失败，返回错误码
    }

    /* 创建并启动十秒定时器 */
    // 创建十秒定时器，定时器触发间隔为系统时钟频率 * 10秒
    ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate() * TEN_SECOND_TIMER_INTERVAL, ten_second_timer_count, NULL, ten_second_timer_callback, &g_ten_second_timer_id);
    if (ret != 0) {
        printk("Create Ten Second Timer Fail!\n");
        return -1;  // 如果定时器创建失败，返回错误码
    }

    /* 激活一秒定时器 */
    ret = TTOS_ActiveTimer(g_one_second_timer_id);
    if (ret != 0) {
        printk("Failed to activate One Second Timer.\n");
        return -1;  // 如果激活定时器失败，返回错误码
    }

    /* 激活十秒定时器 */
    ret = TTOS_ActiveTimer(g_ten_second_timer_id);
    if (ret != 0) {
        printk("Failed to activate Ten Second Timer.\n");
        return -1;  // 如果激活定时器失败，返回错误码
    }

    /* 主任务休眠50秒，期间定时器会定时触发并输出触发次数 */
    sleep(50);

    // 打印任务已结束的信息
    printk("Task sleep limit reached. Exiting...\n");

    return 0;
}
