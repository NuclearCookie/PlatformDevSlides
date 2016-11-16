## Unit testing

Testing of individual pieces of code to assure correctness.

> A unit test provides a strict, written contract that the piece of code must satisfy


### Benefits

* Find problems early ( write test as you write the code )
* Facilitates change ( code will always be tested )
* Simplifies integration ( easier to accept a change if a test has been written )
* Documentation ( tests show the intended use )


### Rules

* When you write a function or a method, Try to write a test for it.
* A test should not cross class boundaries
* Try to cover as many cases as possible
* If you found a bug with a unit afterwards, add the bug to the unit test!


### Difficulties

* No way to test how different units work together
* Setting up realistic and useful tests
* Testing should be enforced! ( CI, see later chapter )


### Test driven development ( TDD )

Write the test before the method.
Make the test succeed.

* Keeps functionality simple.
* Prevents untested code


## Behavior driven development ( BDD )

Like TDD but focusses on tests that describe _behavior_ over a test of implementation.

Non-programmers can design BDD teests for a design.
