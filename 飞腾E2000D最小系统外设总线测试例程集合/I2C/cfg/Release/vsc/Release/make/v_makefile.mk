################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Basic variables defined here:
PLATFORM:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/cfg/Release/vsc
PROJECT_NAME:=vsc
CONFIG_NAME:=Release
CONFIG_PATH:=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/cfg/Release/vsc/Release
CURRENT_BOARD:=e2000d_miniITX_board
OS_FRAMEWORK:=HV
COMPANY := phytium
BOARD_SUFFIX := e2000d_miniITX_board
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
EXECUTABLES +=C:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/cfg/Release/vsc/Release/make/vsc
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DCONFIG_MSL_DEBUG -DMMU_USED_IN_SSK=1 -DCONFIG_ARMV7_LPAE -DARM_ARCH_MAJOR=7 -DHW_NIC_INFO=0 -DINIT_VM_RUN_ON_CPU=0 -DTA_ENABLED=1 -DDEBUG_INFO=1 -DBIND_CONFIG_TABLE=0 -DRUN_WITH_BIND_VM=0 -DBIND_VM1=1 -DBIND_VM2=0 -DTA_SYSDEBUG_ENABLED=0 -DCONFIG_TABLE_IS_IN_VSC=0 -DLOAD_BIND_VM_WHEN_VM_ENTER=1 -DIDLE_VM_LOW_POWER_ENABLED=1 -DINT_ENABLED=1 -DTIMER_ENABLED=1 -DMMU_ENABLED=1 -DCACHE_ENABLED=1 -DCONFIG_CORE_SMP -DARM_ARCH_MAJOR=7 -D${OS_FRAMEWORK} -DENABLE_CPLUSPLUS=0  
COMPILE_INCLUDE := -I./ -I../ -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/cfg/Release/vsc/src -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/cfg/Release/vsc/$(CONFIG_NAME) -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/eclipse/workspace/cfg/Release/vsc/$(CONFIG_NAME)/cfgdata/temp -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/ssk -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/os -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/common -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ssk -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/hacl -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/partition -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/rtl -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/driver -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ta -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ta/$(CONFIG_ARCH) -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ta/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/cfg/ -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/components -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/ttos -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/include/posix -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/init/ssk -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/include -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/host/pub -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/kbsp/include -IC:/Intewell_Developer_Hyper_I_V2.0.0_UVC_II_C1_Demo.20240305/target/RTCore/bsp/board/$(CONFIG_ARCH)/$(COMPANY)/$(CURRENT_BOARD)/bsp 
COMPILE_OPTIMIZATION := -O0  
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin -fno-unwind-tables -mno-unaligned-access -march=armv8-a+simd 


#prebuild target defined here:
