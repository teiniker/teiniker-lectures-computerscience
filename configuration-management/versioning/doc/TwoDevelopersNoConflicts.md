# Two Developers Work Together with no Conficts

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
   ```
   $ git remote -v
   origin	git@github.com:teiniker/teiniker-lectures-computerscience.git (fetch)
   origin	git@github.com:teiniker/teiniker-lectures-computerscience.git (push)
   ```

Let's start with the experiment:

* **(A)** Changes some files and commits these changes.

* **(B)** Starts coding, changes and commit a file. 
   Note that every development starts with a `git pull` to get the lates 
   changes from the repo.
   ```
   $ git pull

   $ code configuration-management/versioning/doc/TwoDevelopersNoConflicts.md
   # do some modifications...

   $ git status
   $ git commit -a -m "Changed test cases."

   $ git pull
   Already up-to-date.

   $ git push
   ```
   Also, for every `git push`, repeat `git pull`!!

* **(A)** Refresh the web page and review the changes.

## References

*Egon Teiniker, 2020-2022, GPL v3.0*
