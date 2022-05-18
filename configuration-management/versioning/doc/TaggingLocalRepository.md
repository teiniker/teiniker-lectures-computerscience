# Tagging Commits in a Local Repository

A tag is used to label and mark a specific commit in the history.
It is usually used to mark release points.
Although a tag may appear similar to branch, a tag however does not change.
It points directly to a specific commit in the history.

## Use an Existing Repository

```
$ cd sandbox/c-example

$ git log --pretty=oneline
6a115638bfb4829d52067da17c71e86004c8223e (HEAD -> master) Added complex_sub operation.
bdbd20e4400a4f80d02c44944cfeb8af522a1ddc Initial import.
```


## Creating Tags

First, we tag the current version of our project: *version-1.0.0*

```
$ git tag -a version-1.0.0 -m "A first working version of this project."

$ git tag
version-1.0.0
```

Make some modifications, commit them and tag the new commit.

``` 
$ vi complex_numbers.c
Do some modifications...

$ git commit -a -m "Added some comments."

$ git tag version-2.0.0

$ git tag
version-1.0.0
version-2.0.0
```
We use tags to identify special points in the course of a project.


## Checkout Tags

The cool thing about tags is that we can reconstruct the state of the 
project for a given tag at any time.

```
$ git checkout tags/version-1.0.0

$ cat complex_numbers.c 
You will see the old version of this file.
```

```
$ git checkout tags/version-2.0.0

$ cat complex_numbers.c  
You will see the new version of this file again.
```


## Tag an Older Commit

We can also tag commits after we have moved past them.

```
$ git log --pretty=oneline
d80d56d613680e5eb9445acb622690c85f6e8fb8 (HEAD -> master, tag: version-2.0.0) Added some comments.
6a115638bfb4829d52067da17c71e86004c8223e (tag: version-1.0.0) Added complex_sub operation.
bdbd20e4400a4f80d02c44944cfeb8af522a1ddc Initial import.

$ git tag -a version-Initial bdbd20e4400a4f80d02c44944cfeb8af522a1ddc -m "First version."

$ git tag
version-1.0.0
version-2.0.0
version-Initial
```

```
$ git checkout tags/version-Initial

$ cat complex_numbers.c
You will see the first version of this project.
```
 
 
## Go Back to the Master Branch

```
$ git checkout master
Switched to branch 'master'

$ git status
On branch master
nothing to commit, working directory clean
```

## References
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2022, GPL v3.0*
