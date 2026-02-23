# Libraries

When we compile C programs, libraries let us **package compiled code** so it can
be reused across many programs without recompiling the same sources each time.

> A library is a collection of compiled object code (`.o` files) that provides
> functions you can call from your programs.

There are two common library types on Linux:

* **Static libraries** (`*.a` files): copied into your program at link time

* **Shared (dynamic) libraries** (`*.so` files): loaded at runtime


## Static Libraries

A static library is just an archive of `.o` files.

At link time, the **linker pulls the required object files** from the archive and
**copies their code directly into the final executable**. The result is a **single,
self-contained binary** that does not need the library file at runtime. 

This means:

* The executable is larger (library code is embedded).

* The binary is easy to deploy (no runtime dependency on the library file).

* Updates to the library require relinking the executable.


**Example: `struct-vector-lib`**

* Create a library from object file(s):

```bash
$ mkdir -p build
$ gcc -std=c17 -g -Wall -I. -c vector.c -o build/vector.o
$ ar -cvq build/libvector.a build/vector.o
$ mkdir -p lib
$ cp build/libvector.a lib/
$ mkdir -p include
$ cp vector.h include/
```

After these steps we have a library (`libvector.a`) in the `lib/` folder and 
the corresponding header file (`vector.h`) in the `include/` folder. 

* Use a library to build the executable

```bash
$ gcc -std=c17 -g -Wall  -c main.c -o build/main.o -I./include 
$ gcc -std=c17 -g -Wall  -o build/main build/main.o -L./lib -lvector
```

First we compile the `main.c` into a object file and then link the 
`main.o` with the `libvector.a` library:

* `-I./include`: Set the include path to the library's header file(s)

* `-L./lib`: Set the library path (where the linker can find the `*.a` files)

* `-lvector`: Specify the library which should be linked. 
    Note the naming convention: `libvector.a` leads to `-lvector`.

Run the application:

```bash
$ make clean
$ make
```

The `make` target builds and runs `build/main`, which exercises the vector
operations via `assert` statements. A successful run prints intermediate vector
values and exits with status code `0`. Any failing assertion will abort the
program.

    
## Shared Libraries

Shared libraries are linked in a different way: the executable contains a small
**reference to the library**, and the **operating system's dynamic loader** resolves
that reference when the program starts. The library's code stays in a separate
`*.so` file that is **loaded into memory at runtime**. 

This means:

* The executable is smaller (code remains in the shared library).

* Multiple programs can share the same library in memory.

* You can update a library without relinking every program (within ABI
  compatibility limits).


## Static vs. Shared: When to Use Which

* Use **static libraries** when you want a fully self-contained binary, simple
  deployment, or when you are distributing a single executable to environments
  where installing dependencies is inconvenient.

* Use **shared libraries** when you want smaller executables, memory sharing
  across processes, or when you need to update library code without rebuilding
  every dependent program.

**Static libraries are also better during the development phase** because missing 
references are detected by the linker at build time rather than later at runtime. 

Note the difference between C libraries (binary reuse) and **Arduino libraries** 
(source code reuse - `*.cpp` and `*.h` files).


## References


*Egon Teiniker, 2020-2026, GPL v3.0*    
