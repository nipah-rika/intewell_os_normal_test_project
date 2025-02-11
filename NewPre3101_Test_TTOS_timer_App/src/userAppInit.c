/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <ttos.h>

// �궨�壺��ʱ���Ĵ������
#define ONE_SECOND_TIMER_INTERVAL  1  // һ�붨ʱ����ÿ�봥����
#define TEN_SECOND_TIMER_INTERVAL 10 // ʮ�붨ʱ����ÿ10�봥����

/************************���Ͷ���******************************/
// һ�붨ʱ��ID��ȫ�ֱ��������ڱ�ʶһ�붨ʱ����
T_MODULE TIMER_ID g_one_second_timer_id;
// ʮ�붨ʱ��ID��ȫ�ֱ��������ڱ�ʶʮ�붨ʱ����
T_MODULE TIMER_ID g_ten_second_timer_id;

/************************ģ�����******************************/
// һ�붨ʱ��������������ʼΪ0��
static int one_second_trigger_count = 0;
// ʮ�붨ʱ��������������ʼΪ0��
static int ten_second_trigger_count = 0;

/************************ʵ��*******************************/

/*
 * ��̷��
 *         ����linux/��unix���
 *         �ֲ�������������������
 *         ȫ�ֱ�����������������
 *         �궨�壺linux��� ��д
 */

/* ˵����
 * �����嵥����ʱ������������
 *
 * �ó��򴴽�������������ʱ��������¼���ǵĴ���������
 * - һ�붨ʱ����ÿ�봥��һ�Σ���¼����������Ĵ�����
 * - ʮ�붨ʱ����ÿʮ�봥��һ�Σ���¼����������Ĵ�����
 *
 * ��ÿ����ʱ������ʱ�����򽫴�ӡ�������Ĵ���������50����˳���
 */

/*
 * һ�붨ʱ���ص�����
 * ÿ�봥��һ�Σ���������Ĵ���
 */
T_MODULE T_VOID one_second_timer_callback()
{
    one_second_trigger_count++;  // ÿ�δ���ʱ������һ�붨ʱ����������
    printk("One second timer triggered %d times.\n", one_second_trigger_count);
}

/*
 * ʮ�붨ʱ���ص�����
 * ÿʮ�봥��һ�Σ���������Ĵ���
 */
T_MODULE T_VOID ten_second_timer_callback()
{
    ten_second_trigger_count++;  // ÿ�δ���ʱ������ʮ�붨ʱ����������
    printk("Ten second timer triggered %d times.\n", ten_second_trigger_count);
}

/*
 * �û���ں���
 * ��ʼ����ʱ����������ʱ������¼���ǵĴ�������
 */
int userAppInit(void)
{
    T_TTOS_ReturnCode ret;  // ���ڴ洢�����ķ���ֵ

    // ����һ���ʮ�붨ʱ���Ĵ�����������ʼ��Ϊ0��
    T_UWORD one_second_timer_count = 0;
    T_UWORD ten_second_timer_count = 0;

    // ��ӡ��ʼ���Ե���Ϣ
    printk("************ Begin to test ***************\n");

    /* ����������һ�붨ʱ�� */
    // ����һ�붨ʱ������ʱ���������Ϊϵͳʱ��Ƶ�� * 1��
    ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate() * ONE_SECOND_TIMER_INTERVAL, one_second_timer_count, NULL, one_second_timer_callback, &g_one_second_timer_id);
    if (ret != 0) {
        printk("Create One Second Timer Fail!\n");
        return -1;  // �����ʱ������ʧ�ܣ����ش�����
    }

    /* ����������ʮ�붨ʱ�� */
    // ����ʮ�붨ʱ������ʱ���������Ϊϵͳʱ��Ƶ�� * 10��
    ret = TTOS_CreateTimerEx(TRUE, TTOS_GetSysClkRate() * TEN_SECOND_TIMER_INTERVAL, ten_second_timer_count, NULL, ten_second_timer_callback, &g_ten_second_timer_id);
    if (ret != 0) {
        printk("Create Ten Second Timer Fail!\n");
        return -1;  // �����ʱ������ʧ�ܣ����ش�����
    }

    /* ����һ�붨ʱ�� */
    ret = TTOS_ActiveTimer(g_one_second_timer_id);
    if (ret != 0) {
        printk("Failed to activate One Second Timer.\n");
        return -1;  // ������ʱ��ʧ�ܣ����ش�����
    }

    /* ����ʮ�붨ʱ�� */
    ret = TTOS_ActiveTimer(g_ten_second_timer_id);
    if (ret != 0) {
        printk("Failed to activate Ten Second Timer.\n");
        return -1;  // ������ʱ��ʧ�ܣ����ش�����
    }

    /* ����������50�룬�ڼ䶨ʱ���ᶨʱ����������������� */
    sleep(50);

    // ��ӡ�����ѽ�������Ϣ
    printk("Task sleep limit reached. Exiting...\n");

    return 0;
}
