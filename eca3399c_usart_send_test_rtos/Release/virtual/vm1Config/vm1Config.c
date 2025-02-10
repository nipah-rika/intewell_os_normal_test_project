#include "vmConfig.h"

/**************************配置数据*********************************/

#define CONFIG_vm1_NAME ("vm1")
#define CONFIG_vm1_BIND_CPU_ID (4)
#define CONFIG_vm1_MEMORY (400*MB)
#define CONFIG_vm1_HARDDISK (128*MB)
#define CONFIG_vm1_UART_NUMBER (1)
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
        .smp = 2,
        .memory = CONFIG_vm1_MEMORY,
        .harddisk = CONFIG_vm1_HARDDISK,
        .guestOsType = GUEST_OS_TYPE_RTOS,
        .imageName = "eca3399c_for_usart_test_app.bin",
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
        {
            .port = ("COM1"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        }
    },
    .usbInfo = {
    },
    .nicInfo = {
        {
            .nicName = "GMAC0",
            .sys_name = BUILD_SYS_NAME('E','N',(0),0x0,0x0),
            .ip = ("0.0.0.0"),
            .mask = ("255.255.255.0"),
            .gateway = ("192.168.115.1"),
            .macaddr = {0x52,0x54,0x00,0x59,0xb3,0x60},
            .dns0 = {"192.168.11.1"},
            .dns1 = {"192.168.11.1"},
            .netif_type = NETIF,
        },
        {
            .nicName = ("vnetF_linux0"),
            .index = 0,
            .ip = ("0.0.0.0"),
            .mask = ("255.255.255.0"),
            .gateway = ("192.168.115.1"),
            .macaddr = {0x52,0x54,0x00,0x64,0xd6,0x6},
            .dns0 = {""},
            .dns1 = {""},
            .netif_type = VNETIF_F_LINUX,
        }
    },
    .gpioGroupInfo = {

    }
};
