## Git


## Basics


## Why git?

### Git vs SVN

* Git is much faster than SVN
* With git, you always clone the entire repository
* Git's repositories are much smaller than Subversions

[more](https://git.wiki.kernel.org/index.php/GitSvnComparison)


## Getting started:

### Create a new repository

`git init` in the directory

### Cloning an existing repository

`git clone /path/to/repository`

or with a remote server:

`git clone username@host:/path/to/repository`


### Workflow

![git-workflow](images/git-basic.png)


### Examining the status of your files

```bash
$ git status
# On branch master
nothing to commit (working directory clean)
```

try creating a file and seeing the status


### Adding files to the staging area

`git add /path/to/file`

Check the status:

`git status`

Create a new file and add it to the staging area.
Now Edit the file and run git status again. notice the state of the file


### Viewing your staged and unstaged changes

what have I not staged yet?

`git diff`

What have I already staged?

`git diff --cached`


### After populating the staging area: Committing

`git commit`

This adds everything in your staging area to your local repo.
The data is grouped saved under a name ( commit message ).

Shortcut: `git commit -m "message"`


### Deleting files

`git rm`

removes the file + adds to the stage.

or

```bash
$ rm file
$ git add file
```



## Must reads

The pro git book:
(http://git-scm.com/book)[http://git-scm.com/book]



## History

what changed, and by who?

`git log`

lots of log formats available.

using oh-my-zsh:

`glog`



## Undoing

Oops, I made a mistake...

### I should not have modified this file!

* File was modified
* Not added to the stage

revert file to last commit:

`git checkout -- file`

### I should not have staged this file!

* File was modified
* File was staged

unstage:

`git reset HEAD file`

### I forgot to add a file to a commit!

```bash
$ git commit -m "Here I'm forgetting a file"
$ git add forgotten_file.txt
$ git commit --amend
```



## Remotes

For now, we only have a local repository!

Why do we need a remote?
* Easy collaboration
  * Multiple users commit in the same remote repository
  * Safety when HD is corrupt
* Ability to work open source ( github )
