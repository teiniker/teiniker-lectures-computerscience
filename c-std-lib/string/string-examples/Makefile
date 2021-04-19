CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init string string_console string_IO

init:
	mkdir -p build

string: string.c
	$(CC) $(CFLAGS) string.c -o build/string
	build/string

string_console: string_console.c
	$(CC) $(CFLAGS) string_console.c -o build/string_console
	build/string_console

string-IO: string_IO.c
	$(CC) $(CFLAGS) string_IO.c -o build/string_IO
	build/string_IO


clean:
	rm -rf string string_console string_IO build/
