################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=D:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=D:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=D:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=D:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/eclipse/workspace/d9_32_test_i2c_app
PROJECT_NAME:=d9_32_test_i2c_app
CONFIG_NAME:=Debug
CONFIG_PATH:=D:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/eclipse/workspace/d9_32_test_i2c_app/Debug
CURRENT_BOARD:=D9_32
COMPANY:=SemiDrive
BOARD_SUFFIX:=D9_32
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
EXECUTABLES +=D:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/eclipse/workspace/d9_32_test_i2c_app/Debug/make/d9_32_test_i2c_app
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/eclipse/workspace/d9_32_test_i2c_app -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/eclipse/workspace/d9_32_test_i2c_app/$(CONFIG_NAME) -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/json -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/bsp/include -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/net -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/sysDriver -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/smipc -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/dfs -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip/netif -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/host/pub -I../ -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/igh -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/igh/osal -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/common -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/rtedebug -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/ttos -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/rpc -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/nfs -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/driver -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/driver/net -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/ssk -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/partition -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/shell -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/dfs -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/sysDriver -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip/arch -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/rtl -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/ta -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/ta/$(CONFIG_ARCH) -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/eclipse/workspace/d9_32_test_i2c_app/src -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/cfg -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/posix -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/init/partition/ttos -ID:/bsp/d9_340/cd_git_d9/ide/BIN/Intewell_Developer/target/RTCore/include/components/soem 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 


#prebuild target defined here:
