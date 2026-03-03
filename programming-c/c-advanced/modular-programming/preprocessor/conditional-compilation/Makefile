CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/debugging: debugging.c
	$(CC) $(CFLAGS) debugging.c -o build/debugging

run: build/debugging
	build/debugging

clean:
	rm -rf build/
