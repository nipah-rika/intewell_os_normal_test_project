/************************头文件******************************/
#include <commonTypes.h>
#include <compConfig.h>
#include <rtl.h>
#include <ttos.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "vbspEx.h"
#include "testSuite.h"

#include <cmd.h>
#include <ttosShell.h>

/************************宏定义******************************/
//#define TEST_SYSTICK_50US
//#define TEST_SYSTICK_100US
#define TEST_SYSTICK_1000US

#ifdef TEST_SYSTICK_50US
#define	HOUR 0									//测试时长
#define 	MIN	 1
#define 	SEC 0

#define 	TIMER_TIME_NS 		50000  						/*50us, 注意系统定时器的时间间隔需要修改为25us。*/
#define 	TIMER_TICKS 		2  						/*50us, 注意系统定时器的时间间隔需要修改为25us。*/
#elif defined(TEST_SYSTICK_100US)
#define	HOUR 12									//测试时长
#define 	MIN	 0
#define 	SEC 0

#define 	TIMER_TIME_NS 		100000  						
#define 	TIMER_TICKS 		1  						/*100us, 注意系统定时器的时间间隔需要修改为100us。*/

#elif defined(TEST_SYSTICK_1000US)
#define	HOUR 12								//测试时长
#define 	MIN	 0
#define 	SEC 0

#define 	TIMER_TIME_NS 		1000000
#define 	TIMER_TICKS 		1  						/*1000us, 注意系统定时器的时间间隔需要修改为1000us。*/
#endif

#define 	TASK_NUM				4
#define 	INTERVAL(X,Y) 			#X"us <= jitter <"#Y"us:"
/************************全局变量******************************/
T_UDWORD freqCPU;
T_UDWORD maxData_L1ms[5] = {TIMER_TIME_NS, TIMER_TIME_NS, TIMER_TIME_NS, TIMER_TIME_NS, TIMER_TIME_NS};
T_UDWORD maxData_H1ms[5] = {0};
T_UDWORD Data_L1ms[5] = {0};
T_UDWORD Data_H1ms[5] = {0};
T_UDWORD subresult = 0;
UINT64	timer_count_L1ms[5] = {0};
UINT64	timer_count_H1ms[5] = {0};
UINT64	timer_count_all = 0;
T_UWORD Shm_ctl_addr;
SHM_ID Shm_ctl_id;
/**************************** 外部声明 ****************************************/

/****************************** 实现部分**************************************/

int shell_main_show_rt_test (const struct shell *shell, size_t argc, char **argv);

SHELL_CMD_REGISTER (st, NULL, "show rt test information", "show rt test information", shell_main_show_rt_test);


T_MODULE T_VOID show_result()
{
	T_UBYTE VMname[10];
	VMK_GetVMName(VMK_NULL_VID,VMname);

    printf("\n****%s: timer_count_all:%lld, Timer Jitter Result****\n", VMname, timer_count_all);
    printf("< Timer:\r\n");
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(0,5), timer_count_L1ms[4],(timer_count_L1ms[4] != 0 ? (TIMER_TIME_NS - Data_L1ms[4]/timer_count_L1ms[4]):timer_count_L1ms[4]),(TIMER_TIME_NS - maxData_L1ms[4]));
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(5,15), timer_count_L1ms[3],(timer_count_L1ms[3] != 0 ? (TIMER_TIME_NS - Data_L1ms[3]/timer_count_L1ms[3]):timer_count_L1ms[3]),(TIMER_TIME_NS - maxData_L1ms[3]));
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(15,30), timer_count_L1ms[2],(timer_count_L1ms[2] != 0 ? (TIMER_TIME_NS - Data_L1ms[2]/timer_count_L1ms[2]):timer_count_L1ms[2]),(TIMER_TIME_NS - maxData_L1ms[2]));
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(30,50), timer_count_L1ms[1],(timer_count_L1ms[1] != 0 ? (TIMER_TIME_NS - Data_L1ms[1]/timer_count_L1ms[1]):timer_count_L1ms[1]),(TIMER_TIME_NS - maxData_L1ms[1]));
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(50,INF), timer_count_L1ms[0],(timer_count_L1ms[0] != 0 ? (TIMER_TIME_NS - Data_L1ms[0]/timer_count_L1ms[0]):timer_count_L1ms[0]),(TIMER_TIME_NS - maxData_L1ms[0]));
    printf("\r\n");
    printf("> Timer:\r\n");
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(0,5), timer_count_H1ms[0],(timer_count_H1ms[0] != 0 ? (Data_H1ms[0]/timer_count_H1ms[0] - TIMER_TIME_NS):timer_count_H1ms[0]),(maxData_H1ms[0] !=0) ?(maxData_H1ms[0] - TIMER_TIME_NS):0);
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(5,15), timer_count_H1ms[1],(timer_count_H1ms[1] != 0 ? (Data_H1ms[1]/timer_count_H1ms[1] - TIMER_TIME_NS):timer_count_H1ms[1]),(maxData_H1ms[1] !=0)?(maxData_H1ms[1]- TIMER_TIME_NS):0);
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(15,30), timer_count_H1ms[2],(timer_count_H1ms[2] != 0 ? (Data_H1ms[2]/timer_count_H1ms[2] - TIMER_TIME_NS):timer_count_H1ms[2]),(maxData_H1ms[2] !=0)?(maxData_H1ms[2]- TIMER_TIME_NS):0);
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(30,50), timer_count_H1ms[3],(timer_count_H1ms[3] != 0 ? (Data_H1ms[3]/timer_count_H1ms[3] - TIMER_TIME_NS):timer_count_H1ms[3]),(maxData_H1ms[3] !=0)?(maxData_H1ms[3]- TIMER_TIME_NS):0);
    printf("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(50,INF), timer_count_H1ms[4],(timer_count_H1ms[4] != 0 ? (Data_H1ms[4]/timer_count_H1ms[4] - TIMER_TIME_NS):timer_count_H1ms[4]),(maxData_H1ms[4] !=0)?(maxData_H1ms[4]- TIMER_TIME_NS):0);
}

int shell_main_show_rt_test (const struct shell *shell, size_t argc, char **argv)
{
	int count = 0;
	char buffer[8] = {};

    /* 清屏 */
    shell_print (shell, "\33[2J");
	for(;;)
	{
    	if (shell->runtime->window_changed)
		{
			shell->runtime->window_changed = false;
			shell_print (shell, "\33[2J");
		}
        /* 设置光标到0:0 , 隐藏光标*/
        shell_print (shell, "\33[0;0H\033[?25l");

		show_result();
		sleep(1);
		shell->basic_shell.iface->read ((shell_obj *)&shell->basic_shell, &buffer, 1, &count);
		if('q' == buffer[0])
		{
			break;
		}
	}
    shell_print (shell, "\33[?25h\n");

	return 0;
}

void timer_handle()
{
	static  T_UDWORD	oldCount=0, currentCount=0;
	currentCount = TTOS_GetCurrentSystemCount();
	subresult = TTOS_GetCurrentSystemSubTime(oldCount, currentCount, TTOS_NS_UNIT);
//	printk("33333333333333333333\n");
	if(0 != oldCount)
	{
	    /***************两次定时器差值小于100us的情况*******************/
		if(subresult <= (TIMER_TIME_NS-50000))														/*偏差值>= 50us*/
		{
			timer_count_L1ms[0]++;
			Data_L1ms[0] += subresult;
			if(subresult < maxData_L1ms[0])
			{
				maxData_L1ms[0] = subresult;
			}
		}
		else if(subresult > (TIMER_TIME_NS-50000) && subresult <= (TIMER_TIME_NS-30000))				/*30us <= 偏差值 < 50us*/
		{
			timer_count_L1ms[1]++;
			Data_L1ms[1] += subresult;
			if(subresult < maxData_L1ms[1])
			{
				maxData_L1ms[1] =  subresult;
			}
		}
		else if(subresult > (TIMER_TIME_NS-30000) && subresult <= (TIMER_TIME_NS-15000))				/*30us <= 偏差值 < 15us*/
		{
			timer_count_L1ms[2]++;
			Data_L1ms[2] += subresult;
			if(subresult < maxData_L1ms[2])
			{
				maxData_L1ms[2] =  subresult;
			}
		}
		else if(subresult > (TIMER_TIME_NS-15000) && subresult <= (TIMER_TIME_NS-5000))				/*5us <= 偏差值 < 15us*/
		{
			timer_count_L1ms[3]++;
			Data_L1ms[3] += subresult;
			if(subresult < maxData_L1ms[3])
			{
				maxData_L1ms[3] =  subresult;
			}
		}
		else if(subresult > (TIMER_TIME_NS-5000) && subresult <= TIMER_TIME_NS)			/*0us <= 偏差值 < 5us*/
		{
			timer_count_L1ms[4]++;
			Data_L1ms[4] += subresult;
			if(subresult < maxData_L1ms[4])
			{
				maxData_L1ms[4] =  subresult;
			}
		}

	       /***************两次定时器差值大于100us的情况*******************/

		else if(subresult > TIMER_TIME_NS && subresult <= (TIMER_TIME_NS+5000))			/*0us < 偏差值 <= 5us*/
		{
			timer_count_H1ms[0]++;
			Data_H1ms[0] += subresult;
			if(subresult > maxData_H1ms[0])
			{
				maxData_H1ms[0] =  subresult;
			}
		}
		else if(subresult >(TIMER_TIME_NS+5000)  && subresult <= (TIMER_TIME_NS+15000))			/*5us < 偏差值 <= 15us*/
		{
			timer_count_H1ms[1]++;
			Data_H1ms[1] += subresult;
			if(subresult > maxData_H1ms[1])
			{
				maxData_H1ms[1] =  subresult;
			}
		}
		else if(subresult > (TIMER_TIME_NS+15000) && subresult <= (TIMER_TIME_NS+30000))			/*15us < 偏差值 <= 30us*/
		{
			timer_count_H1ms[2]++;
			Data_H1ms[2] += subresult;
			if(subresult > maxData_H1ms[2])
			{
				maxData_H1ms[2] =  subresult;
			}
		}
		else if(subresult > (TIMER_TIME_NS+30000) && subresult <=(TIMER_TIME_NS+50000) )			/*30us < 偏差值 <= 50us*/
		{
			timer_count_H1ms[3]++;
			Data_H1ms[3] += subresult;
			if(subresult > maxData_H1ms[3])
			{
				maxData_H1ms[3] =  subresult;
			}
		}
		else																				/*偏差值 > 15us*/
		{
			timer_count_H1ms[4]++;
            Data_H1ms[4] += subresult;
			if(subresult > maxData_H1ms[4] )
			{
				maxData_H1ms[4] = subresult;
			}
		}

		timer_count_all++;
	}

	oldCount = currentCount;
//	printk("timer_count_all:%lld\n", timer_count_all);

}

int TOOL_CT_PER_0012()
{
	T_UBYTE VMname[10] = {0};
	T_TTOS_ReturnCode ret;
	TIMER_ID timer;
	T_UWORD timer_count = 0;

	//testCpuStatustChange(__FUNCTION__, __LINE__, VM_CPU_EXTERNAL_INT_DISABLE);

{
    T_UWORD  sysClkRate;
    T_UWORD  sysTickTimeNs;
    
    sysClkRate = TTOS_GetSysClkRate();
    sysTickTimeNs = 1000000000/sysClkRate;

    if(TIMER_TIME_NS != (sysTickTimeNs*TIMER_TICKS))
    {
        printk("func:%s, line:%d, sysTickTime:%dns * timerTicks:%d =%dns is not equal to TIMER_TIME_NS:%dns, sysTickTime should be:%dns, enter loop!\n", __FUNCTION__, __LINE__,
        		sysTickTimeNs, TIMER_TICKS, sysTickTimeNs*TIMER_TICKS, TIMER_TIME_NS, (TIMER_TIME_NS/TIMER_TICKS));
        printk("Teat Fail!\n");
		return -1;
    }
}

	VMK_GetVMName(VMK_NULL_VID,VMname);
	VMK_GetCPUFreq(&freqCPU);
	printk("freqCPU = %llu, SysClkRate=%d\n",freqCPU, TTOS_GetSysClkRate());
//	printk("freqCPU = %llu\n",freqCPU);
	timer_count = (HOUR * TTOS_GetSysClkRate() * 3600 + MIN * TTOS_GetSysClkRate() * 60 + SEC * TTOS_GetSysClkRate())/TIMER_TICKS;
	printk("timer_count:%d\n", timer_count);
	printk("TOOL_CT_PER_0012 %s is running, wait %u hour %u min %u sec......\n", VMname, HOUR, MIN, SEC);
	TTOS_SleepTask(TTOS_GetSysClkRate()*2);		//等待所有分区的打印完成

      //timer_count = 2;
      
	ret = TTOS_CreateTimerEx(TRUE, TIMER_TICKS, timer_count, NULL, timer_handle, &timer);
	if(ret !=0)
	{
		printk("CreateTimer Fail!\n");
		return -1;
	}

	/*等待定时器结束*/
    while(1)
    {
#if 0
        if(timer_count_all>= timer_count  )
        {
            break;
        }
#else
        /*多加1秒钟是为了保证定时器结束时才有打印。*/
        TTOS_SleepTask(TTOS_GetSysClkRate()*(HOUR * 3600 + MIN * 60 + SEC+ 1));
        TTOS_DeleteTimer(timer);
        break;
#endif        
    }

    printk("\n****%s: timer_count_all:%lld, Timer Jitter Result****\n", VMname, timer_count_all);
    printk("< Timer:\r\n");
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(0,5), timer_count_L1ms[4],(timer_count_L1ms[4] != 0 ? (TIMER_TIME_NS - Data_L1ms[4]/timer_count_L1ms[4]):timer_count_L1ms[4]),(TIMER_TIME_NS - maxData_L1ms[4]));
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(5,15), timer_count_L1ms[3],(timer_count_L1ms[3] != 0 ? (TIMER_TIME_NS - Data_L1ms[3]/timer_count_L1ms[3]):timer_count_L1ms[3]),(TIMER_TIME_NS - maxData_L1ms[3]));
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(15,30), timer_count_L1ms[2],(timer_count_L1ms[2] != 0 ? (TIMER_TIME_NS - Data_L1ms[2]/timer_count_L1ms[2]):timer_count_L1ms[2]),(TIMER_TIME_NS - maxData_L1ms[2]));
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(30,50), timer_count_L1ms[1],(timer_count_L1ms[1] != 0 ? (TIMER_TIME_NS - Data_L1ms[1]/timer_count_L1ms[1]):timer_count_L1ms[1]),(TIMER_TIME_NS - maxData_L1ms[1]));
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(50,INF), timer_count_L1ms[0],(timer_count_L1ms[0] != 0 ? (TIMER_TIME_NS - Data_L1ms[0]/timer_count_L1ms[0]):timer_count_L1ms[0]),(TIMER_TIME_NS - maxData_L1ms[0]));
    printk("\r\n");
    printk("> Timer:\r\n");
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(0,5), timer_count_H1ms[0],(timer_count_H1ms[0] != 0 ? (Data_H1ms[0]/timer_count_H1ms[0] - TIMER_TIME_NS):timer_count_H1ms[0]),(maxData_H1ms[0] !=0) ?(maxData_H1ms[0] - TIMER_TIME_NS):0);
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(5,15), timer_count_H1ms[1],(timer_count_H1ms[1] != 0 ? (Data_H1ms[1]/timer_count_H1ms[1] - TIMER_TIME_NS):timer_count_H1ms[1]),(maxData_H1ms[1] !=0)?(maxData_H1ms[1]- TIMER_TIME_NS):0);
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(15,30), timer_count_H1ms[2],(timer_count_H1ms[2] != 0 ? (Data_H1ms[2]/timer_count_H1ms[2] - TIMER_TIME_NS):timer_count_H1ms[2]),(maxData_H1ms[2] !=0)?(maxData_H1ms[2]- TIMER_TIME_NS):0);
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(30,50), timer_count_H1ms[3],(timer_count_H1ms[3] != 0 ? (Data_H1ms[3]/timer_count_H1ms[3] - TIMER_TIME_NS):timer_count_H1ms[3]),(maxData_H1ms[3] !=0)?(maxData_H1ms[3]- TIMER_TIME_NS):0);
    printk("%22s %8llu,\taverage:%7lluns,\tmax jitter:%7lluns\r\n", INTERVAL(50,INF), timer_count_H1ms[4],(timer_count_H1ms[4] != 0 ? (Data_H1ms[4]/timer_count_H1ms[4] - TIMER_TIME_NS):timer_count_H1ms[4]),(maxData_H1ms[4] !=0)?(maxData_H1ms[4]- TIMER_TIME_NS):0);

   // show_sg_result();
    return 0;
}
