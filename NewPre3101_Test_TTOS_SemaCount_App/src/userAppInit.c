/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <ttos.h>

/************************�� �� ��******************************/
// �����߳�����Ϊ4
#define THREAD_COUNT 4
// �����ź����ĳ�ʼֵΪ2�����������̲߳�������
#define SEM_INIT_VALUE 2

/************************���Ͷ���******************************/
T_MODULE g_TaskID[THREAD_COUNT];  // ���ڴ洢������ÿ���̵߳� ID
T_MODULE g_Sema;  // �ź��������Ʋ����߳���

/************************ģ�����******************************/
static int thread_ids[THREAD_COUNT];  // �߳� ID ���飬���ڴ洢ÿ���̵߳� ID

/************************ʵ��*******************************/

/*
 * ��̷��
 *         ����linux/��unix���
 *         �ֲ�������������������
 *         ȫ�ֱ�����������������
 *         �궨�壺linux��� ��д
 */

/* ˵����
 * �����嵥���ź�������߳�ģ��
 *
 * �ó��򴴽������� 4 ���̣߳�ʹ��һ�������ź��������Ʋ���ִ�У�
 * - ÿ���߳���ִ������ʱ�����ȡ�ź�����ִ��������ͷ��ź�����
 * - ÿ���̻߳�ִ�� 5 ������ÿ����������ȴ��ź�����ִ�������ͷ��ź�����
 * - �ź����ĳ�ʼֵΪ 2��������� 2 ���̲߳���ִ������
 */

/**
 * �̺߳�����ģ��ÿ���߳�ִ������
 * ÿ���̻߳�ȡ�ź�����ִ��������ͷ��ź���
 * ÿ���߳�ִ�� 5 ������
 *
 * @param arg �̵߳Ĳ��������̵߳� ID
 */
void TTOS_thread_function(void* arg) {
    int id = *(int*)arg;  // ��ȡ�߳� ID
    int i;

    // ÿ���߳�ִ�� 5 ������
    for (i = 0; i < 5; i++) {
        // �ȴ��ź��������ź���Ϊ 0����������ֱ���ź�������
        TTOS_ObtainSema(g_Sema, TTOS_SEMA_WAIT_FOREVER);

        // �ɹ���ȡ�ź�����ģ��ִ������
        printf("Thread %d acquired semaphore. Running task...\n", id);
        TTOS_SleepTask(TTOS_GetSysClkRate() * (rand() % 10)); // ���ģ������ִ��ʱ��

        // ������ɺ��ͷ��ź���
        printf("Thread %d releasing semaphore.\n", id);
        TTOS_ReleaseSema(g_Sema); // �ͷ��ź��������������̼߳���ִ��

        // �߳�ִ��������������Ϣһ��ʱ��
        TTOS_SleepTask(TTOS_GetSysClkRate() * (rand() % 5)); // �����Ϣʱ��
    }
}

/**
 * ��ʼ���ź���
 * �����ź����ĳ�ʼֵ�����������ź���
 */
void init_sema(void) {
    T_TTOS_ReturnCode status;  // �洢����ֵ
    T_TTOS_ConfigSema semaParam;  // �ź������ýṹ��

    // ��ʼ���ź�������
    status = TTOS_InitSemaConfig(&semaParam);
    if (status != TTOS_OK) {
        printf("Semaphore initialization failed\n");
        return;  // ��ʼ��ʧ�ܣ��˳�����
    }

    // �����ź��������ƺͳ�ʼֵ
    strcpy((T_BYTE *)semaParam.cfgSemaName, (T_CONST T_BYTE *)"SEMA_DEMO");  // �����ź�������
    semaParam.initValue = SEM_INIT_VALUE;  // �����ź����ĳ�ʼֵΪ 2��������������̲߳���
    semaParam.attributeSet = TTOS_COUNTING_SEMAPHORE;  // �����ź���Ϊ�����ź���
    semaParam.priorityCeiling = 0;  // ���������ȼ�����

    // �����ź���
    status = TTOS_CreateSema(&semaParam, &g_Sema);
    if (status != TTOS_OK) {
        printf("Failed to create semaphore\n");
        return;  // �����ź���ʧ�ܣ��˳�����
    }
}

/**
 * �û�Ӧ�ó�ʼ������
 * ���������� 4 ���̣߳���ʼ���ź���������ʼִ������
 */
int userAppInit(void) {
    T_TTOS_ReturnCode ret;  // �洢�����ķ���ֵ
    int i;

    init_sema();  // ��ʼ���ź���

    // ���� 4 ���̣߳�ÿ���߳�ִ�� TTOS_thread_function
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i + 1;  // �߳� ID �� 1 ��ʼ�������߳� ID Ϊ 0
        ret = TTOS_CreateTaskEx(
            (T_UBYTE *)"Task",  // ��������
            250,                // �������ȼ�����Ϊ 250
            TRUE,               // �Ƿ�������������
            TRUE,               // ��������
            (T_TTOS_TaskRoutine)TTOS_thread_function,  // ����ִ�еĺ���
            &thread_ids[i],     // ��������������߳� ID��
            TTOS_MINIMUM_STACK_SIZE,  // �����ջ��С
            &g_TaskID[i]        // �洢���� ID �ĵ�ַ
        );
        // ������񴴽��Ƿ�ɹ�
        if (ret != TTOS_OK) {
            printf("Failed to create task %d\n", i);  // ����ʧ��ʱ���������Ϣ
        }
    }

    return 0;  // ���� 0 ��ʾ��ʼ�����
}
