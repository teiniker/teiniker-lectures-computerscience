# Debian Package Manager 

**APT** is the **Advanced Package Tool**, an advanced interface to the Debian packaging system which provides the `apt-get` program. It provides commandline tools for searching and managing packages, and for querying information about them, as well as low-level access to all features of the libapt-pkg library.

Common use cases are:
* To **update the list of packages known by your system**:
```    
$ sudo apt update
```

* To **install a package** and all its dependencies:
```
$ sudo apt install foo
```

* To **remove a package from your system**:
```
$ sudo apt remove foo
```

* To **upgrade all the packages on your system** (without installing extra packages or removing packages):
```
$ sudo apt upgrade
```

The following is an **overview of the old and new commands**:
```
 apt-get update             ->  apt update
 apt-get upgrade            ->  apt upgrade
 apt-get dist-upgrade       ->  apt full-upgrade
 apt-get install package    ->  apt install package
 apt-get remove package     ->  apt remove package
 apt-get autoremove         ->  apt autoremove
 apt-cache search string    ->  apt search string
 apt-cache policy package   ->  apt list -a package
 apt-cache show package     ->  apt show package
 apt-cache showpkg package  ->  apt show -a package
```


## References

* [The Debian package management tools](https://www.debian.org/doc/manuals/debian-faq/pkgtools.en.html)