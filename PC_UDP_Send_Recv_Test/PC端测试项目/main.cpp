#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <sys/time.h>

#pragma comment(lib, "ws2_32.lib")
unsigned char dataBuf[2048];
unsigned int vM1Cnt = 0;
unsigned int vM2Cnt = 0;
HANDLE threadsEthRecvVM1;
HANDLE threadsEthSendVM1;
HANDLE threadsEthSendVM2;
HANDLE threadsEthRecvVM2;
unsigned int RxCntVm1 = 0;
unsigned int RxCntOKVm1 = 0;
unsigned int RxCntERRVm1 = 0;

unsigned int RxCntVm2 = 0;
unsigned int RxCntOKVm2 = 0;
unsigned int RxCntERRVm2 = 0;
DWORD WINAPI ThreadFuncEthUDPRecvVM1(void *data)
{

    SOCKET receivingSocket;
    struct sockaddr_in receiverAddr;
    int port = 12345; // 选择一个端口
    char receiveBuf[1024];
    int bufLen = 1024;
    unsigned char *pdata;
    struct sockaddr_in senderAddr;
    int senderAddrSize = sizeof(senderAddr);

    // 创建接收socket
    receivingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (receivingSocket == INVALID_SOCKET)
    {
        printf("Creating socket failed.\n");

        return 0;
    }

    // 绑定socket
    receiverAddr.sin_family = AF_INET;
    receiverAddr.sin_port = htons(port);
    receiverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 监听任何地址
    if (bind(receivingSocket, (SOCKADDR *)&receiverAddr, sizeof(receiverAddr)) == SOCKET_ERROR)
    {
        printf("Binding socket failed.\n");
        closesocket(receivingSocket);

        return 0;
    }
    pdata = (unsigned char *)receiveBuf;
    while (1)
    {

        if (recvfrom(receivingSocket, receiveBuf, bufLen, 0, (SOCKADDR *)&senderAddr, &senderAddrSize) == SOCKET_ERROR)
        {
            printf("Receiving failed.\n");
        }
        else
        {
            RxCntVm1++;
        }
        for(int i=0;i<5;i++){
            pdata[i];
            printf("%d",pdata[i]);
        }
    }

    // 清理
    closesocket(receivingSocket);

    return 0;
}
DWORD WINAPI ThreadFuncEthUDPRecvVM2(void *data)
{

    SOCKET receivingSocket;
    struct sockaddr_in receiverAddr;
    int port = 12346; // 选择一个端口
    char receiveBuf[1024];
    int bufLen = 1024;
    unsigned char *pdata;
    struct sockaddr_in senderAddr;
    int senderAddrSize = sizeof(senderAddr);

    // 创建接收socket
    receivingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (receivingSocket == INVALID_SOCKET)
    {
        printf("Creating socket failed.\n");

        return 0;
    }

    // 绑定socket
    receiverAddr.sin_family = AF_INET;
    receiverAddr.sin_port = htons(port);
    receiverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 监听任何地址
    if (bind(receivingSocket, (SOCKADDR *)&receiverAddr, sizeof(receiverAddr)) == SOCKET_ERROR)
    {
        printf("Binding socket failed.\n");
        closesocket(receivingSocket);

        return 0;
    }
    pdata = (unsigned char *)receiveBuf;
    while (1)
    {

        if (recvfrom(receivingSocket, receiveBuf, bufLen, 0, (SOCKADDR *)&senderAddr, &senderAddrSize) == SOCKET_ERROR)
        {
            printf("Receiving failed.\n");
        }
        else
        {
            RxCntVm2++;
        }

        if (pdata[0] == RxCntVm2)
        {
            RxCntOKVm2++;
        }
        else
        {
            RxCntERRVm2++;
            RxCntVm2 = pdata[0];
        }
    }

    // 清理
    closesocket(receivingSocket);

    return 0;
}

DWORD WINAPI ThreadFuncEthUDPSendVM1(void *data)
{
    // 创建套接字
    int i, j;
    SOCKET slisten = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (slisten == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }
    unsigned char *pdata = (unsigned char *)dataBuf;
    // 绑定IP和端口
    struct sockaddr_in sin;
    unsigned int vM1Cnt = 0;

    struct timeval begin, end;
    gettimeofday(&begin, 0);

    while(1)
    {
        for (j = 0; j < 200; j++)
        {

            for (i = 0; i < 1024; i++)
                pdata[i] = 0x55;
            sin.sin_family = AF_INET;
            sin.sin_port = htons(27015);
            sin.sin_addr.S_un.S_addr = inet_addr("192.168.5.113");
            if (sendto(slisten, (char *)(dataBuf), 1024, 0, (struct sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR)
            {
                printf("Send failed with error code : %d", WSAGetLastError());
                closesocket(slisten);

                return 1;
            }
            vM1Cnt++;
        }
//        Sleep (1);
        gettimeofday(&end, 0);
        long seconds = end.tv_sec - begin.tv_sec;
//        printf("%u\n",seconds);
        if (seconds > 60){
            break;
        }
    }

    printf("vm1 sec cnt:%d\n", vM1Cnt);
    return 0;
}

DWORD WINAPI ThreadFuncEthUDPSendVM2(void *data)
{
    // 创建套接字
    int i, j;
    SOCKET slisten = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (slisten == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }
    unsigned char *pdata = (unsigned char *)dataBuf;
    // 绑定IP和端口
    struct sockaddr_in sin;

//    int timecnt = 0;
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    unsigned int vM2Cnt = 0;
    while(1)
    {
        for (j = 0; j < 400; j++)
        {

            for (i = 0; i < 1024 ; i++)
                pdata[i] = 0x55;
            sin.sin_family = AF_INET;
            sin.sin_port = htons(27016);
            sin.sin_addr.S_un.S_addr = inet_addr("192.168.5.114");
            if (sendto(slisten, (char *)dataBuf, 1024, 0, (struct sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR)
            {
                printf("Send failed with error code : %d", WSAGetLastError());
                closesocket(slisten);

                return 1;
            }
            vM2Cnt++;
        }
//        Sleep(1);
//        Sleep(1);
        gettimeofday(&end, 0);
        long seconds = end.tv_sec - begin.tv_sec;
//        printf("%u\n",seconds);
        if (seconds > 60){
            break;
        }
    }
    printf("vm2 send cnt:%d\n", vM2Cnt);
    return 0;
}
int socketInit(void)
{
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    if (WSAStartup(sockVersion, &wsaData) != 0)
    {
        return 0;
    }
    threadsEthRecvVM1 = CreateThread(NULL, 0, ThreadFuncEthUDPRecvVM1, NULL, 0, NULL);
    threadsEthSendVM1 = CreateThread(NULL, 0, ThreadFuncEthUDPSendVM1, NULL, 0, NULL);
//    threadsEthSendVM2 = CreateThread(NULL, 0, ThreadFuncEthUDPSendVM2, NULL, 0, NULL);
//    threadsEthRecvVM2 = CreateThread(NULL, 0, ThreadFuncEthUDPRecvVM2, NULL, 0, NULL);
}

int main(int argc, char *argv[])
{

    unsigned int secondCntVm1;
    unsigned int secondCntVm2;
    unsigned int TxCntVm1;
    unsigned int TxCntVm2;
    socketInit();

    while (1)
    {
        Sleep(1000);
        printf("==========================VM1=====================\r\n");
        printf("VM1 TxAll: %d Tx/s %d  \r\n",vM1Cnt,vM1Cnt-TxCntVm1 );
        printf("VM1 [R/S:%d] [RCNT:%d] [Er:%d]\r\n", RxCntVm1 - secondCntVm1, RxCntOKVm1, RxCntERRVm1);
//        printf("==========================VM2=====================\r\n");
//        printf("VM2 TxAll: %d Tx/s %d\r\n",vM2Cnt,vM2Cnt-TxCntVm2);
//        printf("VM2 [R/S:%d] [RCNT:%d] [Er:%d]\r\n", RxCntVm2 - secondCntVm2, RxCntOKVm2, RxCntERRVm2);

        secondCntVm1 = RxCntVm1;
        secondCntVm2 = RxCntVm2;
        TxCntVm1=vM1Cnt;
        TxCntVm2=vM2Cnt;
    }
    WSACleanup();
    return 0;
}
int mainn() {
    double sum = 0;
    double add = 1;

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    int iterations = 1000*1000*1000;
    for (int i=0; i<iterations; i++) {
        sum += add;
        add /= 2.0;
    }

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("Result: %.20f\n", sum);

    printf("Time measured: %.3f seconds.\n", elapsed);

    return 0;
}
