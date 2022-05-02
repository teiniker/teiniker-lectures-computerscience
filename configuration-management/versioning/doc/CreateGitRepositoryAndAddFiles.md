# Create a Local Git Repository and Add Files

In this example we create a local Git repository and save a C 
project in it.

## Create a simple C project

```
$ mkdir -p sandbox/c-example
$ cd sandbox/c-examples
```

First, we implement a simple C file called "complex_numbers.c":
```
$ code complex_numbers.c
```

```C
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct complex_number
{
    double re;
    double im;
} complex;

complex complex_add(complex a, complex b)
{
	complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

int main(void)
{
    complex c1 = {1.0, 1.0};
    complex c2;
    c2.re = 2.0;
    c2.im = 4.0;

    printf("c1 = (%f,%f)\n", c1.re, c1.im);
    printf("c2 = (%f,%f)\n", c2.re, c2.im);
    
    complex result = complex_add(c1,c2);
    printf("c1 + c2 = (%f,%f)\n", result.re, result.im);

    complex *c_ptr;
    c_ptr = (complex*)malloc(sizeof(complex)); 
    c_ptr->re = 7.0;
    c_ptr->im = -13.0;
    printf("*c_ptr = (%f,%f)\n", c_ptr->re, c_ptr->im);    
    free(c_ptr);
    
    return 0;
}    
```

Also, let's create a `README.md` file:
```
# README

This is just a simple markdown file which will be:
* created
* committed 
* and finally removed
```

We compile the C file into an execuable:
```
$ gcc -Wall -o complex_numbers complex_numbers.c

$ tree
.
├── README.md
├── complex_numbers
└── complex_numbers.c
```

To execute the binary we type:
```
$ ./complex_numbers 
c1 = (1.000000,1.000000)
c2 = (2.000000,4.000000)
c1 + c2 = (3.000000,5.000000)
*c_ptr = (7.000000,-13.000000)
```

Well done. Now we have a very simple C project which we can put into a
Git repository.


## Create a Git repository

We create the Git repository within our C project directory: 
```
$ pwd
sandbox/c-examples

$ git init
Initialized empty Git repository in sandbox/c-example/.git/

$ ll -a
drwxr-xr-x  3 student student  4096 May  2 14:26 .
drwxr-x--- 15 student student  4096 May  2 10:08 ..
-rwxr-xr-x  1 student student 16752 May  2 10:10 complex_numbers
-rw-r--r--  1 student student   767 May  2 10:50 complex_numbers.c
drwxr-xr-x  8 student student  4096 May  2 14:26 .git
-rw-r--r--  1 student student   105 May  2 14:55 README.md

$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
	README.md
  complex_numbers
	complex_numbers.c

nothing added to commit but untracked files present (use "git add" to track)
```
	
## Add the C project files to the repository

We have to tell Git which files should not be managed by providing a
**.gitignore** file:
```
$ code .gitignore
# Files ignored by Git:
/complex_numbers
```


```
$ git add .gitignore 
$ git add complex_numbers.c README.md 

$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
	new file:   .gitignore
  new file:   README.md
	new file:   complex_numbers.c
```


Finally, we commit all files which are in the staging area:
```
$ git commit -m "Initial import."
[master (Basis-Commit) bdbd20e] Initial import.
 3 files changed, 42 insertions(+)
 create mode 100644 .gitignore
 create mode 100644 README.md
 create mode 100644 complex_numbers.c

$ git status
On branch master
nothing to commit, working tree clean
```

## References
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2022, GPL v3.0*
