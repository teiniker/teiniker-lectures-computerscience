CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init complex_numbers 

init:
	mkdir -p build

complex_numbers: complex_numbers.c
	$(CC) $(CFLAGS) complex_numbers.c -o build/complex_numbers
	build/complex_numbers

clean:
	rm -rf complex_numbers build/
