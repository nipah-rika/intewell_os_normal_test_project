/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

/************************ͷ �� ��******************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/************************�� �� ��******************************/
#define THREAD_STACK_SIZE 512
#define THREAD_TIMESLICE 5
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
static int cnt = 0;

/************************ʵ   ��*******************************/
// �̻߳�����
pthread_mutex_t mutex;

// �߳���ں���
void* thread_entry(void* parameter)
{
    int no = (int)parameter;
    while (1)
    {
        // ����
        pthread_mutex_lock(&mutex);
        cnt += no;
        // ����
        pthread_mutex_unlock(&mutex);

        printf("Thread[%d]'s counter is %d\n", no, cnt);
        sleep(no * 10); // ��ʱ
    }
    return NULL;
}

int userAppInit(void)
{
    pthread_t thread1, thread2;

    // ��ʼ��������
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("Mutex init failed\n");
        return -1;
    }

    // �����߳�1
    if (pthread_create(&thread1, NULL, thread_entry, (void*)10) != 0)
    {
        printf("Thread1 creation failed\n");
        return -1;
    }

    // �����߳�2
    if (pthread_create(&thread2, NULL, thread_entry, (void*)20) != 0)
    {
        printf("Thread2 creation failed\n");
        return -1;
    }

    // �ȴ��߳̽���
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // ���ٻ�����
    pthread_mutex_destroy(&mutex);

    return 0;
}
