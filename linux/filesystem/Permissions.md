# File Permissions

The concept of Linux file permission and ownership is crucial in Linux.

## File Modes and Permissions

Every file has a set of permissions that terminate whether we can read, write, or run the file.
Running `ls -l` displays the permissions.

_Example_: File permissions
```
-rw-r--r-- 1 student student 1308 Mar  9 11:54 README.md
```

The file's mode `-rw-r--r--` represents the file's permissions and some extra information.

The fist character of the mode is the **file type**: 
* A `-` in this position denotes a regular file.
* A `d` in this position indicates a directory.

The rest of a file's mode contains the **permissions**, which break down into three sets: **user**, **group**, 
**others**.
Each permission set can contain four basic representations:
* **r** file readable
* **w** file is writable
* **x** file is executable 
* **-** nothing

### Modifying Permissions

To change a permission, we use the chmod command. 
First we pick the set of permissions (`u` for user, `g` for group, `o` for others) that you want to change, and then we pick the bit to change.
```
$ chmod o+x file 
```

Sometimes people are changing permissions with numbers:
`This is called an absolut change becuase it sets all permission bits at once.
The permissions are represented in octal form: `0644 = 0b 110 100 100 = rw- r-- r--`

**Directories** also have permissions.
We can list the content of a directory if it is readable, but we can only access a file in a directory if the directory is executable.



## References
* [File Permissions in Linux / Unix: How to Read, Write & Change?](https://www.guru99.com/file-permissions.html)

*Egon Teiniker, 2020-2024, GPL v3.0*    