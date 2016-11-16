## Continuous Integration ( CI )

Wikipedia definition:
> continuous integration (CI) is the practice of merging all developer working copies to a shared mainline several times a day

My definition:
> Continuous integration (CI) is the practice of automatically testing and reporting all changes on the shared mainline.


### How is it used

minimal usage:
Each time you push to master, a series of tests are run on servers ( multiple platforms )

extend to:
* when creating a PR
* each commit on each branch


### Advantages

* Automatically test **compilation** on your supported platforms
* Automatically run unit tests on your supported platforms
* Get coverage reports on your unit tests ( what branches did you forget? )


## Projects using it

1 example:
[EASTL](https://github.com/electronicarts/EASTL)
