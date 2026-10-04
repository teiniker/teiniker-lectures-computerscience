# Listing Directory Contents

`ls` (**l**i**s**t) shows the contents of the current directory:

```
$ ls
Documents  Downloads  Pictures  Music  Desktop
```

With **options**, the letters after a dash, the output becomes more informative:

```
$ ls -l        # long format: permissions, size, date
$ ls -a        # also hidden files (those starting with a dot)
$ ls -h        # human-readable sizes (4.0K instead of 4096)
$ ls -la       # options can be combined
$ ls -lh /etc  # also works for a different directory
```

The output of `ls -l` looks like this:

```
drwxr-xr-x  2 student student 4096 Aug 15 10:23 Documents
-rw-r--r--  1 student student  220 Aug 12 09:01 notes.txt
```

The cryptic column on the far left contains the **permissions**. We will look at
them in the chapter [Permissions and sudo](Permissions.md). For now it is enough to
know: if the line starts with `d`, it is a **d**irectory. If it starts with `-`,
it is a file.

> The command `dir` from Windows does exist on Debian and does almost the same as `ls`.

## Exercise 1

* Open a terminal.
* Determine the current directory.
* List its contents, including hidden files.
* List the contents of `/etc` in long format.

## References

* [Youtube: This Is How To Use LS in Linux & When Not To](https://www.youtube.com/watch?v=slVighH_yP4)
* [Ubuntu Users Wiki: ls](https://wiki.ubuntuusers.de/ls/)

*Nicoletta Kaehling, 2026, GPL v3.0*
