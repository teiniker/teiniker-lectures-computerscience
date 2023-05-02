CFLAGS=-std=c17 -g -Wall  
CC=gcc

all: run  

build:
	mkdir -p build

build/sm_parking_gate.o: sm_parking_gate.c sm_parking_gate.h
	$(CC) $(CFLAGS) -c sm_parking_gate.c -o build/sm_parking_gate.o

build/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build build/sm_parking_gate.o build/main.o
	$(CC) $(CFLAGS) build/sm_parking_gate.o build/main.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
