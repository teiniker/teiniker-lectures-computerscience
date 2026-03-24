# Working with a Remote Repository

A remote repository is usually hosted on a server like GitHub.
It is the central place where a team stores the shared project 
history.

Each developer works with a **local repository** on their own computer.
This local repository is a full copy of the project, including the files
and the complete commit history. We can modify files, create commits,
inspect old versions, and compare changes without being connected to GitHub.

The local repository and the remote repository are synchronized with the
commands `git pull` and `git push`:

* `git pull` transfers commits from the remote repository to the local 
    repository.

* `git push` transfers commits from the local repository to the remote 
    repository.


## Before We Start Working

Before we start implementing a change, we should always update the local
repository from the remote repository.

This is done with:

```
$ git pull
```

This step is important because **other developers may already have pushed
new commits to GitHub**. If we start working on an outdated local copy,
we increase the risk of merge conflicts and inconsistent results.

Therefore, a good rule is:

* Before we start coding: `git pull`

* Before we publish our work: `git pull` and then `git push`


## Working With the Local Repository

After pulling the latest changes, we work locally.
That means we modify files, inspect the current status, and create commits.

```
$ code doc/WorkingWithRemoteRepo.md
# do some modifications...

$ git status
$ git diff
$ git commit -a -m "Extended documentation about remote repositories."
```

The important point is that `git commit` stores the **new version only in
the local repository**. The commit is now part of the local history, but it
is still not visible on GitHub.

Working locally has several advantages:

* We can commit small changes whenever we want.

* We can review our own history before publishing it.

* We can continue to work even without network access.


## Push Local Changes 

To publish the local commits on GitHub, we push them to the remote repository.

```
$ git pull
Already up-to-date.

$ git push
```

We use `git pull` before `git push` to make sure that the local repository
still contains the latest commits from the team. If GitHub contains newer
commits, we have to integrate them first before our own commits can be pushed.

After a successful `git push`, the remote repository is updated and other
developers can retrieve the new commits with `git pull`.


## References

* [Git Reference Manual](https://git-scm.com/docs)
* [Pro Git Book](https://git-scm.com/book/en/v2)


*Egon Teiniker, 2020-2026, GPL v3.0*
