################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=E:/git/Fusion/202401015/ide/BIN/Intewell_Developer
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=E:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=E:/git/Fusion/202401015/ide/BIN/Intewell_Developer/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=E:/git/Fusion/202401015/ide/BIN/Intewell_Developer/eclipse/workspace/timer_ad7616
PROJECT_NAME:=timer_ad7616
CONFIG_NAME:=Debug
CONFIG_PATH:=E:/git/Fusion/202401015/ide/BIN/Intewell_Developer/eclipse/workspace/timer_ad7616/Debug
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
EXECUTABLES +=E:/git/Fusion/202401015/ide/BIN/Intewell_Developer/eclipse/workspace/timer_ad7616/Debug/make/timer_ad7616
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -DDEBUG_INFO=1 -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DTTOS_POSIX_API -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/eclipse/workspace/timer_ad7616 -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/eclipse/workspace/timer_ad7616/$(CONFIG_NAME) -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/json -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/bsp/include -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/net -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/sysDriver -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH) -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/smipc -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/dfs -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip/netif -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/host/pub -I../ -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/eigen -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/igh -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/igh/osal -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/common -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/rtedebug -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/ttos -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/rpc -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/nfs -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/driver -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/driver/net -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/ssk -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/partition -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/shell -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/dfs -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/sysDriver -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip/arch -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/tcpip -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/rtl -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/ta -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/ta/$(CONFIG_ARCH) -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/eclipse/workspace/timer_ad7616/src -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/cfg -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/posix -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/init/partition/ttos -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/components/soem -IE:/git/Fusion/202401015/ide/BIN/Intewell_Developer/target/RTCore/include/sntp_client 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 


#prebuild target defined here:
