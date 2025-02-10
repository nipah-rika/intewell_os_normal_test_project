#include "hardwareConfig.h"

/**************************配置数据*********************************/

#define CONFIG_CPU_NAME ("ftc310")
#define CONFIG_CPU_CODE_NAME ("arm64")
#define CONFIG_CPU_HYPER_THREAD (0)
#define CONFIG_CPU_THREAD_NUMBER (2)
#define CONFIG_CPU_CORES {{0},{1}}

#define CONFIG_MEMORY {(2*GB)}

#define CONFIG_UART_NUMBER (9)


#define CONFIG_NIC_GEM0_NAME ("GEM0")
#define CONFIG_NIC_GEM0_VENDOR_ID (0x0014)
#define CONFIG_NIC_GEM0_DEVICE_ID (0x1912)
#define CONFIG_NIC_GEM0_BUS (0x0)
#define CONFIG_NIC_GEM0_SLOT (0x0)
#define CONFIG_NIC_GEM0_FUNCTION (0x0)
#define CONFIG_NIC_GEM0_INDEX (0)
#define CONFIG_NIC_GEM1_NAME ("GEM1")
#define CONFIG_NIC_GEM1_VENDOR_ID (0x0014)
#define CONFIG_NIC_GEM1_DEVICE_ID (0x1912)
#define CONFIG_NIC_GEM1_BUS (0x0)
#define CONFIG_NIC_GEM1_SLOT (0x0)
#define CONFIG_NIC_GEM1_FUNCTION (0x0)
#define CONFIG_NIC_GEM1_INDEX (1)
#define CONFIG_NIC_GEM2_NAME ("GEM2")
#define CONFIG_NIC_GEM2_VENDOR_ID (0x0014)
#define CONFIG_NIC_GEM2_DEVICE_ID (0x1912)
#define CONFIG_NIC_GEM2_BUS (0x0)
#define CONFIG_NIC_GEM2_SLOT (0x0)
#define CONFIG_NIC_GEM2_FUNCTION (0x0)
#define CONFIG_NIC_GEM2_INDEX (2)
#define CONFIG_NIC_NUMBER (3)
#define CONFIG_GPIO_GROUP_NUMBER (6)
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
        .deviceName = "e2000q",
        .acpiPciMMBaseAddr = 0x40000000,
    },
    .cpuCores = CONFIG_CPU_CORES,
    .uartInfo = {
        {
            .port = "COM1",
            .type = 0,
        },
        {
            .port = "COM2",
        },
        {
            .port = "COM3",
        },
        {
            .port = "COM4",
        },
        {
            .port = "COM5",
        },
        {
            .port = "COM6",
        },
        {
            .port = "COM11",
        },
        {
            .port = "COM12",
        },
        {
            .port = "COM20",
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
        {
            .name = "GEM1",
            .sys_name = BUILD_SYS_NAME('E','N',CONFIG_NIC_GEM1_INDEX,CONFIG_NIC_GEM1_FUNCTION,0),
            .vendor_id = CONFIG_NIC_GEM1_VENDOR_ID,
            .device_id = CONFIG_NIC_GEM1_DEVICE_ID,
            .un = {
                .pf = {
                    .bus = CONFIG_NIC_GEM1_BUS,
                    .devfn = BUILD_DEV_FN(CONFIG_NIC_GEM1_SLOT,CONFIG_NIC_GEM1_FUNCTION),
                },
            },
        },
        {
            .name = "GEM2",
            .sys_name = BUILD_SYS_NAME('E','N',CONFIG_NIC_GEM2_INDEX,CONFIG_NIC_GEM2_FUNCTION,0),
            .vendor_id = CONFIG_NIC_GEM2_VENDOR_ID,
            .device_id = CONFIG_NIC_GEM2_DEVICE_ID,
            .un = {
                .pf = {
                    .bus = CONFIG_NIC_GEM2_BUS,
                    .devfn = BUILD_DEV_FN(CONFIG_NIC_GEM2_SLOT,CONFIG_NIC_GEM2_FUNCTION),
                },
            },
        },
    },
    .gpioGroupInfo = {
        {
            .name = "GPIO0",
            .base_address = 0x28034000,
            .irq = 140,
        },
        {
            .name = "GPIO1",
            .base_address = 0x28035000,
            .irq = 140,
        },
        {
            .name = "GPIO2",
            .base_address = 0x28036000,
            .irq = 140,
        },
        {
            .name = "GPIO3",
            .base_address = 0x28037000,
            .irq = 188,
        },
        {
            .name = "GPIO4",
            .base_address = 0x28038000,
            .irq = 189,
        },
        {
            .name = "GPIO5",
            .base_address = 0x28039000,
            .irq = 190,
        }
    },
};

