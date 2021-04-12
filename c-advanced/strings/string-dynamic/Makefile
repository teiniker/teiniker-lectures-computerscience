CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: init string_dynamic

init:
	mkdir -p build

string_dynamic: string_dynamic.c
	$(CC) $(CFLAGS) string_dynamic.c -o build/string_dynamic
	build/string_dynamic

clean:
	rm -rf string_dynamic build/
