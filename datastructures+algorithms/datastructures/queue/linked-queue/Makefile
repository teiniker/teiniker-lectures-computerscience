CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

queue.o: queue.h queue.c
	$(CC) $(CFLAGS) -c queue.c -o build/queue.o

queue_test.o: queue_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c queue_test.c -o build/queue_test.o

test: init unity.o queue.o queue_test.o
	$(CC) $(CFLAGS) build/unity.o build/queue.o build/queue_test.o -o build/queue_test
	build/queue_test

clean:
	rm -rf build/
