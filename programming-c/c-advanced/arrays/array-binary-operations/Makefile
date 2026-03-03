CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/array_operations: array_operations.c
	$(CC) $(CFLAGS) array_operations.c -o build/array_operations

run: build/array_operations
	build/array_operations

clean:
	rm -rf build/
