CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: main  

init:
	mkdir -p build

vector_operations.o: vector_operations.c vector_operations.h
	$(CC) $(CFLAGS) -c vector_operations.c -o build/vector_operations.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

main: init vector_operations.o main.o
	$(CC) $(CFLAGS) build/vector_operations.o build/main.o -o build/vector_operations
	build/vector_operations

clean:
	rm -rf build/
