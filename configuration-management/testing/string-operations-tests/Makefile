CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../unity

all: test 

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

string_operations.o: string_operations.c string_operations.h
	$(CC) $(CFLAGS) -c string_operations.c -o build/string_operations.o

main.o: main.c string_operations.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o

main: init string_operations.o main.o 
	$(CC) $(CFLAGS) build/main.o build/string_operations.o -o build/main
	build/main

test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

test: init unity.o string_operations.o test.o
	$(CC) $(CFLAGS) build/unity.o build/test.o build/string_operations.o -o build/test
	build/test

clean:
	rm -rf build/
