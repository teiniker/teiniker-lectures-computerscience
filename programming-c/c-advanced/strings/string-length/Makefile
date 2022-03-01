CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init length 

init:
	mkdir -p build

length: length.c
	$(CC) $(CFLAGS) length.c -o build/length
	build/length

clean:
	rm -rf length build/
