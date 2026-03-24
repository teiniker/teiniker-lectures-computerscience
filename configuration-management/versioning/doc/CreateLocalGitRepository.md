# Create a Local Git Repository

In this example we create a local Git repository.

## Create a Project Directory

Simply create a directory ans change into this folder:

```bash
$ mkdir -p sandbox/c-examples
$ cd sandbox/c-examples
```

Create the local git repository within our project directory: 

```bash
$ git init
Initialized empty Git repository in sandbox/c-example/.git/
```

All data needed for the local git repository are stored in a `.git`
directory.

```bash
$ ll -a
drwxr-xr-x  3 student student  4096 May  2 14:26 .
drwxr-x--- 15 student student  4096 May  2 10:08 ..
drwxr-xr-x  8 student student  4096 May  2 14:26 .git
```

Now, we are able to work with git.
A very common command is to ask for the status of the local 
git repository.

```bash
$ git status
```

## References
* [Git Reference Manual](https://git-scm.com/docs)
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2026, GPL v3.0*
