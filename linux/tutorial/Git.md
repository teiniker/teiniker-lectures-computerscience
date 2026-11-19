# Git Workflow

**Git** is a version control system: it records every change to the code and
allows several people to work on a project at the same time. Platforms like
GitHub or GitLab are places on the net where such projects, called
**repositories** or *repos* for short, are stored.

## Downloading a Repository: `git clone`

This is the command used most often in class:

```
$ mkdir ~/IP-CS    # create a directory for the course
$ cd ~/IP-CS       # and change into it
$ git clone https://github.com/teiniker/teiniker-lectures-computerscience.git
$ git clone https://github.com/teiniker/teiniker-lectures-arduino.git
```

`mkdir` (**m**a**k**e **dir**ectory) creates a new directory.

Git automatically creates a directory for each project:

```
$ ls
teiniker-lectures-arduino  teiniker-lectures-computerscience
$ cd teiniker-lectures-computerscience
$ ls -a
.  ..  .git  .gitignore  .vscode.template  README.md
configuration-management  datastructures+algorithms  introduction  linux
programming-c  programming-c++
```

Directories and files whose names start with a dot, such as `.gitignore`, are
hidden. The hidden directory `.git` contains the whole history of the repository
and must not be deleted.

## The Most Important Git Commands Afterwards

```
$ git status         # What has changed?
$ git pull           # Fetch the latest changes from the server
```

## Exercise 3

* Create the directory `IP-CS` in your home directory and change into it.
* Clone any public repository, for example:
  `git clone https://github.com/teiniker/teiniker-lectures-computerscience.git`
* Change into the new directory and explore it with `ls -a` and
  `git status`.

## References

* [Git Documentation: gittutorial - A tutorial introduction to Git](https://git-scm.com/docs/gittutorial)
* [LinuxConfig: Git Tutorial for Beginners](https://linuxconfig.org/git-tutorial-for-beginners)

*Nicoletta Kaehling, 2026, GPL v3.0*
