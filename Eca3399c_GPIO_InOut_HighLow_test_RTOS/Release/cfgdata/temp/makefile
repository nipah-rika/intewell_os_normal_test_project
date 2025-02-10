##########自动生成makefile##########
include  $(RTOS_PATH)/base.make
SRC_PATHS = .
SRC_FILES =   $(notdir ${wildcard $(patsubst %, %/*.c, $(SRC_PATHS))}\
            ${wildcard $(patsubst %, %/*.S, $(SRC_PATHS))} )

SRC_OBJS = $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(SRC_FILES))) *.o


EXTRA_CFLAGS = ${COMPILE_DEBUG} ${COMPILE_WARNING} ${COMPILE_OPTIMIZATION} ${COMPILE_SYMBOL} ${COMPILE_OTHER} ${COMPILE_INCLUDE}


LDFLAGS := $(LDFLAGS) -r 

all: configVMK.o configVMTable.o configTTS.o configIntDispatchTable.o configHACL.o
	${LD} ${LDFLAGS} -o osdata.o $^
 	
clean:
	rm -rf ${SRC_OBJS} osdata.o


include $(RTOS_PATH)/Rules.make

