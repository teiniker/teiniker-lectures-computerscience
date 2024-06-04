CFLAGS= -g -Wall  
CC=g++
UNITY=../../../unity

all: run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/can-msg.o: can-msg.cpp can-msg.h
	$(CC) $(CFLAGS) -c can-msg.cpp -o build/can-msg.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c test.cpp -o build/test.o

build/test: build build/unity.o build/can-msg.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/can-msg.o build/test.o -o build/test

run_test: build/test 
	build/test

clean:
	rm -rf build/

