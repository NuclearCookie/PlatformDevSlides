## Take homework sample

Try to run in on a windows pc.


### Several problems:

* There is no .sln file
* Unknown includes
* Unknown function calls



## Cross platform programming

**1 frontend, multiple backends**

_The user should not write platform specific code_



### Solution 1: Virtuality

* Graphics platform
* Sound system

**Exercise:**
Write a simple program that accepts the following syntax:
`myprogram --backend="xx_renderer"`
You support a green console renderer and a red console renderer.
The program's output should be:
`Look mom! I'm colored text!`

Implement those backends using virtuality.

### Advantages of using virtuality

* Switch backends from command line ( or launcher )
* Clear code structure Base > Backend 1 or Base > Backend 2


## Drawbacks of using virtuality

* More Expensive. ( Julien will cover this topic )
* Need to know about each backend on each platform
* What if the choice is obvious ( file system backend )



## Solution 2: Platform specific code

It would be nice if we could have code that only compiles on a given platform.


## Writing Platform specific code

The 4 stages of compiling:

* Preprocessing
* Compiling
* Assembling
* Linking

| Preprocessing | Interpreting preprocessor commands ( # ), stripping comments, ..     |
| :------------ | :------------- |
| Compiling     | Translation C/C++ to assembly       |
| Assembling    | Assembling the assembly to _object code_ ( obj ) |
| Linking       | Adds missing code ( system functions ) and combines the obj files.|


## Use of the Preprocessor to write Platform specific code
