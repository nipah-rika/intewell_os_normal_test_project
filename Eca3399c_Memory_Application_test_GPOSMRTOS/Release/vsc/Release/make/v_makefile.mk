################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Basic variables defined here:
PLATFORM:=D:/InD
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=D:/InD/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=D:/InD/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=D:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/vsc
PROJECT_NAME:=vsc
CONFIG_NAME:=Release
CONFIG_PATH:=D:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/vsc/Release
CURRENT_BOARD:=EC_A3399C
OS_FRAMEWORK:=GPOS_MULTIRTOS
COMPANY := rock-chip
BOARD_SUFFIX := EC_A3399C
CONFIG_BOARD_START := msl_debug
IS_BUILD_APP := Y

USE_DEFAULT_TOOLS_CHAIN = yes
TOOLS_VERSION := gcc-9.3.0

-include $(CONFIG_PATH)/config_cpu.mk

CROSS_COMPILE :=armv8-intewell-eabihf-
# Every subdirectory with source files must be described here
SUBDIR := \


FLAGS :=   --gc-sections
PREFLAGS :=   --gc-sections
LIBS_PATH := -L$(RTOS_PATH)/lib/$(TOOLS_VERSION)/arm/$(CONFIG_SUB_ARCH)/$(CONFIG_CPU_ENDIAN)
ARCHIVES += lib$(PROJECT_NAME).a
EXECUTABLES +=D:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/vsc/Release/make/vsc
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DCONFIG_MSL_DEBUG -DMMU_USED_IN_SSK=1 -DCONFIG_ARMV7_LPAE -DARM_ARCH_MAJOR=7 -DHW_NIC_INFO=0 -DINIT_VM_RUN_ON_CPU=0 -DTA_ENABLED=1 -DDEBUG_INFO=1 -DBIND_CONFIG_TABLE=0 -DRUN_WITH_BIND_VM=0 -DBIND_VM1=1 -DBIND_VM2=0 -DTA_SYSDEBUG_ENABLED=0 -DCONFIG_TABLE_IS_IN_VSC=0 -DLOAD_BIND_VM_WHEN_VM_ENTER=1 -DIDLE_VM_LOW_POWER_ENABLED=1 -DINT_ENABLED=1 -DTIMER_ENABLED=1 -DMMU_ENABLED=1 -DCACHE_ENABLED=1 -DCONFIG_CORE_SMP -DARM_ARCH_MAJOR=7 -D${OS_FRAMEWORK} -DENABLE_CPLUSPLUS=0  
COMPILE_INCLUDE := -I./ -I../ -ID:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/vsc/src -ID:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/vsc/$(CONFIG_NAME) -ID:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/vsc/$(CONFIG_NAME)/cfgdata/temp -ID:/InD/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/ssk -ID:/InD/target/RTCore/include -ID:/InD/target/RTCore/include/os -ID:/InD/target/RTCore/include/common -ID:/InD/target/RTCore/include/ssk -ID:/InD/target/RTCore/include/hacl -ID:/InD/target/RTCore/include/partition -ID:/InD/target/RTCore/include/rtl -ID:/InD/target/RTCore/include/driver -ID:/InD/target/RTCore/include/ta -ID:/InD/target/RTCore/include/ta/$(CONFIG_ARCH) -ID:/InD/target/RTCore/include/ta/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/InD/target/RTCore/include/cfg/ -ID:/InD/target/RTCore/include/components -ID:/InD/target/RTCore/include/ttos -ID:/InD/target/RTCore/include/posix -ID:/InD/target/RTCore/init/ssk -ID:/InD/target/RTCore/bsp/include -ID:/InD/host/pub -ID:/InD/target/RTCore/kbsp/include -ID:/InD/target/RTCore/bsp/board/$(CONFIG_ARCH)/$(COMPANY)/$(CURRENT_BOARD)/bsp 
COMPILE_OPTIMIZATION := -O0  
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin -fno-unwind-tables -mno-unaligned-access -march=armv8-a+simd 


#prebuild target defined here:
