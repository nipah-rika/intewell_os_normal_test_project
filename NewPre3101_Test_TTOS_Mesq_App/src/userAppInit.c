/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

/************************ͷ �� ��******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
#define QUEUE_NAME  "/test_queue"  // ��Ϣ��������
#define MAX_MSG_SIZE 1024          // ��Ϣ��󳤶�
#define MAX_QUEUE_LENGTH 10        // ��Ϣ������󳤶�
/************************ʵ   ��*******************************/

// ��Ϣ�ṹ��
typedef struct {
    char content[MAX_MSG_SIZE];  // ��Ϣ����
} Message;

// ������Ϣ����Ϣ����
int send_message(const char *msg) {
    mqd_t mq;
    struct mq_attr attr;

    // ������Ϣ��������
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_QUEUE_LENGTH;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    // ���������Ϣ����
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open (send)");
        return -1;
    }

    // ������Ϣ
    if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
        perror("mq_send");
        mq_close(mq);
        return -1;
    }

    printf("Sent: %s\n", msg);
    mq_close(mq);
    return 0;
}

// ����Ϣ���н�����Ϣ
int receive_message(Message *msg) {
    mqd_t mq;
    ssize_t bytes_read;

    // ����Ϣ����
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open (receive)");
        return -1;
    }

    // ������Ϣ
    bytes_read = mq_receive(mq, msg->content, MAX_MSG_SIZE, NULL);
    if (bytes_read == -1) {
        perror("mq_receive");
        mq_close(mq);
        return -1;
    }

    msg->content[bytes_read - 1] = '\0';  // ȷ���ַ�����null��β
    printf("Received: %s\n", msg->content);
    mq_close(mq);
    return 0;
}

// �߳�1��������Ϣ
void *thread1_send(void *arg) {
    const char *messages[] = {"Hello", "World", "Message", "Queue", "Test"};
    for (int i = 0; i < 5; i++) {
        if (send_message(messages[i]) == -1) {
            fprintf(stderr, "Failed to send message: %s\n", messages[i]);
        }
        sleep(1);  // ģ�ⷢ�ͼ��
    }
    return NULL;
}

// �߳�2��������Ϣ
void *thread2_receive(void *arg) {
    Message msg;
    while (1) {
        if (receive_message(&msg) == -1) {
            fprintf(stderr, "Failed to receive message\n");
            break;
        }
        if (strcmp(msg.content, "Test") == 0) {
            break;  // ���յ��ض���Ϣ���˳�
        }
    }
    return NULL;
}

int userAppInit(void) {
    pthread_t thread1, thread2;

    // �����߳�1��������Ϣ��
    if (pthread_create(&thread1, NULL, thread1_send, NULL) != 0) {
        perror("pthread_create (thread1)");
        return -1;
    }

    // �����߳�2��������Ϣ��
    if (pthread_create(&thread2, NULL, thread2_receive, NULL) != 0) {
        perror("pthread_create (thread2)");
        return -1;
    }

    // �ȴ��߳̽���
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // ɾ����Ϣ����
    if (mq_unlink(QUEUE_NAME) == -1) {
        perror("mq_unlink");
    }

    printf("Main thread exit.\n");
    return 0;
}
