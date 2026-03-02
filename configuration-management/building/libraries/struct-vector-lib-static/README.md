# Static Libraries

A static library is just an archive of `.o` files.

At link time, the **linker pulls the required object files** from the archive and
**copies their code directly into the final executable**. The result is a **single,
self-contained binary** that does not need the library file at runtime. 

This means:

* The executable is larger (library code is embedded).

* The binary is easy to deploy (no runtime dependency on the library file).

* Updates to the library require relinking the executable.


## Create a Static Library

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

* **ar** is the archive tool for static (`*.a`) libraries.
  - `-c` creates the archive if it doesn’t exist.
  - `-v` verbose output (lists files as they’re added).
  - `-q` quick append (adds build/vector.o to the end without full index rebuild).

After these steps we have a library (`libvector.a`) in the `lib/` folder and 
the corresponding header file (`vector.h`) in the `include/` folder. 


## Use a Static Library

We use the created static library to build our executable:

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

    
## References

* K. N. King. **C Programming, A Modern Approach**. W. W. Norton & Company, inc. 2nd Edition 2008
* Robert C. Seacord. **Effective C**. No Starch Press, 2020
* Steve Oualline. **Practical C Programming**. O'REILLY 3rd Edition 1997


*Egon Teiniker, 2020-2026, GPL v3.0*    
