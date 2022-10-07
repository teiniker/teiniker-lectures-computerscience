# Computer Language Processing

The following examples show the differences between the various language processing approaches.

## Interpreter 

Interpreters operate directly on a text source file by **scanning the source code and processing it line by line** as string data.

_Example_: hello.py
```Python
name = 'Eggenberg'
print(f'Hello {name}!')
```

Run the source file:
```
$ python3 hello.py
``` 

We can also execute the script interactively line by line:
```
$ python3
Python 3.9.2 (default, Feb 28 2021, 17:03:44) 

>>> name = 'Eggeberg'
>>> print(name)
Eggeberg
>>> print(f'Hello {name}!')
Hello Eggeberg!

>>> quit()
``` 

## Compiler

A compiler **translates a source program** in text form **into executable machine code**. 

_Example_: hello.c
```C
#include <stdio.h>

int main(void)
{
    char *name = "Eggenberg";
    printf("Hello %s!\n", name);
    return 0;
}
```

Compile and run the source file:
```
$ gcc -o hello hello.c 
$ ./hello 
``` 

The C compiler creates an executable containing CPU specific assembly commands.
```
$ gdb ./hello

(gdb) disass main
Dump of assembler code for function main:
   0x0000000000001135 <+0>:     push   rbp
   0x0000000000001136 <+1>:     mov    rbp,rsp
   0x0000000000001139 <+4>:     sub    rsp,0x10
   0x000000000000113d <+8>:     lea    rax,[rip+0xec0]        # 0x2004
   0x0000000000001144 <+15>:    mov    QWORD PTR [rbp-0x8],rax
   0x0000000000001148 <+19>:    mov    rax,QWORD PTR [rbp-0x8]
   0x000000000000114c <+23>:    mov    rsi,rax
   0x000000000000114f <+26>:    lea    rdi,[rip+0xeb8]        # 0x200e
   0x0000000000001156 <+33>:    mov    eax,0x0
   0x000000000000115b <+38>:    call   0x1030 <printf@plt>
   0x0000000000001160 <+43>:    mov    eax,0x0
   0x0000000000001165 <+48>:    leave  
   0x0000000000001166 <+49>:    ret    
End of assembler dump.

(gdb) Quit
```

## Incremental Compiler 

An incremental compilers are a cross between a compiler and an interpreter. 
They operate like an interpreter in that they do not compile the source file directly into machine code. 
Instead, they **translate the source code into an intermediate form (bytecode)** which is the machine 
code for a virtual machine language.


_Example_: Hello.java
```Java
public class Hello
{
    public static void main(String... args)
    {
        String name = "Eggenberg";
        System.out.println("Hello " + name + "!");
    }
}
```

Compile and run the source file:
```
$ javac Hello.java -d classes
$ java -cp classes/ Hello 
``` 

The Java compiler reads the source file and turns it into a `*.class` file which contains **bytecode**.
```
$ javap -c classes/Hello.class 
Compiled from "Hello.java"
public class Hello {
  public Hello();
    Code:
       0: aload_0
       1: invokespecial #1                  // Method java/lang/Object."<init>":()V
       4: return

  public static void main(java.lang.String...);
    Code:
       0: ldc           #2                  // String Eggenberg
       2: astore_1
       3: getstatic     #3                  // Field java/lang/System.out:Ljava/io/PrintStream;
       6: aload_1
       7: invokedynamic #4,  0              // InvokeDynamic #0:makeConcatWithConstants:(Ljava/lang/String;)Ljava/lang/String;
      12: invokevirtual #5                  // Method java/io/PrintStream.println:(Ljava/lang/String;)V
      15: return
}
```

Using the **Java Virtual Machine (JVM)** the bytecode will be interpreted and executed.


## References
Randall Hyde. **Writing Great Code, Volume 2: Thinking Low Level, Writing High Level**. No Starch Press, 2020

 
*Egon Teiniker, 2020-2022, GPL v3.0* 
