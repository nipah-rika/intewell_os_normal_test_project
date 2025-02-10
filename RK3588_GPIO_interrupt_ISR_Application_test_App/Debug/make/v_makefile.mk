################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=I:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=I:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=I:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=I:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/eclipse/workspaceio/vmgpio
PROJECT_NAME:=vmgpio
CONFIG_NAME:=Debug
CONFIG_PATH:=I:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/eclipse/workspaceio/vmgpio/Debug
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
EXECUTABLES +=I:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/eclipse/workspaceio/vmgpio/Debug/make/vmgpio
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/eclipse/workspaceio/vmgpio -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/eclipse/workspaceio/vmgpio/$(CONFIG_NAME) -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/json -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/bsp/include -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/bsp/include/net -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/bsp/include/sysDriver -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/smipc -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/dfs -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/tcpip/netif -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/host/pub -I../ -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/igh -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/igh/osal -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/common -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/rtedebug -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/ttos -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/rpc -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/nfs -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/driver -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/driver/net -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/ssk -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/partition -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/shell -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/dfs -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/sysDriver -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/tcpip/arch -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/tcpip -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/rtl -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/ta -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/ta/$(CONFIG_ARCH) -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/eclipse/workspaceio/vmgpio/src -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/cfg -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/posix -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/init/partition/ttos -II:/IntewellDeveloper/Intewell_Developer_V1.9.0_DKS3588_C1_b1/target/RTCore/include/components/soem 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 


#prebuild target defined here:
