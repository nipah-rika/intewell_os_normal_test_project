#ifndef _TEST_H
#define _TEST_H
#include <stdio.h>
#include <ttosTcpipInit.h>
#include <limits.h>
#include "lwip/netif.h"


#define TTOS_IP_vm1 "192.168.1.221"
#define TTOS_IP_vm2 "192.168.1.222"



#define TEST_OKPRINT()	printk("***Test Pass, filename: %s ***\r\n", __FILE__);
#define TSTDEF_FAILPRINT(errno)	printk("***Test Failed, error: %d, filename: %s line: %d***\r\n",errno, __FILE__, __LINE__);

#endif
