# Permissions and sudo

Linux is a multi-user system. Every file belongs to someone, and it is precisely
regulated who may read, change or execute it.

Another look at `ls -l`:

```
-rw-r--r--  1 student student  220 Aug 12 09:01 notes.txt
drwxr-xr-x  2 student student 4096 Aug 15 10:23 Documents
```

The first column breaks down like this:

```
 -   rw-   r--   r--
 |    |     |     +-- everyone else: read only
 |    |     +-------- group: read only
 |    +-------------- owner: read + write
 +------------------- type: - = file, d = directory
```

The three letters mean:

| Letter | For files | For directories |
|---|---|---|
| `r` (**read**) | read | list the contents |
| `w` (**write**) | modify | create/delete files |
| `x` (**execute**) | execute | change into it (`cd`) |

## Changing Permissions: `chmod`

The easiest way is the symbolic notation:

```
$ chmod +x script.sh       # make executable
$ chmod -w file.txt        # remove write permission
$ chmod u+x script.sh      # only for the owner (user)
$ chmod go-r secret.txt    # group and others may no longer read
```

The abbreviations: `u` = user (owner), `g` = group, `o` = others, `a` = all.

The numeric notation is also common. It is the same thing, just encoded in binary:

```
$ chmod 755 script.sh      # rwxr-xr-x  - typical for programs
$ chmod 644 notes.txt      # rw-r--r--  - typical for files
$ chmod 600 private.txt    # rw-------  - owner only
```

(4 = read, 2 = write, 1 = execute; added up, 4+2+1 = 7 = all permissions.)

The owner can be changed with `chown`, which requires administrator rights:

```
$ sudo chown student:student file.txt
```

## `sudo`: Administrator for a Moment

Everything that affects the system as a whole, such as installing software or
changing system files, is not allowed for a normal user account. For this there
is `sudo` (**s**uper**u**ser **do**):

```
$ sudo apt update
[sudo] password for student:
```

The system asks for our **own** password. While typing, nothing moves on the
screen: no asterisks, no cursor. This is intentional and not an error. Just type
and press Enter.

> With `sudo`, all safety nets are gone. Its use should be limited to commands
> whose effect we know.
> **Be careful**

If the message *"student is not in the sudoers file"* appears, the account on
this machine is not enabled for `sudo`. In this case, the administrator should
be contacted.

A more detailed description can be found in [File Permissions](../filesystem/Permissions.md).

## Exercise 6

* Create a file `test.sh` and look at its permissions with `ls -l`.
* Make the file executable and check what has changed in the output.
* Remove the read permission from everyone else and check the result again.

## References

* [Debian Wiki: Permissions](https://wiki.debian.org/Permissions)
* [Debian Wiki: sudo](https://wiki.debian.org/sudo/)

*Nicoletta Kaehling, 2026, GPL v3.0*
