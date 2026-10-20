# Git Workflow

**Git** is a version control system: it records every change to the code and
allows several people to work on a project at the same time. Platforms like
GitHub or GitLab are places on the net where such projects, called
**repositories** or *repos* for short, are stored.

## Checking the Installation

```
$ git --version
git version 2.39.5
```

If an error message appears, install it with:

```
$ sudo apt install git
```

## One-Time Setup

Git needs an identity. This information will later appear in every change:

```
$ git config --global user.name "Firstname Lastname"
$ git config --global user.email "firstname.lastname@edu.fh-joanneum.at"
$ git config --list          # check the settings
```

## Downloading a Repository: `git clone`

This is the command used most often in class:

```
$ mkdir ~/computerscience                             # create a directory for the course
$ cd ~/computerscience                                # and change into it
$ git clone https://github.com/teiniker/teiniker-lectures-computerscience.git
```

`mkdir` (**m**a**k**e **dir**ectory) creates a new directory; it is explained
together with the other file commands in
[Creating, Copying and Deleting Files](FilesAndDirectories.md).

Git automatically creates a directory with the project name:

```
$ ls
teiniker-lectures-computerscience
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
$ git log --oneline  # View the history (quit with q)
```

For our own contributions to a project:

```
$ git add example.txt                        # stage a change
$ git add .                                  # stage all changes
$ git commit -m "Add new example file"       # commit with a description
$ git push                                   # upload to the server
```

Rule of thumb for the workflow: **pull, work, add, commit, push**

## Exercise 3

* Check whether Git is installed and set your name and e-mail address.
* Create the directory `computerscience` in your home directory and change
  into it.
* Clone any public repository, for example:
  `git clone https://github.com/teiniker/teiniker-lectures-computerscience.git`
* Change into the new directory and explore it with `ls -a` and
  `git log --oneline`.
* Determine how many entries are in the top-level directory of the repo.

## References

* [Git Documentation: gittutorial - A tutorial introduction to Git](https://git-scm.com/docs/gittutorial)
* [LinuxConfig: Git Tutorial for Beginners](https://linuxconfig.org/git-tutorial-for-beginners)

*Nicoletta Kaehling, 2026, GPL v3.0*
