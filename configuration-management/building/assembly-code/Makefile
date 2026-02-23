CFLAGS=-std=c17 -Wall
CC=gcc

all: build build/main run

build:
	mkdir -p build

build/add.o: add.s	
	$(CC) $(CFLAGS) -c add.s -o build/add.o

build/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main : build/main.o build/add.o
	$(CC) $(CFLAGS) -o build/main build/main.o build/add.o

run: build/main
	build/main

clean:
	rm -rf build/

