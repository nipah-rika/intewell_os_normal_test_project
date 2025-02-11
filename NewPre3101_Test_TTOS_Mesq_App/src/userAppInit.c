/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*	    ���ļ�ʵ���˻�����Ϣ���еĶ��߳�ͨ��ʾ����������Ϣ�ķ��ͺͽ��ա�
*/

/************************ͷ �ļ�******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>

/************************�� �� ��******************************/
#define QUEUE_NAME  "/test_queue"  // ��Ϣ��������
#define MAX_MSG_SIZE 1024          // ��Ϣ��󳤶�
#define MAX_QUEUE_LENGTH 10        // ��Ϣ������󳤶�

/************************���Ͷ���******************************/
// ��Ϣ�ṹ��
typedef struct {
    char content[MAX_MSG_SIZE];  // ��Ϣ����
} Message;

/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/
/* ˵����
* �����嵥����Ϣ����ʹ������
* ����˵�����������������̣߳���һ����Ϣ���У�һ���������ڷ�����Ϣ���е���Ϣ����һ����������
* ������Ϣ���е���Ϣ����������Ϣ��һ������ʱ����ֹͣ���ͣ��˳��߳�1���߳�2
*
*
*/
/*
*
* ��̷��
*         ����linux/��unix���
*         �ֲ��������»���������
*         ȫ�ֱ������»���������
*         �궨�壺linux��� ��д
*/

// ������Ϣ����Ϣ����
int send_message(const char *msg) {
    mqd_t mq;                    // ��Ϣ����������
    struct mq_attr attr;         // ��Ϣ��������

    // ������Ϣ��������
    attr.mq_flags = 0;           // ��Ϣ���б�־
    attr.mq_maxmsg = MAX_QUEUE_LENGTH;  // ��Ϣ������󳤶�
    attr.mq_msgsize = MAX_MSG_SIZE;     // ��Ϣ��󳤶�
    attr.mq_curmsgs = 0;          // ��ǰ��Ϣ�����е���Ϣ��

    // ���������Ϣ����
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open (send)");  // ����Ϣ����ʧ��ʱ��ӡ������Ϣ
        return -1;  // ���ش�����
    }

    // ������Ϣ
    if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
        perror("mq_send");  // ������Ϣʧ��ʱ��ӡ������Ϣ
        mq_close(mq);       // �ر���Ϣ����
        return -1;  // ���ش�����
    }

    printf("Sent: %s\n", msg);  // ��ӡ���͵���Ϣ
    mq_close(mq);               // �ر���Ϣ����
    return 0;                   // ���سɹ���
}

// ����Ϣ���н�����Ϣ
int receive_message(Message *msg) {
    mqd_t mq;                    // ��Ϣ����������
    ssize_t bytes_read;          // ��ȡ���ֽ���

    // ����Ϣ����
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open (receive)");  // ����Ϣ����ʧ��ʱ��ӡ������Ϣ
        return -1;  // ���ش�����
    }

    // ������Ϣ
    bytes_read = mq_receive(mq, msg->content, MAX_MSG_SIZE, NULL);
    if (bytes_read == -1) {
        perror("mq_receive");  // ������Ϣʧ��ʱ��ӡ������Ϣ
        mq_close(mq);          // �ر���Ϣ����
        return -1;  // ���ش�����
    }

    msg->content[bytes_read - 1] = '\0';  // ȷ���ַ�����null��β
    printf("Received: %s\n", msg->content);  // ��ӡ���յ�����Ϣ
    mq_close(mq);                           // �ر���Ϣ����
    return 0;                               // ���سɹ���
}

// �߳�1��������Ϣ
void *thread1_send(void *arg) {
    const char *messages[] = {"Hello", "World", "Message", "Queue", "Test"};  // ��Ϣ����
    for (int i = 0; i < 5; i++) {
        if (send_message(messages[i]) == -1) {  // ������Ϣʧ��
            fprintf(stderr, "Failed to send message: %s\n", messages[i]);  // ��ӡ������Ϣ
        }
        sleep(1);  // ģ�ⷢ�ͼ��
    }
    return NULL;  // ����ֵΪNULL����ʾ�߳���������
}

// �߳�2��������Ϣ
void *thread2_receive(void *arg) {
    Message msg;  // ��Ϣ�ṹ��
    while (1) {
        if (receive_message(&msg) == -1) {  // ������Ϣʧ��
            fprintf(stderr, "Failed to receive message\n");  // ��ӡ������Ϣ
            break;  // �˳�ѭ��
        }
        if (strcmp(msg.content, "Test") == 0) {  // ���յ��ض���Ϣ���˳�
            break;  // �˳�ѭ��
        }
    }
    return NULL;  // ����ֵΪNULL����ʾ�߳���������
}

int userAppInit(void) {
    pthread_t thread1, thread2;  // ���������̱߳���

    // �����߳�1��������Ϣ��
    if (pthread_create(&thread1, NULL, thread1_send, NULL) != 0) {
        perror("pthread_create (thread1)");  // �����߳�1ʧ��ʱ��ӡ������Ϣ
        return -1;  // ���ش�����
    }

    // �����߳�2��������Ϣ��
    if (pthread_create(&thread2, NULL, thread2_receive, NULL) != 0) {
        perror("pthread_create (thread2)");  // �����߳�2ʧ��ʱ��ӡ������Ϣ
        return -1;  // ���ش�����
    }

    // �ȴ��߳̽���
    pthread_join(thread1, NULL);  // �ȴ��߳�1����
    pthread_join(thread2, NULL);  // �ȴ��߳�2����

    // ɾ����Ϣ����
    if (mq_unlink(QUEUE_NAME) == -1) {
        perror("mq_unlink");  // ɾ����Ϣ����ʧ��ʱ��ӡ������Ϣ
    }

    printf("Main thread exit.\n");  // ��ӡ���߳��˳���Ϣ
    return 0;  // ���سɹ���
}
