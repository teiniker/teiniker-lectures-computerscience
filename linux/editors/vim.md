# vim Editor

Vim is a highly configurable text editor built to make creating and changing any kind of text very efficient. 
It is included as `vi` with most UNIX systems and with Apple OS X.

There are two **modes in vim**, the command mode and the insert mode:
* In the **command mode**, user can move around the file, delete text, etc.
    From command mode to insert mode type **[i]**.
    
* In the **insert mode**, user can insert text.
    From insert mode to command mode type **[Esc]**.

_Example_: Open a new file
1. Type `vi filename` to create a file named `filename`.
2. Type **[i]** to switch to **insert mode**.
3. Enter text like a Python program ;-)
4. Hit [Esc] to switch back to **command mode**.
5. Type **[:][w][q]** to the write file and exit vim.


_Example_: Edit an existing file 
1. Type `vi filename` to edit the existing file named `filename`.
2. Move around the file using the **cursor keys**, or: 
    - **[h]** Moves the cursor one character to the left
    - **[l]** Moves the cursor one character to the right
    - **[k]** Moves the cursor up one line
    - **[j]** Moves the cursor down one line
    - **[nG]** or **[:n]** Cursor goes to the specified (n) line
3. Edit required text (replace or delete or insert).
4. Hit **[Esc]** to exit from insert mode if you insert or replace text.
5. Type **[:][w][q]**

## Some Useful Commands

### Exit Commands
**:wq** Write file to disk and quit the editor

**:q!** Quit (no warning)

**:q** Quit (a warning is printed if a modified file has not been saved)

### Text Deletion Commands
**dd** Delete line

**d$** Delete to end of line

**yy** yank current line

**y$** yank to end of current line from cursor

**p** paste below cursor

**P** paste above cursor

**u** **Undo** last change

### Search  Commands

**:/** pattern Search forward for the pattern

**:?** pattern Search backward for the pattern

**n** (used after either of the 2 search commands above to continue to find next occurrence of the pattern.



## References
* [Vim - The Ubiquitous Text Editor](https://www.vim.org/)
* [VIM Editor Commands](https://www.radford.edu/~mhtay/CPSC120/VIM_Editor_Commands.htm)
* [Youtube: Vim Basics in 8 Minutes](https://youtu.be/ggSyF1SVFr4)

*Egon Teiniker, 2020-2022, GPL v3.0*
