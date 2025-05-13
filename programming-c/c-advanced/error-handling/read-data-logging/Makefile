CFLAGS=-std=c17 -g -Wall
CC=gcc
LOG=../log.c/src

all: run 

build:
	mkdir -p build

build/log.o: $(LOG)/log.c $(LOG)/log.h
	$(CC) $(CFLAGS) -c $(LOG)/log.c -o build/log.o

build/read-data.o: read-data.c
	$(CC) $(CFLAGS) -I $(LOG) -c read-data.c -o build/read-data.o

build/read-data: build/log.o build/read-data.o
	$(CC) $(CFLAGS) build/log.o build/read-data.o -o build/read-data

run: build build/read-data 
	build/read-data

clean:
	rm -rf build/
