CFLAGS=-std=c11 -g -Wall
CC=gcc
UNITY=../unity

all: test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

sprintf_test.o: sprintf_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c sprintf_test.c -o build/sprintf_test.o

test: init unity.o sprintf_test.o
	$(CC) $(CFLAGS) build/unity.o build/sprintf_test.o -o build/sprintf_test
	build/sprintf_test

clean:
	rm -rf build/

