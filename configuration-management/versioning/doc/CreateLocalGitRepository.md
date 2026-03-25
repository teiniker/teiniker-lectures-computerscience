# Create a Local Git Repository

In this example we create a local Git repository.

![Local Repository](figures/LocalRepository.png)

## Create a Working Directory

Simply create a directory and change into this folder:

```bash
$ mkdir -p sandbox/c-examples
$ cd sandbox/c-examples
```

## Create Local Repository 

In this folder, we create the local git repository: 

```bash
$ git init
Initialized empty Git repository in sandbox/c-example/.git/
```

All data needed for the local git repository are stored in 
the `.git` directory.

```bash
$ ll -a
drwxr-xr-x  3 student student  4096 May  2 14:26 .
drwxr-x--- 15 student student  4096 May  2 10:08 ..
drwxr-xr-x  8 student student  4096 May  2 14:26 .git
```

Now, we are able to work with git.

A commonly used Git command is to check the status of the 
local repository:

```bash
$ git status
```

## References
* [Git Reference Manual](https://git-scm.com/docs)
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2026, GPL v3.0*
