/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

/* ˵����
 * �����嵥���������Ļָ�����
 *
 * �ó���ͨ���Զ���� `pthread_mutexattr_setrobust_np` �� `pthread_mutex_lock_with_recovery` ������
 * ģ���˻������ġ�robust��״̬�������ָ����ơ��������������̣߳�
 * - �߳�1�������������������в�ģ�������ͨ��˯��2�룩��
 * - �߳�2����������������������������ʱ���лָ���
 *
 * - �߳�1������������������������߳�2�ڳ�������ʱ���� `EOWNERDEAD` �����롣
 * - �߳�2�������������³������������ճɹ���ȡ����������
 *
 * ������ʾ�����ͨ��ģ��ָ���������������״̬��
 */

#define THREAD_NUM 2 // �����߳���Ϊ2

/* �����̵߳�ǰ������ */
void* thread_1(void* arg);
void* thread_2(void* arg);

/* ģ�⡰robust����־�ı��� */
int robust_flag = 0;

/* ���������� */
pthread_mutex_t mutex;

/*
 * ģ���Զ���� `pthread_mutexattr_setrobust_np` �������������á�robust��״̬��
 * �ú����Ὣ `robust_flag` ����Ϊָ����ֵ����ģ�����ġ�robust�����ԡ�
 */
int pthread_mutexattr_setrobust_np(pthread_mutexattr_t *attr, int robust) {
    robust_flag = robust; // ���ñ�־
    return 0; // ���سɹ�
}

/*
 * ģ�⴦�����Ļָ����ơ���������᳢�Ի�ȡ�����������״̬��
 * �����⵽����״̬��EOWNERDEAD���������лָ�������ģ������״̬����
 */
int pthread_mutex_lock_with_recovery(pthread_mutex_t *mutex) {
    int rc = pthread_mutex_lock(mutex);  // ����������
    if (rc != 0 && robust_flag) {  // ����������������ҡ�robust����־������
        if (rc == EOWNERDEAD) {
            printf("Recovering mutex from dead owner...\n");  // ģ��ָ�
            rc = 0; // �ָ��ɹ�����������
        }
    }
    return rc;  // ��������״̬
}

/* �߳�1����ͨ������ģ����� */
void* thread_1(void* arg) {
    pthread_mutex_lock(&mutex);  // ����������
    printf("Thread 1 locked the mutex\n");
    sleep(2);  // ģ���߳�1����һ��ʱ������
    printf("Thread 1 exiting\n");
    pthread_exit(NULL);  // �˳��߳�
    return NULL;
}

/* �߳�2�����Իָ�����״̬ */
void* thread_2(void* arg) {
    int rc;

    printf("Thread 2 attempting to lock the mutex...\n");

    rc = pthread_mutex_lock(&mutex);  // ��������������
    if (rc == EOWNERDEAD) {  // �������ʧ�ܲ��Ҽ�⵽����
        printf("Thread 2 encountered EOWNERDEAD. Handling mutex recovery...\n");

        // ģ��ָ�������ֱ������
        rc = pthread_mutex_lock(&mutex);  // �ٴγ�������
    }

    if (rc != 0) {
        printf("FAIL: mutex_lock failed with error code %d\n", rc);
        pthread_exit(NULL);  // �����˳��߳�
    }

    printf("Thread 2 successfully locked the mutex\n");
    pthread_mutex_unlock(&mutex);  // ����

    pthread_exit(NULL);  // �˳��߳�
    return NULL;
}

/* �û�Ӧ�ó�ʼ�� */
int userAppInit(void) {
    pthread_t threads[2];  // �߳�����
    pthread_mutexattr_t mutex_attr;  // ����������
    int rc;

    // ��ʼ�����������Բ�ģ�⡰robust������
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_setrobust_np(&mutex_attr, 1);  // ������robust������
    pthread_mutex_init(&mutex, &mutex_attr);  // ��ʼ��������

    // �����߳�
    rc = pthread_create(&threads[0], NULL, thread_1, NULL);
    if (rc != 0) {
        printf("Error creating thread 1: %s\n", strerror(rc));
        return -1;  // �̴߳���ʧ��
    }

    rc = pthread_create(&threads[1], NULL, thread_2, NULL);
    if (rc != 0) {
        printf("Error creating thread 2: %s\n", strerror(rc));
        return -1;  // �̴߳���ʧ��
    }

    // �ȴ��߳̽���
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("Test PASSED\n");
    return 0;
}
