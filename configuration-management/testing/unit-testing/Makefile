CFLAGS=-std=c11 -g -Wall
CC=gcc
UNITY=../unity

all: test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

unit_testing.o: unit_testing.c
	$(CC) $(CFLAGS) -I $(UNITY) -c unit_testing.c -o build/unit_testing.o

test: init unity.o unit_testing.o
	$(CC) $(CFLAGS) build/unity.o build/unit_testing.o -o build/unit_testing
	build/unit_testing 

clean:
	rm -rf build/

