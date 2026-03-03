CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/arduino: arduino.c
	$(CC) $(CFLAGS) arduino.c -o build/arduino

run: build/arduino
	build/arduino

clean:
	rm -rf build/
