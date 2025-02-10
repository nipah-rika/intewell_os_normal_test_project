#include "configTable.h"

#define CONFIG_CFG_TABLE_NUMBER (5)


struct
{
    T_CONFIG_TABLE_SYSTEM header;
    T_CONFIG_TABLE cfgTable[CONFIG_CFG_TABLE_NUMBER];
} __attribute__((packed))  systemConfig __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = CONFIG_TABLE_SIGNATURE,
        .revision = CONFIG_TABLE_REVISION,
        .configTableNum = CONFIG_CFG_TABLE_NUMBER,
    },
    .cfgTable = {
        {
            .fileName = "sskCfg.bin",
            .offset = 0x8000,
            .size = 0x10000,
        },
        {
            .fileName = "hardware.bin",
            .offset = 0x18000,
            .size = 0x8000,
        },
        {
            .fileName = "hypervisor.bin",
            .offset = 0x20000,
            .size = 0x8000,
        },
        {
            .fileName = "vm1Config.bin",
            .offset = 0x28000,
            .size = 0x8000,
        },
        {
            .fileName = "vm2Config.bin",
            .offset = 0x30000,
            .size = 0x8000,
        },
    }
};

