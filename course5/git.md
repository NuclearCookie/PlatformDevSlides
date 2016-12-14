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


## Available Remotes

Without any setup:
* github
* gitlab
* bitbucket
* ...


## Adding a repository to a remote

`git remote add <origin> url@the.remote`


## Syncing with the remote

Getting the latest changes from the remote

```bash
$ git fetch # gets information on what has changed
$ git pull origin master # pulls the master branch from the remote "origin" into your branch
```

Adding your commits to the remote

```bash
$ git push origin master
```


## Merging

What happens if you want to push to a remote, but someone else also pushed!

```bash
$ git push origin master
# ! [rejected] master -> master (non-fast-forward)
# error: failed to push some refs to 'https://github.com/xxx/MyFirstRepo.git'
# hint: Updates were rejected because the tip of your current branch is behind
# hint: its remote counterpart. Integrate the remote changes (e.g.
# hint: 'git pull ...') before pushing again.
# hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

```bash
$ git pull origin master
$ git push origin master
```


## Merging

```bash
$ git pull origin master
# there were conflicts!
```

Time to start the merge tool!

`git mergetool`

When done, add resolved conflicts to stage to mark completion


## Branches

Why branches?

Branches can be used to 
* work on 2 features at once without sharing the code
* Have a stable code branch (master) and working branches (develop)
* Create a merge request


Creating branches

```bash
$ git branch feature
$ git checkout feature
# or shorthand:
$ git checkout -b feature
```

navigating branches

```bash
$ git checkout master
$ git checkout feature
```


## Merging

When finishing work on a branch, we want to merge that branch into the develop / master branch.

develop / master branch are branches with finished features.


```bash
$ git fetch
$ git checkout master
$ git merge origin/feature
$ git push origin master
```

or go through the merge request panel of your remote.


## Git flow

Organized way of working with branches.

![git flow](images/git-flow.png)

handy tool to enforce git flow:

[https://github.com/nvie/gitflow](https://github.com/nvie/gitflow)


## Must reads

The pro git book:
(http://git-scm.com/book)[http://git-scm.com/book]
