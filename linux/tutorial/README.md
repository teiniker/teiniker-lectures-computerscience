# Linux Basics Tutorial

This tutorial covers the basics of working on the Linux command line. It was
written for the Debian VM we use in the course, but most of it works the same
on other Linux distributions.

Every chapter introduces a few commands, and most of them end with a short
exercise. You'll find the solutions in a [separate file](Solutions.md).

## Contents

* [The Virtual Machine: VirtualBox](VirtualBox.md)
* [The Terminal and the Shell](TerminalAndShell.md)
* [Paths and the Working Directory](Paths.md)
* [Listing Directory Contents](ListingFiles.md)
* [Navigating Directories](Navigation.md)
* [Git Workflow](Git.md)
* [The Editor: Visual Studio Code](VSCode.md)
* [Hello Linux World: Compiling and Running](HelloWorld.md)
* [Creating, Copying and Deleting Files](FilesAndDirectories.md)
* [Solutions for the Exercises](Solutions.md)
* [Kahoot Quiz](Kahoot.md)

## Cheat Sheet

```
ORIENTATION
  pwd                     Print the current directory
  ls                      List directory contents
  ls -la                  ... in long format, including hidden files
  cd dir                  Change into a directory
  cd ..                   Go up one level
  cd ~                    Go to the home directory
  cd -                    Go back to the previous directory

FILES
  mkdir name              Create a directory
  mkdir -p name/a/b       Create a chain of directories
  touch file              Create an empty file
  cp source target        Copy
  cp -r source target     Copy a directory
  mv source target        Move / rename
  rm file                 Delete (permanently)
  rm -r dir               Delete a directory

COMPILING
  gcc -o hello hello.c    Compile hello.c into the program hello
  ./hello                 Run a program in the current directory

PROCESSES
  top                     Live view (q to quit)
  Ctrl+C / Ctrl+Z         Abort / suspend

SYSTEM
  man command             Manual page, e.g. man ls, man tree
  clear                   Clear the screen

GIT
  git clone <url>         Download a repository
  git status              Show changes
  git pull                Update
```

## References

* Brian Ward. **How Linux Works**. No Starch Press, 2015
* Heike Jurzik. **Debian GNU/Linux: Das umfassende Handbuch**. Rheinwerk Computing
* Claus Kühnel. **Arduino: Das umfassende Handbuch**. Rheinwerk Computing
* Udo Brandes. **Mikrocontroller ESP32: Das umfassende Handbuch**. Rheinwerk Computing
* [The Linux Command Line](https://linuxcommand.org/tlcl.php) by William Shotts

*Nicoletta Kaehling, 2026, GPL v3.0*
