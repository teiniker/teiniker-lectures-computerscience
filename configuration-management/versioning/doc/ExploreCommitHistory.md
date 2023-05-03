# Explore the Commit History 

The `git log` command is used to **display the commit history** in a Git repository. 
It shows a chronological list of commits, starting from the most recent commit and going back in time to the initial commit.

By default, `git log` displays the following information for each commit:
* Commit Hash (SHA): A unique identifier for each commit.
* Author: The name and email address of the person who made the commit.
* Date: The date and time when the commit was made.
* Commit Message: The message provided by the author to describe the changes made in the commit.

```
$ git log
commit 7a7b34a5e19e74252e883d3fa700bb285acf246b (HEAD -> master, new-feature)
Author: Egon Teiniker <egon.teiniker@gmail.com>
Date:   Tue Apr 25 14:36:49 2023 +0200

    Added super new feature.

commit 7d20d580175302e78155f334f3add56619ccf9ec (tag: version-2.0.0)
Author: Egon Teiniker <egon.teiniker@gmail.com>
Date:   Tue Apr 25 14:27:18 2023 +0200

    Added references to doc.

commit 2d980efcc4c10448aa4a0457bb86dd2a99531559
Author: Egon Teiniker <egon.teiniker@gmail.com>
Date:   Tue Apr 25 14:26:40 2023 +0200

    Added function.

commit 57bcc8717b57f76f5b3935cdd0cda62366c65510 (tag: version-1.0.0)
Author: Egon Teiniker <egon.teiniker@gmail.com>
Date:   Tue Apr 25 13:37:37 2023 +0200

    Renamed doc file.
```

The `git log` command provides various options that allow you to customize the output and filter the commit history based on specific criteria. Here are some commonly used options:
* `--oneline`: Condenses the commit information into a single line, showing only the commit hash and the commit message.
* `--graph`: Displays a text-based ASCII graph representing the commit history, with branches and merges.
* `--author=<pattern>`: Filters the commit history to show only the commits made by the specified author(s) based on the provided pattern.
* `--since=<date>`: Shows commits made since the specified date.
* `--until=<date>`: Shows commits made until the specified date.
* `--grep=<pattern>`: Filters the commit history to show only the commits with commit messages matching the specified pattern.


_Example: Show each commit in one line_\
    The `git log --oneline` command is used to display a **condensed version of the commit history** in a Git repository. It provides a simplified output that shows each commit on a single line, making it easier to scan through the history quickly.

    When we run `git log --oneline`, the following information is displayed for each commit:
    * Commit Hash (SHA): A shortened version of the commit hash, usually the first 7 characters.
    * Commit Message: The commit message provided by the author.
    ```
    $ git log --oneline
    7a7b34a (HEAD -> master, new-feature) Added super new feature.
    7d20d58 (tag: version-2.0.0) Added references to doc.
    2d980ef Added function.
    57bcc87 (tag: version-1.0.0) Renamed doc file.
    1de5dcf Added documentation.
    5d0d1d6 Initial import.
    17b7da3 Initial import.
    ```


_Example: Show only tag-related information_\
    To show the **tag messages** in the Git history, we can use the `git log` command with the `--decorate` option. The `--decorate` option adds additional information, such as tags and branch names, to the commit messages displayed by git log.

    If we want to see **only the tag-related information**, you can combine git log with the `--simplify-by-decoration` option:

    ```
    $ git log --decorate --simplify-by-decoration
    commit 7a7b34a5e19e74252e883d3fa700bb285acf246b (HEAD -> master, new-feature)
    Author: Egon Teiniker <egon.teiniker@gmail.com>
    Date:   Tue Apr 25 14:36:49 2023 +0200

        Added super new feature.

    commit 7d20d580175302e78155f334f3add56619ccf9ec (tag: version-2.0.0)
    Author: Egon Teiniker <egon.teiniker@gmail.com>
    Date:   Tue Apr 25 14:27:18 2023 +0200

        Added references to doc.

    commit 57bcc8717b57f76f5b3935cdd0cda62366c65510 (tag: version-1.0.0)
    Author: Egon Teiniker <egon.teiniker@gmail.com>
    Date:   Tue Apr 25 13:37:37 2023 +0200

        Renamed doc file.

    commit 17b7da3694167dd47be18122030a4b0e9166d052
    Author: Egon Teiniker <egon.teiniker@gmail.com>
    Date:   Tue Apr 25 13:12:47 2023 +0200

        Initial import.

    ```

_Example: Show the files committed in each Git commit_\
    To see the **files committed in each Git commit**, we can use the `git log --stat` command. This command provides a summary of the files that were modified in each commit along with some additional statistics.

    The output of `git log --stat` will show you the commit hash, author, date, and commit message as well as a summary of the files modified in each commit. The summary includes the file name, the number of lines added and deleted, and the total number of changes.
    ```
    $ git log --stat
    commit 7a7b34a5e19e74252e883d3fa700bb285acf246b (HEAD -> master, new-feature)
    Author: Egon Teiniker <egon.teiniker@gmail.com>
    Date:   Tue Apr 25 14:36:49 2023 +0200

        Added super new feature.

    number_of.c | 6 ++++++
    1 file changed, 6 insertions(+)

    commit 7d20d580175302e78155f334f3add56619ccf9ec (tag: version-2.0.0)
    Author: Egon Teiniker <egon.teiniker@gmail.com>
    Date:   Tue Apr 25 14:27:18 2023 +0200

        Added references to doc.

    README.md | 5 ++++-
    1 file changed, 4 insertions(+), 1 deletion(-)
    ...
    ```

## References
* [Git Reference Manual](https://git-scm.com/docs)
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2023, GPL v3.0*