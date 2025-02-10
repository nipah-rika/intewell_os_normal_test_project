#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "vmstatuscheck.h"
void TTOS_VmStatusCheck()
{
	system("echo vvmctrl > /sys/kd_rt_config_space/add");
	
	FILE *fp = NULL;
	char ret[1024] = {0};

	char chCmd[100] = "rt vm status";

	fp = popen(chCmd, "r");

	int nread = fread(ret, 1, 1024, fp);

	printf("%s\n",  ret);


}

