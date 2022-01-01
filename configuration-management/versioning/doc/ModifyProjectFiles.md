# Example: Modify an Existing Project

In this example we modify files in a project that is versioned with Git.

## Modify a file and undo changes 

We start by modifying a file from the versioned project.
```
$ vi complex_numbers.c
```
We make some modifications...

```C
complex complex_sub(complex a, complex b)
{
    complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}
```

Always, we can use *git status* to find files which have been changed.
```
$ git status
	geändert:       complex_numbers.c

$ git status -s
 M complex_numbers.c
```
Also, we can compare the content of files to the version stored in the
Git repository:

```
$ git diff complex_numbers.c
diff --git a/complex_numbers.c b/complex_numbers.c
index f1b077b..caff86e 100644
--- a/complex_numbers.c
+++ b/complex_numbers.c
@@ -16,6 +16,14 @@ complex complex_add(complex a, complex b)
     return c;
 }
 
+complex complex_sub(complex a, complex b)
+{
+    complex c;
+    c.re = a.re - b.re;
+    c.im = a.im - b.im;
+    return c;
+}
+
 int main(void)
 {
     complex c1 = {1.0, 1.0};
```

If we made some mistakes, we can easily go back to the version stored 
in the repository.
```
$ git checkout complex_numbers.c

$ git status
On branch master
nothing to commit, working directory clean
```

Note that these features, making a diff or even going back to the 
version we committed into the repostory is a huge benefit for developers.


## Modify a file and commit changes 

On the other hand, most changes we make to files are saved in the Git 
repository.

Again, we modify a file from the versioned project.
```
$ vi complex_numbers.c
```
```C
complex complex_sub(complex a, complex b)
{
    complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}
```
```
$ git status -s
 M complex_numbers.c
```

In order to transfer all changes to the project files to the repository, 
they must be committed.
```
$ git commit -a -m "Added complex_sub operation."
[master 6a11563] Added complex_sub operation.
 1 file changed, 8 insertions(+)

$ git status
On branch master
nothing to commit, working directory clean
```

```
$ git log
commit 6a115638bfb4829d52067da17c71e86004c8223e (HEAD -> master)
Author: teiniker <egon.teiniker@gmail.com>
Date:   Mon Feb 24 21:28:07 2020 +0100

    Added complex_sub operation.

commit bdbd20e4400a4f80d02c44944cfeb8af522a1ddc
Author: teiniker <egon.teiniker@gmail.com>
Date:   Mon Feb 24 20:53:22 2020 +0100

    Initial import.
```

We can also use a single line log format.
```    
$ git log --pretty=oneline
6a115638bfb4829d52067da17c71e86004c8223e (HEAD -> master) Added complex_sub operation.
bdbd20e4400a4f80d02c44944cfeb8af522a1ddc Initial import.    
```

## References
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020, GPL v3.0*
