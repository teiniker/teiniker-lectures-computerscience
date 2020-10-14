CFLAGS=-std=c11 -g -Wall
CC=gcc

all: printf_escape printf_char printf_integer printf_float

printf_escape: printf_escape.c
	$(CC) $(CFLAGS) printf_escape.c -o printf_escape

printf_char: printf_char.c
	$(CC) $(CFLAGS) printf_char.c -o printf_char

printf_integer: printf_integer.c
	$(CC) $(CFLAGS) printf_integer.c -o printf_integer

printf_float: printf_float.c
	$(CC) $(CFLAGS) printf_float.c -o printf_float

clean:
	rm printf_escape printf_char printf_integer printf_float

