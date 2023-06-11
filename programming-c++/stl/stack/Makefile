CFLAGS= -g -Wall  
CC=g++
UNITY=../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/stack_test.o: stack_test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c stack_test.cpp -o build/stack_test.o

build/test: build build/unity.o build/stack_test.o 
	$(CC) $(CFLAGS) build/unity.o build/stack_test.o -o build/stack_test

test_run: build/test 
	build/stack_test

clean:
	rm -rf build/

