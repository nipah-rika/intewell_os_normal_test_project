################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=D:/Intewell_V1.8.2_beta
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=D:/Intewell_V1.8.2_beta/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=D:/Intewell_V1.8.2_beta/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=D:/Intewell_V1.8.2_beta/eclipse/workspace/Eca3399c_Test_TTOS_SystemClk_App
PROJECT_NAME:=Eca3399c_Test_TTOS_SystemClk_App
CONFIG_NAME:=Debug
CONFIG_PATH:=D:/Intewell_V1.8.2_beta/eclipse/workspace/Eca3399c_Test_TTOS_SystemClk_App/Debug
CURRENT_BOARD:=AIO_3399C
COMPANY:=rock-chip
BOARD_SUFFIX:=AIO_3399C
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
EXECUTABLES +=D:/Intewell_V1.8.2_beta/eclipse/workspace/Eca3399c_Test_TTOS_SystemClk_App/Debug/make/Eca3399c_Test_TTOS_SystemClk_App
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -ID:/Intewell_V1.8.2_beta/eclipse/workspace/Eca3399c_Test_TTOS_SystemClk_App -ID:/Intewell_V1.8.2_beta/eclipse/workspace/Eca3399c_Test_TTOS_SystemClk_App/$(CONFIG_NAME) -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/json -ID:/Intewell_V1.8.2_beta/target/RTCore/bsp/include -ID:/Intewell_V1.8.2_beta/target/RTCore/bsp/include/net -ID:/Intewell_V1.8.2_beta/target/RTCore/bsp/include/sysDriver -ID:/Intewell_V1.8.2_beta/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/Intewell_V1.8.2_beta/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -ID:/Intewell_V1.8.2_beta/target/RTCore/include/smipc -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/dfs -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/tcpip/netif -ID:/Intewell_V1.8.2_beta/host/pub -I../ -ID:/Intewell_V1.8.2_beta/target/RTCore/include -ID:/Intewell_V1.8.2_beta/target/RTCore/include/igh -ID:/Intewell_V1.8.2_beta/target/RTCore/include/igh/osal -ID:/Intewell_V1.8.2_beta/target/RTCore/include/common -ID:/Intewell_V1.8.2_beta/target/RTCore/include/rtedebug -ID:/Intewell_V1.8.2_beta/target/RTCore/include/ttos -ID:/Intewell_V1.8.2_beta/target/RTCore/include/rpc -ID:/Intewell_V1.8.2_beta/target/RTCore/include/nfs -ID:/Intewell_V1.8.2_beta/target/RTCore/include/driver -ID:/Intewell_V1.8.2_beta/target/RTCore/include/driver/net -ID:/Intewell_V1.8.2_beta/target/RTCore/include/ssk -ID:/Intewell_V1.8.2_beta/target/RTCore/include/partition -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components -ID:/Intewell_V1.8.2_beta/target/RTCore/include/shell -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/dfs -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/sysDriver -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/tcpip/arch -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/tcpip -ID:/Intewell_V1.8.2_beta/target/RTCore/include/rtl -ID:/Intewell_V1.8.2_beta/target/RTCore/include/ta -ID:/Intewell_V1.8.2_beta/target/RTCore/include/ta/$(CONFIG_ARCH) -ID:/Intewell_V1.8.2_beta/eclipse/workspace/Eca3399c_Test_TTOS_SystemClk_App/src -ID:/Intewell_V1.8.2_beta/target/RTCore/include/cfg -ID:/Intewell_V1.8.2_beta/target/RTCore/include/posix -ID:/Intewell_V1.8.2_beta/target/RTCore/init/partition/ttos -ID:/Intewell_V1.8.2_beta/target/RTCore/include/components/soem 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 


#prebuild target defined here:
