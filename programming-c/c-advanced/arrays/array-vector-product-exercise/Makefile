CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/vector_operations: vector_operations.c
	$(CC) $(CFLAGS) vector_operations.c -o build/vector_operations

run: build/vector_operations
	build/vector_operations
	
clean:
	rm -rf build/
