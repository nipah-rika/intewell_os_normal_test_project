// ConsoleApplicationShmm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "shm_api.h"

#define SHM_W (2)
#define SHM_R (1)
#define SHM_WAIT (0)

#pragma comment (lib,"shmm.lib")

int main()
{
	uint32_t shm_size_w = 0;
	uint32_t shm_size_r = 0;
	unsigned char *shm_w_ptr = (unsigned char *)open_shared_memory((char *)"shm_w", 3000, &shm_size_w);
	unsigned char *shm_r_ptr = (unsigned char *)open_shared_memory((char *)"shm_r", 3000, &shm_size_r);
	volatile unsigned char *v_shm_w_ptr = shm_w_ptr;
	volatile unsigned char *v_shm_r_ptr = shm_r_ptr;

	if (NULL == shm_w_ptr) {

		printf("shm_w open failed!!!\r\n");
		return 1;
	}
	else {

		printf("shm_w open success!!!\r\n");
		printf("shm_w_ptr: %p\n", shm_w_ptr);
	}

	if (NULL == shm_r_ptr) {

		printf("shm_r open failed!!!\r\n");
		return 1;
	}
	else {

		printf("shm_r open success!!!\r\n");
		printf("shm_r_ptr: %p\n", shm_r_ptr);
	}

	if (shm_size_w != shm_size_r) {

		printf("Test Failed!!!\r\n");
		return 1;
	}

	while (1) {

		while (*v_shm_w_ptr != SHM_W);
		*v_shm_w_ptr = SHM_WAIT;

		memcpy(shm_r_ptr, shm_w_ptr, shm_size_w);

		*v_shm_r_ptr = SHM_R;
	}
	std::cout << "Hello World!\n";
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
