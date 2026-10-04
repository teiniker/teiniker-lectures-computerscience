# Linux Basics Tutorial

This tutorial covers the basics of working on the Linux command line. It was
written for the Debian VM we use in the course, but most of it works the same
on other Linux distributions.

Every chapter introduces a few commands and ends with a short exercise. You'll
find the solutions in a [separate file](Solutions.md).

## Contents

* [The Terminal](Terminal.md)
* [The Shell](Shell.md)
* [Paths and the Working Directory](Paths.md)
* [Listing Directory Contents](ListingFiles.md)
* [Navigating Directories](Navigation.md)
* [Creating, Copying and Deleting Files](FilesAndDirectories.md)
* [Looking into Files](ViewingFiles.md)
* [Pipes and Redirection](Pipes.md)
* [Editing Text: nano and vim](Editors.md)
* [Permissions and sudo](Permissions.md)
* [Processes](Processes.md)
* [Installing Software: apt](PackageManager.md)
* [Git Workflow](Git.md)
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
  grep "text" file        Search inside a file
  find . -name "*.txt"    Find files

PIPES & REDIRECTION
  command > file          Write output to a file (overwrites!)
  command >> file         Append output to a file
  command1 | command2     Pass output on to the next command
  ls | wc -l              Count entries
  ps aux | grep name      Search for a process
  sort / uniq -c          Sort / count

EDITING
  nano file               Simple editor (Ctrl+O save, Ctrl+X quit)
  vim file                i = insert, Esc, :wq = save and quit,
                          :q! = emergency exit

PERMISSIONS
  ls -l                   Show permissions
  chmod +x file           Make executable
  chmod 644 file          rw-r--r--
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
  sudo apt update         Update the package lists
  sudo apt install pkg    Install a program
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
