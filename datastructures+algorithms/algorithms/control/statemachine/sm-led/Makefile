CFLAGS=-std=c17 -g -Wall
CC=gcc
UNITY=../../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

led.o: led.h led.c
	$(CC) $(CFLAGS) -c led.c -o build/led.o

test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

test: init unity.o led.o test.o
	$(CC) $(CFLAGS) build/unity.o build/led.o build/test.o -o build/test
	build/test

clean:
	rm -rf build/
