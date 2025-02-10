################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=D:/Intewell_Developer_V2.1.4_release
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=D:/Intewell_Developer_V2.1.4_release/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=D:/Intewell_Developer_V2.1.4_release/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=D:/Intewell_Developer_V2.1.4_release/eclipse/workspace/Mfc1000_Delay_Func_test_APP
PROJECT_NAME:=Mfc1000_Delay_Func_test_APP
CONFIG_NAME:=Debug
CONFIG_PATH:=D:/Intewell_Developer_V2.1.4_release/eclipse/workspace/Mfc1000_Delay_Func_test_APP/Debug
CURRENT_BOARD:=mfc1000
COMPANY:=eip
BOARD_SUFFIX:=mfc1000
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
EXECUTABLES +=D:/Intewell_Developer_V2.1.4_release/eclipse/workspace/Mfc1000_Delay_Func_test_APP/Debug/make/Mfc1000_Delay_Func_test_APP
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -D_X86_ -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DDEBUG_INFO=1 -DTTOS_POSIX_API -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -ID:/Intewell_Developer_V2.1.4_release/eclipse/workspace/Mfc1000_Delay_Func_test_APP -ID:/Intewell_Developer_V2.1.4_release/eclipse/workspace/Mfc1000_Delay_Func_test_APP/$(CONFIG_NAME) -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/rtl/c++ -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/rtl/c++/x86_64-intewell-elf -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/rtl -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/bsp/include -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/bsp/include/sysDriver -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/tcpip/lwip -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/tcpip/netif -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/dfs -I../ -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/eigen -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/igh -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/igh/osal -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/json -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/smipc -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/rpc -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/nfs -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/common -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/driver -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/ta/$(CONFIG_ARCH) -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/rtedebug -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/ttos -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/ssk -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/partition -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/sysDriver -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/tcpip -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/tcpip/arch -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/ta -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/ta/$(CONFIG_ARCH) -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/ta/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/Intewell_Developer_V2.1.4_release/eclipse/workspace/Mfc1000_Delay_Func_test_APP/src -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/dfs -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/cfg -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/posix -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/shell -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/init/partition/ttos -ID:/Intewell_Developer_V2.1.4_release/host/pub -ID:/Intewell_Developer_V2.1.4_release/target/RTCore/include/components/soem 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin -ffunction-sections -fdata-sections 


#prebuild target defined here:
