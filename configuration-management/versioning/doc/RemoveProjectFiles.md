# Remove Files from a Git Project

If we delete one or more files in the working directory, the files still remain stored 
in the staging area. We must therefore also inform the repository that the files have 
been deleted. 

## Remove files from the working directory

First we remove the file in the working directory.

```
$ rm README.md 
$ ll
-rwxr-xr-x 1 student student 16752 May  2 10:10 complex_numbers
-rw-r--r-- 1 student student   767 May  2 10:50 complex_numbers.c

$ git status
On branch master
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	deleted:    README.md

no changes added to commit (use "git add" and/or "git commit -a")
```

To make this change also visible to the repository, we add and commit the
deleted file:

```
$ git add README.md 
$ git commit -m "Removed documentation."
[master caf8263] Removed documentation.
 1 file changed, 6 deletions(-)
 delete mode 100644 README.md
```

## Remove files using git

Deleting files is a common activity, so there is an **easier way to delete a file** 
from the Git repository:
```
$ git rm README.md 
rm 'README.md'

$ git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	deleted:    README.md

$ git commit -m "Removed documentation."
[master e0e1180] Removed documentation.
 1 file changed, 6 deletions(-)
 delete mode 100644 README.md
```

Note that `git rm` deletes the file from both the working directory and the repository 
(after a `git commit` is performed).


## References
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2022, GPL v3.0*
