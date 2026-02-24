# Build Automation Using GNU Make

The program **make** is designed to aid the programmer in compiling 
and linking programs which consists of many source files.

The program `make` allows us to specify the dependencies between source files 
and the commands that generates the final program in a so called `Makefile`.

The `Makefile` contains the following sections:

* **Comments**: Any line starting with a hash mark `#` is a comment.

* **Macros**: A macro has the format `name = value` where `name` is any valid 
    identifier and `value` is the text that will be substituted whenever make 
    sees `$(name)`.

* **Explicit rules** tell make what commands are needed to create the program.
* Default rules

Explicit rules can take several forms, the most common is:

```
target: source [source2] [source3] ...
    command
    [command2]
    [command3]
    ...
```
where **target** is the name of a file to create.

It is created out of the source file **source**. If the target is created out 
of several files, they are all listed.
This list should include any header files included by the source file as well.

The **command** that generates the target is specified on the next line.
Sometimes we need more than one commend to create the target.
Commands are listed one per line.
**Each is indented by a tab**.

_Example_: struct-vector-modular
```
CFLAGS=-std=c17 -g -Wall -I.
CC=gcc

all: build run

build:
	mkdir -p build

build/vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c -o build/vector.o

build/main.o: main.c vector.h
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build/vector.o build/main.o 
	$(CC) $(CFLAGS) build/main.o build/vector.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
```

When we call `make` to execute the `Makefile`, we get the following output:
```bash
mkdir -p build
gcc -std=c17 -g -Wall -I. -c vector.c -o build/vector.o
gcc -std=c17 -g -Wall -I. -c main.c -o build/main.o
gcc -std=c17 -g -Wall -I. build/main.o build/vector.o -o build/main

build/main
[1.000000, 2.000000, 3.000000]
[4.000000, 5.000000, 6.000000]
[5.000000, 7.000000, 9.000000]
[-3.000000, -3.000000, -3.000000]
[2.000000, 4.000000, 6.000000]
[-3.000000, 6.000000, -3.000000]```
```

Note that we compile the source files (`*.h` and `*.c`) into **object files** (`*.o`), link the together 
into an **executable**, and run that application.

All **build artifacts** are stored in a temporary `build/` directory. 
```
├── build
│   ├── main
│   ├── main.o
│   └── vector.o
```

Executing the `clean` target removes this directory from our project again:
```bash
$ make clean
rm -rf build/
```

To see all commands which will be executed by make, we can use the **-n flag** 
to print out all build steps **without executing them**:
```bash
$ make -n
mkdir -p build
gcc -std=c17 -g -Wall -I. -c vector.c -o build/vector.o
gcc -std=c17 -g -Wall -I. -c main.c -o build/main.o
gcc -std=c17 -g -Wall -I. build/main.o build/vector.o -o build/main
build/main
```


## References
* [GNU Make](https://www.gnu.org/software/make/)
* [GNU Make Manual](https://www.gnu.org/software/make/manual/)

* [YouTube (Jacob Sorber): Why that "Perfect" Makefile Doesn't Work](https://youtu.be/l5KqE0DMG-Q)

* Robert Mecklenburg. Managing Projects with GNU Make. OReilly, 2005


*Egon Teiniker, 2020-2026, GPL v3.0* 
