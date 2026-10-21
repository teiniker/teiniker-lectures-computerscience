# Looking into Files

Now that we can create files, we also need to read them without opening an
editor every time. The following commands print a file, page through it, show
only its beginning or end, or count its lines. All of them work on text files.

```
$ cat notes.txt          # print the whole file
$ less notes.txt         # page through the file (quit with q)
$ head notes.txt         # the first 10 lines
$ tail notes.txt         # the last 10 lines
$ tail -n 20 file.log    # the last 20 lines
$ wc -l notes.txt        # count lines
```

In `less`, we scroll with the arrow keys or `Page Up`/`Page Down`, search with
`/searchterm` and quit with **`q`**.

Searching inside files:

```
$ grep "Error" logfile.txt         # all lines containing "Error"
$ grep -i "error" logfile.txt      # -i ignores case
$ grep -r "TODO" .                 # search recursively in the whole directory
```

Finding files:

```
$ find . -name "*.txt"    # all .txt files from here downwards
```

## References

* [William Shotts: Learning the Shell, Lesson 3 - Looking Around](https://linuxcommand.org/lc3_lts0030.php)
* [GNU Grep Manual](https://www.gnu.org/software/grep/manual/grep.html) (official documentation)
* [LinuxUser 11/2003: Zu Befehl - head, tail, cat](https://www.linux-community.de/ausgaben/linuxuser/2003/11/zu-befehl-head-tail-cat/)

*Nicoletta Kaehling, 2026, GPL v3.0*
