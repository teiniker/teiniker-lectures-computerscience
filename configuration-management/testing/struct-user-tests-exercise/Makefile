CFLAGS=-std=c17 -g -Wall
CC=gcc
UNITY=../unity

all: run 

build:
	mkdir -p build

build/struct-user.o: struct-user.c 
	$(CC) $(CFLAGS) -c struct-user.c -o build/struct-user.o

build/struct-user: build/struct-user.o 
	$(CC) $(CFLAGS) build/struct-user.o -o build/struct-user

run: build build/struct-user
	build/struct-user

clean:
	rm -rf struct-user build/
