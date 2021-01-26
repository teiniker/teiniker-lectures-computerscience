CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: main  

init:
	mkdir -p build

sm_parking_gate.o: sm_parking_gate.c sm_parking_gate.h
	$(CC) $(CFLAGS) -c sm_parking_gate.c -o build/sm_parking_gate.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

main: init sm_parking_gate.o main.o
	$(CC) $(CFLAGS) build/sm_parking_gate.o build/main.o -o build/sm_parking_gate
	build/sm_parking_gate

clean:
	rm -rf build/
