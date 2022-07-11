.PHNOY:clean install distclean

INCLUDE_PATH=../include
CC=gcc
CFLAGS=-I$(INCLUDE_PATH) -Wall -c -g
CPPFLAGS=
LDFLAGS=-lpthread #-lssl -lcrypto
LIBRARY_PATH=../library
TARGET=PTHREAD_COPY
RM=sudo rm -rf
CP=sudo cp
SFILE=$(wildcard *.c)
DFILE=$(patsubst %.c,%.o,$(SFILE))

$(TARGET):$(DFILE) #主级命令
	$(CC) $^ $(LDFLAGS) -o $@


%.o:%.c #次级命令
	$(CC) $(CFLAGS) $<


clean:
	$(RM) $(DFILE) $(TARGET)

distclean:
	#卸载程序和删除配置文件

install:
	#拷贝安装到指定位置
