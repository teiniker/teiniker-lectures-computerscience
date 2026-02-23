CC=gcc
CFLAGS=-std=c17 -g -Wall -Iinclude

SRC_DIR=src
OBJ_DIR=build
SRCS=$(SRC_DIR)/main.c $(SRC_DIR)/vector.c
OBJS=$(OBJ_DIR)/main.o $(OBJ_DIR)/vector.o

all: build run

build:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/vector.o: $(SRC_DIR)/vector.c include/vector.h | build
	$(CC) $(CFLAGS) -c $(SRC_DIR)/vector.c -o $(OBJ_DIR)/vector.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c include/vector.h | build
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OBJ_DIR)/main

run: $(OBJ_DIR)/main
	$(OBJ_DIR)/main

clean:
	rm -rf $(OBJ_DIR)/
