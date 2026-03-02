CFLAGS=-std=c17 -g -Wall
CC=gcc
LOG=../log.c/src

all: build run 

build:
	mkdir -p build

build/log.o: $(LOG)/log.c $(LOG)/log.h
	$(CC) $(CFLAGS) -c $(LOG)/log.c -o build/log.o

build/main.o: main.c
	$(CC) $(CFLAGS) -I $(LOG) -c main.c -o build/main.o

build/main: build/log.o build/main.o
	$(CC) $(CFLAGS) build/log.o build/main.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
