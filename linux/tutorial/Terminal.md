# The Terminal

A **terminal** (also called console) is a window in which commands are
*typed* instead of clicked. Everything that is usually done with the mouse,
such as opening folders, copying files or starting programs, is done here with text.

On the VM, the terminal can be opened in two ways:

* search for **"Terminal"** in the menu, or
* press the key combination `[ctrl] + [alt] + [t]`

The terminal then opens and shows a line like this:

```
student@debian13:~$
```

This line is called the **prompt**. It contains the following information:

| Part | Meaning |
|---|---|
| `student` | The name of the logged-in user |
| `debian13` | The name of the machine |
| `~` | The current directory (`~` stands for the home directory) |
| `$` | Signal: the system is ready for input |

We type a command after the `$` and confirm it with **Enter**.

## Commands to Try

```
$ whoami      # Which user is logged in?
$ pwd         # Where am I?
$ date        # Current date and time
$ clear       # Clear the screen
```

## Case Sensitivity

Linux strictly distinguishes between upper- and lowercase letters.
`ls` works, `LS` does not. `Documents` and `documents` are two different
directories. A large share of all error messages at the beginning comes down to this.

## Terminal and Shell

The program inside the terminal that reads and runs our commands is the **shell**,
on Linux usually **bash**. The terminal is only the window, the shell does the
actual work. The shell is the topic of the next chapter: [The Shell](Shell.md).

## References

* [Youtube: Linux Terminal Crash Course - For Absolute Beginners](https://www.youtube.com/watch?v=hREnP0HslK8&t=57s)
* [Unix & Linux Stack Exchange: Why is the terminal case sensitive?](https://unix.stackexchange.com/questions/60276/why-is-the-terminal-case-sensitive)

*Nicoletta Kaehling, 2026, GPL v3.0*
