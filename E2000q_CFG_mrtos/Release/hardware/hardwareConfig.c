#include "hardwareConfig.h"

/**************************配置数据*********************************/

#define CONFIG_CPU_NAME ("ftc664")
#define CONFIG_CPU_CODE_NAME ("arm64")
#define CONFIG_CPU_HYPER_THREAD (0)
#define CONFIG_CPU_THREAD_NUMBER (1)
#define CONFIG_CPU_CORES {{3}}

#define CONFIG_MEMORY {(4*GB)}

#define CONFIG_UART_NUMBER (1)


#define CONFIG_NIC_GEM0_NAME ("GEM0")
#define CONFIG_NIC_GEM0_VENDOR_ID (0x0014)
#define CONFIG_NIC_GEM0_DEVICE_ID (0x1912)
#define CONFIG_NIC_GEM0_BUS (0x0)
#define CONFIG_NIC_GEM0_SLOT (0x0)
#define CONFIG_NIC_GEM0_FUNCTION (0x0)
#define CONFIG_NIC_GEM0_INDEX (0)
#define CONFIG_NIC_NUMBER (1)
#define CONFIG_GPIO_GROUP_NUMBER (0)
/**************************配置数据变量*********************************/

struct{
    struct hardware_system header;
    T_CPU_CORE cpuCores[CONFIG_CPU_THREAD_NUMBER];
    T_UART_INFO uartInfo[CONFIG_UART_NUMBER];
    T_NIC_INFO nicInfo[CONFIG_NIC_NUMBER];
}__attribute__((packed)) hardwardConfig __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = HARDWARE_SIGNATURE,
        .revision = HARDWARE_REVISION,
        .cpuConfig = {
            .name = CONFIG_CPU_NAME,
            .codeName = CONFIG_CPU_CODE_NAME,
            .hyperThread = CONFIG_CPU_HYPER_THREAD,
        },
        .memConfig = CONFIG_MEMORY,
        .cpuThreadNumber = CONFIG_CPU_THREAD_NUMBER,
        .uartNumber = CONFIG_UART_NUMBER,
        .nicNumber = CONFIG_NIC_NUMBER,
        .deviceName = "e2000q",
        .acpiPciMMBaseAddr = 0x40000000,
    },
    .cpuCores = CONFIG_CPU_CORES,
    .uartInfo = {
        {
            .port = "COM3",
            .irq = 117,
        },
    },

    .nicInfo = {
        {
            .name = "GEM0",
            .sys_name = BUILD_SYS_NAME('E','N',CONFIG_NIC_GEM0_INDEX,CONFIG_NIC_GEM0_FUNCTION,0),
            .vendor_id = CONFIG_NIC_GEM0_VENDOR_ID,
            .device_id = CONFIG_NIC_GEM0_DEVICE_ID,
            .un = {
                .pf = {
                    .bus = CONFIG_NIC_GEM0_BUS,
                    .devfn = BUILD_DEV_FN(CONFIG_NIC_GEM0_SLOT,CONFIG_NIC_GEM0_FUNCTION),
                },
            },
        },
    },
};

