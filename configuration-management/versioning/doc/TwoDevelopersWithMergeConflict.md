Example: Two developers with merge conflicts
=============================================

A: Uses a browser
------------------
	https://github.com/teiniker/teiniker-lectures-configurationmanagement/blob/master/versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java

B: Uses the command line
-------------------------

```
$ mkdir sandbox
$ cd sandbox
$ git clone https://github.com/teiniker/teiniker-lectures-configurationmanagement/
$ cd teiniker-lectures-configurationmanagement/versioning/Java-Algebra-Vector/
```

A: Changes a file
-----------------
	[Commit Changes]

B: Changes the same file in the same line
----------------------------------------

```
$ vi versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java

$ git commit -a -m "Changed test data to 7"
[master 36f5086] Changed test data to 7
 1 file changed, 2 insertions(+), 2 deletions(-)

$ git status
On branch master
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)
nothing to commit, working directory clean
```

Note that we can make a diff between the local working directory and the remote repository:

```
$ git diff origin/master
diff --git a/versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java b/versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java
index 06f61a6..e502493 100644
--- a/versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java
+++ b/versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java
@@ -4,8 +4,8 @@ public class Main
 {
     public static void main(String... args)
     {
-        Vector v1 = new Vector(1,2,3,4,5);
-        Vector v2 = new Vector(3,2,1,4,5);
+        Vector v1 = new Vector(1,2,3,4,7);
+        Vector v2 = new Vector(3,2,1,4,7);
         
         System.out.println("v1 = " + v1);
         System.out.println("v2 = " + v2);
```

```
 $ git pull
 remote: Counting objects: 11, done.
 remote: Compressing objects: 100% (6/6), done.
 remote: Total 11 (delta 3), reused 0 (delta 0), pack-reused 0
 Unpacking objects: 100% (11/11), done.
 From https://github.com/teiniker/teiniker-lectures-configurationmanagement
    0108980..3d18e3a  master     -> origin/master
 Auto-merging versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java
 CONFLICT (content): Merge conflict in versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java
 Automatic merge failed; fix conflicts and then commit the result.
```

```
 $ vi versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java
  1 package org.se.lab;
  2 
  3 public class Main
  4 {
  5     public static void main(String... args)
  6     {
  7 <<<<<<< HEAD
  8         Vector v1 = new Vector(1,2,3,4,7);
  9         Vector v2 = new Vector(3,2,1,4,7);
 10 =======
 11         Vector v1 = new Vector(1,2,3,4);
 12         Vector v2 = new Vector(3,2,1,4);
 13 >>>>>>> 3d18e3a935fbea99c37511f4de9e72656fbf0b79
 14 
 15         System.out.println("v1 = " + v1);
 16         System.out.println("v2 = " + v2);
 17 
 18         System.out.println("v1 + v2 = " + Vector.add(v1, v2));
 19     }
 20 }
```

```
$ git status
On branch master
Your branch and 'origin/master' have diverged,
and have 1 and 1 different commit each, respectively.
  (use "git pull" to merge the remote branch into yours)
You have unmerged paths.
  (fix conflicts and run "git commit")

Unmerged paths:
  (use "git add <file>..." to mark resolution)

	both modified:   versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java
```

We have to resolve the merge conflict manually. Also, we have to remove the conflict-resolution markers.
	 
```	 
$ vi versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java

  1 package org.se.lab;
  2 
  3 public class Main
  4 {
  5     public static void main(String... args)
  6     {
  7         Vector v1 = new Vector(1,2,3,4,7);
  8         Vector v2 = new Vector(3,2,1,4,7);
  9 
 10         System.out.println("v1 = " + v1);
 11         System.out.println("v2 = " + v2);
 12         
 13         System.out.println("v1 + v2 = " + Vector.add(v1, v2));
 14     }
 15 }   
```

Staging a file marks it as resolved.

```
$ git add versioning/Java-Algebra-Vector/src/main/java/org/se/lab/Main.java

$ git status
On branch master
Your branch and 'origin/master' have diverged,
and have 1 and 1 different commit each, respectively.
  (use "git pull" to merge the remote branch into yours)
All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

$ git commit -m "Merged file manually."
[master c9c94b5] Merged file manually.
[student@localhost teiniker-lectures-configurationmanagement]$ git status
On branch master
Your branch is ahead of 'origin/master' by 2 commits.
  (use "git push" to publish your local commits)

nothing added to commit but untracked files present (use "git add" to track)
```

```
$ git push
Counting objects: 12, done.
Compressing objects: 100% (7/7), done.
Writing objects: 100% (12/12), 853 bytes | 0 bytes/s, done.
Total 12 (delta 4), reused 0 (delta 0)
remote: Resolving deltas: 100% (4/4), completed with 3 local objects.
To https://github.com/teiniker/teiniker-lectures-configurationmanagement/
   3d18e3a..c9c94b5  master -> master

$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
nothing to commit, working directory clean
```

A: Refresh
-----------
