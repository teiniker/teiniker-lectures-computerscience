CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run 

build:
	mkdir -p build

build/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build/main.o
	$(CC) $(CFLAGS) build/main.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
