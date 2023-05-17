CFLAGS= -g -Wall  
CC=g++
UNITY=../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

stack.o: stack.cpp stack.h
	$(CC) $(CFLAGS) -c stack.cpp -o build/stack.o

stack_test.o: stack_test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c stack_test.cpp -o build/stack_test.o

test: init unity.o stack.o stack_test.o
	$(CC) $(CFLAGS) build/unity.o build/stack.o build/stack_test.o -o build/stack_test
	build/stack_test

clean:
	rm -rf build/

