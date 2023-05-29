CFLAGS= -g -Wall  
CC=g++
UNITY=../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/string_test.o: string_test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c string_test.cpp -o build/string_test.o

build/test: build build/unity.o build/string_test.o 
	$(CC) $(CFLAGS) build/unity.o build/string_test.o -o build/string_test

test_run: build/test 
	build/string_test

clean:
	rm -rf build/

