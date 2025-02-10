#include "vmConfig.h"

/**************************配置数据*********************************/

#define CONFIG_vm1_NAME ("vm1")
#define CONFIG_vm1_BIND_CPU_ID (0)
#define CONFIG_vm1_MEMORY (256*MB)
#define CONFIG_vm1_UART_NUMBER (9)
#define CONFIG_vm1_NIC_NUMBER (1)
#define CONFIG_vm1_CAN_NUMBER (0)
#define CONFIG_vm1_SPI_NUMBER (0)
#define CONFIG_vm1_QSPI_NUMBER (0)
#define CONFIG_vm1_USBCONTROLLER_NUMBER (0)
#define CONFIG_vm1_GOIO_GROUP_NUMBER (0)
/**************************配置数据变量*********************************/

struct{
    VM_SYSTEM header;
    T_VM_UART_INFO uartInfo[CONFIG_vm1_UART_NUMBER];
    T_VM_NIC_INFO nicInfo[CONFIG_vm1_NIC_NUMBER];
    T_VM_CAN_INFO canInfo[CONFIG_vm1_CAN_NUMBER];
    T_VM_SPI_INFO spiInfo[CONFIG_vm1_SPI_NUMBER];
    T_VM_QSPI_INFO qspiInfo[CONFIG_vm1_QSPI_NUMBER];
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
        .imageName = "APP.bin",
        .graphic = TRUE,
        .ps2Keyboard = TRUE,
        .ps2Mouse = TRUE,
        .usb = TRUE,
        .uartNumber = CONFIG_vm1_UART_NUMBER,
        .nicNumber = CONFIG_vm1_NIC_NUMBER,
        .canNumber = CONFIG_vm1_CAN_NUMBER,
        .spiNumber = CONFIG_vm1_SPI_NUMBER,
        .qspiNumber = CONFIG_vm1_QSPI_NUMBER,
        .usbNumber = CONFIG_vm1_USBCONTROLLER_NUMBER,
        .gpioGroupNumber = CONFIG_vm1_GOIO_GROUP_NUMBER,
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
        },
        {
            .port = ("COM3"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        },
        {
            .port = ("COM4"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        },
        {
            .port = ("COM5"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        },
        {
            .port = ("COM6"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        },
        {
            .port = ("COM11"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        },
        {
            .port = ("COM12"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        },
        {
            .port = ("COM20"),
            .inputFreq = 1843200,
            .ioMode = UART_IO_MODE_INTERRUPT,
            .dev_model = UART_DEV_MODEL_PASS_THROUGH
        }
    },
    .usbInfo = {
    },
    .nicInfo = {
        {
            .nicName = "GEM1",
            .sys_name = BUILD_SYS_NAME('E','N',(1),0x0,0x0),
            .ip = ("192.168.1.70"),
            .mask = ("255.255.255.0"),
            .gateway = (""),
            .macaddr = {0x52,0x54,0x00,0xe5,0xe2,0xee},
            .dns0 = {""},
            .dns1 = {""},
            .netif_type = NETIF,
        }
    },
    .gpioGroupInfo = {

    }
};
