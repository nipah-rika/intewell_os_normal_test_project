################################################################################
# Automatically-generated file. Do not edit!
################################################################################
-include ./v_makefile.mk
-include $(CONFIG_PATH)/config_system.mk

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
#操作系统路径
RTOS:=RTCore
RTOS_MAKE_PATH:=$(PLATFORM)/template/$(RTOS)/make

-include $(RTOS_MAKE_PATH)/util.make

BOARDPATH := $(RTOS_PATH)/bsp/board/$(CONFIG_ARCH)
################################公共库部分#####################################

#BSP目标板项目生成的库路径
LIBS_PATH += -L$(BOARDPATH)/lib
LIBS_PATH += -L$(RTOS_PATH)/lib/$(CONFIG_CPU_ENDIAN)
################################makefile和linkcmds相关部分################################

CRT0 := $(BOARDPATH)/start/ssk/crt0.o
VSC_INIT0 := $(RTOS_PATH)/init/ssk/vscInit.o

#统一使用base.make定义的$(CFLAGS)
-include $(RTOS_PATH)/base.make
USER_OPTION += $(CFLAGS)

# All of the sources participating in the build are defined here
ifeq ($(IS_COMPILE_SOURCE),Y)
-include $(SUBDIR_PATH)/subdir.mk
else
-include $(SUBDIR:%=%/subdir.mk)
endif

-include $(PROJECT_PATH)/config_system.mk

#default link library
LIBS += -lcommon -lssk -lhacl -lrtl_boot -lsyscallEx -ltal -ltar 

ifeq ($(CONFIG_ARCH),x86)
	LIBS += -lvtd -lgcc 
endif 

ifeq ($(HAS_CPP),Y)
	LIBS += -lstdc++
endif 

#Whether add the app build target
ALL +=app
CLEAN +=app_clean
CLEAN_OBJ +=app_clean_obj

# All Target
all: CRT0_create VSC_INIT0_create $(ALL)
clean: crt0_clean VSC_INIT0_clean $(CLEAN)
clean_obj: crt0_clean VSC_INIT0_clean $(CLEAN_OBJ)

app: $(EXECUTABLES).$(TARGET_EXT) 

app_clean:
	-$(RM) $(OBJS) $(ARCHIVES) $(DEPS) $(EXECUTABLES).$(TARGET_EXT)
	-$(RM) $(CONFIG_PATH)/_linkcmds $(CONFIG_PATH)/catlinkcmds $(CONFIG_PATH)/config_*.h $(CONFIG_PATH)/config_*.mk $(CONFIG_PATH)/imgHeader.h $(CONFIG_PATH)/prelinkcmds	
	-@$(BIN_PATH)/echo ' '

app_clean_obj:
	-$(RM) $(OBJS) $(ARCHIVES) $(DEPS) $(EXECUTABLES).$(TARGET_EXT)
	-@$(BIN_PATH)/echo ' '

$(EXECUTABLES).elf : $(ARCHIVES) 
	@$(BIN_PATH)/echo 'Building target: $@'
	@$(BIN_PATH)/echo 'Invoking: GCC C Linker'
	$(LD) $(LDFLAGS) $(LIBS_PATH) $(USER_OBJS_PATH) -L$(LIB_PATH) $(PREFLAGS) $(CRT0) $(VSC_INIT0) $(USER_OBJS) --start-group $< $(LIBS) --end-group -o $@
	$(SIZE) -A -x $@ 1>presize.txt
	$(HOSTPUB_PATH)/parse
	$(RM) $@ presize.txt
	$(BIN_PATH)/catlinkcmds $(LINKCMDS_PATH) $(BIN_PATH)
	$(LD) $(LDFLAGS) $(LIBS_PATH) $(USER_OBJS_PATH) -L$(LIB_PATH) $(FLAGS) $(CRT0) $(VSC_INIT0) $(USER_OBJS) --start-group $< $(LIBS) --end-group -o $@
	$(SIZE) -A -x $@ 1>presize.txt
	@$(OBJCOPY) --add-section .imgattr=ImgInfoGen $(EXECUTABLES).elf $(EXECUTABLES)_tmp.elf
	@rm $(EXECUTABLES).elf 
	@$(OBJCOPY) $(EXECUTABLES)_tmp.elf $(EXECUTABLES).elf
	@rm $(EXECUTABLES)_tmp.elf
	$(OBJCOPY) -O binary --strip-unneeded -R .note -R .comment -R .stab -R .stabstr $(EXECUTABLES).elf $(EXECUTABLES).bin
	@$(BIN_PATH)/echo 'Finished building target: $@'
	@$(BIN_PATH)/echo ' '

$(EXECUTABLES).bin : $(EXECUTABLES).elf
	@$(BIN_PATH)/echo 'Building target: $@'
	$(OBJCOPY) -O binary --strip-unneeded -R .note -R .comment -R .stab -R .stabstr $<  $@
	@$(BIN_PATH)/echo 'Finished building target: $@'
	@$(BIN_PATH)/echo ' '
	
$(EXECUTABLES).hex : $(EXECUTABLES).elf
	@$(BIN_PATH)/echo 'Building target: $@'
	$(OBJCOPY) -O ihex --strip-unneeded -R .note -R .comment -R .stab -R .stabstr $<  $@
	@$(BIN_PATH)/echo 'Finished building target: $@'
	@$(BIN_PATH)/echo ' '

$(EXECUTABLES).exe : $(EXECUTABLES).elf
	$(BIN_PATH)/echo 'Building target: $@'
	$(OBJCOPY) -O a.out-i386 --strip-debug -R .note -R .comment -R .stab -R .stabstr -R .jcr -R .rodata.str1.4 -R .rodata.str1.1 $<  $@
	@$(BIN_PATH)/echo 'Finished building target: $@'
	@$(BIN_PATH)/echo ' '
$(EXECUTABLES).srec : $(EXECUTABLES).elf
	@$(BIN_PATH)/echo 'Building target: $@'
	$(OBJCOPY) -O srec --strip-unneeded -R .note -R .comment -R .stab -R .stabstr $<  $@
	@$(BIN_PATH)/echo 'Finished building target: $@'
	@$(BIN_PATH)/echo ' '

$(ARCHIVES): $(OBJS)
	@$(BIN_PATH)/echo 'Invoking: GCC Archiver'
	$(AR) $(AR_FLAGS) $(ARCHIVES) $(OBJS)	
	$(BIN_PATH)/echo 'Finished building: $@'
	@$(BIN_PATH)/echo ' '

osdata_clean:
	$(MAKE) -C $(CONFIG_PATH)/cfgdata/temp/ clean	
	
CRT0_create:
	$(MAKE) -C $(CONFIG_MAKEFILE_PATH) GenerateSSKLinkcmds CONFIG_PROJ=$(CONFIG_PATH) IMAGE_NAME=$(PROJECT_NAME)
	-$(RM)  $(BOARDPATH)/start/ssk/*.o
	$(MAKE) -C $(BOARDPATH)/start/ssk/
crt0_clean:
	$(MAKE) -C $(BOARDPATH)/start/ssk/ clean		

VSC_INIT0_create:
	$(MAKE) -C $(CONFIG_MAKEFILE_PATH) GenerateSSKLinkcmds CONFIG_PROJ=$(CONFIG_PATH) IMAGE_NAME=$(PROJECT_NAME)
	-$(RM)  $(RTOS_PATH)/init/ssk/*.o
	$(MAKE) -C $(RTOS_PATH)/init/ssk/
	
VSC_INIT0_clean:
	$(MAKE) -C $(RTOS_PATH)/init/ssk/ clean	
	
compile_source :$(OBJS)

clean_source:
	-$(RM) $(OBJS)	

.PHONY: all clean clean_obj dependents
.SECONDARY:
