CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init dynamic_arrays_fibonacci

init:
	mkdir -p build

dynamic_arrays_fibonacci: dynamic_arrays_fibonacci.c
	$(CC) $(CFLAGS) dynamic_arrays_fibonacci.c -o build/dynamic_arrays_fibonacci
	build/dynamic_arrays_fibonacci

clean:
	rm -rf build/
