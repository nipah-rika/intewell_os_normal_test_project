#include "vmConfig.h"

/**************************配置数据*********************************/

#define CONFIG_vm2_NAME ("vm2")
#define CONFIG_vm2_BIND_CPU_ID (0)
#define CONFIG_vm2_MEMORY (200*MB)
#define CONFIG_vm2_HARDDISK (128*MB)
#define CONFIG_vm2_UART_NUMBER (0)
#define CONFIG_vm2_NIC_NUMBER (1)
#define CONFIG_vm2_CAN_NUMBER (0)
#define CONFIG_vm2_SPI_NUMBER (0)
#define CONFIG_vm2_USBCONTROLLER_NUMBER (0)
#define CONFIG_vm2_GOIO_GROUP_NUMBER (0)
/**************************配置数据变量*********************************/

struct{
    VM_SYSTEM header;
    T_VM_UART_INFO uartInfo[CONFIG_vm2_UART_NUMBER];
    T_VM_NIC_INFO nicInfo[CONFIG_vm2_NIC_NUMBER];
    T_VM_CAN_INFO canInfo[CONFIG_vm2_CAN_NUMBER];
    T_VM_SPI_INFO spiInfo[CONFIG_vm2_SPI_NUMBER];
    T_VM_USB_INFO usbInfo[CONFIG_vm2_USBCONTROLLER_NUMBER];
    T_VM_GPIO_GROUP_INFO gpioGroupInfo[CONFIG_vm2_GOIO_GROUP_NUMBER];
}__attribute__((packed)) vm2Config __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = VM_SIGNATURE,
        .revision = VM_REVISION,
        .name = CONFIG_vm2_NAME,
        .description = "",
        .cpuId = CONFIG_vm2_BIND_CPU_ID,
        .smp = 2,
        .memory = CONFIG_vm2_MEMORY,
        .harddisk = CONFIG_vm2_HARDDISK,
        .guestOsType = GUEST_OS_TYPE_RTOS,
        .imageName = "os.bin",
        .graphic = TRUE,
        .ps2Keyboard = TRUE,
        .ps2Mouse = TRUE,
        .usb = TRUE,
        .uartNumber = CONFIG_vm2_UART_NUMBER,
        .nicNumber = CONFIG_vm2_NIC_NUMBER,
        .canNumber = CONFIG_vm2_CAN_NUMBER,
        .spiNumber = CONFIG_vm2_SPI_NUMBER,
        .usbNumber = CONFIG_vm2_USBCONTROLLER_NUMBER,
        .gpioGroupNumber = CONFIG_vm2_GOIO_GROUP_NUMBER,
    },
    .uartInfo = {
    },
    .usbInfo = {
    },
    .nicInfo = {
        {
            .nicName = ("vnetF_linux1"),
            .index = 1,
            .ip = ("192.168.1.71"),
            .mask = ("255.255.255.0"),
            .gateway = (""),
            .macaddr = {0x52,0x54,0x00,0x57,0xe6,0xe8},
            .dns0 = {""},
            .dns1 = {""},
            .netif_type = VNETIF_F_LINUX,
        }
    },
    .gpioGroupInfo = {

    }
};
