CC=gcc
CFLAGS=-Wall -std=c99 -w
LIBS=-lm #-ljpeg -lpng -ltiff
INCLUDES=-I./stb_image
SRC=./src/imageutil.c ./src/main.c# ./src/helpers.c 
OBJS=$(SRC:.c=.o)

TARGET=imageutil

# detect if the machine is a mac M1 chip and set the correct architecture
ifeq ($(shell uname -m),arm64)
    CFLAGS += -arch arm64
endif

all: $(TARGET)

$(TARGET): $(OBJS) ./src/main.o ./src/helpers.o
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) ./src/main.o $(TARGET)
