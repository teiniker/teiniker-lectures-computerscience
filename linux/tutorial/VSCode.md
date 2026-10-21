# The Editor: Visual Studio Code

For quick changes a terminal editor such as `nano` is enough, but for writing
programs we want more: syntax highlighting, error markers while typing, and a
debugger. For this we use **Visual Studio Code** (short: VS Code, command
`code`), a free editor from Microsoft that is already installed in the lab
image. It is not a replacement for the terminal; the two are used side by
side, and VS Code even has a terminal built in.

## Opening a Folder

VS Code works with **folders**, not with single files. The usual way to start
it is from the terminal, inside the directory we want to work on:

```
$ cd ~/IP-CS/teiniker-lectures-computerscience
$ code .
```

The dot `.` stands for the current directory (see [Paths](Paths.md)). VS Code
opens with this folder as its **workspace**, and the Explorer on the left shows
all files in it. Alternatively, start VS Code from the application menu and
choose **File > Open Folder...**.

> When a folder is opened for the first time, VS Code asks whether you trust
> its authors. For our own repository, answer **Yes, I trust the authors**,
> otherwise many features such as debugging stay disabled.

## The User Interface

| Area | Where | What it does |
|---|---|---|
| **Activity Bar** | narrow bar on the far left | Switches between the views: Explorer, Search, Source Control, Run and Debug, Extensions |
| **Side Bar** | left | Shows the selected view, usually the **Explorer** with the files of the workspace |
| **Editor** | centre | The open files, each in a tab |
| **Panel** | bottom | **Terminal**, **Problems** (compiler errors), **Debug Console** |
| **Status Bar** | bottom edge | Line number, file type, Git branch |

The **integrated terminal** opens with `` [ctrl] + [`] `` (or **View >
Terminal**). It is the same Bash shell as in a separate terminal window (see
[The Terminal and the Shell](TerminalAndShell.md)), it just starts in the workspace folder. Every
command from this tutorial works there as well.

## Extensions

VS Code understands C only with an extension. Open the Extensions view with
`[ctrl] + [shift] + [x]`, search for **C/C++** and install the extension by
**Microsoft**. It provides syntax checking (IntelliSense) and the connection to
the debugger `gdb`.

If the extension is already installed in the lab image, the Extensions view
shows it under *Installed*.

## Useful Shortcuts

| Key | Function |
|---|---|
| `[ctrl] + [s]` | Save the file |
| `[ctrl] + [p]` | Quickly open a file by name |
| `[ctrl] + [shift] + [p]` | Command Palette: every VS Code command, searchable |
| `[ctrl] + [b]` | Show / hide the Side Bar |
| `` [ctrl] + [`] `` | Show / hide the Terminal |
| `[ctrl] + [alt] + [n]` | Run Code: compile and run the current file |
| `F5` | Start debugging |
| `F9` | Set / remove a breakpoint in the current line |
| `F10` / `F11` | Step over / step into the next line |

How compiling and debugging look in practice is shown with a real program in
the next chapter, [Hello Linux World](HelloWorld.md).

## References

* [Visual Studio Code Documentation: Getting Started](https://code.visualstudio.com/docs)
* [Visual Studio Code: Using C++ on Linux](https://code.visualstudio.com/docs/cpp/config-linux)
* [Visual Studio Code: Integrated Terminal](https://code.visualstudio.com/docs/terminal/basics)

*Nicoletta Kaehling, 2026, GPL v3.0*
