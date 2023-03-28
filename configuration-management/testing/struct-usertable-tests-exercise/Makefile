CFLAGS=-std=c17 -g -Wall  
CC=gcc
UNITY=../unity

all: run 

build:
	mkdir -p build

build/usertable.o: usertable.c 
	$(CC) $(CFLAGS) -c usertable.c -o build/usertable.o

build/usertable: build/usertable.o 
	$(CC) $(CFLAGS) build/usertable.o -o build/usertable

run: build build/usertable
	build/usertable

clean:
	rm -rf usertable build/
