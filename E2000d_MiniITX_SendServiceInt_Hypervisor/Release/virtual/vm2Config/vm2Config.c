#include "vmConfig.h"

/**************************配置数据*********************************/

#define CONFIG_vm2_NAME ("vm2")
#define CONFIG_vm2_BIND_CPU_ID (1)
#define CONFIG_vm2_MEMORY (256*MB)
#define CONFIG_vm2_UART_NUMBER (0)
#define CONFIG_vm2_NIC_NUMBER (1)
#define CONFIG_vm2_CAN_NUMBER (0)
#define CONFIG_vm2_SPI_NUMBER (0)
#define CONFIG_vm2_QSPI_NUMBER (0)
#define CONFIG_vm2_USBCONTROLLER_NUMBER (0)
#define CONFIG_vm2_GOIO_GROUP_NUMBER (0)
/**************************配置数据变量*********************************/

struct{
    VM_SYSTEM header;
    T_VM_UART_INFO uartInfo[CONFIG_vm2_UART_NUMBER];
    T_VM_NIC_INFO nicInfo[CONFIG_vm2_NIC_NUMBER];
    T_VM_CAN_INFO canInfo[CONFIG_vm2_CAN_NUMBER];
    T_VM_SPI_INFO spiInfo[CONFIG_vm2_SPI_NUMBER];
    T_VM_QSPI_INFO qspiInfo[CONFIG_vm2_QSPI_NUMBER];
    T_VM_USB_INFO usbInfo[CONFIG_vm2_USBCONTROLLER_NUMBER];
    T_VM_GPIO_GROUP_INFO gpioGroupInfo[CONFIG_vm2_GOIO_GROUP_NUMBER];
}__attribute__((packed)) vm2Config __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = VM_SIGNATURE,
        .revision = VM_REVISION,
        .name = CONFIG_vm2_NAME,
        .description = "vm",
        .cpuId = CONFIG_vm2_BIND_CPU_ID,
        .smp = 1,
        .memory = CONFIG_vm2_MEMORY,
        .guestOsType = GUEST_OS_TYPE_RTOS,
        .imageName = "APP.bin",
        .graphic = TRUE,
        .ps2Keyboard = TRUE,
        .ps2Mouse = TRUE,
        .usb = TRUE,
        .uartNumber = CONFIG_vm2_UART_NUMBER,
        .nicNumber = CONFIG_vm2_NIC_NUMBER,
        .canNumber = CONFIG_vm2_CAN_NUMBER,
        .spiNumber = CONFIG_vm2_SPI_NUMBER,
        .qspiNumber = CONFIG_vm2_QSPI_NUMBER,
        .usbNumber = CONFIG_vm2_USBCONTROLLER_NUMBER,
        .gpioGroupNumber = CONFIG_vm2_GOIO_GROUP_NUMBER,
    },
    .uartInfo = {
    },
    .usbInfo = {
    },
    .nicInfo = {
        {
            .nicName = "GEM2",
            .sys_name = BUILD_SYS_NAME('E','N',(1),0x0,0x0),
            .ip = ("192.168.16.119"),
            .mask = ("255.255.255.0"),
            .gateway = ("192.168.115.1"),
            .macaddr = {0x52,0x54,0x00,0x50,0x86,0x26},
            .dns0 = {"192.168.11.1"},
            .dns1 = {"192.168.11.1"},
            .netif_type = NETIF,
        }
    },
    .gpioGroupInfo = {

    }
};
