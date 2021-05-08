CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init array_list 

init:
	mkdir -p build

array_list: array_list.c
	$(CC) $(CFLAGS) array_list.c -o build/array_list
	build/array_list

clean:
	rm -rf array_list build/
