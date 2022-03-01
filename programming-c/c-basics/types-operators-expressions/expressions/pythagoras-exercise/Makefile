CFLAGS=-std=c99 -g -Wall  
CC=gcc
LIBS=-lm

all: pythagoras 

pythagoras: pythagoras.c
	$(CC) $(CFLAGS) pythagoras.c -o pythagoras $(LIBS)
	./pythagoras

clean:
	rm -rf pythagoras
