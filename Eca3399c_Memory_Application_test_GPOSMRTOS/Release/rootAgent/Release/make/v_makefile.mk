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
PROJECT_PATH:=D:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/rootAgent
PROJECT_NAME:=rootAgent
CONFIG_NAME:=Release
CONFIG_PATH:=D:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/rootAgent/Release
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


FLAGS :=    --gc-sections
PREFLAGS :=    --gc-sections
LIBS_PATH := -L$(RTOS_PATH)/lib/$(TOOLS_VERSION)/arm/$(CONFIG_SUB_ARCH)/$(CONFIG_CPU_ENDIAN)
ARCHIVES += lib$(PROJECT_NAME).a
EXECUTABLES +=D:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/rootAgent/Release/make/rootAgent
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DROOTAGENT=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0  
COMPILE_INCLUDE := -ID:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/rootAgent -ID:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/rootAgent/$(CONFIG_NAME) -ID:/InD/target/RTCore/include/components/json -ID:/InD/target/RTCore/bsp/include -ID:/InD/target/RTCore/bsp/include/net -ID:/InD/target/RTCore/bsp/include/sysDriver -ID:/InD/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/InD/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -ID:/InD/target/RTCore/include/smipc -ID:/InD/target/RTCore/include/components/dfs -ID:/InD/target/RTCore/include/components/tcpip/netif -ID:/InD/host/pub -I../ -ID:/InD/target/RTCore/include -ID:/InD/target/RTCore/include/igh -ID:/InD/target/RTCore/include/common -ID:/InD/target/RTCore/include/rtedebug -ID:/InD/target/RTCore/include/ttos -ID:/InD/target/RTCore/include/rpc -ID:/InD/target/RTCore/include/nfs -ID:/InD/target/RTCore/include/driver -ID:/InD/target/RTCore/include/driver/net -ID:/InD/target/RTCore/include/ssk -ID:/InD/target/RTCore/include/partition -ID:/InD/target/RTCore/include/components -ID:/InD/target/RTCore/include/shell -ID:/InD/target/RTCore/include/components/dfs -ID:/InD/target/RTCore/include/components/sysDriver -ID:/InD/target/RTCore/include/components/tcpip/arch -ID:/InD/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/InD/target/RTCore/include/components/tcpip -ID:/InD/target/RTCore/include/rtl -ID:/InD/target/RTCore/include/ta -ID:/InD/target/RTCore/include/ta/$(CONFIG_ARCH) -ID:/InD/eclipse/workspace/Eca3399c_Memory_Application_test_GPOSMRTOS/Release/rootAgent/src -ID:/InD/target/RTCore/include/cfg -ID:/InD/target/RTCore/include/posix -ID:/InD/target/RTCore/init/partition/ttos 
COMPILE_OPTIMIZATION := -O0  
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin  


#prebuild target defined here:
