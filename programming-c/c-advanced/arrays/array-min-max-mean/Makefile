CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/array_min_max_mean: array_min_max_mean.c
	$(CC) $(CFLAGS) array_min_max_mean.c -o build/array_min_max_mean

run: build/array_min_max_mean
	build/array_min_max_mean

clean:
	rm -rf build/
