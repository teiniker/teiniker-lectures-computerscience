CFLAGS=-std=c99 -g -Wall  
CC=gcc
LIBS=-lm

all: rounding 

rounding: rounding.c
	$(CC) $(CFLAGS) rounding.c -o rounding $(LIBS)
	./rounding

clean:
	rm -rf rounding
