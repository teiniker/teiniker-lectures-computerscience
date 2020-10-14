Compiling and Running a Simple C Program
-------------------------------------------------------------------------------

Write the source code
---------------------

$ vi hello.c

 #include <stdio.h>
 
int main()
{
    for(int i=0; i<10; i++)
    {
       printf("Hello world!\n");
    }
    return 0;
}


Compile and run the executable  
------------------------------

$ gcc -std=c99 -g -Wall -o hello hello.c
$ ./hello

Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!


Review all the steps from source code to the executable
-------------------------------------------------------

Run the C pre-processor
$ cpp hello.c _hello.c 

Generate the assembly code
$ gcc -std=c99 -S _hello.c

Run the assembler
$ as -o hello.o _hello.s

Link the object file into an executable
$ gcc -o hello hello.o

Run the executable
$ ./hello 


Use a build tool 
----------------

$ vi Makefile

OBJECTS = 
CFLAGS = -std=c99 -g -Wall  
LDLIBS = 
CC=gcc

all: hello 

hello: hello.c
    $(CC) $(CFLAGS) $(LDLIBS) -o hello hello.c 

clean:
    rm hello 

$ make
$ make clean


Start the executable in the debugger
------------------------------------

$ gdb ./hello
(gdb) list 
1   #include <stdio.h>
2   
3   int main()
4   {
5       for(int i=0; i<10; i++)
6       {
7           printf("Hello world!\n");
8       }   
9       return 0;
10  }

(gdb) disass main
Dump of assembler code for function main:
   0x00000000004004d7 <+0>:	    push   %rbp
   0x00000000004004d8 <+1>:	    mov    %rsp,%rbp
   0x00000000004004db <+4>:	    sub    $0x10,%rsp
   0x00000000004004df <+8>:	    movl   $0x0,-0x4(%rbp)
   0x00000000004004e6 <+15>:	jmp    0x4004f6 <main+31>
   0x00000000004004e8 <+17>:	mov    $0x4005a0,%edi
   0x00000000004004ed <+22>:	callq  0x4003f0 <puts@plt>
   0x00000000004004f2 <+27>:	addl   $0x1,-0x4(%rbp)
   0x00000000004004f6 <+31>:	cmpl   $0x9,-0x4(%rbp)
   0x00000000004004fa <+35>:	jle    0x4004e8 <main+17>
   0x00000000004004fc <+37>:	mov    $0x0,%eax
   0x0000000000400501 <+42>:	leaveq
   0x0000000000400502 <+43>:	retq

(gdb) break main
Breakpoint 1 at 0x4004df: file hello.c, line 5.


(gdb) run
Starting program: /home/student/workspace-2014ws-ims14-SWSecurity/c-helloworld/hello 
(gdb) next
(gdb) next
(gdb) next

(gdb) print i
$1 = 1


(gdb) continue
Continuing.
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!

(gdb) quit


Check for memory leaks
----------------------

$ valgrind ./hello
==7728== Memcheck, a memory error detector
==7728== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7728== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7728== Command: ./hello
==7728==
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
==7728==
==7728== HEAP SUMMARY:
==7728==     in use at exit: 0 bytes in 0 blocks
==7728==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==7728==
==7728== All heap blocks were freed -- no leaks are possible
==7728==
==7728== For counts of detected and suppressed errors, rerun with: -v
==7728== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

