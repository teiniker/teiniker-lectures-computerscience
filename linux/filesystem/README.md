# Linux Directory Hierarchy 

## The / Directory
The most important **subdirectories in root** are:

```
/
├── bin -> usr/bin
├── boot
├── dev
├── etc
├── home
├── lib -> usr/lib
├── media
├── opt
├── proc
├── root
├── sbin -> usr/sbin
├── sys
├── tmp
├── usr
└── var
```

* **/bin** Contains **executable programs**, including most of the basic Unix commands such as `ls` and `cp`.
    Most of the programs in `/bin` are in binary format, having been created by a C compiler, but some are shell scripts.

* **/boot** Contains **kernel boot loader** files. These files pertain only to the very first stage of the Linux startup procedure.

* **/dev** Contains **device files**.

* **/etc** This core **system configuration** directory contains the user password, boot, device, networking, and other setup files. 

* **/home** Holds **personal directories** for regular users.

* **/lib** This directory holds **library files** containing code that executables can use. 
    
* **/media** A base attachement point for **removable media** such as flash drives.

* **/opt** This may contain additional **third-party software**.

* **/proc** Provides **system statistics** through a directory-and-file interface.
    The `/proc` directory contains information about currently running processes as well as some kernel parameters.
    
* **/sys** This directory is similar to `/proc` in that it provides a **device and system interface**.

* **/sbin** The place for **system executables**. Programs in `/sbin` directories relate to system management, so regular users usually do not have `/sbin` in their command path.

* **/tmp** A storage are for smaller, **temporary files** that we don't care much about.
    Any user may read to and write from `/tmp`, but the user may not have permission to access another user's file there.
    Many programs use this directory as a workspace.
    Most Linux distributions clear `/tmp` when the machine boots.

* **/usr** It contains a large directory hierarchy, including the bulk of the **linux system**.
Many of the directory names in /usr are the same as those in the root directory, and they hold the same type of files.
The reason that the root directory does not contain the complete system is primarily historic.

* **/var** The variable subdirectory, where programs record **runtime information**. System logging, user tracking, caches, and other files that system programs create and manage are here. 


## The /usr Directory 

The `/usr` directory may look relatively clean at first glance, but `/usr` is where most of the user-space programs and data reside.

```
/usr/
├── bin
├── include
├── lib
├── local
├── sbin
├── share
|    ├── man
|    └── info
└── src
```

* **/usr/include** Holds header files used by teh C compiler. 

* **/usr/local** Is where administrators can install their own software. Its structure should look like that of `/` and `/usr`.

* **/usr/share** Contains files that should work on other kinds of Unix machines with no loss of functionality.

* **/usr/share/man** Contains manual pages.

* **/usr/share/info** Contains GNU info manuals.


## Kernel Location

On Linux systems, the kernel is normally in `/vmlinuz` or `/boot/vmlinuz`.
A boot loader loads this file into memory and sets it in motion when the system boots.
Many modules that the kernel can load and unload on demand during are located under `/lib/modules`.


## References

* Brian Ward. **How Linux Works**. No Starch Press, 2015
    * Chapter 2: Basic Commands and Directory Hierarchy
    
* [Filesystem Hierarchy Standard](https://www.pathname.com/fhs/pub/fhs-2.3.html)

*Egon Teiniker, 2020-2022, GPL v3.0*    