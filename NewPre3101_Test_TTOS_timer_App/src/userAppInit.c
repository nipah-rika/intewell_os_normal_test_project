/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

#include <commonTypes.h>
#include <stdio.h>
#include <ttos.h>

/************************�� �� ��******************************/
#define ONE_SECOND_TIMER_INTERVAL  1  // һ�붨ʱ����ÿ�봥����
#define TEN_SECOND_TIMER_INTERVAL 10 // ʮ�붨ʱ����ÿ10�봥����

/************************���Ͷ���******************************/
T_MODULE TIMER_ID g_one_second_timer_id;   // һ�붨ʱ��ID
T_MODULE TIMER_ID g_ten_second_timer_id;   // ʮ�붨ʱ��ID

/************************ģ�����******************************/
static int one_second_trigger_count = 0;   // һ�붨ʱ����������
static int ten_second_trigger_count = 0;   // ʮ�붨ʱ����������

/************************ʵ��*******************************/

// һ�붨ʱ���ص���ÿ�봥����
T_MODULE T_VOID one_second_timer_callback()
{
    one_second_trigger_count++;  // ÿ�δ���ʱ������һ�붨ʱ����������
    printk("One second timer triggered %d times.\n", one_second_trigger_count);
}

// ʮ�붨ʱ���ص���ÿ10�봥����
T_MODULE T_VOID ten_second_timer_callback()
{
    ten_second_trigger_count++;  // ÿ�δ���ʱ������ʮ�붨ʱ����������
    printk("Ten second timer triggered %d times.\n", ten_second_trigger_count);
}

int userAppInit(void)
{
    T_TTOS_ReturnCode ret;
    T_UWORD one_second_timer_count = 0;  // һ�붨ʱ�������������˴�Ϊ���޴Σ�
    T_UWORD ten_second_timer_count = 0;  // ʮ�붨ʱ�������������˴�Ϊ���޴Σ�

    printk("************ Begin to test ***************\n");

    // ����һ�붨ʱ����ÿ�봥������ֱ�Ӽ���
    ret = TTOS_CreateTimerEx(TRUE, 100, 5, NULL, one_second_timer_callback, &g_one_second_timer_id);
    if (ret != 0)
    {
        printk("Create One Second Timer Fail!\n");
        return -1;
    }

    // ����ʮ�붨ʱ����ÿ10�봥������ֱ�Ӽ���
    ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate() * TEN_SECOND_TIMER_INTERVAL, 10, NULL, ten_second_timer_callback, &g_ten_second_timer_id);
    if (ret != 0)
    {
        printk("Create Ten Second Timer Fail!\n");
        return -1;
    }

    // ֱ�Ӽ��ʱ��
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
//    // �������˯�ߴ�������
//    const int sleep_limit = 5;  // �������˯�ߴ���Ϊ5��
//    int sleep_count = 0;         // ��ǰ˯�ߴ���
//
//    // ������ѭ�������ִ��5�Σ�ÿ������5��
//    while (sleep_count < sleep_limit)
//    {
//        TTOS_SleepTask(5000);  // ����ǰ����5��
//        sleep_count++;         // ����˯�߼���
//    }
//
//    // ֹͣ��ʱ��
//    TTOS_StopTimer(g_one_second_timer_id);
//    TTOS_StopTimer(g_ten_second_timer_id);

    printf("Task sleep limit reached. Exiting...\n");

    return 0;
}
