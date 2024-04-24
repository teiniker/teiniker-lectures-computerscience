CFLAGS=-std=c17 -g -Wall
CC=gcc
UNITY=../unity

all: build run_test

build:
	mkdir -p build

build/vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c -o build/vector.o

build/main.o: main.c vector.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build/vector.o build/main.o 
	$(CC) $(CFLAGS) build/main.o build/vector.o -o build/main

run: build/main	
	build/main


build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build/unity.o build/vector.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/test.o build/vector.o -o build/test
	
run_test: build/test
	build/test

clean:
	rm -rf build/
