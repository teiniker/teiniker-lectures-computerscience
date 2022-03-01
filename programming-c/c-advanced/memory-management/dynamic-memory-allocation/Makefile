CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init dynamic_allocation_malloc dynamic_allocation_calloc dynamic_allocation_realloc

init:
	mkdir -p build

dynamic_allocation_malloc: dynamic_allocation_malloc.c
	$(CC) $(CFLAGS) dynamic_allocation_malloc.c -o build/dynamic_allocation_malloc

dynamic_allocation_calloc: dynamic_allocation_calloc.c
	$(CC) $(CFLAGS) dynamic_allocation_calloc.c -o build/dynamic_allocation_calloc

dynamic_allocation_realloc: dynamic_allocation_realloc.c
	$(CC) $(CFLAGS) dynamic_allocation_realloc.c -o build/dynamic_allocation_realloc

clean:
	rm -rf build/
