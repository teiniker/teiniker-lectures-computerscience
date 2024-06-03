CC=g++
CFLAGS= -g -Wall  
UNITY=../../../../unity

all: run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/book.o: book.cpp book.h
	$(CC) $(CFLAGS) -c book.cpp -o build/book.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c test.cpp -o build/test.o

build/test: build build/unity.o build/book.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/book.o build/test.o -o build/test

run_test: build/test 
	build/test

clean:
	rm -rf build/

