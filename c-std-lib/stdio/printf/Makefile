CFLAGS=-std=c11 -g -Wall
CC=gcc

all: init printf_escape printf_char printf_integer printf_float 

init:
	mkdir -p build

printf_escape: printf_escape.c
	$(CC) $(CFLAGS) printf_escape.c -o build/printf_escape

printf_char: printf_char.c
	$(CC) $(CFLAGS) printf_char.c -o build/printf_char

printf_integer: printf_integer.c
	$(CC) $(CFLAGS) printf_integer.c -o build/printf_integer

printf_float: printf_float.c
	$(CC) $(CFLAGS) printf_float.c -o build/printf_float

clean:
	rm -rf build/

