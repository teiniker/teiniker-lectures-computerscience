CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: main 

init:
	mkdir -p build

string_operations.o: string_operations.c string_operations.h
	$(CC) $(CFLAGS) -c string_operations.c -o build/string_operations.o

main.o: main.c string_operations.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o


main: init string_operations.o main.o 
	$(CC) $(CFLAGS) build/main.o build/string_operations.o -o build/main
	build/main

clean:
	rm -rf build/
