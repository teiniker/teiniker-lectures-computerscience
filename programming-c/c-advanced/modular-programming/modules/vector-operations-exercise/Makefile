CFLAGS=-std=c17 -g -Wall  
CC=gcc

all: run  

build:
	mkdir -p build

build/vector_operations.o: vector_operations.c vector_operations.h
	$(CC) $(CFLAGS) -c vector_operations.c -o build/vector_operations.o

build/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build build/vector_operations.o build/main.o
	$(CC) $(CFLAGS) build/vector_operations.o build/main.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
