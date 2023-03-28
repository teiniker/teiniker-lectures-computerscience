CFLAGS=-std=c17 -g -Wall
CC=gcc
UNITY=../unity

all: run_test 

build:
	mkdir -p build

doc:
	doxygen Doxyfile

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o
	
build/usertable.o: usertable.c usertable.h
	$(CC) $(CFLAGS) -c usertable.c -o build/usertable.o

build/main.o: main.c usertable.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build/main.o build/usertable.o 
	$(CC) $(CFLAGS) build/main.o build/usertable.o -o build/main

run: build build/main
	build/main

build/test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

build/test: build/unity.o build/usertable.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/usertable.o build/test.o -o build/test

run_test: build build/test
	build/test

clean:
	rm -rf user build/ doc/
