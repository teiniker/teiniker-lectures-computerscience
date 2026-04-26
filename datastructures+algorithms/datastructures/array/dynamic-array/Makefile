CFLAGS=-std=c99 -g -O0 -Wall  
CC=gcc

all: init dynamic_arrays

init:
	mkdir -p build

dynamic_arrays: dynamic_arrays.c
	$(CC) $(CFLAGS) dynamic_arrays.c -o build/dynamic_arrays
	build/dynamic_arrays

clean:
	rm -rf build/
