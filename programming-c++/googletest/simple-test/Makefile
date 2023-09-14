CFLAGS= -g -Wall  
LIBS=-lgtest -lgtest_main -pthread
CC=g++

all: run_test

build:
	mkdir -p build

build/test: test.cpp 
	$(CC) $(CFLAGS) test.cpp -o build/test $(LIBS)

run_test: build build/test 
	build/test

clean:
	rm -rf build/

