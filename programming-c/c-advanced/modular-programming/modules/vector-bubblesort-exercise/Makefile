CFLAGS=-std=c17 -g -Wall  
CC=gcc

all: run  

build:
	mkdir -p build

build/bubblesort: bubblesort.c 
	$(CC) $(CFLAGS) bubblesort.c -o build/bubblesort

run: build/bubblesort
	build/bubblesort

clean:
	rm -rf build/
