# GLib

GLib is a core library that forms the basis of the GTK+ toolkit and GNOME 
desktop environment, though its utility extends far beyond these uses. 

It's designed to provide core data structures and utilities to C programmers, 
offering robustness and portability on a wide range of systems.

* **Data Structures**:
    GLib provides several data structures for general use, including dynamically 
    sized arrays (`GArray`), balanced binary trees (`GTree`), hash tables 
    (`GHashTable`), linked lists (`GList` for doubly-linked lists and `GSList` 
    for singly-linked lists), queues (`GQueue`), and more. 
    
    These data structures are designed to be used in a wide variety of applications, 
    from desktop applications to servers and embedded systems.

* **Utilities**:
    GLib includes a variety of utilities to help with system abstraction, 
    file handling, and utility functions:

    * Main Loop and Event Handling: It offers a main event loop implementation that handles all kinds of events including timeouts, input notification, and idle functions. This is especially useful for GUI and server applications.
    * I/O Channels: Abstracts various kinds of I/O channels including files, sockets, and even low-level Unix file descriptors.
    * Threading Utilities: Provides thread, mutex, conditional variables, and other synchronization primitives. It also offers high-level constructs like thread pools.
    * Timers and Timeouts: Functions for calculating time intervals, setting timeouts, etc.
    * String Utilities: Offers robust functions for string manipulation that go beyond what the standard C library offers, including string buffers (GString).

* **Error Handling**:
    GLib introduces a systematic way to manage errors in applications through 
    the GError structure, providing a consistent method across all GLib and 
    GTK applications.


## Setup 

## Install GLib
GLib is available on most Unix-like platforms, including Linux and macOS, 
and can also be used on Windows. It can be installed from package managers 
or compiled from source. 

```
$ sudo apt install libglib2.0-dev
```

Applications that use GLib usually compile with gcc or another compatible 
compiler, often using the pkg-config tool to get the necessary compiler 
and linker flags.

```
$ pkg-config --modversion glib-2.0
2.74.6

$ pkg-config --cflags glib-2.0
-I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include 

$ pkg-config --libs glib-2.0
-lglib-2.0 
```

## Configure VS Code 

* Open Command Palette: Press Ctrl+Shift+P
* Edit Configurations: Type C/C++: Edit Configurations (UI)
	This opens the UI to edit the c_cpp_properties.json file.
* Locate the "Include path" setting 
* Add the paths to the directories containing the headers of 
    our third-party libraries. 

_Example_: `.vscode/c_cpp_properties.json`
```
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/include/glib-2.0",
                "/usr/lib/x86_64-linux-gnu/glib-2.0/include"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "c++14",
            "intelliSenseMode": "linux-clang-x64"
        }
    ],
    "version": 4
}
```


## References

* [GLib Reference Manual](https://developer-old.gnome.org/glib/unstable/index.html)

*Egon Teiniker, 2020-2024, GPL v3.0* 