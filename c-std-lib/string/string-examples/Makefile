CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init string 

init:
	mkdir -p build

string: string.c
	$(CC) $(CFLAGS) string.c -o build/string
	build/string

clean:
	rm -rf string build/
