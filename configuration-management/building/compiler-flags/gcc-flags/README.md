# Using gcc Flags

GCC (GNU Compiler Collection) compiler flags are used to specify options and settings that **control the behavior of the GCC compiler during the compilation process**. 
These flags can influence various stages of the compilation process, including preprocessing, compiling, linking, and debugging. Here are some examples of what GCC compiler flags can do:

* **Standard**: The `-std` flag is used to specify the version of the C or C++ standard that the code should conform to. For example, `-std=c99` would set the C standard to C99.

* **Warning Messages**: Flags like `-Wall`, `-Wextra`, and `-Werror` are used to control the generation of warning messages. These flags can help identify potential issues in the source code that are not necessarily syntax errors.

* **Debugging**: The `-g` flag is used to include debugging information in the compiled program. This information is useful when debugging the program with a tool like GDB.

* **Compiling Only**: The `-c` flag in GCC is used to tell the compiler to compile and assemble the code, but not to link it.  The output is an object file for each source file we are compiling. These object files can then be linked together to create the final executable.

* **Output File**: The `-o` flag is used to specify the name of the output file. For example, `gcc -o myprogram myprogram.c` would compile `myprogram.c` and output a binary file named `myprogram`.

* **Include Paths**: The `-I` flag is used to add additional directories to the list of directories that GCC will search for header files.

* **Linking**: Flags like `-l` (lowercase L) and `-L` are used to control the linking process. For example, `-lmylib` would link against the library `libmylib.a` or `libmylib.so`, and `-L/my/path` would add `/my/path` to the list of paths that the linker searches for libraries.

* **Optimization**: Flags like `-O1`, `-O2`, and `-O3` are used to control the optimization level of the compilation. These flags can help improve the performance
and/or reduce the size of the compiled code.

* **Defining Macros**: The `-D` flag is used to define macros. For example, `-DDEBUG` would have the same effect as adding `#define DEBUG` at the top of your source files.

There are many more GCC compiler flags that can be used to control various aspects 
of the compilation process. The appropriate flags to use depend on the specific 
requirements of your project.

## Supported C Versions  

The **gcc 10.2.1** compiler, released in August 2020, supports various versions of the 
C programming language up to the C17 standard. 

Here is a breakdown of the supported C versions by gcc 10.2.1:
* **C89/C90**: Fully supported by **default**.
* **C99**: Fully supported with the `-std=c99` flag.
* **C11**: Fully supported with the `-std=c11` flag.
* **C17**: Partially supported with the `-std=c17` flag. 
    Some features might not be fully implemented or might require additional flags.

## References

* [Linux manual page: gcc](https://man7.org/linux/man-pages/man1/gcc.1.html)


*Egon Teiniker, 2020-2026, GPL v3.0*    



