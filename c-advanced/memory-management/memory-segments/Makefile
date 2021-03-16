CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init local_vs_global memory_segments

init:
	mkdir -p build

local_vs_global: local_vs_global.c
	$(CC) $(CFLAGS) local_vs_global.c -o build/local_vs_global
	
memory_segments: memory_segments.c
	$(CC) $(CFLAGS) memory_segments.c -o build/memory_segments

clean:
	rm -rf build/
