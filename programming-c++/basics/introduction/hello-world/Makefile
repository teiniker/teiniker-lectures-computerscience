CFLAGS= -std=c++17 -g -Wall
CC=g++
UNITY=../../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/hello.o: hello.cpp hello.h
	$(CC) $(CFLAGS) -c hello.cpp -o build/hello.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c test.cpp -o build/test.o

build/test: build build/unity.o build/hello.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/hello.o build/test.o -o build/test

test_run: build/test
	build/test

clean:
	rm -rf build/
