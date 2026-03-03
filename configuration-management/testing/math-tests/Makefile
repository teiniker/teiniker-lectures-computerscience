CFLAGS=-std=c17 -g -Wall -DUNITY_INCLUDE_DOUBLE
CC=gcc
UNITY=../unity

all: build run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build/unity.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/test.o -o build/test -lm

run_test: build/test
	build/test

clean:
	rm -rf build/
