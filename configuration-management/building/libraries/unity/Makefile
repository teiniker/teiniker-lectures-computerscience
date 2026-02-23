CC=gcc
AR=ar
CFLAGS=-std=c17 -g -Wall -Iinclude

SRC=unity.c
OBJ=build/unity.o
LIB=lib/libunity.a

all: $(LIB)

build:
	mkdir -p build

$(OBJ): $(SRC) unity.h unity_internals.h | build
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

$(LIB): $(OBJ)
	mkdir -p lib
	$(AR) rcs $(LIB) $(OBJ)

install: $(LIB)
	mkdir -p include lib
	cp unity.h unity_internals.h include/
	cp $(LIB) lib/

clean:
	rm -rf build lib
