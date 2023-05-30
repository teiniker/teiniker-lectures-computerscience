CFLAGS=-std=c17 -g -Wall  
CC=gcc
UNITY=../../unity

all: run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/linked_list.o: linked_list.h linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c -o build/linked_list.o

build/test.o: test.c linked_list.h
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build build/unity.o build/linked_list.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/linked_list.o build/test.o -o build/test

run_test: build/test
	build/test

clean:
	rm -rf build/
