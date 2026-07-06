CC=g++
CFLAGS= -std=c++20 -g -Wall
UNITY=../../unity

all: run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/led.o: led.cpp led.h
	$(CC) $(CFLAGS) -c led.cpp -o build/led.o

build/test.o: test.cpp led.h
	$(CC) $(CFLAGS) -I $(UNITY) -c test.cpp -o build/test.o

build/test: build build/unity.o build/led.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/led.o build/test.o -o build/test

run_test: build/test
	build/test

clean:
	rm -rf build/
