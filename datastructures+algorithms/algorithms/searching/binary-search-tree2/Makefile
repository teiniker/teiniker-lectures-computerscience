CFLAGS=-std=c17 -g -Wall  
CC=gcc
UNITY=../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

search_tree.o: search_tree.h search_tree.c
	$(CC) $(CFLAGS) -c search_tree.c -o build/search_tree.o

search_tree_test.o: search_tree_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c search_tree_test.c -o build/search_tree_test.o

test: init unity.o search_tree.o search_tree_test.o
	$(CC) $(CFLAGS) build/unity.o build/search_tree.o build/search_tree_test.o -o build/search_tree_test
	build/search_tree_test

clean:
	rm -rf build/
