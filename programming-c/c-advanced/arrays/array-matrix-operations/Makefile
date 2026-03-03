CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/matrix_operations: matrix_operations.c
	$(CC) $(CFLAGS) matrix_operations.c -o build/matrix_operations

run: build/matrix_operations
	build/matrix_operations

clean:
	rm -rf build/
