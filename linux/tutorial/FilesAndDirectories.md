# Creating, Copying and Deleting Files

After focusing on the file system, we now want to modify it. Here are the
commands to create directories and files, copy and move them, and delete them
again. Each command takes the file or directory it works on as an argument.

```
$ mkdir computerscience       # create a directory (make directory)
$ mkdir -p ece26/linux/lab01  # create a whole chain of directories at once

$ touch notes.txt             # create an empty file

$ cp notes.txt copy.txt       # copy a file (copy)
$ cp -r computerscience backup  # copy a whole directory (-r = recursive)

$ mv copy.txt old.txt         # rename (move)
$ mv old.txt computerscience/ # move

$ rm old.txt                  # delete a file (remove)
$ rm -r backup                # delete a directory including its contents
$ rmdir empty_dir             # deletes empty directories only
```

> **`rm` has no recycle bin.**
> Deleted means deleted. There is no undo. Before pressing Enter, we should
> check the line twice. With `rm -i` the system asks before every deletion.
> The command `rm -rf /` must **never** be entered. It deletes the entire system.

## Exercise 3

* Create a directory `computerscience` in the home directory.
* Inside it, create the files `task1.txt` and `task2.txt`.
* Copy `task1.txt` to `task1_backup.txt`.
* Create a subdirectory `backup` and move the backup file into it.
* Check the result with `ls -l`.

## References

* [Medium: Kali Linux Basics Part 2 - Creating, Copying, Moving and Deleting Files](https://medium.com/@pharessaint/kali-linux-basics-part-2-creating-copying-moving-and-deleting-files-d41f4e34823c)

*Nicoletta Kaehling, 2026, GPL v3.0*
