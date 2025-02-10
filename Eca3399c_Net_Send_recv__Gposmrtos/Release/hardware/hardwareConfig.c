#include "hardwareConfig.h"

/**************************配置数据*********************************/

#define CONFIG_CPU_NAME ("CortexA72")
#define CONFIG_CPU_CODE_NAME ("arm")
#define CONFIG_CPU_HYPER_THREAD (0)
#define CONFIG_CPU_THREAD_NUMBER (6)
#define CONFIG_CPU_CORES {{0},{1},{2},{3},{4},{5}}

#define CONFIG_MEMORY {(8*GB)}

#define CONFIG_UART_NUMBER (1)


#define CONFIG_NIC_GMAC0_NAME ("GMAC0")
#define CONFIG_NIC_GMAC0_VENDOR_ID (0x14)
#define CONFIG_NIC_GMAC0_DEVICE_ID (0x1912)
#define CONFIG_NIC_GMAC0_BUS (0x03)
#define CONFIG_NIC_GMAC0_SLOT (0x00)
#define CONFIG_NIC_GMAC0_FUNCTION (0x0)
#define CONFIG_NIC_GMAC0_INDEX (0)
#define CONFIG_NIC_NUMBER (1)
#define CONFIG_GPIO_GROUP_NUMBER (5)
/**************************配置数据变量*********************************/

struct{
    struct hardware_system header;
    T_CPU_CORE cpuCores[CONFIG_CPU_THREAD_NUMBER];
    T_UART_INFO uartInfo[CONFIG_UART_NUMBER];
    T_NIC_INFO nicInfo[CONFIG_NIC_NUMBER];
    T_GPIO_GROUP_CONFIG gpioGroupInfo[CONFIG_GPIO_GROUP_NUMBER];
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
        .gpioGroupNumber = CONFIG_GPIO_GROUP_NUMBER,
        .deviceName = "rk3399",
        .acpiPciMMBaseAddr = 0x40000000,
    },
    .cpuCores = CONFIG_CPU_CORES,
    .uartInfo = {
        {
            .port = "COM1",
            .type = 0,
            .irq = 4,
            .tty = "ttyS0",
        },
    },

    .nicInfo = {
        {
            .name = "GMAC0",
            .sys_name = BUILD_SYS_NAME('E','N',CONFIG_NIC_GMAC0_INDEX,CONFIG_NIC_GMAC0_FUNCTION,0),
            .vendor_id = CONFIG_NIC_GMAC0_VENDOR_ID,
            .device_id = CONFIG_NIC_GMAC0_DEVICE_ID,
            .un = {
                .pf = {
                    .bus = CONFIG_NIC_GMAC0_BUS,
                    .devfn = BUILD_DEV_FN(CONFIG_NIC_GMAC0_SLOT,CONFIG_NIC_GMAC0_FUNCTION),
                },
            },
        },
    },
    .gpioGroupInfo = {
        {
            .name = "GPIO0",
            .base_address = 0xff720000,
            .irq = 46,
        },
        {
            .name = "GPIO1",
            .base_address = 0xff730000,
            .irq = 47,
        },
        {
            .name = "GPIO2",
            .base_address = 0xff780000,
            .irq = 48,
        },
        {
            .name = "GPIO3",
            .base_address = 0xff788000,
            .irq = 49,
        },
        {
            .name = "GPIO4",
            .base_address = 0xff790000,
            .irq = 50,
        }
    },
};

