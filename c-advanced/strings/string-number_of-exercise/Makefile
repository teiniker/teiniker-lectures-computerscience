CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init number_of 

init:
	mkdir -p build

number_of: number_of.c
	$(CC) $(CFLAGS) number_of.c -o build/number_of
	build/number_of

clean:
	rm -rf number_of build/
