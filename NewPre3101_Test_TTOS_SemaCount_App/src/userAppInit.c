/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <ttos.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

#define THREAD_COUNT 4  // �߳�����
#define SEM_INIT_VALUE 2 // �������󲢷��߳���

T_MODULE g_TaskID[THREAD_COUNT];  // ���� ID ����
T_MODULE g_Sema;  // �ź���

void TTOS_thread_function(void* arg) {
    int id = *(int*)arg;
    int i;

    for (i = 0; i < 5; i++) { // ÿ���߳�ִ�� 5 ������
        // �ȴ��ź���
        TTOS_ObtainSema(g_Sema, TTOS_SEMA_WAIT_FOREVER);

        printf("Thread %d acquired semaphore. Running task...\n", id);
        TTOS_SleepTask(TTOS_GetSysClkRate() * (rand() % 10)); // ģ������ִ��

        printf("Thread %d releasing semaphore.\n", id);
        TTOS_ReleaseSema(g_Sema); // �ͷ��ź���

        TTOS_SleepTask(TTOS_GetSysClkRate() * (rand() % 5)); // ��Ϣһ��ʱ��
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

    // �����ź������ƺͳ�ʼֵ
    strcpy((T_BYTE *)semaParam.cfgSemaName, (T_CONST T_BYTE *)"SEMA_DEMO");
    semaParam.initValue = SEM_INIT_VALUE;  // ���������̲߳�������
    semaParam.attributeSet = TTOS_COUNTING_SEMAPHORE;  // �����ź���
    semaParam.priorityCeiling = 0;  // ���ȼ�����Ϊ 0

    // �����ź���
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

    init_sema();  // ��ʼ���ź���

    // ���������̣߳�
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i + 1; // �߳� ID �� 1 ��ʼ
        ret = TTOS_CreateTaskEx(
            (T_UBYTE *)"Task",  // ��������
            250,                // �������ȼ�
            TRUE,               // �Ƿ���������
            TRUE,               // �Ƿ�����
            (T_TTOS_TaskRoutine)TTOS_thread_function,  // ������
            &thread_ids[i],     // �������������߳� ID��
            TTOS_MINIMUM_STACK_SIZE,  // �����ջ��С
            &g_TaskID[i]        // ���� ID
        );
        if (ret != TTOS_OK) {
            printf("Failed to create task %d\n", i);
        }
    }

    return 0;
}
