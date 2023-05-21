# A Simple C++ Program

C++ has a reputation for being hard to learn.
It’s true that C++ is a big, complex, and ambitious language and that even veteran 
C++ programmers regularly learn new patterns, features, and usages.

But in this example, we will write a simple C++ program and then compile and run it.
We **reuse our knowledge of modular programming, build and test automation**, 
which we know from C.

```C++
#include <cstdio>

#include "hello.h"

size_t say_hello(const char *name)
{
    size_t len = printf("Hello %s!\n",name);
    return len;
}
```

The only difference for now is that we call the header file `cstdin` and not `stdin.h`

In C++, the traditional C library headers, such as `stdio.h`, have been adapted to the 
**C++ standard library** and given the `c` prefix. 
The primary reason for this adaptation is to ensure compatibility and consistency 
between C and C++ codebases. 

In addition, we change the name of the compiler from `gcc` to `g++` in the `Makefile`.

The C++ implementation files have a `.cpp` extension to distinguish them 
from the C source files.

```
CFLAGS= -std=c++17 -g -Wall
CC=g++
UNITY=../../../unity

all: test_run

build:
	mkdir -p build

build/unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

build/hello.o: hello.cpp hello.h
	$(CC) $(CFLAGS) -c hello.cpp -o build/hello.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -I $(UNITY) -c test.cpp -o build/test.o

build/test: build build/unity.o build/hello.o build/test.o
	$(CC) $(CFLAGS) build/unity.o build/hello.o build/test.o -o build/test

test_run: build/test
	build/test

clean:
	rm -rf build/
```

Note that we can adopt the tooling almost unchanged from our C examples. 
In fact, **many tool chains offer C and C++ support** (see also the **Arduino Framework**).


## References

* Josh. Lospinoso. **C++ Crash Course**. No Starch Press, 2019 
    * Part I: Chapter 1: Up and Running 

*Egon Teiniker, 2020-2023, GPL v3.0*