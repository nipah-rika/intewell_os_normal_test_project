################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=C:/Intewell_Developer_V2.3.0_FUSION_C1_b2
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=C:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=C:/Intewell_Developer_V2.3.0_FUSION_C1_b2/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=C:/Intewell_Developer_V2.3.0_FUSION_C1_b2/eclipse/workspace/HT7038
PROJECT_NAME:=HT7038
CONFIG_NAME:=Debug
CONFIG_PATH:=C:/Intewell_Developer_V2.3.0_FUSION_C1_b2/eclipse/workspace/HT7038/Debug
CURRENT_BOARD:=D9_FUSION_64
COMPANY:=semidrive
BOARD_SUFFIX:=D9_FUSION_64
CONFIG_BOARD_START := msl_debug
IS_BUILD_APP := Y

USE_DEFAULT_TOOLS_CHAIN = yes
TOOLS_VERSION := gcc-9.3.0

-include $(CONFIG_PATH)/config_cpu.mk

CROSS_COMPILE :=aarch64-intewell-elf-


# Every subdirectory with source files must be described here
SUBDIR := \
src \


FLAGS := --gc-sections 
PREFLAGS := --gc-sections 
LIBS_PATH := -L$(RTOS_PATH)/lib/$(TOOLS_VERSION)/arm64/$(CONFIG_SUB_ARCH)/$(CONFIG_CPU_ENDIAN)
ARCHIVES += lib$(PROJECT_NAME).a
EXECUTABLES +=C:/Intewell_Developer_V2.3.0_FUSION_C1_b2/eclipse/workspace/HT7038/Debug/make/HT7038
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/eclipse/workspace/HT7038 -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/eclipse/workspace/HT7038/$(CONFIG_NAME) -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/json -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/bsp/include -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/bsp/include/net -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/bsp/include/sysDriver -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH) -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/smipc -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/dfs -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/tcpip/netif -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/host/pub -I../ -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/eigen -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/igh -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/igh/osal -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/common -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/rtedebug -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/ttos -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/rpc -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/nfs -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/driver -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/driver/net -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/ssk -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/partition -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/shell -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/dfs -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/sysDriver -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/tcpip/arch -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/tcpip -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/rtl -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/ta -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/ta/$(CONFIG_ARCH) -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/eclipse/workspace/HT7038/src -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/cfg -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/posix -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/init/partition/ttos -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/components/soem -IC:/Intewell_Developer_V2.3.0_FUSION_C1_b2/target/RTCore/include/sntp_client 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 


#prebuild target defined here:
