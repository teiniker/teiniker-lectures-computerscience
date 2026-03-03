CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -fPIC -I. -c vector.c -o build/vector.o


lib: build/vector.o
	$(CC) -shared -Wl,-soname,libvector.so -o build/libvector.so build/vector.o

install: lib
	mkdir -p lib
	cp build/libvector.so lib/
	mkdir -p include
	cp vector.h include/


build/main.o: install main.c include/vector.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o -I./include 

build/main: build/main.o
	$(CC) $(CFLAGS) -o build/main build/main.o -L./lib -lvector

run: build/main
	export LD_LIBRARY_PATH=./lib; build/main

clean:
	rm -rf build/
