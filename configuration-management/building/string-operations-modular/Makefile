CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build build/main run

build:
	mkdir -p build

build/string_operations.o: string_operations.c string_operations.h
	$(CC) $(CFLAGS) -c string_operations.c -o build/string_operations.o

build/main.o: main.c string_operations.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o


build/main: build/string_operations.o build/main.o 
	$(CC) $(CFLAGS) build/main.o build/string_operations.o -o build/main

run:
	build/main

clean:
	rm -rf build/
