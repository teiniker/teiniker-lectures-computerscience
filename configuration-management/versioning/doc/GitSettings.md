# Git Settings

Before we start working with git, we need to make some settings. 
These settings have to be **made once** and then apply to **all repositories on the local machine**.

We need to configure our **name**, **email address** and **default editor** (eg: VS Code). 
In addition, we set the git client to insert the **line break** correctly, 
depending on the operating system.
```
	$ git config --global user.name "Homer Simpson"
	$ git config --global user.email "homer.simpson@powerplant.com"
	$ git config --global core.editor "code --wait"
	$ git config --global core.autocrlf input	// true for windows
```

All these settings are stored in a file called `.gitconfig` in the home directory and can 
be looked up there.
```
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

*Egon Teiniker, 2020-2022, GPL v3.0*

