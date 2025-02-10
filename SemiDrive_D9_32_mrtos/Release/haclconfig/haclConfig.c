#include "haclConfig.h"
#include "hardwareConfig.h"

#define CONFIG_RTRE_MEMORY (249*MB)
#define CONFIG_RTRE_VM_SUM_MEMORY (768*MB)
#define CONFIG_MEMORY (8*GB)
#define CONFIG_RTRE_VM_MEMORY_START ((UINT64)((CONFIG_MEMORY - CONFIG_RTRE_VM_SUM_MEMORY)/(4*KB)))*(4*KB)
#define CONFIG_CPU_CORE_MASK (B1111)
#define CONFIG_RTRE_START_CPU_ID (2)
#define CONFIG_RTRE_CPU_MASK ((1<<2)|(1<<3))
#define CONFIG_RTRE_START (0x70000000)
#define CONFIG_RE_CFG_SPACE_START (0x7f900000)
#define CONFIG_RE_CFG_SPACE_MEMORY (0x700000)
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define CONFIG_RT_TA_SPACE_START (0x70000000)
#define CONFIG_RT_TA_SPACE_SIZE (0x80000)

struct {
    struct hacl_system header;
    UINT64 cpus[1];
    struct hacl_memory mem_regions[3];
} __attribute__((packed)) config __attribute__((__section__(".vmk_info"))) = {
    .header = {
        .signature = HACL_SYSTEM_SIGNATURE,
        .revision = HACL_CONFIG_REVISION,
        .cpu_set_size = sizeof(config.cpus),
        .num_memslots = ARRAY_SIZE(config.mem_regions),
        .start_arg = CONFIG_RE_CFG_SPACE_START,
    },
    .cpus = {
            CONFIG_RTRE_CPU_MASK,
    },
    .mem_regions = {
        {
            .phys_start = CONFIG_RTRE_START,
            .size = CONFIG_RTRE_MEMORY,
        },
        {
            .phys_start = CONFIG_RE_CFG_SPACE_START,
            .size = CONFIG_RE_CFG_SPACE_MEMORY,
        },
        {
            .phys_start = CONFIG_RTRE_VM_MEMORY_START,
            .size = (UINT64)((CONFIG_RTRE_VM_SUM_MEMORY+(4*KB-1)) / (4*KB)) * (4*KB),
        },
    }
};

