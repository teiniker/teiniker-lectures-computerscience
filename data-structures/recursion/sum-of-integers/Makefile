CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

sum.o: sum.h sum.c
	$(CC) $(CFLAGS) -c sum.c -o build/sum.o

sum_test.o: sum_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c sum_test.c -o build/sum_test.o

test: init unity.o sum.o sum_test.o
	$(CC) $(CFLAGS) build/unity.o build/sum.o build/sum_test.o -o build/sum_test
	build/sum_test

clean:
	rm -rf build/
