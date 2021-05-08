CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init linked_list 

init:
	mkdir -p build

linked_list: linked_list.c
	$(CC) $(CFLAGS) linked_list.c -o build/linked_list
	build/linked_list

clean:
	rm -rf linked_list build/
