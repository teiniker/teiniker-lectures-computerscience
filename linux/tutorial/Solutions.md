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

See [Creating, Copying and Deleting Files](FilesAndDirectories.md).

```
$ cd ~
$ mkdir computerscience
$ cd computerscience
$ touch task1.txt task2.txt
$ cp task1.txt task1_backup.txt
$ mkdir backup
$ mv task1_backup.txt backup/
$ ls -l
```

## Exercise 4

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

## Exercise 5

See [Git Workflow](Git.md).

```
$ git --version
$ git config --global user.name "Firstname Lastname"
$ git config --global user.email "mail@example.at"
$ cd ~/computerscience
$ git clone https://github.com/teiniker/teiniker-lectures-computerscience.git
$ cd teiniker-lectures-computerscience
$ ls -a
$ git log --oneline
$ ls | wc -l           # the pipe | passes the output of ls on to wc,
                       # which counts the entries in the top-level directory
```

*Nicoletta Kaehling, 2026, GPL v3.0*
