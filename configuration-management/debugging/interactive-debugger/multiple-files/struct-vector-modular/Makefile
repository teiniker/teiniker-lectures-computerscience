CFLAGS=-std=c17 -g -Wall -I.
CC=gcc

all: build run

build:
	mkdir -p build


build/vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c -o build/vector.o

build/main.o: main.c vector.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o


build/main: build/vector.o build/main.o 
	$(CC) $(CFLAGS) build/main.o build/vector.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
