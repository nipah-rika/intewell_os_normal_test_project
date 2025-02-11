/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

/************************ͷ �ļ�******************************/
#include <stdio.h>     // ��׼�������ͷ�ļ�
#include <stdlib.h>    // ��׼��ͷ�ļ�
#include <pthread.h>   // POSIX�߳̿�ͷ�ļ�
#include <unistd.h>    // �ṩsleep��ϵͳ����

/************************�� �� ��******************************/
#define THREAD_STACK_SIZE 512  // �����߳�ջ��С
#define THREAD_TIMESLICE 5    // �����߳�ʱ��Ƭ

/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
static int cnt = 0;  // ȫ�ֱ����������̼߳乲�����

/************************ʵ   ��*******************************/
/* ˵����
 * �����嵥��������ʹ������
 *
 * ���������ڱ���������Դ����ȫ�ֱ���cnt������ֹ����߳�ͬʱ���ʵ������ݾ�����
 * �ڷ��ʹ�����Դ֮ǰ���̱߳����Ȼ�ȡ��������pthread_mutex_lock����������ɺ��ͷŻ�������pthread_mutex_unlock����
 * ���һ���߳��Ѿ���ȡ�˻������������̳߳��Ի�ȡ����ʱ�ᱻ������ֱ�������ͷš�
 *
 * ��̷��
 *         ������Linux/��Unix���
 *         �ֲ��������»���������
 *         ȫ�ֱ������»���������
 *         �궨�壺Linux��񣨴�д��
 */

// �̻߳�����
pthread_mutex_t mutex;  // ���������������ڱ���������Դ

// �߳���ں���
void* thread_entry(void* parameter)
{
    int no = (int)parameter;  // �ֲ���������ʾ�̱߳��
    while (1)
    {
        // ��������ȡ������������������Դcnt
        pthread_mutex_lock(&mutex);
        cnt += no;  // �޸Ĺ�����Դ
        // �������ͷŻ����������������̷߳��ʹ�����Դ
        pthread_mutex_unlock(&mutex);

        printf("Thread[%d]'s counter is %d\n", no, cnt);  // ��ӡ��ǰ�̵߳ļ���ֵ
        sleep(no * 10);  // ��ʱ��ģ���̹߳�������
    }
    return NULL;  // ����ֵΪNULL����ʾ�߳���������
}

int userAppInit(void)
{
    pthread_t thread1, thread2;  // ���������̱߳���

    // ��ʼ��������
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("Mutex init failed\n");  // ��ʼ��ʧ��ʱ��ӡ������Ϣ
        return -1;  // ���ش�����
    }

    // �����߳�1
    if (pthread_create(&thread1, NULL, thread_entry, (void*)10) != 0)
    {
        printf("Thread1 creation failed\n");  // ����ʧ��ʱ��ӡ������Ϣ
        return -1;  // ���ش�����
    }

    // �����߳�2
    if (pthread_create(&thread2, NULL, thread_entry, (void*)20) != 0)
    {
        printf("Thread2 creation failed\n");  // ����ʧ��ʱ��ӡ������Ϣ
        return -1;  // ���ش�����
    }

    // �ȴ��߳�1����
    pthread_join(thread1, NULL);
    // �ȴ��߳�2����
    pthread_join(thread2, NULL);

    // ���ٻ�����
    pthread_mutex_destroy(&mutex);

    return 0;  // ���سɹ���
}
