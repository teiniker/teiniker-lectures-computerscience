# Two Developers with Merge Conflicts

The following example shows two developers collaborating on a GitHub repository.
Try this with our own GitHub repository.

* **(A)** Uses a browser to access the repository
   https://github.com/teiniker/teiniker-lectures-computerscience

* **(B)** Uses the command line interface
   ```
   $ mkdir sandbox
   $ cd sandbox
   $ git clone git@github.com:teiniker/teiniker-lectures-computerscience.git
   ```

Let's start with the experiment:

* **(A)** Changes some files and commits these changes.

* **(B)** Changes the **same file in the same line**.
  ```
   $ git pull

   $ code configuration-management/versioning/doc/TwoDevelopersNoConflicts.md
   # do some modifications...

   $ git status
   $ git commit -a -m "Changed test cases."
  ```

  We can make a diff between the local working directory and the remote repository:
  ```
  $ git diff origin/master
  ```

  When we use git pull, a merge conflict occurs: 
  ```
  $ git pull
  ...
  CONFLICT (content): Merge conflict in versioning
  Automatic merge failed; fix conflicts and then commit the result.
  ```

  We can see the two versions in the changed file:
  ```
  <<<<<<< HEAD
          Vector v1 = new Vector(1,2,3,4,7);
          Vector v2 = new Vector(3,2,1,4,7);
  =======
          Vector v1 = new Vector(1,2,3,4);
          Vector v2 = new Vector(3,2,1,4);
  >>>>>>> 3d18e3a935fbea99c37511f4de9e72656fbf0b79 
  ```

  We have to **resolve the merge conflict manually**. Also, we have to remove the conflict-resolution markers.
	 
  **Staging a file marks it as resolved**.
  ```
  $ git add . 
  ```

  Finally, we **commit and push** our changes.
  ```
  $ git commit -m "Resolved merge conflict." 
  $ git push
  ```

* **(A)** Refresh the web page and review the changes.


## References
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2022, GPL v3.0*