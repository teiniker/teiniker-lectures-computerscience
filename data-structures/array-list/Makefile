CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

array_list.o: array_list.h array_list.c
	$(CC) $(CFLAGS) -c array_list.c -o build/array_list.o

array_list_test.o: array_list_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c array_list_test.c -o build/array_list_test.o

test: init unity.o array_list.o array_list_test.o
	$(CC) $(CFLAGS) build/unity.o build/array_list.o build/array_list_test.o -o build/array_list_test
	build/array_list_test

clean:
	rm -rf build/
