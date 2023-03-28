CFLAGS=-std=c17 -g -Wall  
CC=gcc

all: build run

build:
	mkdir -p build

build/string_operations: string_operations.c
	$(CC) $(CFLAGS) string_operations.c -o build/string_operations

run: build/string_operations
	build/string_operations

clean:
	rm -rf string_operations build/
