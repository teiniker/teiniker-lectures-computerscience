# Installing Software: apt

Debian comes with its own package management. Programs are not downloaded via
the browser but obtained from a verified repository:

```
$ sudo apt update              # update the package lists (always first)
$ sudo apt upgrade             # update the installed packages
$ sudo apt install git         # install a package
$ sudo apt install tree htop   # several packages at once
$ sudo apt remove tree         # uninstall
$ apt search editor            # search for packages
```

`apt update` only downloads the *lists* of what is available and installs
nothing. That is why it always comes before an `install`.

A small program to try out:

```
$ sudo apt install tree
$ tree ~/computerscience
```

This displays the directory structure as a tree.

A more detailed description can be found in [Package Management](../package-manager/README.md).

## References

* [Debian: APT User's Guide](https://www.debian.org/doc/manuals/apt-guide/index.en.html)

*Nicoletta Kaehling, 2026, GPL v3.0*
