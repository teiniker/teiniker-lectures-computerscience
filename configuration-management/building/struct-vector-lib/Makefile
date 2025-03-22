CFLAGS=-std=c17 -g -Wall -I.
CC=gcc

all: build run

build:
	mkdir -p build

build/vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c -o build/vector.o


lib: build/vector.o
	ar -cvq build/libvector.a build/vector.o

install: lib
	mkdir -p lib
	cp build/libvector.a lib/
	mkdir -p include
	cp vector.h include/


build/main.o: install main.c 
	$(CC) $(CFLAGS) -c main.c -o build/main.o -I./include 

build/main: build/main.o
	$(CC) $(CFLAGS) -o build/main build/main.o -L./lib -lvector


build/main.o: main.c vector.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o

run: build/main
	build/main

clean:
	rm -rf build/
