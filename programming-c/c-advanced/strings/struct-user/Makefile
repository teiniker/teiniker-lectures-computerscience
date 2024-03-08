CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init user 

init:
	mkdir -p build

user: user.c
	$(CC) $(CFLAGS) user.c -o build/user
	build/user

clean:
	rm -rf user build/
