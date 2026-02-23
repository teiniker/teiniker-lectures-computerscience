CFLAGS=-std=c17 -g -Wall 
CC=gcc

all: build run

build:
	mkdir -p build

build/vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -I. -c vector.c -o build/vector.o


lib: build/vector.o
	ar -cvq build/libvector.a build/vector.o

install: lib
	mkdir -p lib
	cp build/libvector.a lib/
	mkdir -p include
	cp vector.h include/


build/main.o: install main.c include/vector.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o -I./include 

build/main: build/main.o
	$(CC) $(CFLAGS) -o build/main build/main.o -L./lib -lvector

run: build/main
	build/main

clean:
	rm -rf build/
