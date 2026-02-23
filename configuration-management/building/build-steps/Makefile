all: hello

_hello.c: hello.c
	cpp hello.c _hello.c

_hello.s: _hello.c
	gcc -Wall -g -S _hello.c

hello.o : _hello.s
	as -o hello.o _hello.s

hello: hello.o
	gcc -o hello hello.o

clean:
	rm hello hello.o _hello.s _hello.c

