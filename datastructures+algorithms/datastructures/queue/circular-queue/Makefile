CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../../unity

all: run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/queue.o: queue.h queue.c
	$(CC) $(CFLAGS) -c queue.c -o build/queue.o

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build build/unity.o build/queue.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/queue.o build/test.o -o build/test

run_test: build/test
	build/test

clean:
	rm -rf build/
