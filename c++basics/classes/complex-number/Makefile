CFLAGS= -g -Wall  
CC=g++
UNITY=../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

complex_number.o: complex_number.c complex_number.h
	$(CC) $(CFLAGS) -c complex_number.c -o build/complex_number.o

complex_number_test.o: complex_number_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c complex_number_test.c -o build/complex_number_test.o

test: init unity.o complex_number.o complex_number_test.o
	$(CC) $(CFLAGS) build/unity.o build/complex_number.o build/complex_number_test.o -o build/complex_number_test
	build/complex_number_test

clean:
	rm -rf build/

