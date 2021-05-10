CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init user_address node 

init:
	mkdir -p build

user_address: user_address.c
	$(CC) $(CFLAGS) user_address.c -o build/user_address.c
	build/user_address.c

node: node.c
	$(CC) $(CFLAGS) node.c -o build/node.c
	build/node.c

clean:
	rm -rf user_address node build/
