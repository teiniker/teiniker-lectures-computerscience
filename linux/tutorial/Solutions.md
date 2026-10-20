# Solutions for the Exercises

## Exercise 1

See [Listing Directory Contents](ListingFiles.md).

```
$ pwd
$ ls -a
$ ls -l /etc
```

## Exercise 2

See [Navigating Directories](Navigation.md).

```
$ cd ~
$ cd /usr/share
$ ls
$ cd ..
$ pwd            # -> /usr
$ cd ~           # or simply: cd
```

## Exercise 3

See [Git Workflow](Git.md).

```
$ git --version
$ git config --global user.name "Firstname Lastname"
$ git config --global user.email "mail@example.at"
$ mkdir ~/computerscience
$ cd ~/computerscience
$ git clone https://github.com/teiniker/teiniker-lectures-computerscience.git
$ cd teiniker-lectures-computerscience
$ ls -a
$ git log --oneline
$ ls | wc -l           # the pipe | passes the output of ls on to wc,
                       # which counts the entries in the top-level directory
```

## Exercise 4

See [Hello Linux World: Compiling and Running](HelloWorld.md).

```
$ cd ~/computerscience/teiniker-lectures-computerscience/linux/tutorial
$ gcc -o hello-linux hello-linux.c
$ ./hello-linux
$ code .
  # open hello-linux.c, change the text inside the quotes of the
  # first printf, Ctrl+S
$ gcc -o hello-linux hello-linux.c
$ ./hello-linux        # shows the new text
  # in VS Code: delete a closing parenthesis, Ctrl+S
$ gcc -o hello-linux hello-linux.c
  # hello-linux.c:<line>:<column>: error: expected ')' before ...
  # the compiler names the line where it noticed the missing parenthesis
  # in VS Code: Ctrl+G, type the line number, put the parenthesis back, Ctrl+S
$ gcc -o hello-linux hello-linux.c
  # in VS Code: click left of the line number of "return 0;",
  # press F5; the output appears in the Terminal panel
```

## Exercise 5

See [Creating, Copying and Deleting Files](FilesAndDirectories.md).

```
$ cd ~
$ mkdir computerscience    # already exists if you did Exercise 3
$ cd computerscience
$ touch task1.txt task2.txt
$ cp task1.txt task1_backup.txt
$ mkdir backup
$ mv task1_backup.txt backup/
$ ls -l
```

## Exercise 6

See [Editing Text: nano](Editors.md).

```
$ nano profile.txt
  # type the three lines, then Ctrl+O, Enter, Ctrl+X
$ cat profile.txt
$ nano profile.txt
  # move to the end with the arrow keys, type the fourth line,
  # Ctrl+O, Enter, Ctrl+X
$ nano -l profile.txt
  # Ctrl+W, type the word, Enter (cursor jumps to line 2),
  # Ctrl+K cuts the line, Ctrl+O, Enter, Ctrl+X
$ cat profile.txt
```

## Exercise 7

See [File Permissions](Permissions.md).

```
$ cd ~/computerscience
$ echo "Hello" > readme.txt
$ ls -l readme.txt     # -rw-r--r--
$ chmod -w readme.txt
$ ls -l readme.txt     # -r--r--r--
$ nano readme.txt      # nano shows [ File 'readme.txt' is unwritable ]
$ chmod +w readme.txt
$ nano readme.txt      # change the text, Ctrl+O, Enter, Ctrl+X
$ cd teiniker-lectures-computerscience/linux/tutorial
$ chmod -x hello-linux
$ ./hello-linux        # bash: ./hello-linux: Permission denied
$ chmod 755 hello-linux
$ ./hello-linux
  # rwxr-x--- = 7 5 0 -> chmod 750
```

*Nicoletta Kaehling, 2026, GPL v3.0*
