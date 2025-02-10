#ifndef __WATCHDOG_H
#include <stdio.h>
#include <stdlib.h>

T_VMK_ReturnCode GPIO_StartWatchdog(T_UWORD maxFeeddogTime, T_BOOL timeout_stop);
T_VMK_ReturnCode GPIO_FeedWatchdog(T_VOID);
T_VMK_ReturnCode GPIO_StopWatchdog(T_VOID);
#endif //End of !__WATCHDOG_H
