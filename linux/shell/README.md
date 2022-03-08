# Linux Command Line

## The Bourne Shell

A **shell** is a program that runs commands which the user enter.

The shell also serves as a small **programming environment**.
Many important parts of the system are **shell scripts** - text files that contain a sequence of shell commands.

There are many different Unix shells, but all derive several of their fetures from the **Bourne shell** 
in order to function correctly.
Linux uses an enhanced version of the Bourne shell called **bash** or the **Bourne-again shell**.
The bash shell is the default shell on most Linux distributions. 


## Standard Input and Standard Output 
Unix processes use **I/O files** to read and write data.

Programs such as `ls` actually send their results to a special file called **standard output** (`stdout`)
and their status messages to another file called **standard error** (`stderr`).
By default, both stdout and stderr are linked to the screen and not saved into a disk file.

In addition, many programs take input from a file called **standard input** (`stdin`), which is, by default, attached to the keyboard.


## Basic Commands


## Navigating Directories


## Intermediate Commands


## Hidden Files


## Environment Variables 


## Listing and Manipulating Processes 

## File Modes and Permissions

## Archiving and Compressing Files

## Running Commands as the Superuser



## References

* Brian Ward. **How Linux Works**. No Starch Press, 2015
    * Chapter 2: Basic Commands and Directory Hierarchy
    

*Egon Teiniker, 2020-2022, GPL v3.0*    
