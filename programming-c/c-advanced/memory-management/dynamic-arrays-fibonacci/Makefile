CFLAGS=-std=c17 -g -Wall  
CC=gcc

all: build build/dynamic_arrays_fibonacci run

build:
	mkdir -p build

build/dynamic_arrays_fibonacci: dynamic_arrays_fibonacci.c
	$(CC) $(CFLAGS) dynamic_arrays_fibonacci.c -o build/dynamic_arrays_fibonacci

run: build
	build/dynamic_arrays_fibonacci

clean: 
	rm -rf build/
