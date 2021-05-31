CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

binary_tree.o: binary_tree.h binary_tree.c
	$(CC) $(CFLAGS) -c binary_tree.c -o build/binary_tree.o

binary_tree_test.o: binary_tree_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c binary_tree_test.c -o build/binary_tree_test.o

test: init unity.o binary_tree.o binary_tree_test.o
	$(CC) $(CFLAGS) build/unity.o build/binary_tree.o build/binary_tree_test.o -o build/binary_tree_test
	build/binary_tree_test

clean:
	rm -rf build/
