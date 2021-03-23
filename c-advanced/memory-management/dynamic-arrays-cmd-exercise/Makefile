CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init dynamic_arrays_cmd

init:
	mkdir -p build

dynamic_arrays_cmd: dynamic_arrays_cmd.c
	$(CC) $(CFLAGS) dynamic_arrays_cmd.c -o build/dynamic_arrays_cmd
	build/dynamic_arrays_cmd 10 11 12 13 14 15 16 17 18 19

clean:
	rm -rf build/
