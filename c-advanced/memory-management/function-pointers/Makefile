CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: function-pointers 

init:
	mkdir -p build

function-pointers: init function-pointers.c
	$(CC) $(CFLAGS) function-pointers.c -o build/function-pointers
	build/function-pointers

clean:
	rm -rf build/
