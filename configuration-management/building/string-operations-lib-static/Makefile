CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: main 

init:
	mkdir -p build

string_operations.o: string_operations.c string_operations.h
	$(CC) $(CFLAGS) -c string_operations.c -o build/string_operations.o

lib: string_operations.o
	ar -cvq build/libstrops.a build/string_operations.o

install: lib
	mkdir lib
	cp build/libstrops.a lib/
	mkdir include
	cp string_operations.h include/

main.o: main.c install
	$(CC) $(CFLAGS) -c main.c -o build/main.o -I./include 

main: init main.o
	$(CC) $(CFLAGS) -o build/main build/main.o -I./include -L./lib -lstrops
	build/main

clean:
	rm -rf build/
	rm -rf lib/ include/
