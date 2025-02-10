/****************************************************************************
 *			鍖椾含绉戦摱浜垚鎶�鏈湁闄愬叕鍙� 鐗堟潈鎵�鏈�
 *
 * 		 Copyright (C) 2000-2006 CoreTek Systems Inc. All Rights Reserved.
 ***************************************************************************/
/*
 * return codes
 */
#ifndef _TEST_H
#define _TEST_H
#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <ttosTcpipInit.h>
#include <config_components.h>
#include <mpart.h>
#include <limits.h>
#include "lwip/netif.h"
#ifndef UNUSED_ARG
#define UNUSED_ARG(x)     (void)x
#endif /* UNUSED_ARG */
/*
 * @brief 娉㈢壒鐜囪〃
 */
#define BAUD_9600       9600
#define BAUD_19200      19200
#define BAUD_38400      38400
#define BAUD_57600      57600
#define BAUD_115200     115200

//缃戠粶鐢ㄤ緥鐨処P鍦ㄨ繖閲屼娇鐢ㄥ畯杩涜缁熶竴绠＄悊锛屾墽琛屾祴璇曟椂鍙灏嗕互涓�9涓猧p淇敼涓庣洰鏍囨満鍚屼竴缃戞鍗冲彲
#define TTOS_IP_vm1 "192.168.118.200"
#define TTOS_IP_vm2 "192.168.118.201"
#define TTOS_IP_vm3 "192.168.118.202"
#define TTOS_IP_vm4 "192.168.118.203"
#define TTOS_IP_vm5 "192.168.118.204"
#define TTOS_IP_vm6 "192.168.118.205"
#define TTOS_IP_vm7 "192.168.118.206"
#define TTOS_IP_vm8 "192.168.118.207"
#define COMMONNET_IP "192.168.118.208"


#define SELF_DEFINE_TYPE 0x0700  //绫诲瀷甯э細瑕佸ぇ浜�0x0600

//浠ヤ笅4涓猧p鏃犻渶淇敼
#define TTOS_IP_vm12 "192.168.117.207"
#define TTOS_IP_vm13 "192.168.119.216"
#define TTOS_IP_vm22 "192.168.117.212"
#define TTOS_IP_vm23 "192.168.119.211"

//posix鐢ㄤ緥鑷姩鍖�
struct test_fn_arr{
    int (*fn)(void);
	int (*beforefn)(void);
	int (*afterfn)(void);
    const char *fn_name;
};

extern int test_restart_flag;
#define PTS_PASS        0
#define PTS_FAIL        1
#define PTS_UNRESOLVED  2
#define PTS_UNSUPPORTED 4
#define PTS_UNTESTED    5

#define PTS_NOTBEGIN 6
#define PTS_FINISH 7

#define PTS_SEND   -1
#define PTS_RECV    -2
#define PTS_JUDGEONHOST  -3
#define TEST_RESTART {test_restart_flag = 1;}    //閽堝娴嬭瘯宸ュ叿娣诲姞瀹忓畾涔�

extern UINT32 hpet_int_vector;
#define HPET_INT_NUM (hpet_int_vector)
//VMK_VINT_EXCEPTION鏍堜繚鎶ゅ紓甯镐腑鏂彿瀹氫箟
#ifdef _X86_
#define EXCEPTION_NUM 14
#elif defined(_MIPS_)
#ifdef CONFIG_OS_LP64
#define EXCEPTION_NUM 3
#else
#define EXCEPTION_NUM 1
#endif
#elif defined(__AARCH32__)
#define EXCEPTION_NUM 3
#elif defined(__AARCH64__)
#define EXCEPTION_NUM 36
#endif


#ifdef _X86_
#define ETH_NAME "en1"
#elif defined (_MIPS_)
#define ETH_NAME "gm1"
#elif defined(__AARCH32__)
#define ETH_NAME  "gm1"
#elif defined(__AARCH64__)
#define ETH_NAME  "gm1"
#endif

/*
 * @brief 鍚勪釜骞冲彴鐨勬祴璇曚覆鍙�
 */
#ifdef _X86_
#define TEST_COM    "/COM2"
#elif defined (_MIPS_)
#define TEST_COM    "/COM4"
#elif defined(__AARCH32__)
#define TEST_COM    "/COM1"
#elif defined(__AARCH64__)
#define TEST_COM    "/COM1"
#endif

#ifdef __cplusplus

#define TEST_OKPRINT()      
#define TEST_ERRFPRINT(err) std::cout << "***Test Failed, error: " << err << ", filename: " << __FILE__ << " line: " << __LINE__ << "***" << std::endl;
#define TEST_FAILRINT()     std::cout << "***Test Failed, filename: " << __FILE__ << " line: " << __LINE__ << "***" << std::endl;

#define VERIFY(condition) do{\
    if (condition) {\
        TEST_OKPRINT();\
        c_Results.isPass=PTS_PASS;\
    } else {\
        TEST_FAILRINT();\
        c_Results.isPass=PTS_FAIL;\
        return;\
    }\
} while (0)

#define TEST_START(casename) do {\
	extern void casename();\
    cout << "****test_begin****" << #casename << endl;\
    casename();\
	if (c_Results.isPass == PTS_PASS) {cout << "***Test Pass, filename: ../../src/" << #casename << ".cpp ***" <<endl;}\
	else {cout << "***Test Failed, filename: ../../src/" << #casename << ".cpp ***" <<endl;}\
    cout << "****test_end****" << #casename << endl;\
} while(0)\
	
#else

#define TEST_OKPRINT()	printk("***Test Pass, filename: %s ***\r\n", __FILE__);
#define TEST_ERRPRINT(err)	printk("***Test Failed, error: %s, filename: %s line: %d***\r\n", err, __FILE__, __LINE__);
#define TEST_FAILPRINT(err)	printk("***Test Failed, error: %s, filename: %s line: %d***\r\n",err, __FILE__, __LINE__);
#define TEST_FAILRINT()  	printk("***Test Failed, filename: %s line: %d***\r\n",  __FILE__, __LINE__);

#define TSTDEF_OKPRINT()	printk("***Test Pass, filename: %s ***\r\n", __FILE__);
#define TSTDEF_ERRPRINT(errno)	printk("***Test Failed, error: %d, filename: %s line: %d***\r\n", errno, __FILE__, __LINE__);
#define TSTDEF_FAILPRINT(errno)	printk("***Test Failed, error: %d, filename: %s line: %d***\r\n",errno, __FILE__, __LINE__);

#define TEST_RESULT 	if(PTS_PASS != status){printf("Result: error,function:%s,line:%d,status:%d\n",__FUNCTION__,__LINE__,status);return ;}

#endif


#ifndef SRC_INCLUDE_CONFIG_H_
#define SRC_INCLUDE_CONFIG_H_

#define GJB_PASS        (0)
#define GJB_FAIL        (-1)

#define PASS_F            "***Test Pass, filename: " __FILE__
#define FAILED_F           "***Test Failed, filename:  "  __FILE__

#define GJB_PRT_INFO(fmt, arg...)       gjb_os_fprintf(fmt, ##arg)
#define GJB_PRT_ERROR_INFO(fmt, arg...) gjb_os_fprintf("<ERROR %d> <FUNC %s> -- <LINE %d> "fmt GJB_CRLF, errno, __func__, __LINE__, ##arg)

#define GJB_PRI_PASS()      gjb_os_result(PASS_F, 0)
#define GJB_PRI_FAIL()      gjb_os_result(FAILED_F, -1)

#endif /* SRC_INCLUDE_CONFIG_H_ */

#define GoOnChoice(str,a)

#ifndef TEST_DYLOAD_H
#define TEST_DYLOAD_H

#define  TESTCASE_Normal  1
#define  TESTCASE_Errno 1

#define Skip_TestCase()   printk("****test_begin****\n***Test Pass SKIP_TESTCASE ***\n****test_end****\n");

typedef struct
{
    int isPass;              //娴嬭瘯缁撴灉TEST_PASS~TEST_UNRESOLVED
    char retValue[100];            //娴嬭瘯涓帴鍙ｇ湡瀹炶繑鍥炲��
}T_TestResults;

extern T_TestResults c_Results;

static inline T_ULONG Get_unMapAddress()
{
 return 0x00000000;
}

//nfs鍜宖atfs鏂囦欢绯荤粺

#ifdef __cplusplus        //c++鏍圭洰褰曢渶瑕佸姞涓�涓��/鈥�
#define PATH_F "/"
#else
#define PATH_F
#endif

#if CONFIG_NFS
#define FS_ROOT  "/nfsd"PATH_F
#else
#define FS_ROOT  "/mount/fatfs_C"PATH_F
#endif



#define EPSION 1.0e-6


// /*鏍稿績绌洪棿*/
// #define KERNEL_RAM_START			0x400000
// #define PAGE_RAM_START				0x600000


/*搴旂敤鍒嗗尯绌洪棿*/
#define P1_RAM_START				0xA000000
#define P2_RAM_START				0xB000000

#define P1_RAM_LOGIC_START			0x40000000
#define P2_RAM_LOGIC_START			0x40000000


#ifdef __AARCH32__
#define P1_SHARE_MEM_LOGIC_START	0xde000000
#define P2_SHARE_MEM_LOGIC_START	0xde000000
#elif defined(__AARCH64__)
#define P1_SHARE_MEM_LOGIC_START	0xFFFFFFF4e0000000
#define P2_SHARE_MEM_LOGIC_START	0xFFFFFFF4e0000000
#else
#define P1_SHARE_MEM_LOGIC_START	0x50200000
#define P2_SHARE_MEM_LOGIC_START	0x50200000
#endif
#define P1_RAM_RDONLY_START				0x4d000000   //鍙绌洪棿鍦板潃
#define P2_RAM_RDONLY_START				0x4d000000
/*鍙姞杞芥ā鍧楃殑鍦板潃*/
//#define ELF_PATH 	"/ata0a/out/testfile.out"
//#define ELF_PATH 	"host:/testfile.out"
#define ELF_PATH            "/ata00:2/test_file.out"

/*鍙姞杞芥ā鍧楀悕*/
#define ELF_NAME 	"test_file.out"

/*鍙姞杞芥ā鍧楄矾寰�*/
#define FILE_PATH 	"/ata00:2"

/*妯″潡涓璫ommon绗﹀彿鍚�*/
#define COMSYM 	"iTestCommmon"

/*妯″潡涓叏灞�鍙橀噺鍚�*/
#define GLOSYM 	"iTestGlobal"

/*妯″潡涓叏灞�鍑芥暟鍚�*/
#define GLOFUN 	"func_hello1"

/*妯″潡涓眬閮ㄥ嚱鏁板悕*/
#define LOCFUN 	"localFunc"

#define ROOTDIR "/ata00:2"

#endif
static  ip_addr_t brief_of_netif_getip(char * netif_name)
{
	struct netif * netif_temp =  NULL;
	ip_addr_t ipaddr = {};
	if (NULL != netif_name)
	{
		netif_temp = netif_find(netif_name);
		if (NULL != netif_temp)
		{
			ipaddr = netif_temp->ip_addr;
		}
	}
	return ipaddr;
}
#endif
