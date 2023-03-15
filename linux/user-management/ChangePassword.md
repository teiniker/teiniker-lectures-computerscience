# Change Passwords 

Users can change their own passwords and users belonging to the sudo (super user) group can administrate the passwords of other users.

## Change your own Password

A user can change its password at any time using the `passwd` command. 

```
$ passwd
Changing password for student.
Current password: 
New password: 
Retype new password: 
passwd: password updated successfully
```

## Change Another User's Password

To change another user's password we use the same command, but specify the user’s name.
```
$ sudo passwd homer
New password: 
Retype new password: 
passwd: password updated successfully
```

## References


*Egon Teiniker, 2020-2023, GPL v3.0* 