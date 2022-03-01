CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init literal 

init:
	mkdir -p build

literal: literal.c
	$(CC) $(CFLAGS) literal.c -o build/literal
	build/literal

clean:
	rm -rf literal build/
