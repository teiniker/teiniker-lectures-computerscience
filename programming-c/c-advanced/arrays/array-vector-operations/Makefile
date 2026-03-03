CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/array_vector_operations: array_vector_operations.c
	$(CC) $(CFLAGS) array_vector_operations.c -o build/array_vector_operations

run: build/array_vector_operations
	build/array_vector_operations

clean:
	rm -rf build/
