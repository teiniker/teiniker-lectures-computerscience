CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../..unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

linked_list.o: linked_list.h linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c -o build/linked_list.o

linked_list_test.o: linked_list_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c linked_list_test.c -o build/linked_list_test.o

test: init unity.o linked_list.o linked_list_test.o
	$(CC) $(CFLAGS) build/unity.o build/linked_list.o build/linked_list_test.o -o build/linked_list_test
	build/linked_list_test

clean:
	rm -rf build/
