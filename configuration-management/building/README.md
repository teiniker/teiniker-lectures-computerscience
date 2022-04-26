# Build Automation

A **build process** is a series of steps that transforms our creative artifacts into deliverable software.

Having an automated build process lets us produce our software at the **push of a button**.

We need builds which are:
* **Complete** builds are made from scratch using only the steps specified in the build script.
    
* **Repeatable** The key to producing repeatable builds is to store the build file and all the build inputs 
    in a version control system.

* **Informative** builds give valuable information to us so that we always know the health of our software. 
    If the build fails, we want to know quickly why.
    
 * **Schedulable** Since everything that goes into making a build is available in the version control system, 
    a computer can easily generate fresh builds many times per day or on demand whenever we want 
    (e.g. nightly builds, continuous integration).
 
 * **Portable** Running a build should not be dependent on any particular IDE, a machine’s IP address, 
    or the directory from which it’s run.



## GNU make

The program **make** is designed to aid the programmer in compiling and linking programs which consists of many 
source files.

The program `make` allows us to specify the dependencies between source files 
and the commands that generates the final program in a so called `Makefile`.

The `Makefile` contains the following sections:
* **Comments**: Any line starting with a hash mark `#` is a comment.
* **Macros**: A macro has the format `name = value` where `name` is any valid identifier 
    and `value` is the text that will be substituted whenever make sees `$(name)`.
* **Explicit rules** tell make what commands are needed to create the program.
* Default rules

Explicit rules can take several forms, the most common is:
```
target: source [source2] [source3] ...
    command
    [command2]
    [command3]
    ...
```
where **target** is the name of a file to create.

It is created out of the source file **source**. If the target is created out of several files, they
are all listed.
This list should include any header files included by the source file as well.

The **command** that generates the target is specified on the next line.
Sometimes we need more than one commend to create the target.
Commands are listed one per line.
**Each is indented by a tab**.

_Example_: Makefile to compile three object files and link them into an executable
```
CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../../unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

linked_list.o: linked_list.h linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c -o build/linked_list.o

linked_list_test.o: linked_list_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c linked_list_test.c -o build/linked_list_test.o

test: init unity.o linked_list.o linked_list_test.o
	$(CC) $(CFLAGS) build/unity.o build/linked_list.o build/linked_list_test.o -o build/linked_list_test
	build/linked_list_test

clean:
	rm -rf build/
```

When we call `make` to execute the `Makefile`, we get the following output:
```
$ makemkdir -p build
gcc -std=c99 -g -Wall   -c ../../unity/unity.c -o build/unity.o
gcc -std=c99 -g -Wall   -c linked_list.c -o build/linked_list.o
gcc -std=c99 -g -Wall   -I ../../unity -c linked_list_test.c -o build/linked_list_test.o
gcc -std=c99 -g -Wall   build/unity.o build/linked_list.o build/linked_list_test.o -o build/linked_list_test
build/linked_list_test
linked_list_test.c:65:test_size:PASS
linked_list_test.c:66:test_get:PASS
linked_list_test.c:67:test_find:PASS
linked_list_test.c:68:test_insert:PASS
linked_list_test.c:69:test_remove:PASS
-----------------------
5 Tests 0 Failures 0 Ignored 
OK
```
Note that we compile the source files (`*.h` and `*.c`) into **object files** (`*.o`), link the together 
into an **executable**, and run that application.

In the given example, we use the **unity testing framework** to implement automated test cases.
In general, two **diffent executables** can be built: 
* One for running **test cases** (only used during development)
* A second representing the **software release** (shipped to the customer)

All **build artifacts** are stored in a temporary `build/` directory. 
```
build
├── linked_list.o
├── linked_list_test
├── linked_list_test.o
└── unity.o
```

Executing the `clean` target removes this directory from our project again:
```
$ make clean
rm -rf build/
```

To see all commands which will be executed by make, we can use the **-n flag** 
to print out all build steps **without executing them**:
```
$ make -n
mkdir -p build
gcc -std=c99 -g -Wall   -c ../../unity/unity.c -o build/unity.o
gcc -std=c99 -g -Wall   -c linked_list.c -o build/linked_list.o
gcc -std=c99 -g -Wall   -I ../../unity -c linked_list_test.c -o build/linked_list_test.o
gcc -std=c99 -g -Wall   build/unity.o build/linked_list.o build/linked_list_test.o -o build/linked_list_test
build/linked_list_test
```

## Debugging in VS Code

To debug an executable which we have built using `make`, we have to change the `launch.json`
file: 
* **Remove the "preLaunchTask" element** to stop automatic compiling before the debugging:

  Remove the following line:
  ```
    "preLaunchTask": "C/C++: gcc build active file",
  ```  

* **Change the "program" element** to point to the executable created by make within the `build` folder:

  Change from:  
  ```
    "program": "${fileDirname}/${fileBasenameNoExtension}", 
  ```  
  to:	 
  ```
    "program": "${fileDirname}/build/${fileBasenameNoExtension}",    
  ```    

Note that we have to open the `main.c` file before we start the debugger because the `${fileBasenameNoExtension}`
variable contains the current opened file's basename.

Here the final `launch.json` file:
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc - Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/build/${fileBasenameNoExtension}", //!! change
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
//!! remove "preLaunchTask": "C/C++: gcc build active file",
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}
```

## References
* [GNU Make](https://www.gnu.org/software/make/)

* [GNU Make Manual](https://www.gnu.org/software/make/manual/)

* Robert Mecklenburg. Managing Projects with GNU Make. OReilly, 2005



*Egon Teiniker, 2020-2021, GPL v3.0* 
