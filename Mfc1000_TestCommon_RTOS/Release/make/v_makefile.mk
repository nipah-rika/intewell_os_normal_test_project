################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=C:/IntewellDeveloper_V1.2.0_beta
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=C:/IntewellDeveloper_V1.2.0_beta/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=C:/IntewellDeveloper_V1.2.0_beta/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=D:/IntewellDeveloper_V1.2.0_beta/eclipse/workspace/Mfc1000_TestCommon_RTOS
PROJECT_NAME:=Mfc1000_TestCommon_RTOS
CONFIG_NAME:=Release
CONFIG_PATH:=D:/IntewellDeveloper_V1.2.0_beta/eclipse/workspace/Mfc1000_TestCommon_RTOS/Release
CURRENT_BOARD:=mfc1000
CONFIG_BOARD_START := msl_debug
IS_BUILD_APP := Y

USE_DEFAULT_TOOLS_CHAIN = yes
TOOLS_VERSION := gcc-9.3.0

-include $(CONFIG_PATH)/config_system.mk

CROSS_COMPILE :=x86_64-intewell-elf-


# Every subdirectory with source files must be described here
SUBDIR := \


FLAGS := --gc-sections 
PREFLAGS := --gc-sections 
LIBS_PATH := -L$(RTOS_PATH)/lib/$(TOOLS_VERSION)/x86/$(CONFIG_SUB_ARCH)/$(CONFIG_CPU_ENDIAN)
ARCHIVES += lib$(PROJECT_NAME).a
EXECUTABLES +=D:/IntewellDeveloper_V1.2.0_beta/eclipse/workspace/Mfc1000_TestCommon_RTOS/Release/make/sskCfg
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DCONFIG_MSL_DEBUG -D_X86_ -D_HARD_FLOAT_ -DCONFIG_CORE_SMP -DSTDOUT_DISPLAY=0 -DSTDOUT_COM1=1 -DSTDOUT_COM2=2 -DKPRINT_STDOUT_UART=STDOUT_COM1 -DDEBUG_INFO=1 -DTA_DEBUG_INT=1 -DHW_NIC_INFO=0 -DINIT_VM_RUN_ON_CPU=0 -DTA_ENABLED=1 -DBIND_CONFIG_TABLE=0 -DRUN_WITH_BIND_VM=0 -DVTD_INIT=1 
COMPILE_INCLUDE := -I./ -I../ -ID:/IntewellDeveloper_V1.2.0_beta/eclipse/workspace/Mfc1000_TestCommon_RTOS/src -ID:/IntewellDeveloper_V1.2.0_beta/eclipse/workspace/Mfc1000_TestCommon_RTOS/$(CONFIG_NAME) -ID:/IntewellDeveloper_V1.2.0_beta/eclipse/workspace/Mfc1000_TestCommon_RTOS/$(CONFIG_NAME)/cfgdata/temp -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/ssk -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/os -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/common -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/ssk -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/hacl -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/partition -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/rtl -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/driver -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/ta -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/ta/$(CONFIG_ARCH) -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/ta/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/cfg/ -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/components -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/ttos -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/include/posix -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/init/ssk -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/bsp/include -IC:/IntewellDeveloper_V1.2.0_beta/host/pub -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/kbsp/include -IC:/IntewellDeveloper_V1.2.0_beta/target/RTCore/bsp/board/$(CONFIG_ARCH)/$(COMPANY)/$(CURRENT_BOARD)/bsp 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin -march=i386 -ffunction-sections -fdata-sections 


#prebuild target defined here:
