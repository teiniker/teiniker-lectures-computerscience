# Using Assembly Code 

We can build assembly code together with C source code into an executable.

We **create an object file from the assembly file**, with the help of the assembler 
called by gcc.

_Example:_ Assembly file (AT&T syntax)
```
.text
.globl	add
.type	add, @function

add:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	
	popq	%rbp
	ret
```

We use `gcc` to build an object file:
```
$ gcc -std=c17 -Wall -c add.s -o build/add.o
```

Finally, we can link all the object files into an executable:
```
gcc -std=c17 -Wall -o build/main build/main.o build/add.o
```

Note that all these steps will be specified by the `Makefile` of this example.
Thus, to build the whole application just type:

```
$ make
mkdir -p build
gcc -std=c17 -Wall -c main.c -o build/main.o
gcc -std=c17 -Wall -c add.s -o build/add.o
gcc -std=c17 -Wall -o build/main build/main.o build/add.o
build/main
7 + 5 = 12
```

**Intel syntax** can also be used for x86 assembly by replacing the `gcc` with 
the **nasm assembler**.


## References

* [The Process Behind Compiling and Executing C Code](https://vitaminac.github.io/Compiling-Executing-C/)

* [NASM Documentation](https://www.nasm.us/docs.php)

*Egon Teiniker, 2020-2023, GPL v3.0*