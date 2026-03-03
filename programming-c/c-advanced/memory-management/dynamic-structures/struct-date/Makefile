CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/date: date.c
	$(CC) $(CFLAGS) date.c -o build/date

run: build/date
	build/date

clean:
	rm -rf build/
