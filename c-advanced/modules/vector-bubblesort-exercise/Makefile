CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: main  

init:
	mkdir -p build

bubblesort.o: bubblesort.c bubblesort.h
	$(CC) $(CFLAGS) -c bubblesort.c -o build/bubblesort.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

main: init bubblesort.o main.o
	$(CC) $(CFLAGS) build/bubblesort.o build/main.o -o build/main
	build/main

clean:
	rm -rf build/
