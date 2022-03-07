# Example: File Access - Tracing System Calls  

We try to guess the right password for the user `student`:
```
$ ./file_login 
username> student
password> student
Login rejected!
```

From the given source code we can see that file_login reads user 
credentials from a file.
```C
bool is_valid_user(char* username, char* password)
{
    char _username[256];
    char _password[256];
    FILE *fp;
    fp = fopen("application-users.config", "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't open passwords.txt file!\n");
        return false;
    }
    
    while(fscanf(fp, "%s %s", _username, _password) != EOF)
    {
        if(strcmp(username,_username) == 0
            && strcmp(password,_password) == 0)
        {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}
```

Note that **file access is based on system calls** (open, write, read, close)
so we can use **strace** to find out more.
```
$ ./file_login 
username> 
```

In parallel, open a terminal and check the running processes:
```
$ ps -a
  PID TTY          TIME CMD
 2580 pts/0    00:00:00 file_login   <== PID
 2589 pts/2    00:00:00 ps

$ strace -p 2580 -s 1024
```
 
Now let's continue with the login.
```
username> student
password> student
Login rejected!
```

Same result as before, but have a look on the strace output:
```
read(0, "student\n", 1024)              = 8
write(1, "password> ", 10)              = 10
read(0, "student\n", 1024)              = 8
brk(0)                                  = 0x89e5000
brk(0x8a06000)                          = 0x8a06000
brk(0)                                  = 0x8a06000
open("application-users.config", O_RDONLY) = 3
fstat64(3, {st_mode=S_IFREG|0664, st_size=39, ...}) = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb7770000
read(3, "student de1d9228df\nteacher 96c2d1049a\n\n", 4096) = 39
read(3, "", 4096)                       = 0
write(1, "Login rejected!\n", 16)       = 16
exit_group(0)                           = ?
```

Here we can see the file access operations in detail:
```
open("application-users.config", O_RDONLY) = 3
read(3, "student de1d9228df\nteacher 96c2d1049a\n\n", 4096) = 39
```

So, let's try `de1d9228df` as the password:
```
$ ./file_login 
username> student
password> de1d9228df
Welcome, student!
```

And also use the following credentials `teacher/96c2d1049a`
```
$ ./file_login 
username> teacher
password> 96c2d1049a
Welcome, teacher!
```

_Exercise_: Make the same experiment but use **ltrace** instead of strace.


## References:
* [strace](https://strace.io/)

* [The strace Command in Linux](https://www.baeldung.com/linux/strace-command)

*Egon Teiniker, 2020-2022, GPL v3.0* 
