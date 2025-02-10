#include <partition.h>
#include <test.h>
extern int IntewellOS_NET_FT_MULTICAST_001();
int test_restart_flag;
void test_begin(char *casename)
{
	printk("****test_begin****%s",casename);
}
void test_end(char *casename)
{
	printk("****test_end****%s",casename);
}


T_VOID test(T_VOID)
{
	test_begin("test\n");
	printk("******testsuite start******\n");

	test_begin("IntewellOS_NET_FT_MULTICAST_001\n");
	IntewellOS_NET_FT_MULTICAST_001();
	test_end("IntewellOS_NET_FT_MULTICAST_001\n");

}

