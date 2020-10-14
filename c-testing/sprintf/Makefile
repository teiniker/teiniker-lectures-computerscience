CFLAGS=-std=c11 -g -Wall
CC=gcc
UNITY=../unity

all: test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

sprintf_test.o: test/sprintf_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test/sprintf_test.c -o build/sprintf_test.o

test: init unity.o sprintf_test.o
	$(CC) $(CFLAGS) build/unity.o build/sprintf_test.o -o build/test
	build/test 

clean:
	rm -rf build/

