##输入参数
#CONFIG_PROJ//配置项目
#PLATFORM//开发环境路径
#PARTITION //分区名称
#OUTPUT_PATH/输出路径
#FILE_NAME//传入的单个文件名全路径
#IMAGE_NAME//映像名
#######################################################3
####调用示例:
#### make ConfigCheck CONFIG_PROJ=F:/SIDE2_bak/target/configspace/configTest PLATFORM=f:/side2_bak
#### make GenerateOSLinkcmds CONFIG_PROJ=F:/SIDE2_bak/target/configspace/configTest PLATFORM=f:/side2_bak
#### make GenerateAppLinkcmds CONFIG_PROJ=F:/SIDE2_bak/target/configspace/configTest PLATFORM=f:/side2_bak
#### make GenerateAppLink CONFIG_PROJ=F:/SIDE2/target/configspace/configTest PLATFORM=f:/side2 PartitionName=app1
#### make GenerateOSLink CONFIG_PROJ=F:/SIDE2/target/configspace/configTest PLATFORM=f:/side2
#### make GenerateConfigData PLATFORM=E:/IDE/4x/liyj/LambdaSIDE_Mac

#配置检查生成工具路径
TOOLNAME = $(PLATFORM)/host/pub/ccgTools.exe
ECHOPATH = $(PLATFORM)/host/bin
CONFIGPATH = $(PLATFORM)/host/pub/ccgtool.cfg

#各个配置在配置项目的相对目录
CONFIG_OUTPUT_PATH 	= $(CONFIG_PROJ)/output
LINK_PATH 		= $(CONFIG_PROJ)/link

#配置文件名称
SYSTEM_COMFIG_NAME = system
LINK_CONFIG_NAME 	 = default
IMAGE_CONFIG_NAME 	 = image

LINK_FILE 	= $(CONFIG_PROJ)/$(LINK_CONFIG_NAME).mtp
IMAGE_FILE 	= $(CONFIG_PROJ)/$(IMAGE_CONFIG_NAME).cfg

#解析出入的多个文件
ifeq ($(FILE_NAME),)
  ifeq ($(FILE_LIST),)
    ifeq ($(CONFIG_PROJ),)
    else
	FILE_NAME = $(CONFIG_PROJ)/system.cfg
    endif
  else
    FILE_NAME = $(subst ;,=,$(FILE_LIST))
  endif
endif

#传给检查工具的参数
INPUT_CONFIG = -input $(FILE_NAME)

#工具动作
CCG_ConfigCheck = -type ConfigCheck
CCG_GenerateLinkcmds = -type GenerateLinkcmds
CCG_GenerateConfigOSData = -type GenerateConfigOSData
CCG_ConfigPath = -cfgPath $(CONFIGPATH)

#生成linkcmds
GenerateOSLinkcmds:
	$(TOOLNAME)  $(CCG_GenerateLinkcmds) -imgType 0 -imgName $(IMAGE_NAME) -imgCfgFile $(IMAGE_FILE) -linkCfgFile $(LINK_FILE) -linkCmdsFile $(CONFIG_PROJ)/_linkcmds -imgHeaderFile $(CONFIG_PROJ)/imgHeader.h $(CCG_ConfigPath) -input $(CONFIG_PROJ)/system.cfg -cpuCfg $(CONFIG_PROJ)/cpu.cfg

GenerateSSKLinkcmds:
	$(TOOLNAME)  $(CCG_GenerateLinkcmds) -imgType 0 -imgName $(IMAGE_NAME) -imgCfgFile $(IMAGE_FILE) -linkCfgFile $(LINK_FILE) -linkCmdsFile $(CONFIG_PROJ)/_linkcmds -imgHeaderFile $(CONFIG_PROJ)/imgHeader.h $(CCG_ConfigPath) -input $(CONFIG_PROJ)/system.cfg -cpuCfg $(CONFIG_PROJ)/cpu.cfg
	
GenerateCONFIGURATIONLinkcmds:
	$(TOOLNAME)  $(CCG_GenerateLinkcmds) -imgType 0 -imgName $(IMAGE_NAME) -imgCfgFile $(IMAGE_FILE) -linkCfgFile $(LINK_FILE) -linkCmdsFile $(CONFIG_PROJ)/_linkcmds -imgHeaderFile $(CONFIG_PROJ)/imgHeader.h $(CCG_ConfigPath) -input $(CONFIG_PROJ)/system.cfg -cpuCfg $(CONFIG_PROJ)/cpu.cfg	

GenerateAppLinkcmds:
	$(TOOLNAME)  $(CCG_GenerateLinkcmds) -imgType 1 -imgName $(IMAGE_NAME) -imgCfgFile $(IMAGE_FILE) -linkCfgFile $(LINK_FILE) -linkCmdsFile $(CONFIG_PROJ)/_linkcmds -imgHeaderFile $(CONFIG_PROJ)/imgHeader.h $(CCG_ConfigPath) -input $(CONFIG_PROJ)/system.cfg -cpuCfg $(CONFIG_PROJ)/cpu.cfg

GenerateTALinkcmds:
	$(TOOLNAME)  $(CCG_GenerateLinkcmds) -imgType 3 -imgName $(IMAGE_NAME) -imgCfgFile $(IMAGE_FILE) -linkCfgFile $(LINK_FILE) -linkCmdsFile $(CONFIG_PROJ)/_linkcmds -imgHeaderFile $(CONFIG_PROJ)/imgHeader.h $(CCG_ConfigPath) -input $(CONFIG_PROJ)/system.cfg -cpuCfg $(CONFIG_PROJ)/cpu.cfg

#GenerateTTOSLinkcmds:
#	$(TOOLNAME_TTOS)  $(CCG_GenerateLinkcmds) -imgType 0 -imgName $(IMAGE_NAME) -imgCfgFile $(IMAGE_FILE) -linkCfgFile $(LINK_FILE) -linkCmdsFile $(CONFIG_PROJ)/_linkcmds -imgHeaderFile $(CONFIG_PROJ)/imgHeader.h $(CCG_ConfigPath)
	
#配置检查
ConfigCheck:
	$(TOOLNAME) $(CCG_ConfigCheck) $(INPUT_CONFIG)  $(CCG_ConfigPath)

#生成OS配置数据
GenerateConfigData:
	$(TOOLNAME) $(CCG_GenerateConfigOSData) $(INPUT_CONFIG)  -path $(OUTPUT_PATH) $(CCG_ConfigPath)
