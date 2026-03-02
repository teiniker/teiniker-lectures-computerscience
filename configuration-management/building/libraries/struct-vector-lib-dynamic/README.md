# Shared Libraries

This example shows how to build and use a shared library (`.so`) in C.
The project provides a small vector API in `vector.h`/`vector.c` and 
a client program in `main.c`.

## Static Library vs. Dynamic Library

A static library (`.a`) is copied into the executable at link time.
The executable becomes larger, but it has no runtime dependency on 
that library file.

A dynamic library (`.so`) is loaded by the dynamic linker at runtime.
The executable is smaller and multiple programs can share one library 
file in memory.
The tradeoff is that the `.so` must be available when the program starts.

## Create a Shared Library

Important parts in the `Makefile`:

* `build/vector.o` is compiled with `-fPIC`:
  - **Position Independent Code (PIC)** is required for shared libraries 
    on typical Linux systems.

* Target `lib` creates `build/libvector.so`:
  - `gcc -shared -Wl,-soname,libvector.so -o build/libvector.so build/vector.o`

  - `-shared` tells the linker to produce a shared object.
  
  - `-Wl,-soname,libvector.so` is passed from `gcc` to the linker (`ld`):
    - `-Wl,...` means: forward comma-separated options to the linker.

    - `-soname libvector.so` sets the ELF `DT_SONAME` entry.

    - This SONAME is the runtime identity of the library and is stored in
      dependent executables as the needed library name (`DT_NEEDED`).
    
    - At runtime, the dynamic loader searches for this SONAME in library paths
      (for example via `LD_LIBRARY_PATH`).

- Target `install` copies artifacts to local folders:
  - `lib/libvector.so`
  - `include/vector.h`

Build and run everything:

```bash
$ make clean
$ make
```

## Use a Shared Library

The executable is linked against `libvector.so` with:

```bash
$ gcc ... -L./lib -lvector
```

* `-L./lib` adds the local `lib/` directory to the linker search path.

* `-lvector` links against `libvector.so` (or `libvector.a` if only static exists).

At runtime, the loader must find `libvector.so`. In this example this is done with
`LD_LIBRARY_PATH` using the export variant:

```bash
$ export LD_LIBRARY_PATH=./lib
$ ./build/main
```

`export LD_LIBRARY_PATH=./lib` adds the local `lib/` directory to the runtime
library search path for the current shell session.


## Static vs. Shared Libraries

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