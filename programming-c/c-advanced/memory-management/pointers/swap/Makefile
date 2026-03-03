CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init swap 

init:
	mkdir -p build

swap: init swap.c
	$(CC) $(CFLAGS) swap.c -o build/swap
	build/swap

clean:
	rm -rf build/
