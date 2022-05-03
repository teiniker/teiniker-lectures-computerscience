CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init resistor 

init:
	mkdir -p build

resistor: resistor.c
	$(CC) $(CFLAGS) resistor.c -o build/resistor
	build/resistor

clean:
	rm -rf resistor build/
