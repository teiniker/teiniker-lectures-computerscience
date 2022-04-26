CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../unity

all: test 

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o
	
usertable.o: usertable.c usertable.h
	$(CC) $(CFLAGS) -c usertable.c -o build/usertable.o

main.o: main.c usertable.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o

main: init main.o usertable.o 
	$(CC) $(CFLAGS) build/main.o build/usertable.o -o build/main
	build/main

test.o: test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test.c -o build/test.o

test: init unity.o usertable.o test.o
	$(CC) $(CFLAGS) build/unity.o build/usertable.o build/test.o -o build/test
	build/test

clean:
	rm -rf user build/
