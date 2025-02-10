################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/APP
PROJECT_NAME:=APP
CONFIG_NAME:=Debug
CONFIG_PATH:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/APP/Debug
CURRENT_BOARD:=e2000d_miniITX_board
COMPANY:=phytium
BOARD_SUFFIX:=e2000d_miniITX_board
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
EXECUTABLES +=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/APP/Debug/make/APP
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/APP -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/APP/$(CONFIG_NAME) -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/json -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/include -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/include/net -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/include/sysDriver -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH) -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/smipc -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/dfs -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/tcpip/netif -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/host/pub -I../ -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/eigen -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/igh -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/igh/osal -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/common -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/rtedebug -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ttos -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/rpc -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/nfs -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/driver -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/driver/net -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ssk -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/partition -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/shell -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/dfs -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/sysDriver -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/tcpip/arch -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/tcpip -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/rtl -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ta -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ta/$(CONFIG_ARCH) -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/APP/src -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/cfg -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/posix -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/init/partition/ttos -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components/soem 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 


#prebuild target defined here:
