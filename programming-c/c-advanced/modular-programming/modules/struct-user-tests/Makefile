CFLAGS=-std=c17 -g -Wall
CC=gcc
UNITY=../unity

all: run_test 

build:
	mkdir -p build

build/main.o: main.c user.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build build/main.o 
	$(CC) $(CFLAGS) build/main.o -o build/main
	
run: build/main	
	build/main


build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o
	
build/test.o: test.c user.h
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build build/unity.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/test.o -o build/test

run_test: build/test
	build/test

clean:
	rm -rf user build/
