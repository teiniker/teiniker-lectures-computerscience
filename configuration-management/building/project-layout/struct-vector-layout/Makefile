CC=gcc
CFLAGS=-std=c17 -g -Wall -Iinclude

all: build run

build:
	mkdir -p build

build/vector.o: src/vector.c include/vector.h | build
	$(CC) $(CFLAGS) -c src/vector.c -o build/vector.o

build/main.o: src/main.c include/vector.h | build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/main: build/vector.o build/main.o
	$(CC) $(CFLAGS) build/vector.o build/main.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
