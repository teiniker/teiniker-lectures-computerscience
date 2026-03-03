CFLAGS=-std=c17 -g -Wall
CC=gcc

all: build run

build:
	mkdir -p build

build/array_xor_encryption: array_xor_encryption.c
	$(CC) $(CFLAGS) array_xor_encryption.c -o build/array_xor_encryption

run: build/array_xor_encryption
	build/array_xor_encryption

clean:
	rm -rf build/
