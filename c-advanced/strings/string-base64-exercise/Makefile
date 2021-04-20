CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init base64 

init:
	mkdir -p build

base64: base64.c
	$(CC) $(CFLAGS) base64.c -o build/base64
	build/base64

clean:
	rm -rf base64 build/
