CFLAGS=-std=c17 -g -Wall
CC=gcc
UNITY=../../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

parking_gate.o: parking_gate.h parking_gate.c
	$(CC) $(CFLAGS) -c parking_gate.c -o build/parking_gate.o

test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

test: init unity.o parking_gate.o test.o
	$(CC) $(CFLAGS) build/unity.o build/parking_gate.o build/test.o -o build/test
	build/test

clean:
	rm -rf build/
