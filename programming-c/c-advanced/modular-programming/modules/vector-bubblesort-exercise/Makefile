CFLAGS=-std=c17 -g -Wall  
CC=gcc

all: run  

build:
	mkdir -p build

build/bubblesort.o: bubblesort.c bubblesort.h
	$(CC) $(CFLAGS) -c bubblesort.c -o build/bubblesort.o

build/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build build/bubblesort.o build/main.o
	$(CC) $(CFLAGS) build/bubblesort.o build/main.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
