CFLAGS= -std=c++17 -g -O0 -Wall
CC=g++
UNITY=../../../unity

all: run_test

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/lcd.o: lcd.cpp lcd.h
	$(CC) $(CFLAGS) -c lcd.cpp -o build/lcd.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c test.cpp -o build/test.o

build/test: build build/unity.o build/lcd.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/lcd.o build/test.o -o build/test

run_test: build/test
	build/test

clean:
	rm -rf build/
