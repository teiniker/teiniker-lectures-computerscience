CFLAGS= -g -Wall  
CC=g++
UNITY=../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/queue_test.o: queue_test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c queue_test.cpp -o build/queue_test.o

build/test: build build/unity.o build/queue_test.o 
	$(CC) $(CFLAGS) build/unity.o build/queue_test.o -o build/queue_test

test_run: build/test 
	build/queue_test

clean:
	rm -rf build/

