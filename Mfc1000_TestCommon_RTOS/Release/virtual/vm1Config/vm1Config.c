#include "vmConfig.h"

/**************************配置数据*********************************/

#define CONFIG_vm1_NAME ("vm1")
#define CONFIG_vm1_BIND_CPU_ID (0)
#define CONFIG_vm1_MEMORY (128*MB)
#define CONFIG_vm1_HARDDISK (128*MB)
#define CONFIG_vm1_UART_NUMBER (2)
#define CONFIG_vm1_NIC_NUMBER (2)
#define CONFIG_vm1_CAN_NUMBER (0)
#define CONFIG_vm1_SPI_NUMBER (0)
#define CONFIG_vm1_USBCONTROLLER_NUMBER (0)
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_NAME ("RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0")
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_IP ("0.0.0.0")
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_MASK ("255.255.255.0")
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_GATEWAY ("192.168.115.1")
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_MAC {0x52,0x54,0x00,0x3d,0x2e,0xa2}
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_DNS0IP {"192.168.11.1"}
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_DNS1IP {"192.168.11.1"}
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_FUNCTION (0)
#define CONFIG_CAN_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_INDEX (0)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_INDEX (0)
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_NAME ("RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1")
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_IP ("0.0.0.0")
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_MASK ("255.255.255.0")
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_GATEWAY ("192.168.115.1")
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_MAC {0x52,0x54,0x00,0xd9,0x9b,0xa0}
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_DNS0IP {"192.168.11.1"}
#define CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_DNS1IP {"192.168.11.1"}
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_FUNCTION (0)
#define CONFIG_CAN_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_INDEX (1)
#define CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_INDEX (1)
/**************************配置数据变量*********************************/

struct{
    VM_SYSTEM header;
    T_VM_UART_INFO uartInfo[CONFIG_vm1_UART_NUMBER];
    T_VM_NIC_INFO nicInfo[CONFIG_vm1_NIC_NUMBER];
    T_VM_CAN_INFO canInfo[CONFIG_vm1_CAN_NUMBER];
    T_VM_SPI_INFO spiInfo[CONFIG_vm1_SPI_NUMBER];
    T_VM_USB_INFO usbInfo[CONFIG_vm1_USBCONTROLLER_NUMBER];
}__attribute__((packed)) vm1Config __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = VM_SIGNATURE,
        .revision = VM_REVISION,
        .name = CONFIG_vm1_NAME,
        .description = "vm",
        .cpuId = CONFIG_vm1_BIND_CPU_ID,
        .smp = 4,
        .memory = CONFIG_vm1_MEMORY,
        .harddisk = CONFIG_vm1_HARDDISK,
        .guestOsType = GUEST_OS_TYPE_RTOS,
        .imageName = "Mfc1000_Test_TTOS_Mesq_App.bin",
        .graphic = FALSE,
        .ps2Keyboard = TRUE,
        .ps2Mouse = TRUE,
        .usb = FALSE,
        .uartNumber = CONFIG_vm1_UART_NUMBER,
        .nicNumber = CONFIG_vm1_NIC_NUMBER,
        .canNumber = CONFIG_vm1_CAN_NUMBER,
        .spiNumber = CONFIG_vm1_SPI_NUMBER,
        .usbNumber = CONFIG_vm1_USBCONTROLLER_NUMBER,
    },
    .uartInfo = {
        {
            .port = ("COM1"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        },
        {
            .port = ("COM2"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        }
    },
    .usbInfo = {
    },
    .nicInfo = {
        {
            .nicName = "RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0",
            .sys_name = BUILD_SYS_NAME('E','N',CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_INDEX,CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_FUNCTION,0),
            .ip = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_IP,
            .mask = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_MASK,
            .gateway = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_GATEWAY,
            .macaddr = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_MAC,
            .dns0 = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_DNS0IP,
            .dns1 = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__0_DNS1IP,
            .netif_type = NETIF,
        },
        {
            .nicName = "RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1",
            .sys_name = BUILD_SYS_NAME('E','N',CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_INDEX,CONFIG_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_FUNCTION,0),
            .ip = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_IP,
            .mask = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_MASK,
            .gateway = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_GATEWAY,
            .macaddr = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_MAC,
            .dns0 = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_DNS0IP,
            .dns1 = CONFIG_vm1_NIC_RTL8111_8168_8411_PCI_Express_Gigabit_Ethernet_Controller__8168__1_DNS1IP,
            .netif_type = NETIF,
        }
    }
};
