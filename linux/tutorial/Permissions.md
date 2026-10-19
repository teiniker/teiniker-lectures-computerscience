# File Permissions

Linux is a multi-user system: several people, and many system services, share
the same file system. **Permissions** decide who may read, change or run a
file. We have seen them already in the first column of `ls -l`; now we learn
to read and change them. The two files from the chapter
[Hello Linux World](HelloWorld.md) are a good example:

```
$ ls -l hello-linux hello-linux.c
-rwxr-xr-x 1 student student 16024 Oct 20 10:15 hello-linux
-rw-r--r-- 1 student student   524 Oct 20 10:14 hello-linux.c
```

## Reading the Permission Column

The first column consists of ten characters. The first one is the **file
type**: `-` for a regular file, `d` for a directory. The remaining nine are
three groups of three letters:

| Position | Applies to | Example `hello-linux` | Example `hello-linux.c` |
|---|---|---|---|
| 2-4 | **user** (the owner) | `rwx` | `rw-` |
| 5-7 | **group** | `r-x` | `r--` |
| 8-10 | **others** (everybody else) | `r-x` | `r--` |

Each group lists the same three permissions in the same order. A dash means
the permission is missing:

| Letter | Permission | For a file | For a directory |
|---|---|---|---|
| `r` | **r**ead | Show the contents (`cat`, `less`) | List the contents (`ls`) |
| `w` | **w**rite | Change or overwrite the file | Create, rename and delete files inside |
| `x` | e**x**ecute | Run the file as a program | Enter the directory (`cd`) |

The third and fourth columns of `ls -l` show the **owner** and the **group** of
the file, here both `student`. The owner is the user who created the file.

So `hello-linux.c` can be read by everybody, but only `student` may change it.
`hello-linux` is additionally **executable**, which is exactly what `gcc` set
up when it created the program. That `x` is the reason why `./hello-linux`
works at all.

## Changing Permissions: chmod

Permissions are changed with **`chmod`** (**ch**ange **mod**e). The simplest
form adds (`+`) or removes (`-`) a permission for everybody:

```
$ chmod -x hello-linux       # remove the execute permission
$ ./hello-linux
bash: ./hello-linux: Permission denied
$ chmod +x hello-linux       # ... and give it back
$ ./hello-linux
Hello in the Linux World!
```

The program itself has not changed at all. The shell simply refuses to start a
file that is not marked executable, which is why a freshly written shell
script, for example, has to be made executable once with `chmod +x`.

To address only one of the three groups, put `u`, `g` or `o` in front:

```
$ chmod u+x script.sh        # only the owner may execute
$ chmod go-w notes.txt       # group and others may no longer write
$ chmod o-r secret.txt       # others may no longer read
```

Permissions are often written as **three digits** as well, one per group, where
`r` = 4, `w` = 2 and `x` = 1 are added up:

```
$ chmod 644 notes.txt        # rw-r--r--   the usual setting for text files
$ chmod 755 hello-linux      # rwxr-xr-x   the usual setting for programs
$ chmod 600 secret.txt       # rw-------   only the owner
```

Both notations do the same thing; the numeric one is common in instructions
and configuration guides, so it is worth recognising it.

> **Files owned by root.** Files outside the home directory, for example in
> `/etc`, belong to the user `root`. Only the owner (or `root`) may change
> permissions and content, which is why such files are edited with
> `sudo nano file` (see [Editing Text: nano](Editors.md)). Changing permissions
> of system files is rarely necessary and can break the system; leave them as
> they are.

Ownership itself is changed with `chown`, and there are a few further
permission bits. Both are described on the page
[File Permissions](../filesystem/Permissions.md) in the Linux section of the
repository.

## Exercise 7

* In the directory `computerscience`, create a file `readme.txt` with one line
  of text, and look at its permissions with `ls -l`.
* Remove the write permission for everybody. Open the file with `nano`, change
  something and try to save. What does nano report?
* Give the write permission back and save the change.
* Remove the execute permission from your compiled `hello-linux` program and
  try to run it. Then restore it using the numeric notation.
* Which three-digit number corresponds to `rwxr-x---`?

## References

* [William Shotts: The Linux Command Line, Chapter 9 - Permissions](https://linuxcommand.org/lc3_lts0090.php)
* [Ubuntu Users Wiki: Rechte](https://wiki.ubuntuusers.de/Rechte/)
* `man chmod`

*Nicoletta Kaehling, 2026, GPL v3.0*
