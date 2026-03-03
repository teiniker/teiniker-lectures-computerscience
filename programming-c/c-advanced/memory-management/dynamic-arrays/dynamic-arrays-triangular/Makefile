CFLAGS=-std=c17 -g -Wall  
CC=gcc

all: build build/dynamic_arrays_triangular run

build:
	mkdir -p build

build/dynamic_arrays_triangular: dynamic_arrays_triangular.c
	$(CC) $(CFLAGS) dynamic_arrays_triangular.c -o build/dynamic_arrays_triangular

run: build
	build/dynamic_arrays_triangular

clean: 
	rm -rf build/ dynamic_arrays_triangular
