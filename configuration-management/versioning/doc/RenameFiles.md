# Rename Files 

There are two ways to rename files in the working directory and in the repository. A two-step one in which the file in the working directory is first renamed or the direct command using the git mv.

## Rename Files in the Working Directory

First we rename the file in the working directory.

```bash
$ mv README.md doc.md 
$ ll
total 28
-rwxr-xr-x 1 student student 16752 May  2 10:10 complex_numbers
-rw-r--r-- 1 student student   767 May  2 10:50 complex_numbers.c
-rw-r--r-- 1 student student     9 May  2 14:18 doc.md

$ git status
On branch master
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	deleted:    README.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
	doc.md  
```

Renaming a file in the working directory causes git to delete a file with the old name 
and add a file with the new name. As soon as both files are in the staging area, git 
recognizes the renaming:

```bash
$ git add README.md doc.md

$ git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	renamed:    README.md -> doc.md
```

A `git commit` completes this operation:

```bash
$ git commit -m "Renamed documentation file."
[master 01b38a6] Renamed documentation file.
 1 file changed, 0 insertions(+), 0 deletions(-)
 rename README.md => doc.md (100%)
```

## Rename Files Using git

There is also a direct way that renames files in both the working directory and the repository:

```bash
$ git mv README.md doc.md 

$ ll
-rwxr-xr-x 1 student student 16752 May  2 10:10 complex_numbers
-rw-r--r-- 1 student student   767 May  2 10:50 complex_numbers.c
-rw-r--r-- 1 student student     9 May  2 14:18 doc.md

$ git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	renamed:  README.md -> doc.md
```

Again, `git commit` completes the operation:

```bash
$ git commit -m "Renamed documentation file."
[master 01b38a6] Renamed documentation file.
 1 file changed, 0 insertions(+), 0 deletions(-)
 rename README.md => doc.md (100%)
```

## References
* [Git Reference Manual](https://git-scm.com/docs)
* [Pro Git Book](https://git-scm.com/book/en/v2)


*Egon Teiniker, 2020-2026, GPL v3.0*
