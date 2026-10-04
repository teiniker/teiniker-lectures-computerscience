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

See [Pipes and Redirection](Pipes.md).

```
$ cd ~/computerscience
$ ls /etc > etc-list.txt
$ wc -l etc-list.txt
$ date >> etc-list.txt
$ ls /etc | grep conf | wc -l
```

## Exercise 5

See [Editing Text: nano and vim](Editors.md).

```
$ nano profile.txt
  # type the text, then Ctrl+O, Enter, Ctrl+X
$ cat profile.txt
$ vim profile.txt
  # G (jump to the end), then o for a new line, type the text,
  # Esc, :wq, Enter
$ cat profile.txt
```

## Exercise 6

See [Permissions and sudo](Permissions.md).

```
$ touch test.sh
$ ls -l test.sh        # -rw-r--r--
$ chmod +x test.sh
$ ls -l test.sh        # -rwxr-xr-x
$ chmod go-r test.sh
$ ls -l test.sh        # -rwx--x--x
```

## Exercise 7

See [Processes](Processes.md).

```
$ ps aux | less        # quit with q
$ sleep 300 &
[1] 3812               # the PID is displayed directly
$ jobs                 # alternative: job overview
$ ps aux | grep sleep  # alternative: search for the PID
$ kill 3812
$ ps aux | grep sleep  # the process has disappeared
$ top                  # quit with q
```

## Exercise 8

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
$ ls | wc -l           # counts the entries in the top-level directory
```

*Nicoletta Kaehling, 2026, GPL v3.0*
