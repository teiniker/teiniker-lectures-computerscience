# Branching and Merging in a Local Repository


## Use an existing repository

```
$ cd sandbox/c-example

$ git log --pretty=oneline
6a115638bfb4829d52067da17c71e86004c8223e (HEAD -> master) Added complex_sub operation.
bdbd20e4400a4f80d02c44944cfeb8af522a1ddc Initial import.
```


## Create a new feature in a separate branch

You can implement a new functionality in your own branch so as not to 
destroy the existing project in the master branch.

```
$ git branch new-feature

$ git branch
* master
  new-feature

$ git checkout new-feature
Switched to branch 'new-feature'

$ git branch
  master
* new-feature
```

## Implement the new feature

In our new branch we are implementing a new function *complex_mul()*.

```
$ code complex_numbers.c 

complex complex_mul(complex a, double real)
{
    complex c;
    c.re = a.re * real;
    c.im = a.im * real;
    return c;
}
```

```
$ git status 
Auf Branch new-feature
Änderungen, die nicht zum Commit vorgemerkt sind:
  (benutzen Sie "git add <Datei>...", um die Änderungen zum Commit vorzumerken)
  (benutzen Sie "git checkout -- <Datei>...", um die Änderungen im Arbeitsverzeichnis zu verwerfen)

	geändert:       complex_numbers.c

keine Änderungen zum Commit vorgemerkt (benutzen Sie "git add" und/oder "git commit -a")
```

We commit these changes to the local repository.
```
$ git commit -a -m "Added new function."
[new-feature 20a83ea] Added new function.
 1 file changed, 9 insertions(+), 2 deletions(-)
```


## Go back to the master branch and merge changes from new-feature branch

After we have implemented and tested all new functionalities, we can 
transfer them to the master branch.

```
$ git checkout master
Switched to branch 'master'
* master
new-feature

$ git merge new-feature
Aktualisiere d80d56d..20a83ea
Fast-forward
 complex_numbers.c | 11 +++++++++--
 1 file changed, 9 insertions(+), 2 deletions(-)
```

```
$ cat complex_numbers.c
You will see the new function in this file of the master branch.
```

So we have integrated the new feature into the master branch.


## Remove the new-feature branch

At the end we can delete the developer branch, because it is no longer 
needed.

```
$ git branch
* master
  new-feature

$ git branch -d new-feature
Branch new-feature entfernt (war 20a83ea).

$ git branch
* master
```

## References
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2022, GPL v3.0*
