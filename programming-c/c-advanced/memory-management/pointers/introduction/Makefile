CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: pointers 

init:
	mkdir -p build

pointers: init pointers.c
	$(CC) $(CFLAGS) pointers.c -o build/pointers
	build/pointers

clean:
	rm -rf build/
