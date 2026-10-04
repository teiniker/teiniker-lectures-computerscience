# The Shell

The **shell** is the program that runs inside the terminal. It reads what we type,
runs the command and shows the result. The terminal is only the window, the shell
does the actual work.

There are several shells. Linux uses **bash** (the **B**ourne-**a**gain **sh**ell)
by default, and that is what this tutorial assumes. Which shell is running can
be checked with:

```
$ echo $SHELL
/bin/bash
```

## Anatomy of a Command

Almost every command line has the same structure:

```
$ ls -l /etc
  |  |  |
  |  |  +-- argument: what the command works on (here a directory)
  |  +----- option: how the command should behave (here: long format)
  +-------- command: the program to run
```

* The **command** always comes first.
* **Options** start with a dash and modify the behavior. Short options have one
  letter (`-l`), long options have a word (`--all`). Many options exist in both
  forms, `-a` and `--all` do the same thing.
* **Arguments** are the files, directories or texts the command works on.

Short options can be combined: `ls -l -a` and `ls -la` are the same.
All parts are separated by **spaces**. This is why file names with spaces are
awkward on the command line and why underscores or dashes are preferred:
`my_notes.txt` instead of `my notes.txt`.

## Getting Help

Linux comes with documentation for almost every command, directly in the terminal:

```
$ man ls          # the manual page, quit with q
$ ls --help       # short overview of the options
$ man -k copy     # search the manual pages for a keyword
```

In `man`, we scroll with the arrow keys, search with `/searchterm` and quit with
`q`.

## Keyboard Shortcuts

A few keys make working in the shell much faster. The first two should become
a habit from day one:

| Key / Command | Effect |
|---|---|
| **Tab** | Auto-complete file and directory names |
| **Up / Down** | Scroll through the most recently entered commands |
| `[ctrl] + [c]` | Abort the running command |
| `[ctrl] + [l]` | Clear the screen (like `clear`) |
| `[ctrl] + [d]` | Close the terminal (like `exit`) |
| `[ctrl] + [r]` | Search backwards in the command history |
| `history` | List all previous commands |

**Note on copy and paste:** in the terminal, `[ctrl] + [c]` does *not* copy,
it aborts the running command. To copy, use `[ctrl] + [shift] + [c]`,
to paste, use `[ctrl] + [shift] + [v]`.

## Shell Variables and Environment Variables

The shell can store values in **variables**. A variable is set with `=` (no
spaces around it) and read with a `$` in front of its name:

```
$ NAME=student
$ echo $NAME
student
```

Some variables are set by the system and are available in every program we
start. These are called **environment variables**. The most important ones:

| Variable | Content |
|---|---|
| `$HOME` | The home directory, the same as `~` |
| `$USER` | The name of the logged-in user |
| `$SHELL` | The shell currently in use |
| `$PATH` | The directories in which the shell looks for programs |

```
$ echo $HOME
/home/student
$ echo $PATH
/home/student/.local/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games
$ env             # list all environment variables
```

`$PATH` explains the error message `command not found`: the shell only finds a
program if it is located in one of these directories.

A variable we set ourselves is only known to the shell. To pass it on to the
programs we start, we use `export`:

```
$ export EDITOR=nano
```

## Commands to Try

```
$ echo $SHELL                 # Which shell is running?
$ echo $USER                  # Who am I? (the same as whoami)
$ ls --help | less            # read the options of ls page by page
$ man man                     # the manual about the manual
```

**Outlook:**
A more detailed description can be found in [Linux Shell: Bash](../shell/README.md).

## References

* Brian Ward. **How Linux Works**. No Starch Press, 2015
    * Chapter 2: Basic Commands and Directory Hierarchy
* [Youtube: Bash in 100 Seconds](https://www.youtube.com/watch?v=I4EWvMFj37g)
* [GNU Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) (official documentation)

*Nicoletta Kaehling, 2026, GPL v3.0*
