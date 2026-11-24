CFLAGS=-std=c17 -g -Wall
CC=gcc
UNITY=../../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

roller_blind.o: roller_blind.h roller_blind.c
	$(CC) $(CFLAGS) -c roller_blind.c -o build/roller_blind.o

test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

test: init unity.o roller_blind.o test.o
	$(CC) $(CFLAGS) build/unity.o build/roller_blind.o build/test.o -o build/test
	build/test

clean:
	rm -rf build/
