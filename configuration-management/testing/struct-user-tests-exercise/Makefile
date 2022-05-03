CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../unity

all: struct-user 

init:
	mkdir -p build

struct-user.o: struct-user.c 
	$(CC) $(CFLAGS) -c struct-user.c -o build/struct-user.o

struct-user: init struct-user.o 
	$(CC) $(CFLAGS) build/struct-user.o -o build/struct-user
	build/struct-user

clean:
	rm -rf struct-user build/
