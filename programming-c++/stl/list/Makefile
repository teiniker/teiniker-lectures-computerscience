CFLAGS= -g -Wall  
CC=g++
UNITY=../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/list_test.o: list_test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c list_test.cpp -o build/list_test.o

build/test: build build/unity.o build/list_test.o 
	$(CC) $(CFLAGS) build/unity.o build/list_test.o -o build/list_test

test_run: build/test 
	build/list_test

clean:
	rm -rf build/

