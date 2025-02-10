#include "vmConfig.h"

/**************************配置数据*********************************/

#define CONFIG_rootAgent_NAME ("rootAgent")
#define CONFIG_rootAgent_BIND_CPU_ID (3)
#define CONFIG_rootAgent_MEMORY (200*MB)
#define CONFIG_rootAgent_HARDDISK (128*MB)
#define CONFIG_rootAgent_UART_NUMBER (0)
#define CONFIG_rootAgent_NIC_NUMBER (1)
#define CONFIG_rootAgent_CAN_NUMBER (0)
#define CONFIG_rootAgent_SPI_NUMBER (0)
#define CONFIG_rootAgent_USBCONTROLLER_NUMBER (0)
#define CONFIG_rootAgent_GPIO_GROUP_NUMBER (0)
#define CONFIG_rootAgent_SOC_CAN_NUMBER (0)
/**************************配置数据变量*********************************/

struct{
    VM_SYSTEM header;
    T_VM_UART_INFO uartInfo[CONFIG_rootAgent_UART_NUMBER];
    T_VM_NIC_INFO nicInfo[CONFIG_rootAgent_NIC_NUMBER];
    T_VM_CAN_INFO canInfo[CONFIG_rootAgent_CAN_NUMBER];
    T_VM_SPI_INFO spiInfo[CONFIG_rootAgent_SPI_NUMBER];
    T_VM_USB_INFO usbInfo[CONFIG_rootAgent_USBCONTROLLER_NUMBER];
    T_VM_GPIO_GROUP_INFO gpioGroupInfo[CONFIG_rootAgent_GPIO_GROUP_NUMBER];
    T_VM_SOC_CAN_INFO socCanInfo[CONFIG_rootAgent_SOC_CAN_NUMBER];
}__attribute__((packed)) rootAgentConfig __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = VM_SIGNATURE,
        .revision = VM_REVISION,
        .name = CONFIG_rootAgent_NAME,
        .description = "Root agent",
        .cpuId = CONFIG_rootAgent_BIND_CPU_ID,
        .smp = 1,
        .memory = CONFIG_rootAgent_MEMORY,
        .harddisk = CONFIG_rootAgent_HARDDISK,
        .guestOsType = GUEST_OS_TYPE_RTOS,
        .imageName = "rootAgent.bin",
        .graphic = TRUE,
        .ps2Keyboard = TRUE,
        .ps2Mouse = TRUE,
        .usb = TRUE,
        .uartNumber = CONFIG_rootAgent_UART_NUMBER,
        .nicNumber = CONFIG_rootAgent_NIC_NUMBER,
        .canNumber = CONFIG_rootAgent_CAN_NUMBER,
        .spiNumber = CONFIG_rootAgent_SPI_NUMBER,
        .usbNumber = CONFIG_rootAgent_USBCONTROLLER_NUMBER,
        .gpioGroupNumber = CONFIG_rootAgent_GPIO_GROUP_NUMBER,
        .socCanNumber = CONFIG_rootAgent_SOC_CAN_NUMBER,
    },
    .uartInfo = {
    },
    .usbInfo = {
    },
    .nicInfo = {
        {
            .nicName = ("vnetF_linux0"),
            .index = 0,
            .ip = ("192.168.1.69"),
            .mask = ("255.255.255.0"),
            .gateway = ("192.168.1.1"),
            .macaddr = {0x52,0x54,0x00,0x34,0x39,0x10},
            .dns0 = {""},
            .dns1 = {""},
            .netif_type = VNETIF_F_LINUX,
        }
    },
    .gpioGroupInfo = {

    },
    .socCanInfo = {

    },
};
