CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init date 

init:
	mkdir -p build

date: date.c
	$(CC) $(CFLAGS) date.c -o build/date
	build/date

clean:
	rm -rf date build/
