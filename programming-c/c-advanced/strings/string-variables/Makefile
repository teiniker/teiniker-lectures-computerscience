CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init variables

init:
	mkdir -p build

variables: variables.c
	$(CC) $(CFLAGS) variables.c -o build/variables
	build/variables

clean:
	rm -rf variables build/
