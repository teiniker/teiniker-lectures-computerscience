# Working with the File System

## Basic Commands

* **ls** Lists the contents of a directory.  The default is the current directory.
    Use `ls -l` for a detailed (long) listing and `ls -a` to also list hidden files (dot files).
    There is an alias for `ls -l` called `ll`.

* **cp** Copies files. 
    `cp file1 file2` means copy `file1` to `file2`. To copy a number of files to a directory named `dir`, use 
    `cp file1 ... fileN dir`    

* **mv** Moves files. In its simplest form, it renames a file. For example, `mv file1 file2` renames `file1` to `file2`.
    We can also use `mv` to move  a number of files to a different directory: `mv file1 ... fileN dir`

* **touch** Creates a file. If the file already exists, `touch` only updates the file modification time stamp.

* **rm** Deletes a file. For example `rm file`. Note that after removing a file, it is gine from the system and cannot be undeleted.

* **echo** Prints its argument to the standard output. For example `echo Hello!`.
    The echo command is very useful to print environment variables, like `echo $HOME`.

* **file** Analyzes a file and reports the file format: `file file`

* **tree** Outputs an overview of a subtree of the file system.
    ```
    $ tree
    .
    ├── build
    │   ├── sprintf_test
    │   ├── sprintf_test.o
    │   └── unity.o
    ├── Makefile
    └── sprintf_test.c
    ```

## Navigating Directories

The Unix directory hierarchy starts at the **root directors (/)**.
The **directory separator** is the **slash (/)**.

The current **working directory** is the directory that a process, such as the shell, is currently in.

When we refer to a file or directory, we specify a **path** or pathname:
* When a path starts with `/` it is a full or **absolut path**.
* If a path **not** begining mit `/` is called a **relative path**.
* A path component idntified by **two dots (..)** specifies the **parent of a directory**.
* **One dot (.)** refers to the **current directory**.

* **pwd** Print working directory. This program simply outputs the name of the current working directory.

* **cd** Changes the shell's current working directory: `cd dir`. 
    If we omit `dir`, the shell returns to your home directory.

* **mkdir**  Creates a new directory: `mkdir dir`

* **rmdir** Removes the directory: `rmdir dir`.
    If `dir` is not empty, this command fails.
    We can use `rm -rf dir` to delete a directory and its contents - be careful!
    This is one of the few commands that can do serious damage, espacially as superuser.

* **find** Search for files in a directory hierarchy: `find dir -name file`.
    The `find` command accepts special pattern-matching characters such as `*`, but we must enclose them in single quotes.

## Working with Text Files

* **cat** Outputs the content of one or more files to the standard output: `cat file1 file2 ...`.
    The command is called cat because it prforms concatination when it prints the content of more the one file.


* **less** This command comes in handy when a file is really big or when a command's output is long and 
    scrolls off the top of the screen.
    Wen running less, we can use the cursor up and down keys to scroll the file.
    To quit, we type `q`.
    We can even search for text inside less. To search forward for a word type `/word`, and to search backward, 
    we use `?word`. When we find a match, we press `n` to continue searching.

* **diff** To see the differences between two text files: `diff file1 file2`.

* **head** and **tail**
    To quick view a portion of a file.
    `head file` shows the first 10 lines of the file, and `tail file` shows the last 10 lines.
    To change the number of lines to display, use the `-n` option, where n ist the number of lines.

* **sort** Sort lines of text files: `sort file`.
    The `-r` option reverses the order of the sort.

## Dot Files (a.k.a. Hidden Files)
These are files and directories whose name begin with a dot (.).
Common dot files are: `.bashrc` and `.bash_history`.
Some programs don't show them by default.
For example, `ls` doesn't list dot files unless we use the `-a` option.

## Symbolic Links 

A symbolic link is **a file that point to another file or a directory**, 
effectively creating an **alias**.

Symbolic links offer quick access to obscure directory paths.

A symbolic link has an `l` as file type.
```
$ ls -l /bin
lrwxrwxrwx 1 root root 7 Sep  1  2021 /bin -> usr/bin
```
If we access `/bin`, the system gives us `/usr/bin` instead.

To **create a symbolic link** from `linkname` to `target`, we use:
```
$ ln -s target linkname
```
The `linkname` is the nme of the symbolic link, the `target` argument is the path of the file or directory 
that the link points to.
The `-s` flag specifies a **symbolic link**. Without it, `ln` creates a **hard link**, giving an additional real filename 
to a single file.


## Shell Input and Output 

### Redirect Output 
To send the output of command to a file instead of the terminal, use the `>` **redirection operator**:
```
$ command > file
```
The shell creates file if it does not already exist.
If the file exists, the shell erases the original file first.

To **append** the output to the file instead of overwriting it we use the `>>` redirection operator.


Note that messages send to **standard error** are still printed to the terminal instead redirected. 
We can also redirect the stderr by using the `2>` syntax:
```
$ command > file 2> error_file
```

We can also send the standard error to the same file as standard output:
```
$ command > file 2>&1
```

### Redirect Input
To **redirect a file** to a program's standard input, we use the `<` operator.
```
$ command < file
```

### Pipe
To send the standard output of a command to the standard input of another command, we use the **pipe** character `|`.
We can send output through as many piped commands as we wish.





## References
* Brian Ward. **How Linux Works**. No Starch Press, 2015
    * Chapter 2: Basic Commands and Directory Hierarchy

*Egon Teiniker, 2020-2023, GPL v3.0* 
