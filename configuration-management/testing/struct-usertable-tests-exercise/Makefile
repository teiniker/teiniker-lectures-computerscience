CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../unity

all: usertable 

init:
	mkdir -p build

usertable.o: usertable.c 
	$(CC) $(CFLAGS) -c usertable.c -o build/usertable.o

usertable: init usertable.o 
	$(CC) $(CFLAGS) build/usertable.o -o build/usertable
	build/usertable

clean:
	rm -rf usertable build/
