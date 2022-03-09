# Linux Command Line

## The Bourne Shell

A **shell** is a program that runs commands which the user enter.

The shell also serves as a small **programming environment**.
Many important parts of the system are **shell scripts** - text files that contain a sequence of shell commands.

There are many different Unix shells, but all derive several of their fetures from the **Bourne shell** 
in order to function correctly.
Linux uses an enhanced version of the Bourne shell called **bash** or the **Bourne-again shell**.
The bash shell is the default shell on most Linux distributions. 


## Standard Input and Standard Output 
Unix processes use **I/O files** to read and write data.

Programs such as `ls` actually send their results to a special file called **standard output** (`stdout`)
and their status messages to another file called **standard error** (`stderr`).
By default, both stdout and stderr are linked to the screen and not saved into a disk file.

In addition, many programs take input from a file called **standard input** (`stdin`), which is, by default, attached to the keyboard.


## Getting Help

Linux systems come with a wealth of documentation.

* **man** The man pages will tell us what we need to know for a particular command. For example `man ls`.
    When programs have many options, the manual pages often list the options in some systematic way.
    To search for a manual page by keyword, use the `-k` option: `man -k keyword`.

* **--help** If we are just looking for a certain option for a command, we tra to enter a command followed by `--help`. 

* **info** The GNU project decided to use another format called info. To access an info manual, we use info with the command name:` info ls`.


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


## Dot Files
These are files and directories whose name begin with a dot (.).
Common dot files are: `.bashrc` and `.bash_history`.
Some programs don't show them by default.
For example, `ls` doesn't list dot files unless we use the `-a` option.


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


## Common Commands

* **cat** Outputs the content of one or more files to the standard output: `cat file1 file2 ...`.
    The command is called cat because it prforms concatination when it prints the content of more the one file.


* **less** This command comes in handy when a file is really big or when a command's output is long and 
    scrolls off the top of the screen.
    Wen running less, we can use the cursor up and down keys to scroll the file.
    To quit, we type `q`.
    We can even search for text inside less. To search forward for a word type `/word`, and to search backward, 
    we use `?word`. When we find a match, we press `n` to continue searching.

* **diff** To see the differences between two test files: `diff file1 file2`.

* **find** Search for files in a directory hierarchy: `find dir -name file`.
    The `find` command accepts special pattern-matching characters such as `*`, but we must enclose them in single quotes.

* **head** and **tail**
    To quick view a portion of a file.
    `head file` shows the first 10 lines of the file, and `tail file` shows the last 10 lines.
    To change the number of lines to display, use the `-n` option, where n ist the number of lines.

* **sort** Sort lines of text files: `sort file`.
    The `-r` option reverses the order of the sort.

## Changing the Password

We use the `passwd` command to change our password.
We will be asked for our old password and then prompted for our new password twice.


## Environment Variables 

The shell can store temporary variables, called **shell variables**, containing the values of text strings.
Shell variables are very useful for keeping track of values in scripts, and some shell variables control the way the shell behaves.

To assign a value to a shell variable, use the equal sign `=`. To access the variable use the `$` prefix.

_Example_: 
```
$ CC=gcc 
$ echo $CC
```

An **environment variable** is like a shell variale, but it is not specific to the shell.
The operating system passes all environment valiables to programs that the shell runs, whereas 
shell variables cannot be accessed in the commands we run.

We assign an environment variable with the shell's `export` command.
_Example_: 
```
$ export CC=gcc 
$ echo $CC
```

Environment variables are useful because many programs read them for configuration and options.

* **PATH** This is a special environment variable that contains the **command path**.
    A command path is a list of system directories that the shell searches when trying to locate a command.
    If we run `echo $PATH`, we will see that the path components are separated by colons `:`.

    _Example_: 
    ```
    $ echo $PATH 
    /home/student/.local/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games
    ```
    
    To tell the shell to look in more places for programs, change the PATH environment variable.
    _Example_: 
    ```
    $ PATH=dir:$PATH 
    ```


## Working with Processes 

### Listing Processes
For a quick listing of running processes, we run the command `ps`.
```
$ ps
    PID TTY          TIME CMD
   1680 pts/2    00:00:00 bash
   2670 pts/2    00:00:00 ps 
```
The fields are as follows:
* **PID** The process ID.
* **TTY** The terminal device where the process is running.
* **TIME** The amount of CPU time in minutes and seconds that the program has used so far.
* **CMD** Name of the running process.

The `ps` command has many options:
* `ps x` Show all of our running processes
* `ps ax` Show all processes running on the system
* `ps u` Include more detailed information on processes
* `ps w` Show full command names

### Killing Processes
To terminate a process, we send a **signal** with the `kill` command.
A singnal is a message to a process from the kernel.
```
$ kill pid
```
There are many types of signals:
* `-TERM` Terminate the process (default)
* `-STOP` Freeze a process. A stopped process is still in memory. 
* `-CONT` Continue running.
* `-KILL` While other signals give the process a chance to clean up after itself, `KILL` does not. 
Note that using `CTRL-C` to terminate a process that is running in the current terminal is 
the same as using kill to end the process with the `-INT` (interrupt) signal. 

### Background Processes
Normally, when we run a command from the shell, we don't get the shell prompt back until the 
program finishes executing.

We can detach a process from the shell and put it in the background using the & operator.
The shell should respond by printing the PID of the new background process, and the prompt 
should return immediately so that we can continue working.
The process will continue to run after we log out.


## File Modes and Permissions

Every file has a set of permissions that terminate whether we can read, write, or run the file.
Running `ls -l` displays the permissions.

_Example_: File permissions
```
-rw-r--r-- 1 student student 1308 Mar  9 11:54 README.md
```

The file's mode `-rw-r--r--` represents the file's permissions and some extra information.

The fist character of the mode is the **file type**: 
* A `-` in this position denotes a regular file.
* A `d` in this position indicates a directory.

The rest of a file's mode contains the **permissions**, which break down into three sets: **user**, **group**, 
**others**.
Each permission set can contain four basic representations:
* **r** file readable
* **w** file is writable
* **x** file is executable 
* **-** nothing

### Modifying Permissions

To change a permission, we use the chmod command. 
First we pick the set of permissions (`u` for user, `g` for group, `o` for others) that you want to change, and then we pick the bit to change.
```
$ chmod o+x file 
```

Sometimes people are changing permissions with numbers:
`This is called an absolut change becuase it sets all permission bits at once.
The permissions are represented in octal form: `0644 = 0b 110 100 100 = rw- r-- r--`

**Directories** also have permissions.
We can list the content of a directory if it is readable, but we can only access a file in a directory if the directory is executable.


### Symbolic Links 

A symbolic link is a file that point to another file or a directory, effectively creating an alias.
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


## References

* Brian Ward. **How Linux Works**. No Starch Press, 2015
    * Chapter 2: Basic Commands and Directory Hierarchy
    

*Egon Teiniker, 2020-2022, GPL v3.0*    
