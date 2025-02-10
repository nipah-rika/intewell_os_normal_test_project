#include <ttos.h>
#include <commonTypes.h>
// ∂¡–¥≤‚ ‘µÿ÷∑ 0x8300£¨ ≤‚ ‘≥§∂» 256B

void fpga_test (void)
{
	static  T_UDWORD	aftercnt=0, beforeCout=0, subresult=0;
    int testcnt = 10000;
	int fd = -1;
	int readbuf[256]={0};
	int writbuf[256]={0};
	int i;
    unsigned long long  rwcnt = testcnt;

	fd = open("fpga", 0);
	if (fd < 0) {
		printf("fpga dev open fail\r\n");
	}

//	G_fpgaFd = fd;

	lseek(fd, 0, SEEK_SET);
	read(fd, readbuf, 4*4);

	printf("read from fpga: ");
	for (i = 0; i < 4; i++) {
		printf("0x%08x ", readbuf[i]);
	}

	lseek(fd, 0, SEEK_SET);
	i = 0x55aaff44;
	write(fd, &i, 4);
	lseek(fd, 0, SEEK_SET);
	read(fd, readbuf, 4*4);

	printf("read from fpga: ");
	for (i = 0; i < 4; i++) {
		printf("0x%08x ", readbuf[i]);
	}


	// test 0x8300
	for (i = 0; i < sizeof(writbuf)/sizeof(int); i++) {
		writbuf[i] = i;
	}

	printf("\r\n*********FPGA PIO RAM [0x8300] Write TEST START! times:%d******\r\n", testcnt);
	beforeCout = TTOS_GetCurrentSystemCount();
	while(--testcnt) {
		lseek(fd, 0x8300, SEEK_SET);
		write(fd, writbuf, sizeof(writbuf));
	}
	aftercnt = TTOS_GetCurrentSystemCount();
	subresult = TTOS_GetCurrentSystemSubTime(beforeCout, aftercnt, TTOS_US_UNIT);
	printf("*********FPGA PIO RAM TEST END! spend:%lld us speed: %d B/s******\r\n\r\n", subresult, (sizeof(writbuf) * rwcnt*1000*1000)/subresult);


testcnt = 10000;
	printf("\r\n*********FPGA PIO RAM [0x8300] Read  TEST START! times:%d******\r\n", testcnt);
	beforeCout = TTOS_GetCurrentSystemCount();
	while(--testcnt) {
		lseek(fd, 0x8300, SEEK_SET);
		read(fd, readbuf, sizeof(readbuf));
	}
	aftercnt = TTOS_GetCurrentSystemCount();
	subresult = TTOS_GetCurrentSystemSubTime(beforeCout, aftercnt, TTOS_US_UNIT);
	printf("*********FPGA PIO RAM TEST END! spend:%lld us speed: %d B/s******\r\n\r\n", subresult, (sizeof(writbuf) * rwcnt*1000*1000)/subresult);


	for (i = 0; i < sizeof(readbuf)/sizeof(int); i++) {
		printf(" %x ", readbuf[i]);
	}

	 close(fd);
}
