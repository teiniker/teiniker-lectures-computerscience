# Editing Text: nano and vim

Two classic editors are available on the command line. For the beginning we
recommend **`nano`**. Vim is more advanced, which is why the repository has a
separate, more detailed page on it: [Editor: vim](../editors/vim.md).

## nano

```
$ nano notes.txt
```

Writing works immediately, just like in an ordinary text editor. At the bottom
there is a help bar, where the symbol `^` stands for the **Ctrl** key:

| Key | Function |
|---|---|
| `[ctrl] + [o]` | Save (then Enter to confirm) |
| `[ctrl] + [x]` | Quit |
| `[ctrl] + [w]` | Search |
| `[ctrl] + [k]` | Cut the current line |
| `[ctrl] + [g]` | Help |

Nothing more is needed at the beginning.

## vim

Vim is a highly configurable text editor built to make creating and changing
any kind of text very efficient.

`vim` is pre-installed on almost every Linux server, which is why a minimum of
knowledge pays off. The crucial difference: vim works with **modes**. After
starting, *normal mode* is active. Typing there does not write text, it
triggers commands. This is exactly where the first attempt almost always fails.

```
$ vim notes.txt
```

(If the message `command not found` appears, only the stripped-down variant `vi`
is installed. The full version can be installed with `sudo apt install vim`.)

The workflow for the beginning:

1. Press **`i`**: *insert mode*, normal typing is now possible
2. Write the text
3. Press **`Esc`**: back to normal mode
4. Type **`:wq`** and press **Enter**: **w**rite + **q**uit = save and quit

| Input | Effect |
|---|---|
| `i` | Start insert mode |
| `Esc` | Back to normal mode |
| `:w` | Save |
| `:q` | Quit |
| `:wq` | Save and quit |
| `:q!` | Quit **without** saving (lifeline) |
| `dd` | Delete the current line (in normal mode) |
| `/word` | Search for "word" |

> **Emergency exit from vim:** press `Esc`, then type `:q!` and press Enter.
> This always works.

## Exercise 5

* Use `nano` to create a file `profile.txt` and write three lines into it.
  Save and quit.
* Display the contents with `cat`.
* Open the same file with `vim`, append a fourth line, save and quit.
* Check the result again with `cat`.

## References

* [How-To Geek: The Beginner's Guide to Nano, the Linux Command-Line Text Editor](https://www.howtogeek.com/42980/the-beginners-guide-to-nano-the-linux-command-line-text-editor/)
* [Vim - The Ubiquitous Text Editor](https://www.vim.org/)

*Nicoletta Kaehling, 2026, GPL v3.0*
