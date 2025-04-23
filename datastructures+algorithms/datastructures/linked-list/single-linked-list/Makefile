CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: run

build:
	mkdir -p build

build/linked_list.o: linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c -o build/linked_list.o

build/linked_list: build build/linked_list.o
	$(CC) $(CFLAGS) build/linked_list.o -o build/linked_list

run: build/linked_list
	build/linked_list

clean:
	rm -rf build/
