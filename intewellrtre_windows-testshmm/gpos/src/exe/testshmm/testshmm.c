#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "shm_api.h"

VOID __cdecl
main1(
	_In_ ULONG argc,
	_In_reads_(argc) PCHAR argv[]
)
{
	PUCHAR          GetMemAddress = NULL;
	ULONG           index, offset;
	BOOLEAN			isQuit = FALSE;
	UCHAR			setValue = 0;
	UINT			Function;
	uint32_t		dwMemSize;

	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	printf("sizeof(LONG):%zd\n", sizeof(LONG));
	printf("sizeof(uint32_t):%zd\n", sizeof(uint32_t));
	printf("sizeof(LONGLONG):%zd\n", sizeof(LONGLONG));
	printf("sizeof(uint64_t):%zd\n", sizeof(uint64_t));

	do
	{
		dwMemSize = 0x1000000;
		

		GetMemAddress = allocate_shared_memory("testshmm", dwMemSize, SHM_CACHE_DEFAULT);
		if (!GetMemAddress) {
			printf("allocate_shared_memory failed, open_shared_memory\n");
			GetMemAddress = open_shared_memory("testshmm", 3000, &dwMemSize);
			if (!GetMemAddress) {
				printf("open_shared_memory failed, exit\n");
				exit(-1);
			}
		}
		
		printf("DeviceIoControl worked OK. %p\n", GetMemAddress);

		if (GetMemAddress) {
			//
			 // Infinitely print out the list of choices, ask for input, process
			 // the request
			 //
			while (!isQuit) {

				printf("\nOSRMEMDRV TEST -- Functions:\n\n");
				printf("\t1. Test Write\n");
				printf("\t2. Test Read\n");
				printf("\n\t0. Exit\n");
				printf("\n\tSelection: ");
				scanf("%x", &Function);

				switch (Function) {
				case 1: {
					setValue++;
					memset(GetMemAddress, setValue, dwMemSize);
					printf("WRITE pattern = %x\n", setValue);
				}
						break;
				case 2: {
					printf("Input Offset:");
					scanf("%x", &offset);
					printf("Dump Buffer:");
					for (index = offset; index < offset + 256; index++) {
						if (!(index % 16)) {
							printf("\n0x%08x ", index);
						}
						printf("%02x ", GetMemAddress[index]);
					}
				}
						break;
				case 0: {
					isQuit = TRUE;
				}
						break;
				}
			}
		}

	} while (0);
}