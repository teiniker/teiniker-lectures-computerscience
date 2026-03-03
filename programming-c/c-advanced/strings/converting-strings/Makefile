CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/convert-strings: convert-strings.c
	$(CC) $(CFLAGS) convert-strings.c -o build/convert-strings

run: build/convert-strings
	build/convert-strings

clean:
	rm -rf build/
