/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*/

/************************头 文 件******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>

/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
#define QUEUE_NAME  "/test_queue"  // 消息队列名称
#define MAX_MSG_SIZE 1024          // 消息最大长度
#define MAX_QUEUE_LENGTH 10        // 消息队列最大长度
/************************实   现*******************************/

// 消息结构体
typedef struct {
    char content[MAX_MSG_SIZE];  // 消息内容
} Message;

// 发送消息到消息队列
int send_message(const char *msg) {
    mqd_t mq;
    struct mq_attr attr;

    // 设置消息队列属性
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_QUEUE_LENGTH;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    // 创建或打开消息队列
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open (send)");
        return -1;
    }

    // 发送消息
    if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
        perror("mq_send");
        mq_close(mq);
        return -1;
    }

    printf("Sent: %s\n", msg);
    mq_close(mq);
    return 0;
}

// 从消息队列接收消息
int receive_message(Message *msg) {
    mqd_t mq;
    ssize_t bytes_read;

    // 打开消息队列
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open (receive)");
        return -1;
    }

    // 接收消息
    bytes_read = mq_receive(mq, msg->content, MAX_MSG_SIZE, NULL);
    if (bytes_read == -1) {
        perror("mq_receive");
        mq_close(mq);
        return -1;
    }

    msg->content[bytes_read - 1] = '\0';  // 确保字符串以null结尾
    printf("Received: %s\n", msg->content);
    mq_close(mq);
    return 0;
}

// 线程1：发送消息
void *thread1_send(void *arg) {
    const char *messages[] = {"Hello", "World", "Message", "Queue", "Test"};
    for (int i = 0; i < 5; i++) {
        if (send_message(messages[i]) == -1) {
            fprintf(stderr, "Failed to send message: %s\n", messages[i]);
        }
        sleep(1);  // 模拟发送间隔
    }
    return NULL;
}

// 线程2：接收消息
void *thread2_receive(void *arg) {
    Message msg;
    while (1) {
        if (receive_message(&msg) == -1) {
            fprintf(stderr, "Failed to receive message\n");
            break;
        }
        if (strcmp(msg.content, "Test") == 0) {
            break;  // 接收到特定消息后退出
        }
    }
    return NULL;
}

int userAppInit(void) {
    pthread_t thread1, thread2;

    // 创建线程1（发送消息）
    if (pthread_create(&thread1, NULL, thread1_send, NULL) != 0) {
        perror("pthread_create (thread1)");
        return -1;
    }

    // 创建线程2（接收消息）
    if (pthread_create(&thread2, NULL, thread2_receive, NULL) != 0) {
        perror("pthread_create (thread2)");
        return -1;
    }

    // 等待线程结束
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 删除消息队列
    if (mq_unlink(QUEUE_NAME) == -1) {
        perror("mq_unlink");
    }

    printf("Main thread exit.\n");
    return 0;
}
