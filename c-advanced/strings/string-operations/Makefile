CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init string_operations 

init:
	mkdir -p build

string_operations: string_operations.c
	$(CC) $(CFLAGS) string_operations.c -o build/string_operations
	build/string_operations

clean:
	rm -rf string_operations build/
