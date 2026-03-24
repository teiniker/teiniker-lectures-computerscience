# Branching and Merging 

Branching means we **diverge from the mainline of development** 
and continue to do work without messing with that mainline.

![Branching](figures/Branching.png)

The way git branches is **incredibly lightweight**, making 
branching operations nearly instantaneous, and switching back 
and forth between branches generally, just as fast.


## Use an existing repository

```bash
$ cd sandbox/c-example

$ git log --pretty=oneline
6a115638bfb4829d52067da17c71e86004c8223e (HEAD -> master) Added complex_sub operation.
bdbd20e4400a4f80d02c44944cfeb8af522a1ddc Initial import.
```


## Create a New Feature in a Separate Branch

We can implement a new functionality in your own branch so as not to 
destroy the existing project in the master branch.

```bash
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

## Implement the New Feature

In our new branch we are implementing a new function *complex_mul()*.

```bash
$ code complex_numbers.c 

complex complex_mul(complex a, double real)
{
    complex c;
    c.re = a.re * real;
    c.im = a.im * real;
    return c;
}
```

```bash
$ git status 
Auf Branch new-feature
Änderungen, die nicht zum Commit vorgemerkt sind:
  (benutzen Sie "git add <Datei>...", um die Änderungen zum Commit vorzumerken)
  (benutzen Sie "git checkout -- <Datei>...", um die Änderungen im Arbeitsverzeichnis zu verwerfen)

	geändert:       complex_numbers.c

keine Änderungen zum Commit vorgemerkt (benutzen Sie "git add" und/oder "git commit -a")
```

We commit these changes to the local repository.
```bash
$ git commit -a -m "Added new function."
[new-feature 20a83ea] Added new function.
 1 file changed, 9 insertions(+), 2 deletions(-)
```


## Go Back to the Master Branch and Merge Changes From new-feature Branch

After we have implemented and tested all new functionalities, we can 
transfer them to the master branch.

```bash
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

```bash
$ cat complex_numbers.c
You will see the new function in this file of the master branch.
```

So we have integrated the new feature into the master branch.


## Remove the new-feature Branch

At the end we can delete the developer branch, because it is no longer 
needed.

```bash
$ git branch
* master
  new-feature

$ git branch -d new-feature
Branch new-feature entfernt (war 20a83ea).

$ git branch
* master
```

## Push a Branch to the Remote Repository 

To push a branch to a remote repo, we send our local branch to 
a branch on the remote.

We can push a local tag to the remote repository:

```bash
$ git push -u origin my-branch
```

* `origin`: The remote repo
* `my-branch`: Our local branch name
* `-u`: Links our local branch to the remote branch.  
  After that, `git push` and `git pull` usually work without extra 
  names.


## Patterns for Branching and Merging

### Develop on Mainline 

All **developers work on the mainline** (master or trunk), 
committing code at least once a day. 

To make a **complex change**, like developing new functionality or 
refactoring parts of the system, branches are not used by default. 
Instead, changes are planned and implemented as a set of **small, 
incremental steps** that do not break existing functionality.

The main advantage of this pattern lies in the **rapid feedback** 
we get on the effect of every change on the fully integrated 
application.


### Branch for Release

**Features** are always **developed on mainline**.

A branch is created when our **code is feature-complete for a 
particular release**, and we want to start working on a new 
feature.

Only **fixes** for critical defects are committed on release 
branches, and they are merged into mainline immediately.

It is important that **branches for later releases should always 
be made off mainline**, not of existing release branches.


### Branch for Feature

This pattern is designed to make it easier for **large teams** 
to work simultaneously on features while keeping mainline in a 
releasable state.

**Every feature is developed on a separate branch**.

Only after a feature is **accepted by testers**, it is 
**merged to mainline** to ensure that mainline is always releasable.

This pattern is motivated by the desire to **keep the trunk 
always releasable**.

Distributed version control systems (DVCS) are designed with 
exactly this pattern in mind and make it easy to merge to and
from trunk.

Prerequisites for this pattern to work:
* Any changes from mainline must be merged onto every branch 
  on a daily basis.
* Branches must be short-lived (ideally less than a few days).
* The number of active branches that exist at any time must be 
  limited to the number of stories in play.
* Consider having testers accept features before they are merged.
* Refactorings must be merged immediately to minimize merge conflicts.	

Keep in mind that this pattern is closely related to one of the 
most common antipatterns of commercial software development because 
it is **fundamentally contrary to continuous integration**. 

Therefore, we should start with the develop on mainline pattern 
first.

## References
* [Git Reference Manual](https://git-scm.com/docs)
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2026, GPL v3.0*
