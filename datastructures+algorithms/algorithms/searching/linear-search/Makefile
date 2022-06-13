CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

linear-search.o: linear-search.h linear-search.c
	$(CC) $(CFLAGS) -c linear-search.c -o build/linear-search.o

test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

test: init unity.o linear-search.o test.o
	$(CC) $(CFLAGS) build/unity.o build/linear-search.o build/test.o -o build/test
	build/test

clean:
	rm -rf build/
