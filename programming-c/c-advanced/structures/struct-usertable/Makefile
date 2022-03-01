CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init usertable 

init:
	mkdir -p build

user: usertable.c
	$(CC) $(CFLAGS) usertable.c -o build/usertable
	build/usertable

clean:
	rm -rf usertable build/
