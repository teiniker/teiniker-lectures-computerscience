CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: run

build:
	mkdir -p build

build/array.o: array.c
	$(CC) $(CFLAGS) -c array.c -o build/array.o

build/array: build build/array.o
	$(CC) $(CFLAGS) build/array.o -o build/array

run: build/array
	build/array

clean:
	rm -rf build/
