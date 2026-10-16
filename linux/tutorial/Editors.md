# Editing Text: nano

Sooner or later a file has to be changed directly on the command line, for
example a configuration file on a server without a graphical desktop. For this
we use **`nano`**: a small, easy-to-use editor that is pre-installed on most
Linux distributions and behaves much like an ordinary text editor.

## Opening a file

```
$ nano notes.txt
```

If the file does not exist yet, nano creates it when you save. Writing works
immediately, just like in an ordinary text editor: type, move around with the
arrow keys, delete with Backspace.

At the bottom there is a help bar, where the symbol `^` stands for the
**Ctrl** key. `^O` therefore means `[ctrl] + [o]`.

## Saving and quitting

| Key | Function |
|---|---|
| `[ctrl] + [o]` | Save ("write **o**ut"), then Enter to confirm the file name |
| `[ctrl] + [x]` | Quit (nano asks whether to save if there are unsaved changes) |

The usual workflow is: edit, `[ctrl] + [o]`, Enter, `[ctrl] + [x]`.

If you quit with `[ctrl] + [x]` and nano asks `Save modified buffer?`, answer
`Y` to save, `N` to discard the changes, or `[ctrl] + [c]` to cancel and keep
editing.

## Useful keys

| Key | Function |
|---|---|
| `[ctrl] + [w]` | Search ("**w**here is") |
| `[ctrl] + [\]` | Search and replace |
| `[ctrl] + [k]` | Cut the current line |
| `[ctrl] + [u]` | Paste the cut line(s) |
| `[ctrl] + [a]` / `[ctrl] + [e]` | Jump to the start / end of the line |
| `[ctrl] + [_]` | Go to a line number |
| `[alt] + [u]` | Undo |
| `[alt] + [e]` | Redo |
| `[ctrl] + [g]` | Help |

Cut and paste work line by line: press `[ctrl] + [k]` several times to cut
several lines, then `[ctrl] + [u]` to paste them all at the new position.

## Helpful options

```
$ nano -l notes.txt
```

`-l` shows line numbers, which makes error messages such as
`error on line 12` much easier to follow. Other useful options:

| Option | Effect |
|---|---|
| `-l` | Show line numbers |
| `-m` | Enable mouse support |
| `+12` | Open the file at line 12 |

> **Editing system files:** files outside your home directory, such as those
> in `/etc`, usually belong to `root`. Open them with `sudo nano file`;
> otherwise nano shows `[ File is unwritable ]` and refuses to save.

## Outlook: vim

Besides nano, almost every Linux system also ships **`vim`**, a much more
powerful but mode-based editor with a steeper learning curve. It is not needed
for this tutorial, but it is worth knowing: on a minimal server it may be the
only editor available. The repository has a separate, more detailed page on it:
[Editor: vim](../editors/vim.md).

> **Emergency exit from vim:** if you ever land in it by accident, press
> `Esc`, then type `:q!` and press Enter.

## Exercise 4

* Use `nano` to create a file `profile.txt` and write three lines into it.
  Save and quit.
* Display the contents with `cat`.
* Open the same file again, append a fourth line, save and quit.
* Open the file with line numbers shown, search for a word from the second
  line with `[ctrl] + [w]`, and cut that line with `[ctrl] + [k]`. Save and
  quit.
* Check the result again with `cat`.

## References

* [GNU nano](https://www.nano-editor.org/)
* [How-To Geek: The Beginner's Guide to Nano, the Linux Command-Line Text Editor](https://www.howtogeek.com/42980/the-beginners-guide-to-nano-the-linux-command-line-text-editor/)

*Nicoletta Kaehling, 2026, GPL v3.0*
