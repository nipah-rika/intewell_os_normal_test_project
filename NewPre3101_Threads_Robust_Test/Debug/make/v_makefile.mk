################################################################################
# 自动生成的文件。不要编辑！
################################################################################

#Basic variables defined here:
PLATFORM:=F:/Developer_V2.3.1_beta_20240223
RTOS:=RTCore
RTOS_PATH:=$(PLATFORM)/target/$(RTOS)
BSPS_PATH:=F:/Developer_V2.3.1_beta_20240223/target/RTCore/kbsp/board
TOOLS_CHAIN_PATH:=F:/Developer_V2.3.1_beta_20240223/host/gnu
BIN_PATH:=$(PLATFORM)/host/bin
PROJECT_PATH:=F:/Developer_V2.3.1_beta_20240223/eclipse/workspace/robust_test
PROJECT_NAME:=robust_test
CONFIG_NAME:=Debug
CONFIG_PATH:=F:/Developer_V2.3.1_beta_20240223/eclipse/workspace/robust_test/Debug
CURRENT_BOARD:=generic_board
COMPANY:=intel
BOARD_SUFFIX:=generic_board
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
EXECUTABLES +=F:/Developer_V2.3.1_beta_20240223/eclipse/workspace/robust_test/Debug/make/robust_test
TARGET_EXT +=elf
LIB_PATH := $(CONFIG_PATH)/lib
IS_INCREMENTAL_BUILD_WITHBSP := N
# BSP目标文件存放的路径
BSP_OBJ_PATH :=$(CONFIG_PATH)/obj

IS_COMPILE_SOURCE := N
HAS_CPP := N

COMPILE_SYMBOL := -D_X86_ -DOS_FAULT_STACK_DEEPTH=4 -DTTOS_RUN_IN_USER -DCONFIG_DEVICE_COM1=1 -DCONFIG_DEVICE_COM2=1 -DCONFIG_CONSOLE_STDIN=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DCONFIG_CONSOLE_STDOUT=CONFIG_DEVICE_VIRTUAL_TERMINAL_NAME -DDEBUG_INFO=1 -DTTOS_POSIX_API -DENABLE_CPLUSPLUS=0 
COMPILE_INCLUDE := -IF:/Developer_V2.3.1_beta_20240223/eclipse/workspace/robust_test -IF:/Developer_V2.3.1_beta_20240223/eclipse/workspace/robust_test/$(CONFIG_NAME) -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/rtl/c++ -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/rtl/c++/x86_64-intewell-elf -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/rtl -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/bsp/include -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/bsp/include/sysDriver -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/bsp/include/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/tcpip/lwip -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/tcpip/netif -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/dfs -I../ -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/bsp/board/$(CONFIG_ARCH)/start/partition/ttos -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/eigen -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/igh -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/igh/osal -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/json -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/smipc -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/rpc -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/nfs -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/common -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/driver -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/ta/$(CONFIG_ARCH) -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/rtedebug -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/ttos -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/ssk -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/partition -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/sysDriver -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/sysDriver/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/tcpip -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/tcpip/arch -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/ta -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/ta/$(CONFIG_ARCH) -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/ta/$(CONFIG_ARCH)/$(CONFIG_SUB_ARCH) -IF:/Developer_V2.3.1_beta_20240223/eclipse/workspace/robust_test/src -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/dfs -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/cfg -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/posix -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/shell -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/init/partition/ttos -IF:/Developer_V2.3.1_beta_20240223/host/pub -IF:/Developer_V2.3.1_beta_20240223/target/RTCore/include/components/soem 
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG := -g 
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin -ffunction-sections -fdata-sections 


#prebuild target defined here:
