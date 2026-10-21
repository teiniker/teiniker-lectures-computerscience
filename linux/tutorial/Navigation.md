# Navigating Directories

`cd` (**c**hange **d**irectory) changes the current directory:

```
# we start in the home directory, ~ = /home/student
$ cd Documents        # into the subdirectory Documents
$ pwd
/home/student/Documents

$ cd ..               # one level up
$ pwd
/home/student

$ cd /etc             # absolute path: directly to /etc
$ cd ~                # back to the home directory
$ cd                  # the same: cd without an argument also goes home
```

Combinations are allowed as well:

```
$ cd ../Downloads     # one level up, then into Downloads
$ cd ~/Documents/uni  # from the home directory down into a subdirectory
```

> The most important trick of all: **the Tab key**

After typing `cd Doc`, a single press of **Tab** is enough and the shell
automatically completes it to `cd Documents/`. This not only saves time but also
prevents typos. If there are several possibilities, a second press of Tab lists
them. Using Tab should become a habit. Since Linux is case sensitive, it also
helps to avoid errors like this one:

```
$ cd documents
bash: cd: documents: No such file or directory
```

A classic: case sensitivity. The correct name is `Documents`.

## Exercise 2

* Change to the home directory.
* Change to `/usr/share` and look at its contents with `ls`.
* Go **one** level up and check your location with `pwd`.
* Jump back to the home directory with a single command.

## References

* [Red Hat Blog: 8 essential Linux file navigation commands for new users](https://www.redhat.com/en/blog/Linux-file-navigation-commands)
* [Youtube: The cd Command](https://www.youtube.com/watch?v=MRxWMZJMEJI)

*Nicoletta Kaehling, 2026, GPL v3.0*
