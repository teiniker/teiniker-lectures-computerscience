Example: Two developers no conficts
====================================

This is a test !!!!
This is a second one :-D :-(


A: Uses a browser
-----------------
	https://github.com/teiniker/teiniker-lectures-configurationmanagement/blob/master/versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java


B: Uses the command line
------------------------

```
$ mkdir sandbox
$ cd sandbox
$ git clone https://github.com/teiniker/teiniker-lectures-configurationmanagement/
```
```
$ git remote -v
origin	https://github.com/teiniker/teiniker-lectures-configurationmanagement/ (fetch)
origin	https://github.com/teiniker/teiniker-lectures-configurationmanagement/ (push)
```

A: Changes a file
-----------------
[Commit Changes]

B: Starts coding 
-----------------

```
$ git pull
remote: Counting objects: 11, done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 11 (delta 3), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (11/11), done.
From https://github.com/teiniker/teiniker-lectures-configurationmanagement
   e653cf2..175ef7e  master     -> origin/master
Updating e653cf2..175ef7e
Fast-forward
 versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)
```

```
$ vi versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java
Do some modifacations...
```

```
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java

no changes added to commit (use "git add" and/or "git commit -a")
```

```
$ git commit -a -m "Changed test cases."
[master 0108980] Changed test cases.
1 file changed, 2 insertions(+), 2 deletions(-)
```

```
$ git pull
Already up-to-date.

$ git push
Counting objects: 11, done.
Compressing objects: 100% (6/6), done.
Writing objects: 100% (11/11), 719 bytes | 0 bytes/s, done.
Total 11 (delta 3), reused 0 (delta 0)
remote: Resolving deltas: 100% (3/3), completed with 3 local objects.
To https://github.com/teiniker/teiniker-lectures-configurationmanagement/
   175ef7e..0108980  master -> master
```

A: Refresh
----------
