################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Basic variables defined here:
PLATFORM:=F:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=F:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=F:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=F:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/eclipse/workspace2/d9_32_mrtos/Release/rootAgent
PROJECT_NAME:=rootAgent
CONFIG_NAME:=Release
CONFIG_PATH:=F:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/eclipse/workspace2/d9_32_mrtos/Release/rootAgent/Release
CURRENT_BOARD:=D9_32
OS_FRAMEWORK:=GPOS_MULTIRTOS
COMPANY := SemiDrive
BOARD_SUFFIX := D9_32
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
EXECUTABLES +=F:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/eclipse/workspace2/d9_32_mrtos/Release/rootAgent/Release/make/rootAgent
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DROOTAGENT=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0  
COMPILE_INCLUDE := -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/eclipse/workspace2/d9_32_mrtos/Release/rootAgent -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/eclipse/workspace2/d9_32_mrtos/Release/rootAgent/$(CONFIG_NAME) -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components/json -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/bsp/include -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/net -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/sysDriver -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/smipc -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components/dfs -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip/netif -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/host/pub -I../ -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/igh -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/common -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/rtedebug -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/ttos -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/rpc -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/nfs -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/driver -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/driver/net -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/ssk -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/partition -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/shell -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components/dfs -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components/sysDriver -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip/arch -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/rtl -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/ta -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/ta/$(CONFIG_ARCH) -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/eclipse/workspace2/d9_32_mrtos/Release/rootAgent/src -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/cfg -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/include/posix -IF:/git_IDE/chengdu_git/d9_ide_from_cd/ide/BIN/Intewell_Developer/target/RTCore/init/partition/ttos 
COMPILE_OPTIMIZATION := -O0  
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin  


#prebuild target defined here:
