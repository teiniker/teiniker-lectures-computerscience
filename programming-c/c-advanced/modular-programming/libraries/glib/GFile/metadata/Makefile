CFLAGS=-std=c99 -g -Wall
INCLUDE=-I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LIB=-lglib-2.0  
CC=gcc

all: build run

build:
	mkdir -p build

build/file-metadata.o: file-metadata.c
	$(CC) $(CFLAGS) $(INCLUDE) -c file-metadata.c -o build/file-metadata.o

build/file-metadata: build build/file-metadata.o
	$(CC) $(CFLAGS) build/file-metadata.o -o build/file-metadata $(LIB)

run: build/file-metadata
	build/file-metadata

clean:
	rm -rf build/
