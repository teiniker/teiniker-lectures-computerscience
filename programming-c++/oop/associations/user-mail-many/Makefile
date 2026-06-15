CFLAGS= -std=c++17 -g -O0 -Wall
CC=g++
UNITY=../../../unity

all: run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/mail.o: mail.cpp mail.h
	$(CC) $(CFLAGS) -c mail.cpp -o build/mail.o

build/user.o: user.cpp user.h mail.h
	$(CC) $(CFLAGS) -c user.cpp -o build/user.o

build/test.o: test.cpp user.h mail.h
	$(CC) $(CFLAGS) -I $(UNITY) -c test.cpp -o build/test.o

build/test: build build/unity.o build/mail.o build/user.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/mail.o build/user.o \
	    build/test.o -o build/test

run_test: build/test
	build/test

clean:
	rm -rf build/

