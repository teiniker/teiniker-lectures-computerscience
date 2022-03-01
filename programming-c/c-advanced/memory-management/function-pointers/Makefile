CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: function-pointers function-pointers-struct

init:
	mkdir -p build

function-pointers: init function-pointers.c
	$(CC) $(CFLAGS) function-pointers.c -o build/function-pointers
	build/function-pointers

function-pointers-struct: init function-pointers-struct.c
	$(CC) $(CFLAGS) function-pointers-struct.c -o build/function-pointers-struct
	build/function-pointers-struct

clean:
	rm -rf build/ function-pointers function-pointers-struct
