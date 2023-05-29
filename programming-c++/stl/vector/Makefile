CFLAGS= -g -Wall  
CC=g++
UNITY=../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/vector_test.o: vector_test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c vector_test.cpp -o build/vector_test.o

build/test: build build/unity.o build/vector_test.o 
	$(CC) $(CFLAGS) build/unity.o build/vector_test.o -o build/vector_test

test_run: build/test 
	build/vector_test

clean:
	rm -rf build/

