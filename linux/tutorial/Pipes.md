# Pipes and Redirection

> This chapter goes a bit further than the previous ones. Take your time with it.

This is where the real power of the command line starts. Normally, every command
writes its result to the screen. This data stream can also be **redirected**,
either into a file or directly into another command.

## Redirecting Output to a File: `>` and `>>`

```
$ ls -l > contents.txt        # write the output to a file
$ date >> contents.txt        # append the output to the file
```

The difference is important:

| Symbol | Effect |
|---|---|
| `>` | Creates the file anew. Existing content is **overwritten** |
| `>>` | Appends to the end. Existing content is kept |

> An accidental `>` instead of `>>` silently deletes the previous content of the file.

## Chaining Commands: the Pipe `|`

The symbol `|` (on a German keyboard `[altgr] + [<]`) takes the output of the
command on the left and passes it as input to the command on the right:

```
$ ls -l | less                     # page through a long listing comfortably
$ ls | wc -l                       # count the entries in a directory
$ cat logfile.txt | grep "Error"   # show only the error lines
```

The principle can be continued indefinitely. Every further command processes
the result of the previous one:

```
$ cat logfile.txt | grep "Error" | wc -l
```

This line means: print the file, keep only the lines containing "Error",
count these lines. The result is a single number.

## Useful Building Blocks for Pipes

| Command | Function |
|---|---|
| `sort` | Sort lines alphabetically |
| `sort -n` | Sort numerically |
| `uniq` | Remove consecutive duplicates |
| `uniq -c` | Count duplicates |
| `wc -l` | Count lines |
| `head -n 5` | Only the first 5 lines |
| `tail -n 5` | Only the last 5 lines |
| `grep pattern` | Only matching lines |
| `less` | Display page by page |

A common pattern, the ten largest files in a directory:

```
$ du -h * | sort -h | tail -n 10
```

And the top 5 most frequently used commands from our own history:

```
$ history | awk '{print $2}' | sort | uniq -c | sort -rn | head -n 5
```

(The last command only serves as a demonstration of how far the principle can be
taken. `awk` is a topic for later.)

## Exercise 4

* Change to the directory `computerscience`.
* Write the list of all files in `/etc` into a file `etc-list.txt`.
* Count how many lines this file has.
* Append the current date to the file without losing the existing content.
* Use a pipe to find out how many entries in `/etc` contain the text "conf".

## References

* [IONOS Digital Guide: Linux pipes explained](https://www.ionos.com/digitalguide/server/configuration/linux-pipes/)

*Nicoletta Kaehling, 2026, GPL v3.0*
