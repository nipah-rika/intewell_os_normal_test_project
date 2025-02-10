################################################################################
# Automatically-generated file. Do not edit!
################################################################################
-include ./v_makefile.mk
-include ../config_system.mk

##
## = 和 :=的区别
##使用=可以使用后面定义的变量,但是可能会造成"递归"，导致未知错误。
##使用:=则只能使用前面的变量
##

#输出所有变量
.EXPORT_ALL_VARIABLES:

# 每个源文件的子目录都必须在此描述
SUBDIR := \
src \

################################makefile公共变量(宏)部分################################
RTOS:=RTCore
RTOS_MAKE_PATH:=$(PLATFORM)/template/$(RTOS)/make

-include $(RTOS_MAKE_PATH)/util.make

################################makefile和linkcmds相关部分################################

#设置构建目标
TARGET_EXT = elf
EXECUTABLES = hypervisor
objs = hypervisorConfig.o 

#设置默认编译参数
COMPILE_OPTIMIZATION := -O0 
COMPILE_DEBUG :=  
COMPILE_WARNING := -Wall 
COMPILE_OTHER := -c -fno-builtin 
USER_INCLUDE := -I$(PLATFORM)/target/RTCore/include/ -I$(PLATFORM)/target/RTCore/include/common -I$(PLATFORM)/target/RTCore/include/rtl
EXTRA_CFLAGS := ${COMPILE_DEBUG} ${COMPILE_WARNING} ${COMPILE_OPTIMIZATION} ${COMPILE_SYMBOL} ${COMPILE_OTHER} 

#统一使用base.make定义的$(CFLAGS)
-include $(RTOS_PATH)/base.make

$(EXECUTABLES).elf : $(OSDATA_OBJ)
	@$(BIN_PATH)/echo 'Building target: $@'
	@$(BIN_PATH)/echo 'Invoking: GCC C Linker'
	$(LD) $(LDFLAGS) ${PREFLAGS} -e hypervisorConfig $(OSDATA_OBJ) -o $@
	$(SIZE) -A -x $@ 1>presize.txt
	$(HOSTPUB_PATH)/parse
	$(RM) $@ presize.txt
	$(BIN_PATH)/catlink/catlinkcmds $(LINKCMDS_PATH) $(BIN_PATH)
	$(LD) $(LDFLAGS) $(FLAGS) -e hypervisorConfig $(OSDATA_OBJ) -o $@
	$(SIZE) -A -x $@ 1>presize.txt
	$(OBJCOPY) -O binary --strip-unneeded -R .note -R .comment -R .stab -R .stabstr $(EXECUTABLES).elf $(EXECUTABLES).bin
	@$(BIN_PATH)/echo 'Finished building target: $@'
	@$(BIN_PATH)/echo ' '
	
.PHONY: all clean dependents
.SECONDARY:

$(OSDATA_OBJ): $(objs)
	${LD} ${LDFLAGS} -o osdata.o $^
 		
$(objs).o: hypervisorConfig.c
	$(TOOLNAME)  $(CCG_GenerateLinkcmds) -imgType 0 -imgName $(IMAGE_NAME) -imgCfgFile $(IMAGE_FILE) -linkCfgFile $(LINK_FILE) -linkCmdsFile $(CONFIG_PROJ)/_linkcmds -imgHeaderFile $(CONFIG_PROJ)/imgHeader.h $(CCG_ConfigPath)	
	$(CC) -fno-builtin $(CFLAGS) $(EXTRA_CFLAGS)  $(VERSION_FLAGS) $(USER_INCLUDE) -c -o $@ $^

clean:
	$(RM) -rf ${CONFIG_PATH}/*.bin
	$(RM) -rf ${CONFIG_PATH}/*.elf 	
