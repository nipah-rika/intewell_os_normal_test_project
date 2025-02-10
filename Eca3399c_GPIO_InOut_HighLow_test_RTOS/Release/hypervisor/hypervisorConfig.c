#include "hypervisorConfig.h"
#include "configTableUtils.h"

/**************************配置数据*********************************/

//实时运行环境
#define CONFIG_RTRE_START_CPU_ID (4)
#define CONFIG_RTRE_MEMORY (256*MB)
#define CONFIG_RTRE_VM_SUM_MEMORY (400*MB)
#define CONFIG_RTRE_UART_NUMBER (1)
#define CONFIG_RTRE_UART {{("COM1")}}
#define CONFIG_RTRE_NIC_NUMBER (1)
#define CONFIG_RTRE_NIC {{("GMAC0")}}

#define CONFIG_RTRE_CPU_MASK ((1<<4)|(1<<5))
//非实时运行环境
#define CONFIG_NRRE_START_CPU_ID (0)
#define CONFIG_NRRE_UART_NUMBER (0)
#define CONFIG_NRRE_UART {}
#define CONFIG_NRRE_NIC_NUMBER (0)
#define STATIC_ROUTE_NUMBER (0)
#define CONFIG_NRRE_NIC {}
#define CONFIG_NRRE_CPU_MASK ((1<<0)|(1<<1)|(1<<2)|(1<<3))

/**************************配置数据变量*********************************/

struct{
    struct hypervisor_system header;
    T_RE_UART rtreUart[CONFIG_RTRE_UART_NUMBER];
    T_RE_NIC rtreNic[CONFIG_RTRE_NIC_NUMBER];
    T_RE_UART nrreUart[CONFIG_NRRE_UART_NUMBER];
    T_RE_NIC nrreNic[CONFIG_NRRE_NIC_NUMBER];
    T_SYS_STATIC_ROUTE staticRouteTable[STATIC_ROUTE_NUMBER];
}__attribute__((packed)) hypervisorConfig __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = HYPERVISOR_SIGNATURE,
        .revision = HYPERVISOR_REVISION,
        .rtreConfig = {
            .cpuMask = CONFIG_RTRE_CPU_MASK,
            .vmmMemory = CONFIG_RTRE_MEMORY,
            .vmMemorySum = CONFIG_RTRE_VM_SUM_MEMORY,
            .imageName = "%PROJECT%/Debug/vsc/Debug/make/vsc.bin",
        },
        .nrreConfig = {
            .cpuMask = CONFIG_NRRE_CPU_MASK,
        },
        .rtreUartNumber = CONFIG_RTRE_UART_NUMBER,
        .rtreNicNumber = CONFIG_RTRE_NIC_NUMBER,
        .nrreUartNumber = CONFIG_NRRE_UART_NUMBER,
        .nrreNicNumber = CONFIG_NRRE_NIC_NUMBER,
        .staticRouteNumber = STATIC_ROUTE_NUMBER,
        .mgConfig = {
            .nfs_server = {
                .ip = "10.10.8.222",
                .root = "/nfs_root",
            },
            .debug_agent = {
                .isEnable = 0,
            },
            .sys_logger = {
                .logger_file = {
                    .isEnable = FALSE,
                },
                .mode = LOGGER_MODE_DIRECT,
                .logger_uart =  {
                    .isEnable = TRUE,
                    .uart = {
                        .port = "COM1",
                        .inputFreq = 1843200,
                        .ioMode  = UART_IO_MODE_POOL,
                        .dev_model  = UART_DEV_MODEL_PASS_THROUGH,
                    },
                },
           },
        },
    },
    .rtreUart = CONFIG_RTRE_UART,
    .rtreNic = CONFIG_RTRE_NIC,
    .nrreUart = CONFIG_NRRE_UART,
    .nrreNic = CONFIG_NRRE_NIC,
    .staticRouteTable={    },
};

