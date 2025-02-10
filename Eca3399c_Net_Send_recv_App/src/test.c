#include <test.h>
#include <ttos.h>
void test_begin(char *casename)
{
printk("****test_begin****%s",casename);
}
void test_end(char *casename)
{
printk("****test_end****%s",casename);
}

extern int RTOS_NET_FT_TCP_001();
int test_restart_flag;
void test()
{	
	test_begin("test\n");
	printk("******testsuite start******\n");
	
    test_begin("RTOS_NET_FT_TCP_001\n");	
	RTOS_NET_FT_TCP_001();
	test_end("RTOS_NET_FT_TCP_001\n");

	test_end("test\n");
	printk("******testsuite end******\n");
	printk("****please restart****\n");
	TEST_RESTART;
}
