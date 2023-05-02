# Modular Programming

As programs grow larger and larger, it is more desirable to split them into modules.
C allows programs to be split into multiple files, compiled separately, and then 
linked to form a single program. 

## Modules
A **module** is a collection of functions that perform related tasks.

Modules are divided into two parts: 
* The **public** part tells the user how to call the functions in the module. It contains the definition of 
data structures and functions that are to be used outside the module.
These definitions are put in a **header file**, and the file must be included in any program that depends on that module.

* Anything that is not directly usable by the outside world should be kept **private**. 
All implementation details are stored in a corresponding **implementation file**. 

![Modules](figures/Modules.png)

## Headers
Information that is shared between modules should be put in a header file.
By convention, all header filenames end with `.h` to distinguish them from the `.c` implementation files.

The header should contain all the public information:
* Common constants
* Common data structures
* Prototypes of all public functions

Example: `sm_parking_gate.h`
```C
#ifndef _SM_PARKING_GATE_H_
#define _SM_PARKING_GATE_H_

#include <stdio.h>

enum events
{
    CAR_AT_GATE,
    TOP_SWITCH,
    CAR_JUST_EXITED,
    BOTTOM_SWITCH
};

enum sm_states 
{
    WAITING,
    RAISING,
    OPEN,
    LOWERING
};

extern enum sm_states state; 
extern void sm_parking_gate(enum events event);

#endif /* SM_PARKING_GATE_H */
```
The **extern** modifier is used to indicate that a variable or function is defined outside the current 
file.

Note that every header file should implement the **include guard** idiom:
```C
#ifndef _MY_HEADER_FILE_H_
#define _MY_HEADER_FILE_H_

// Constants, prototypes...

#endif /* _MY_HEADER_FILE_H_ */
```
This ensures that when a header file is included in multiple places, it will not be duplicated
for the compiler's input.


## Implementation
The body of the module contains all the functions and variables needed to implement that module.

Example: `sm_parking_gate.c`
```C
#include "sm_parking_gate.h"

// Variable definition
enum sm_states state; 

// Function definitions
void motor_right(void)
{
    printf("MOTOR: >>>\n");
}

void motor_stop(void)
{
    printf("MOTOR: ---\n");
}

void motor_left(void)
{
    printf("MOTOR: <<<\n");
}
//...
```
Note that functions not declared in the header file are local to this implementation
file. Thus, we **encapsulate the implementation details**. 
 
## Makefile

Example: Makefile to compile two object files and link them into an executable
```
CFLAGS=-std=c17 -g -Wall  
CC=gcc

all: run  

build:
	mkdir -p build

build/sm_parking_gate.o: sm_parking_gate.c sm_parking_gate.h
	$(CC) $(CFLAGS) -c sm_parking_gate.c -o build/sm_parking_gate.o

build/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/main: build build/sm_parking_gate.o build/main.o
	$(CC) $(CFLAGS) build/sm_parking_gate.o build/main.o -o build/main

run: build/main
	build/main

clean:
	rm -rf build/
```

When we call `make` to execute the `Makefile`, we get the following output:
```
$ make 
mkdir -p build
gcc -std=c99 -g -Wall   -c sm_parking_gate.c -o build/sm_parking_gate.o
gcc -std=c99 -g -Wall   -c main.c -o build/main.o
gcc -std=c99 -g -Wall   build/sm_parking_gate.o build/main.o -o build/sm_parking_gate
build/sm_parking_gate
MOTOR: >>>
MOTOR: ---
MOTOR: <<<
MOTOR: ---
```
Note that we compile the source files (`*.h` and `*.c`) into object files (`*.o`), link the together 
into an application, and execute that application.

All **build artifacts** are stored in a temporary `build/` directory. 
Executing the `clean` target removes this directory from our project again:
```
$ make clean
rm -rf build/
```


## References
* Steve Oualline. **Practical C Programming**. O'REILLY 3rd Edition 1997. Chapter 18: Modular Programming 

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
  Chapter 15: Writing Large Programs
      
* [GNU Make](https://www.gnu.org/software/make/)    

 
*Egon Teiniker, 2020-2023, GPL v3.0* 
