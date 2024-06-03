CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../../unity

all: build run

build:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/qsort: qsort.c
	$(CC) $(CFLAGS) qsort.c -o build/qsort

run: build/qsort 
	build/qsort

clean:
	rm -rf build/
