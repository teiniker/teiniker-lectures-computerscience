CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init linked_nodes 

init:
	mkdir -p build

linked_nodes: linked_nodes.c
	$(CC) $(CFLAGS) linked_nodes.c -o build/linked_nodes
	build/linked_nodes

clean:
	rm -rf linked_nodes build/
