#include "hardwareConfig.h"

/**************************配置数据*********************************/

#define CONFIG_CPU_NAME ("Intel(R) Celeron(R) CPU  J1900  @ 1.99GHz")
#define CONFIG_CPU_CODE_NAME ("")
#define CONFIG_CPU_HYPER_THREAD (0)
#define CONFIG_CPU_THREAD_NUMBER (4)
#define CONFIG_CPU_CORES {{0},{2},{4},{6}}

#define CONFIG_MEMORY {(8*GB)}

#define CONFIG_HARDISK_NUMBER (1)
#define CONFIG_HARDISK_INFO {{119*GB,""}}

#define CONFIG_UART_NUMBER (2)


#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_NAME ("RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0")
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_VENDOR_ID (0x10ec)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_DEVICE_ID (0x8168)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_BUS (0x03)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_SLOT (0x00)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_FUNCTION (0x0)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_INDEX (0)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_NAME ("RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1")
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_VENDOR_ID (0x10ec)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_DEVICE_ID (0x8168)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_BUS (0x04)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_SLOT (0x00)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_FUNCTION (0x0)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_INDEX (1)
#define CONFIG_NIC_NUMBER (2)
/**************************配置数据变量*********************************/

struct{
    struct hardware_system header;
    T_CPU_CORE cpuCores[CONFIG_CPU_THREAD_NUMBER];
    T_HARDDISK_CONFIG harddiskInfo[CONFIG_HARDISK_NUMBER];
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
        .harddiskNumber = CONFIG_HARDISK_NUMBER,
        .graphicConfig = {""},
        .usbConfig = {""},
        .deviceName = "MFC1000",
    },
    .cpuCores = CONFIG_CPU_CORES,
    .harddiskInfo = CONFIG_HARDISK_INFO,
    .uartInfo = {
        {
            .port = "COM1",
            .type = 0,
            .irq = 4,
            .tty = "ttyS0",
        },
        {
            .port = "COM2",
            .type = 0,
            .irq = 3,
            .tty = "ttyS1",
        },
    },
    .nicInfo = {
        {
            .name = "RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0",
            .sys_name = BUILD_SYS_NAME('E','N',CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_INDEX,CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_FUNCTION,0),
            .vendor_id = CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_VENDOR_ID,
            .device_id = CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_DEVICE_ID,
            .un = {
                .pf = {
                    .bus = CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_BUS,
                    .devfn = BUILD_DEV_FN(CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_SLOT,CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_FUNCTION),
                },
            },
        },
        {
            .name = "RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1",
            .sys_name = BUILD_SYS_NAME('E','N',CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_INDEX,CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_FUNCTION,0),
            .vendor_id = CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_VENDOR_ID,
            .device_id = CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_DEVICE_ID,
            .un = {
                .pf = {
                    .bus = CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_BUS,
                    .devfn = BUILD_DEV_FN(CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_SLOT,CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_FUNCTION),
                },
            },
        },
    }
};

