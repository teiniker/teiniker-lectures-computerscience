CFLAGS=-std=c17 -g -Wall  
CC=gcc
UNITY=../../unity

all: init build/test

init:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/search_tree.o: search_tree.h search_tree.c
	$(CC) $(CFLAGS) -c search_tree.c -o build/search_tree.o

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: init build/unity.o build/search_tree.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/search_tree.o build/test.o -o build/test
	build/test

clean:
	rm -rf build/
