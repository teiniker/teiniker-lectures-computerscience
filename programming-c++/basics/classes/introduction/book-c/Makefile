CC=gcc
CFLAGS= -g -Wall  
UNITY=../../../../unity

all: run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/book.o: book.c book.h
	$(CC) $(CFLAGS) -c book.c -o build/book.o

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build build/unity.o build/book.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/book.o build/test.o -o build/test

run_test: build/test 
	build/test

clean:
	rm -rf build/

