/*
* @file：userAppInit.c
* @brief：
*	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
* @implements：
*	    本文件实现了基于消息队列的多线程通信示例，包括消息的发送和接收。
*/

/************************头 文件******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>

/************************宏 定 义******************************/
#define QUEUE_NAME  "/test_queue"  // 消息队列名称
#define MAX_MSG_SIZE 1024          // 消息最大长度
#define MAX_QUEUE_LENGTH 10        // 消息队列最大长度

/************************类型定义******************************/
// 消息结构体
typedef struct {
    char content[MAX_MSG_SIZE];  // 消息内容
} Message;

/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/
/* 说明：
* 程序清单：消息队列使用例程
* 程序说明：创建两个任务（线程），一个消息队列，一个任务用于发送消息队列的消息，另一个任务用于
* 接收消息队列的消息，当发送消息到一定数量时，就停止发送，退出线程1、线程2
*
*
*/
/*
*
* 编程风格：
*         函数linux/类unix风格
*         局部变量：下划线命名法
*         全局变量：下划线命名法
*         宏定义：linux风格 大写
*/

// 发送消息到消息队列
int send_message(const char *msg) {
    mqd_t mq;                    // 消息队列描述符
    struct mq_attr attr;         // 消息队列属性

    // 设置消息队列属性
    attr.mq_flags = 0;           // 消息队列标志
    attr.mq_maxmsg = MAX_QUEUE_LENGTH;  // 消息队列最大长度
    attr.mq_msgsize = MAX_MSG_SIZE;     // 消息最大长度
    attr.mq_curmsgs = 0;          // 当前消息队列中的消息数

    // 创建或打开消息队列
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open (send)");  // 打开消息队列失败时打印错误信息
        return -1;  // 返回错误码
    }

    // 发送消息
    if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
        perror("mq_send");  // 发送消息失败时打印错误信息
        mq_close(mq);       // 关闭消息队列
        return -1;  // 返回错误码
    }

    printf("Sent: %s\n", msg);  // 打印发送的消息
    mq_close(mq);               // 关闭消息队列
    return 0;                   // 返回成功码
}

// 从消息队列接收消息
int receive_message(Message *msg) {
    mqd_t mq;                    // 消息队列描述符
    ssize_t bytes_read;          // 读取的字节数

    // 打开消息队列
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open (receive)");  // 打开消息队列失败时打印错误信息
        return -1;  // 返回错误码
    }

    // 接收消息
    bytes_read = mq_receive(mq, msg->content, MAX_MSG_SIZE, NULL);
    if (bytes_read == -1) {
        perror("mq_receive");  // 接收消息失败时打印错误信息
        mq_close(mq);          // 关闭消息队列
        return -1;  // 返回错误码
    }

    msg->content[bytes_read - 1] = '\0';  // 确保字符串以null结尾
    printf("Received: %s\n", msg->content);  // 打印接收到的消息
    mq_close(mq);                           // 关闭消息队列
    return 0;                               // 返回成功码
}

// 线程1：发送消息
void *thread1_send(void *arg) {
    const char *messages[] = {"Hello", "World", "Message", "Queue", "Test"};  // 消息数组
    for (int i = 0; i < 5; i++) {
        if (send_message(messages[i]) == -1) {  // 发送消息失败
            fprintf(stderr, "Failed to send message: %s\n", messages[i]);  // 打印错误信息
        }
        sleep(1);  // 模拟发送间隔
    }
    return NULL;  // 返回值为NULL，表示线程正常结束
}

// 线程2：接收消息
void *thread2_receive(void *arg) {
    Message msg;  // 消息结构体
    while (1) {
        if (receive_message(&msg) == -1) {  // 接收消息失败
            fprintf(stderr, "Failed to receive message\n");  // 打印错误信息
            break;  // 退出循环
        }
        if (strcmp(msg.content, "Test") == 0) {  // 接收到特定消息后退出
            break;  // 退出循环
        }
    }
    return NULL;  // 返回值为NULL，表示线程正常结束
}

int userAppInit(void) {
    pthread_t thread1, thread2;  // 定义两个线程变量

    // 创建线程1（发送消息）
    if (pthread_create(&thread1, NULL, thread1_send, NULL) != 0) {
        perror("pthread_create (thread1)");  // 创建线程1失败时打印错误信息
        return -1;  // 返回错误码
    }

    // 创建线程2（接收消息）
    if (pthread_create(&thread2, NULL, thread2_receive, NULL) != 0) {
        perror("pthread_create (thread2)");  // 创建线程2失败时打印错误信息
        return -1;  // 返回错误码
    }

    // 等待线程结束
    pthread_join(thread1, NULL);  // 等待线程1结束
    pthread_join(thread2, NULL);  // 等待线程2结束

    // 删除消息队列
    if (mq_unlink(QUEUE_NAME) == -1) {
        perror("mq_unlink");  // 删除消息队列失败时打印错误信息
    }

    printf("Main thread exit.\n");  // 打印主线程退出信息
    return 0;  // 返回成功码
}
