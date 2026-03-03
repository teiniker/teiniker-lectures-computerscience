CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init pointers_and_arrays

init:
	mkdir -p build

pointers_and_arrays: init pointers_and_arrays.c
	$(CC) $(CFLAGS) pointers_and_arrays.c -o build/pointers_and_arrays
	build/pointers_and_arrays

clean:
	rm -rf build/
