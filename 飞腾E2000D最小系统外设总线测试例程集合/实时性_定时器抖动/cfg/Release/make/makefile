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

#统一使用base.make定义的$(CFLAGS)
-include $(RTOS_PATH)/base.make

#设置构建目标
ALL +=app
CLEAN +=app_clean cfg_clean
CLEAN_OBJ +=app_clean cfg_clean_obj

# All Target
all: OSDATA $(ALL)
clean: $(CLEAN)
clean_obj: $(CLEAN_OBJ)

app: $(EXECUTABLES).$(TARGET_EXT) 

app_clean:
	-$(RM) $(OBJS) $(ARCHIVES) $(DEPS) $(EXECUTABLES).$(TARGET_EXT)
	-@$(BIN_PATH)/echo ' '

cfg_names= hardware haclconfig configtable hypervisor rampayloadtable ssk

cfg_clean:
	for cfg_name_0 in $(cfg_names); \
	do \
	$(RM) $(CONFIG_PATH)/$$cfg_name_0/*linkcmds \
			$(CONFIG_PATH)/$$cfg_name_0/*.out \
			$(CONFIG_PATH)/$$cfg_name_0/*.bin \
			$(CONFIG_PATH)/$$cfg_name_0/*.elf \
			$(CONFIG_PATH)/$$cfg_name_0/*.o \
			$(CONFIG_PATH)/$$cfg_name_0/*.txt \
			$(CONFIG_PATH)/$$cfg_name_0/*.h \
			$(CONFIG_PATH)/$$cfg_name_0/*.c \
			$(CONFIG_PATH)/$$cfg_name_0/makefile \
			$(CONFIG_PATH)/$$cfg_name_0/v_makefile.mk; \
	done
	$(RM) $(CONFIG_PATH)/cfgdata;
	$(RM) $(CONFIG_PATH)/*linkcmds \
			$(CONFIG_PATH)/*.h \
			$(CONFIG_PATH)/*.mk \
			$(CONFIG_PATH)/sh \
			$(CONFIG_PATH)/load \
			$(CONFIG_PATH)/merge \
			$(CONFIG_PATH)/virtual/*Config \
			$(CONFIG_PATH)/vsc/$(CONFIG_NAME)/make \
			$(CONFIG_PATH)/rootAgent/$(CONFIG_NAME)/make;


cfg_clean_obj:
	for cfg_name_0 in $(cfg_names); \
	do \
	$(RM) $(CONFIG_PATH)/$$cfg_name_0/*linkcmds \
			$(CONFIG_PATH)/$$cfg_name_0/*.out \
			$(CONFIG_PATH)/$$cfg_name_0/*.bin \
			$(CONFIG_PATH)/$$cfg_name_0/*.elf \
			$(CONFIG_PATH)/$$cfg_name_0/*.o \
			$(CONFIG_PATH)/$$cfg_name_0/*.txt; \
	done
	$(RM) $(CONFIG_PATH)/cfgdata;
	$(RM) $(CONFIG_PATH)/*linkcmds \
			$(CONFIG_PATH)/sh \
			$(CONFIG_PATH)/load \
			$(CONFIG_PATH)/merge \
			$(CONFIG_PATH)/virtual/*Config/*.out \
			$(CONFIG_PATH)/virtual/*Config/*.bin \
			$(CONFIG_PATH)/virtual/*Config/*.elf \
			$(CONFIG_PATH)/virtual/*Config/*.o \
			$(CONFIG_PATH)/virtual/*Config/*.txt;
	
	
$(EXECUTABLES).elf : $(CONFIG_PATH)/make/makefile
	@$(BIN_PATH)/echo 'Building target: $@'
	@$(BIN_PATH)/echo 'Invoking: GCC C Linker'
	$(LD) $(LDFLAGS) ${PREFLAGS} -e vmkConfigTable $(OSDATA_OBJ) -o $@
	$(SIZE) -A -x $@ 1>presize.txt
	$(HOSTPUB_PATH)/parse
	$(RM) $@ presize.txt
	$(BIN_PATH)/catlinkcmds $(LINKCMDS_PATH) $(BIN_PATH)
	$(LD) $(LDFLAGS) $(FLAGS) -e vmkConfigTable $(OSDATA_OBJ) -o $@
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
	$(AR) -r $(ARCHIVES) $(OBJS)	
	$(BIN_PATH)/echo 'Finished building: $@'
	@$(BIN_PATH)/echo ' '

OSDATA:
	$(BIN_PATH)/echo $(RTOS_PATH)
	#生成linkcmds
	$(MAKE) -C $(CONFIG_MAKEFILE_PATH) GenerateCONFIGURATIONLinkcmds CONFIG_PROJ=$(CONFIG_PATH) IMAGE_NAME=$(PROJECT_NAME)
	#生成OS数据
	$(BIN_PATH)/mkdir -p $(CONFIG_PATH)/lib
	$(BIN_PATH)/mkdir -p $(CONFIG_PATH)/cfgdata/temp
	$(BIN_PATH)/cp $(CONFIG_MAKEFILE_PATH)/makefile  $(CONFIG_PATH)/cfgdata
	$(BIN_PATH)/cp $(CONFIG_MAKEFILE_PATH)/fileisexist  $(CONFIG_PATH)/cfgdata
	$(BIN_PATH)/cp $(CONFIG_MAKEFILE_PATH)/temp/makefile  $(CONFIG_PATH)/cfgdata/temp
	$(BIN_PATH)/rm -rf $(CONFIG_PATH)/cfgdata/temp/*.h $(CONFIG_PATH)/cfgdata/temp/*.c
	$(MAKE) -C $(CONFIG_MAKEFILE_PATH) GenerateConfigData CONFIG_PROJ=$(CONFIG_PATH) OUTPUT_PATH=$(CONFIG_PATH)/cfgdata/temp
	$(MAKE) -C $(CONFIG_PATH)/cfgdata/temp
	$(BIN_PATH)/cp $(CONFIG_PATH)/cfgdata/temp/osdata.o  $(CONFIG_PATH)
	$(BIN_PATH)/rm -rf $(CONFIG_PATH)/cfgdata/temp/*.o $(CONFIG_PATH)/cfgdata/temp/*.a

osdata_clean:
	$(MAKE) -C $(CONFIG_PATH)/cfgdata/temp/ clean	

compile_source :$(OBJS)

clean_source:
	-$(RM) $(OBJS)	

.PHONY: all clean clean_obj dependents 
.SECONDARY:
