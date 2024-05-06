# Command Line Parameters in C 

Command line parameters in C programming allow users to pass arguments 
to a program when it's executed from the command line interface (CLI). 

These parameters provide a way for users to **customize the behavior 
of the program** without modifying its source code.

The **main() function** is the entry point of a program, and it can 
accept two parameters:

* **argc** stands for "argument count" and represents the number of 
    command line parameters passed to the program, including the 
    name of the program itself.

* **argv** stands for "argument vector" and is an array of strings 
    `char* argv[]` or `char **` that contains the actual command line 
    parameters.    

_Example:_ `main()` function with command line parameters
```C
int main(int argc, char **argv)
{
    //...
}
```

Each element of the `argv` array represents a command line parameter, 
where `argv[0]` contains the name of the program, and subsequent elements 
contain the additional parameters passed by the user.

_Example:_ Pass filename to a C application
```C
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;   
    }
    printf("Open file %s...\n", argv[1]);
    //...
}
```

If the program is called with the wrong numbers of parameters, it prints a usage 
message to `stderr` and returns a non-zero value to indicate an error condition. 
Printing error messages to `stderr` is a good practice as it keeps error output 
separate from normal program output.

Otherwise, it proceeds with processing the parameters as usual.


## References

* [YouTube (Jacob Sorber): Getting Command-Line Arguments in C](https://youtu.be/6Dk8s0F2gow?si=Wk9dB6pCpx97_Wmr)

*Egon Teiniker, 2020-2024, GPL v3.0* 

