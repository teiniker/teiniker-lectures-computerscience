CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/vector: vector.c
	$(CC) $(CFLAGS) vector.c -o build/vector

run: build/vector
	build/vector

clean:
	rm -rf build/
