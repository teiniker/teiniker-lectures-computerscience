CFLAGS=-std=c99 -g -Wall  
CC=gcc
LIBS=-lm

all: double_rounding 

double_rounding: double_rounding.c
	$(CC) $(CFLAGS) double_rounding.c -o double_rounding $(LIBS)
	./double_rounding

clean:
	rm -rf double_rounding
