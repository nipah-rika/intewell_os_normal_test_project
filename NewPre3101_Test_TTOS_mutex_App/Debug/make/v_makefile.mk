################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=E:/Intewell_Developer_V2.3.1_beta
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=E:/Intewell_Developer_V2.3.1_beta/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=E:/Intewell_Developer_V2.3.1_beta/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=E:/Intewell_Developer_V2.3.1_beta/eclipse/workspace/mutex
PROJECT_NAME:=mutex
CONFIG_NAME:=Debug
CONFIG_PATH:=E:/Intewell_Developer_V2.3.1_beta/eclipse/workspace/mutex/Debug
CURRENT_BOARD:=generic_board
COMPANY:=intel
BOARD_SUFFIX:=generic_board
CONFIG_BOARD_START := msl_debug
IS_BUILD_APP := Y

USE_DEFAULT_TOOLS_CHAIN = yes
TOOLS_VERSION := gcc-9.3.0

-include $(CONFIG_PATH)/config_cpu.mk

CROSS_COMPILE :=x86_64-intewell-elf-


# Every subdirectory with source files must be described here
SUBDIR := \
src \


FLAGS := --gc-sections 
PREFLAGS := --gc-sections 
LIBS_PATH := -L$(RTOS_PATH)/lib/$(TOOLS_VERSION)/x86/$(CONFIG_SUB_ARCH)/$(CONFIG_CPU_ENDIAN)
ARCHIVES += lib$(PROJECT_NAME).a
EXECUTABLES +=E:/Intewell_Developer_V2.3.1_beta/eclipse/workspace/mutex/Debug/make/mutex
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -D_X86_ -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DDEBUG_INFO=1 -DTTOS_POSIX_API -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -IE:/Intewell_Developer_V2.3.1_beta/eclipse/workspace/mutex -IE:/Intewell_Developer_V2.3.1_beta/eclipse/workspace/mutex/$(CONFIG_NAME) -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/rtl/c++ -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/rtl/c++/x86_64-intewell-elf -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/rtl -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/bsp/include -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/bsp/include/sysDriver -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/tcpip/lwip -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/tcpip/netif -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/dfs -I../ -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/eigen -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/igh -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/igh/osal -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/json -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/smipc -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/rpc -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/nfs -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/common -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/driver -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/ta/$(CONFIG_ARCH) -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/rtedebug -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/ttos -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/ssk -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/partition -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/sysDriver -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/tcpip -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/tcpip/arch -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/ta -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/ta/$(CONFIG_ARCH) -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/ta/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IE:/Intewell_Developer_V2.3.1_beta/eclipse/workspace/mutex/src -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/dfs -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/cfg -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/posix -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/shell -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/init/partition/ttos -IE:/Intewell_Developer_V2.3.1_beta/host/pub -IE:/Intewell_Developer_V2.3.1_beta/target/RTCore/include/components/soem 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin -ffunction-sections -fdata-sections 


#prebuild target defined here:
