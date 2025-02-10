#include "vmConfig.h"

/**************************配置数据*********************************/

#define CONFIG_vm1_NAME ("vm1")
#define CONFIG_vm1_BIND_CPU_ID (3)
#define CONFIG_vm1_MEMORY (128*MB)
#define CONFIG_vm1_UART_NUMBER (0)
#define CONFIG_vm1_NIC_NUMBER (2)
#define CONFIG_vm1_CAN_NUMBER (0)
#define CONFIG_vm1_SPI_NUMBER (0)
#define CONFIG_vm1_USBCONTROLLER_NUMBER (0)
#define CONFIG_vm1_GOIO_GROUP_NUMBER (0)
/**************************配置数据变量*********************************/

struct{
    VM_SYSTEM header;
    T_VM_UART_INFO uartInfo[CONFIG_vm1_UART_NUMBER];
    T_VM_NIC_INFO nicInfo[CONFIG_vm1_NIC_NUMBER];
    T_VM_CAN_INFO canInfo[CONFIG_vm1_CAN_NUMBER];
    T_VM_SPI_INFO spiInfo[CONFIG_vm1_SPI_NUMBER];
    T_VM_USB_INFO usbInfo[CONFIG_vm1_USBCONTROLLER_NUMBER];
    T_VM_GPIO_GROUP_INFO gpioGroupInfo[CONFIG_vm1_GOIO_GROUP_NUMBER];
}__attribute__((packed)) vm1Config __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = VM_SIGNATURE,
        .revision = VM_REVISION,
        .name = CONFIG_vm1_NAME,
        .description = "vm",
        .cpuId = CONFIG_vm1_BIND_CPU_ID,
        .smp = 1,
        .memory = CONFIG_vm1_MEMORY,
        .guestOsType = GUEST_OS_TYPE_RTOS,
        .imageName = "test_e2000q_spi_app.bin",
        .graphic = TRUE,
        .ps2Keyboard = TRUE,
        .ps2Mouse = TRUE,
        .usb = TRUE,
        .uartNumber = CONFIG_vm1_UART_NUMBER,
        .nicNumber = CONFIG_vm1_NIC_NUMBER,
        .canNumber = CONFIG_vm1_CAN_NUMBER,
        .spiNumber = CONFIG_vm1_SPI_NUMBER,
        .usbNumber = CONFIG_vm1_USBCONTROLLER_NUMBER,
        .gpioGroupNumber = CONFIG_vm1_GOIO_GROUP_NUMBER,
    },
    .uartInfo = {
    },
    .usbInfo = {
    },
    .nicInfo = {
        {
            .nicName = "GEM0",
            .sys_name = BUILD_SYS_NAME('E','N',(0),0x0,0x0),
            .ip = ("192.168.1.71"),
            .mask = ("255.255.255.0"),
            .gateway = (""),
            .macaddr = {0x52,0x54,0x00,0x1a,0x91,0x6e},
            .dns0 = {""},
            .dns1 = {""},
            .netif_type = NETIF,
        },
        {
            .nicName = ("vnetF_linux1"),
            .index = 1,
            .ip = ("192.168.1.70"),
            .mask = ("255.255.255.0"),
            .gateway = (""),
            .macaddr = {0x52,0x54,0x00,0xab,0xc4,0x2c},
            .dns0 = {""},
            .dns1 = {""},
            .netif_type = VNETIF_F_LINUX,
        }
    },
    .gpioGroupInfo = {

    }
};
