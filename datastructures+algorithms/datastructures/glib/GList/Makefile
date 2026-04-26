CFLAGS=-std=c99 -g -Wall
INCLUDE=-I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LIB=-lglib-2.0  
CC=gcc
UNITY=../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) $(INCLUDE) -c test.c -o build/test.o

build/test: build build/unity.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/test.o -o build/test $(LIB)

test_run: build/test
	build/test

clean:
	rm -rf build/
