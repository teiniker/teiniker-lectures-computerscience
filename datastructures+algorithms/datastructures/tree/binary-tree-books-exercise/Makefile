CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/binary_tree.o: binary_tree.h binary_tree.c
	$(CC) $(CFLAGS) -c binary_tree.c -o build/binary_tree.o

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build build/unity.o build/binary_tree.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/binary_tree.o build/test.o -o build/test

test_run: build/test
	build/test

clean:
	rm -rf build/
