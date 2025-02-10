################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=D:/Intewell_Developer_V1.9.0_DKS3588_C1_b9
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=D:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=D:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=D:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/eclipse/workspace/os
PROJECT_NAME:=os
CONFIG_NAME:=Debug
CONFIG_PATH:=D:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/eclipse/workspace/os/Debug
CURRENT_BOARD:=iTOP_RK3588
COMPANY:=rock-chip
BOARD_SUFFIX:=iTOP_RK3588
CONFIG_BOARD_START := msl_debug
IS_BUILD_APP := Y

USE_DEFAULT_TOOLS_CHAIN = yes
TOOLS_VERSION := gcc-9.3.0

-include $(CONFIG_PATH)/config_cpu.mk

CROSS_COMPILE :=armv8-intewell-eabihf-


# Every subdirectory with source files must be described here
SUBDIR := \
src \


FLAGS := --gc-sections 
PREFLAGS := --gc-sections 
LIBS_PATH := -L$(RTOS_PATH)/lib/$(TOOLS_VERSION)/arm/$(CONFIG_SUB_ARCH)/$(CONFIG_CPU_ENDIAN)
ARCHIVES += lib$(PROJECT_NAME).a
EXECUTABLES +=D:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/eclipse/workspace/os/Debug/make/os
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/eclipse/workspace/os -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/eclipse/workspace/os/$(CONFIG_NAME) -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/json -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/bsp/include -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/bsp/include/net -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/bsp/include/sysDriver -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/smipc -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/dfs -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/tcpip/netif -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/host/pub -I../ -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/igh -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/igh/osal -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/common -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/rtedebug -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/ttos -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/rpc -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/nfs -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/driver -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/driver/net -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/ssk -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/partition -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/shell -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/dfs -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/sysDriver -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/tcpip/arch -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/tcpip -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/rtl -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/ta -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/ta/$(CONFIG_ARCH) -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/eclipse/workspace/os/src -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/cfg -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/posix -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/init/partition/ttos -ID:/Intewell_Developer_V1.9.0_DKS3588_C1_b9/target/RTCore/include/components/soem 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 


#prebuild target defined here:
