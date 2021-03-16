CFLAGS=-std=c11 -g -Wall
CC=gcc

all: init calculator

init:
	mkdir -p build

calculator: calculator.c
	$(CC) $(CFLAGS) calculator.c -o build/calculator

clean:
	rm -rf build/

