# Name Mangling

**C++ does name mangling**, it encodes a function's parameter types 
(and namespace/class) into the symbol name in the compiled object file, 
because C++ supports overloading and the linker needs unique symbol 
names to distinguish `foo(int)` from `foo(double)`.

**C doesn't do this**. A C compiler emits the symbol exactly as the function 
is named: `foo` stays `foo`.

_Example:_ Call a C function from C++ code

If we have:

```c
// mylib.h (C header file) 
int add(int a, int b);
```

and we try to call it from C++ without any special handling, the C++ 
compiler mangles the call site to look for something like `_Z3addii` (GCC-style 
mangling), but the C compiler that built `mylib.c` only emitted `add`. 

Linker error: `undefined reference`.


## Typical Usage of `extern "C"`

`extern "C"` tells the C++ compiler "don't mangle these names, use 
C linkage rules instead."

**Wrapping a C header for use in C++:**

```cpp
extern "C" {
    #include "mylib.h"
}
```

**Inside a header meant to be used from both C and C++** (very common 
pattern, this is what we will see in basically every C library that wants 
C++ compatibility):

```c
#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);
void process(const char* data);

#ifdef __cplusplus
}
#endif
```

`__cplusplus` is automatically defined by C++ compilers, so when a C compiler 
includes this header, it just sees the plain declarations. When a C++ compiler 
includes it, it wraps them in `extern "C"`.

**Single declaration, no braces needed:**

```cpp
extern "C" int add(int a, int b);
```

## What `extern "C"` does *not* do

- It doesn't change argument-passing conventions or calling conventions on 
    its own (that's a separate, platform-specific concern, though in practice 
    on most platforms C and C++ use the same calling convention for the same ABI).

- It doesn't make C++-only features work. We can't put a class, template, default 
    argument, or overloaded function inside `extern "C"`. Overloading is fundamentally incompatible with C linkage, since C has no concept of multiple functions sharing 
    a name.

- It doesn't affect how the function body is compiled, only how its **name is exposed 
    for linking**.


## References

* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019 

*Egon Teiniker, 2020-2026, GPL v3.0*