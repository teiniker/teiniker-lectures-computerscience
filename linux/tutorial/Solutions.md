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
$ mkdir ~/IP-CS
$ cd ~/IP-CS
$ git clone https://github.com/teiniker/teiniker-lectures-computerscience.git
$ cd teiniker-lectures-computerscience
$ ls -a
$ git status
```

## Exercise 4

See [Hello Linux World: Compiling and Running](HelloWorld.md).

```
$ cd ~/IP-CS/teiniker-lectures-computerscience/linux/tutorial
$ gcc -o hello-linux hello-linux.c
$ ./hello-linux
$ code .
  # open hello-linux.c, change the text inside the quotes of the
  # first printf, Ctrl+S
$ gcc -o hello-linux hello-linux.c
$ ./hello-linux        # shows the new text
  # in VS Code: click left of the line number of "return 0;",
  # press F5; the output appears in the Terminal panel
```

## Exercise 5

See [Creating, Copying and Deleting Files](FilesAndDirectories.md).

```
$ cd ~
$ mkdir IP-CS              # already exists if you did Exercise 3
$ cd IP-CS
$ touch task1.txt task2.txt
$ cp task1.txt task1_backup.txt
$ mkdir backup
$ mv task1_backup.txt backup/
$ ls -l
```

*Nicoletta Kaehling, 2026, GPL v3.0*
