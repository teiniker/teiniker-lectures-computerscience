CFLAGS=-std=c17 -g -Wall
CC=gcc
UNITY=../unity

all: build build/main run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/string_operations.o: string_operations.c string_operations.h
	$(CC) $(CFLAGS) -c string_operations.c -o build/string_operations.o

build/main.o: main.c string_operations.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build/string_operations.o build/main.o 
	$(CC) $(CFLAGS) build/main.o build/string_operations.o -o build/main

run: build/main	
	build/main


build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build/unity.o build/string_operations.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/test.o build/string_operations.o -o build/test
	
run_test: build/test
	build/test

clean:
	rm -rf build/
