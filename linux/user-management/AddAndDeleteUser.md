# Add and Delete Users

Linux is a multi-user operating system. 
Each user can have different permission levels and specific settings for various command-line and GUI applications.

## Add a User 
We use the adduser cammand to add a new user to the Linux system.
In order to add a new user, we have have to switch into the rootmode. 
```
$ sudo adduser homer

[sudo] password for student: 
Adding user `homer' ...
Adding new group `homer' (1001) ...
Adding new user `homer' (1001) with group `homer' ...
Creating home directory `/home/homer' ...
Copying files from `/etc/skel' ...
New password: 
Retype new password: 
passwd: password updated successfully
Changing the user information for homer
Enter the new value, or press ENTER for the default
	Full Name []: 
	Room Number []: 
	Work Phone []: 
	Home Phone []: 
	Other []: 
Is the information correct? [Y/n] 
```
We will be asked a series of questions. 
The password is required, and all other fields are optional.
On the last prompt you’ll need to confirm that the information is correct by entering `Y`.

The command will create the new user’s home directory, and copy files from `/etc/skel` 
directory to the user’s home directory. 
Within the home directory, the user can write, edit, and delete files and directories.
```
$ ll /home/
total 8
drwxr-xr-x  2 homer   homer   4096 Mar 15 08:43 homer
drwxr-xr-x 32 student student 4096 Mar 15 08:25 student
```
```
$ su homer
Password: 
homer@lab:/home/student$ cd
homer@lab:~$ pwd
/home/homer
```

## Add User to a Group 
By default on Debian, members of the group sudo are granted with sudo access.
If you want the newly created user to have administrative rights, add the user 
to the sudo group :
```
$ sudo usermod -aG sudo homer
```

To print the groups a user is in, type:
```
$ groups homer
homer : homer sudo
```

## Delete a User 

If a user account is no longer needed, we can delete it with deluser. 
```
$ sudo deluser homer 
```

If we want to delete the user and its home directory and mail spool, we can use the `--remove-home` flag:
```
$ sudo deluser --remove-home homer

Looking for files to backup/remove ...
Removing user `homer' ...
Warning: group `homer' has no more members.
Done.

$ ll /home/
total 4
drwxr-xr-x 32 student student 4096 Mar 15 08:53 student
```

## References

* [Debian Reference: An extra user account](https://www.debian.org/doc/manuals/debian-reference/ch01.en.html#_an_extra_user_account)

*Egon Teiniker, 2020-2023, GPL v3.0* 