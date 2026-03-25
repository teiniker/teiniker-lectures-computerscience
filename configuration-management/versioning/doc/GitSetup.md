# Git Settings

Before we start working with git, we need to make some setup and configurations. 
These settings have to be **made once** and then apply to **all repositories 
on the local machine**.

## Setup Git 

We can install git using the Debian package manager:

```bash
 $ sudo apt install git 

 $ git --version
```

Note that in our VM Image git is already installed.


## Configure Git 

We need to configure our **name**, **email address** and **default editor** 
(eg: VS Code). 
In addition, we set the git client to insert the **line break** correctly, 
depending on the operating system.

```bash
	$ git config --global user.name "Homer Simpson"
	$ git config --global user.email "homer.simpson@powerplant.com"
	$ git config --global core.editor "code --wait"
	$ git config --global core.autocrlf input	// true for windows
```

All these settings are stored in a file called `.gitconfig` in the home 
directory and can be looked up there.

```bash
	$ cat .gitconfig
	[user]
		name = Homer Simpson
		email = homer.simpson@powerplant.com
	[pull]
		rebase = false
	[core]
		editor = code --wait
```

## References
* [YouTube: Git Tutorial for Beginners: Learn Git in 1 Hour](https://youtu.be/8JJ101D3knE)

* [Git Reference Manual](https://git-scm.com/docs)
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020-2026, GPL v3.0*

