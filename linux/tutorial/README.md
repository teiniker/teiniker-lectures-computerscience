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
* [Looking into Files](ViewingFiles.md)
* [Editing Text: nano](Editors.md)
* [File Permissions](Permissions.md)
* [Solutions for the Exercises](Solutions.md)

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
  mkdir -p a/b/c          Create a chain of directories
  touch file              Create an empty file
  cp source target        Copy
  cp -r source target     Copy a directory
  mv source target        Move / rename
  rm file                 Delete (permanently)
  rm -r dir               Delete a directory

VIEWING & SEARCHING
  cat file                Print the contents
  less file               Page through a file (q to quit)
  head / tail file        First / last lines
  wc -l file              Count lines
  grep "text" file        Search inside a file
  find . -name "*.txt"    Find files

EDITING
  nano file               Edit a file (Ctrl+O save, Ctrl+X quit)
  nano -l file            ... with line numbers
  sudo nano file          Edit a file owned by root
  code .                  Open the current directory in VS Code

COMPILING
  gcc -o prog prog.c      Compile prog.c into the program prog
  gcc -g -o prog prog.c   ... with debugging information for gdb
  ./prog                  Run a program in the current directory

PERMISSIONS
  ls -l                   Show permissions
  chmod +x file           Make executable
  chmod -x file           Remove the execute permission
  chmod 644 file          rw-r--r--
  chmod 755 file          rwxr-xr-x
  sudo command            Run as administrator

PROCESSES
  ps aux                  All processes
  top / htop              Live view (q to quit)
  command &               Start in the background
  jobs / fg               Show / bring back background jobs
  kill PID                Terminate a process
  kill -9 PID             Force termination
  Ctrl+C / Ctrl+Z         Abort / suspend

SYSTEM
  man command             Manual page
  clear                   Clear the screen

GIT
  git --version           Check the version
  git config --global user.name "Name"
  git clone <url>         Download a repository
  git status              Show changes
  git pull                Update
  git add .               Stage changes
  git commit -m "Text"    Commit
  git push                Upload
```

## References

* Brian Ward. **How Linux Works**. No Starch Press, 2015
* Heike Jurzik. **Debian GNU/Linux: Das umfassende Handbuch**. Rheinwerk Computing
* Claus Kühnel. **Arduino: Das umfassende Handbuch**. Rheinwerk Computing
* Udo Brandes. **Mikrocontroller ESP32: Das umfassende Handbuch**. Rheinwerk Computing
* [The Linux Command Line](https://linuxcommand.org/tlcl.php) by William Shotts

*Nicoletta Kaehling, 2026, GPL v3.0*
