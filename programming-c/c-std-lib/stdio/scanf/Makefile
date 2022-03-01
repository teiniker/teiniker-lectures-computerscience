CFLAGS=-std=c11 -g -Wall
CC=gcc

all: init scanf_int

init:
	mkdir -p build

scanf_int: scanf_int.c
	$(CC) $(CFLAGS) scanf_int.c -o build/scanf_int

clean:
	rm -rf build/

