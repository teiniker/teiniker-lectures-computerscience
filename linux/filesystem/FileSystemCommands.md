# Working with the File System


## Files, Directories, and Navigation

* **ls** List directory contents.
* **pwd** Print name of current/working directory.
* **cd** Change the current working directory.
 
* **file** Determine file type.

* **touch** Change file timestamps.
* **cp** Copy files and directories.
* **mv** Move (rename) files.
* **rm** Remove files or directories.
* **mkdir** Create the directory(ies), if they do not already exist.
* **rmdir** Remove the directory(ies), if they are empty.

## Directory Structure
The `tree` command can be used to get an overview of a subtree of the file system.

```
$ tree
.
├── build
│   ├── sprintf_test
│   ├── sprintf_test.o
│   └── unity.o
├── Makefile
└── sprintf_test.c
```

## Working with Text Files
* **cat** Concatenate files and print on the standard output.
* **less**  A filter for scrolling through text and search for patterns (replacement for more).


## References
* Brian Ward. **How Linux Works**. No Starch Press, 2015
    * Chapter 2: Basic Commands and Directory Hierarchy

*Egon Teiniker, 2020-2023, GPL v3.0* 
