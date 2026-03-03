CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/message: message.c
	$(CC) $(CFLAGS) message.c -o build/message

run: build/message
	build/message

clean:
	rm -rf build/
