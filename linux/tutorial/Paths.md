# Paths and the Working Directory

In the terminal, a session is always "inside" a directory. The command `pwd`
(**p**rint **w**orking **d**irectory) shows which one:

```
$ pwd
/home/student
```

This is the **home directory**, the place for all personal files.
Its short form is the tilde: `~`

## Structure of Linux Paths

Unlike Windows (`C:\Users\...`), there are **no drive letters**.
Everything hangs off a single root directory: `/`

```
/                     <- root directory
├── home/
│   └── student/      <- the home directory = ~
│       ├── Documents/
│       └── Downloads/
├── etc/              <- system configuration files
├── usr/              <- installed programs
├── var/              <- log files, variable data
└── tmp/              <- temporary files
```

An **absolute path** starts with `/` and describes the complete way from the
root directory: `/home/student/Documents`

A **relative path** does *not* start with `/` and is read starting from the
current directory: `Documents/exercises`

Four short symbols come up all the time:

| Symbol | Meaning |
|---|---|
| `.` | The current directory |
| `..` | The directory one level up |
| `~` | The home directory |
| `/` | The root directory of the file system |

## References

* [Youtube: Linux Filesystem Explained for Beginners](https://www.youtube.com/watch?v=WdInegtTTCE)

*Nicoletta Kaehling, 2026, GPL v3.0*
