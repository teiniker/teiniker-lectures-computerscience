CC=gcc
CFLAGS= -std=c17 -g -Wall
UNITY=../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/hello.o: hello.c hello.h
	$(CC) $(CFLAGS) -c hello.c -o build/hello.o

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build build/unity.o build/hello.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/hello.o build/test.o -o build/test

test_run: build/test
	build/test

clean:
	rm -rf build/
