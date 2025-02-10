################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=F:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=F:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=F:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=F:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/eclipse/workspace/cfg_e2000q_mrtos
PROJECT_NAME:=cfg_e2000q_mrtos
CONFIG_NAME:=Release
CONFIG_PATH:=F:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/eclipse/workspace/cfg_e2000q_mrtos/Release
CURRENT_BOARD:=e2000q_demo_board_64
CONFIG_BOARD_START := msl_debug
IS_BUILD_APP := Y

USE_DEFAULT_TOOLS_CHAIN = yes
TOOLS_VERSION := gcc-9.3.0

-include $(CONFIG_PATH)/config_system.mk

CROSS_COMPILE :=aarch64-intewell-elf-


# Every subdirectory with source files must be described here
SUBDIR := \


FLAGS := --gc-sections 
PREFLAGS := --gc-sections 
LIBS_PATH := -L$(RTOS_PATH)/lib/$(TOOLS_VERSION)/arm64/$(CONFIG_SUB_ARCH)/$(CONFIG_CPU_ENDIAN)
ARCHIVES += lib$(PROJECT_NAME).a
EXECUTABLES +=F:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/eclipse/workspace/cfg_e2000q_mrtos/Release/make/sskCfg
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DHW_NIC_INFO=0 -DINIT_VM_RUN_ON_CPU=0 -DTA_ENABLED=1 -DDEBUG_INFO=1 -DBIND_CONFIG_TABLE=0 -DRUN_WITH_BIND_VM=0 -DBIND_VM1=1 -DBIND_VM2=0 -DTA_SYSDEBUG_ENABLED=0 -DLOAD_BIND_VM_WHEN_VM_ENTER=1 -DIDLE_VM_LOW_POWER_ENABLED=1 -DINT_ENABLED=1 -DTIMER_ENABLED=1 -DMMU_ENABLED=1 -DCACHE_ENABLED=1 -DCONFIG_CORE_SMP -DUART_PL011 
COMPILE_INCLUDE := -I./ -I../ -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/eclipse/workspace/cfg_e2000q_mrtos/src -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/eclipse/workspace/cfg_e2000q_mrtos/$(CONFIG_NAME) -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/eclipse/workspace/cfg_e2000q_mrtos/$(CONFIG_NAME)/cfgdata/temp -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/ssk -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/os -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/common -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/ssk -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/hacl -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/partition -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/rtl -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/driver -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/ta -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/ta/$(CONFIG_ARCH) -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/ta/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/cfg/ -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/components -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/ttos -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/include/posix -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/init/ssk -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/bsp/include -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/host/pub -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/kbsp/include -IF:/git_IDE/chengdu_git/phytium_e2000/ide/BIN/Intewell_Developer/target/RTCore/bsp/board/$(CONFIG_ARCH)/$(COMPANY)/$(CURRENT_BOARD)/bsp 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 


#prebuild target defined here:
