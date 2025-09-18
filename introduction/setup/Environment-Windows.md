# Setup a C/C++ Environment in Windows 

The following instructions show how to create a development environment under Windows 10 in which 
the examples of this repository can be executed.

## MinGW
First we need a C compiler and other command line tools.
[MinGW](https://sourceforge.net/projects/mingw/) 
is a free and open source software development environment to create Microsoft Windows 
applications using GNU tools.

After downloading and starting the **installer**: `mingw-get-setup.exe` 
we have to specify the **installation directory** (e.g. C:\MinGW). 
**Make sure that there are no spaces in the path/to/MinGW!!**

After downloading MinGW, the **Installation Manager** shows up:
![Modules](figures/InstallationManager.png)

We can select or remove packages from the selection using the right-click context menu.
To update the packages select the menu item: **Installation / Apply Changes**
Finally, we close the Installation Manager by selecting the menu **Installation / Quit**

Make sure that the following system environment variables are set:
```
PATH:
    C:\MinGW\bin 
    C:\MinGW\msys\1.0\bin 	
```

To test the installation, open a **command line** and type:
```
> gcc --version
gcc (MinGW.org GCC Build-2) 9.2.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

> gdb --version
GNU gdb (GDB) 7.6.1
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.

> make --version
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i686-pc-msys
```

If you get all these version information, MinGW is installed correctly.


## Git Client
We use a [Git client](https://git-scm.com/download/win) to clone source code repositories from GitHub.

Just download the installer and run it.

Verify the installation from the command line:
```
> git --version
git version 2.31.1.windows.1
```


## Visual Studio Code

[Code](https://code.visualstudio.com/) is an editor for different programming languages which can be downloaded for free.

To install Code we download and start the **installer**: `VSCodeUserSetup-x64-1.46.1.exe`

We follow the install wizard and test the installation on the **command line**:
```
> code
```

Within Code, we install the following **extensions**:
* **C/C++**: IntelliSense, debugging, and code browsing (Microsoft)
* **Code Runner**: Run C, C++, Java, JS, PHP, Python... (Jun Han)


## References
* [Git - Download](https://git-scm.com/download/win)
* [MinGW - Download](https://sourceforge.net/projects/mingw/) 
* [Visual Studio Code - Download](https://code.visualstudio.com/)
