CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build build/main run

build:
	mkdir -p build

build/string_operations.o: string_operations.c string_operations.h
	$(CC) $(CFLAGS) -c string_operations.c -o build/string_operations.o

lib: build/string_operations.o
	ar -cvq build/libstrops.a build/string_operations.o

install: lib
	mkdir -p lib
	cp build/libstrops.a lib/
	mkdir -p include
	cp string_operations.h include/

build/main.o: install main.c 
	$(CC) $(CFLAGS) -c main.c -o build/main.o -I./include 

build/main: build/main.o
	$(CC) $(CFLAGS) -o build/main build/main.o -L./lib -lstrops

run:
	build/main

clean:
	rm -rf build/
	rm -rf lib/ include/
