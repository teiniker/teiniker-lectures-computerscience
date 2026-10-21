# Hello Linux World: Compiling and Running

So far we have only worked with text files. Now we turn a text file into a
running program. The file [`hello-linux.c`](hello-linux.c) in this directory is
a small C program that prints a greeting and Tux, the Linux mascot. Change into
the tutorial directory of the cloned repository and have a look at it:

```
$ cd ~/computerscience/teiniker-lectures-computerscience/linux/tutorial
$ cat hello-linux.c
```

The source code is readable by humans, but not by the computer. The
**compiler** translates it into machine code, an **executable** file. On Linux
the standard C compiler is **`gcc`** (GNU Compiler Collection).

## Compiling

```
$ gcc -o hello-linux hello-linux.c
```

`gcc` takes the source file as an argument. The option `-o` (**o**utput) gives
the name of the executable to create. Without `-o`, the result would be called
`a.out`.

If everything went well, `gcc` prints nothing at all. A new file has appeared:

```
$ ls -l
-rwxr-xr-x 1 student student 16024 Oct 20 10:15 hello-linux
-rw-r--r-- 1 student student   524 Oct 20 10:14 hello-linux.c
```

`hello-linux.c` is the source code, `hello-linux` is the program. The program is
much larger than its source, because it contains machine code and everything
needed to start it. Note the `x` in its permissions, which we look at in the
chapter [File Permissions](Permissions.md).

## Running

A program in the current directory is started with `./` in front of its name:

```
$ ./hello-linux
Hello in the Linux World!

       .--.
      |o_o |
      |:_/ |
     //   \ \
    (|     | )
   /'\_   _/`\
   \___)=(___/

Welcome to Linux! 
```

Why `./`? The shell looks for commands such as `ls` or `gcc` only in a list of
system directories (the variable `PATH`, see [The Terminal and the Shell](TerminalAndShell.md)), never in
the current directory. `./hello-linux` says explicitly: *the file
`hello-linux` right here*. Typing just `hello-linux` gives
`command not found`.

> Source files are usually committed to Git, compiled programs are not. They
> can be recreated at any time, and they differ from machine to machine.

## Compiler Errors

Compilers are picky. Open `hello-linux.c` in VS Code, remove the semicolon at
the end of the first `printf` line and save the file. Compiling again now
fails:

```
$ gcc -o hello-linux hello-linux.c
hello-linux.c: In function 'main':
hello-linux.c:10:44: error: expected ';' before 'printf'
```

The message names the **file**, the **line** (`10`) and the **column** (`44`),
followed by what the compiler expected. The line number is the important part:
in VS Code, `[ctrl] + [g]` jumps to a line number, and the editor `nano`
from a later chapter can open a file directly at a line (see
[Editing Text: nano](Editors.md)). Put the semicolon back and compile again.

Note that the old `hello-linux` executable survives a failed compilation. If a
program behaves as if a change had no effect, check whether the last compile
actually succeeded.

## The Same in VS Code

The same steps work in [Visual Studio Code](VSCode.md), provided the folder
`.vscode` has been copied from the template as described there.

1. Open the repository with `code .` and the file `hello-linux.c` from the
   Explorer.
2. **Compile** with `[ctrl] + [shift] + [b]`. The build task runs `gcc -g` and
   shows its output in the Terminal panel; errors also appear underlined in the
   editor and in the **Problems** panel.
3. Click left of a line number to set a red **breakpoint**, for example on the
   first `printf`.
4. **Debug** with `F5`. The program starts and stops at the breakpoint. Step
   through it line by line with `F10`, and watch the output appear in the
   Terminal panel. Continue with `F5` or stop with `[shift] + [F5]`.

The option `-g` in the build task adds debugging information so that `gdb`
knows which machine instruction belongs to which source line. The executable
built on the command line without `-g` runs the same, but cannot be debugged
line by line.

## Exercise 4

* Change into the tutorial directory and compile `hello-linux.c` into a program
  called `hello-linux`. Run it.
* Change the greeting in the first `printf` to your own text in VS Code,
  compile again and run the program. Is the new text shown?
* Remove a closing parenthesis `)` somewhere in the file, compile, and read the
  error message. Which line does the compiler point to? Fix the error.
* Open the file in VS Code, set a breakpoint on the line with `return 0;` and
  start the debugger. In which panel does the output appear?

## References

* [GCC, the GNU Compiler Collection](https://gcc.gnu.org/)
* [A Simple C Program](../../programming-c/c-basics/introduction/hello-world/README.md) (the structure of `main()`, directives and statements)
* [Visual Studio Code: Debug C++ in Visual Studio Code](https://code.visualstudio.com/docs/cpp/cpp-debug)

*Nicoletta Kaehling, 2026, GPL v3.0*
