## Strings in games


## Strings in games

Strings are one of the most allocated resources in games.
* File paths
* Names
* UI texts
* Tutorials
* ...


## How much memory does a string take?
```cpp
class SimpleString
{
private:
    char *
        buffer;
    uint_32
        length;

public:

    SimpleString(char * array)
    {
        length = strlen(array);
        buffer = array;
    }
}
SimpleString("hello world");
// h + e + l + l + o +  + w + o + r + l + d + \0
// == 12 * 1 byte + 4 byte = 16 byte.
```


## How does std implement strings?

compiler specific.

usually:
* Short String Optimization ( SSO )
  --> Short strings live on the stack.
* Shrinking used characters does not shrink capacity ( no re-allocation )


## Strings in games

Remember. Allocations are expensive!
How can we improve on strings?


## Strings in games

* Reduce the amount of used strings: replace them with integers
  * Inconvenient: reduces readability
  * Very good when the string is used as key in a map
* Short string optimization
* use fixed size char[]. **Don't do this! dangerous!**
* Use different kind of strings where you can.


## Different kind of strings in games


### Normal strings

The good old wrapped char * array with extra functionality and safety.

* Temporary strings
* Passing ownership to another class
* Other


### Preallocated string streaming

Create a pre-allocated buffer ( 1024 bytes for example ). fill it with any type using operator <<.

* Appending strings, or other types
* Avoids re-allocations due to small string capacity
* Not the case in std::stringstream!!


### String interning

Storing only 1 copy of each distinct string value.
```cpp
interned_string one("hello");
interned_string two("hello");
interned_string three("world!");

// one and two reference the same char * array.
assert(one.getStringArray() == two.getStringArray() );
assert(one.getStringArray() != three.getStringArray() );
```

* No modifications
* Used in a lot of places
* Comparing 2 interned strings ( compare data pointer )
* Expensive to create.
  * strings stored in data container. requires search in container.
  * + potential allocation and insertion if not found.
* repeated strings take less memory

```cpp
class file_description
{
private:
    interned_string directory;
    string file_name;
};
// all files in this directory will use the same directory string.
```


## String views and sub strings

Doesn't copy a string. Takes a view on the data pointer.

* Pass a string to a function that does not take ownership
* Avoids allocations
* No null termination with substrings! Be careful.

```cpp
sub_string getExtension()
{
    uint23_t count = getExtensionCharacterCount();
    return sub_string(file_path.c_str() + file_path.length() - count, count);
}

// use
// note use of strncmp. gives length to check.
if ( strncpm( path.getExtension(), ".exe", 4 ) == 0 )
{
    // do something
}
```


### String hash

String hash: converts a string to a unique number.

* No modifications.
* No need to print the string.
* Comparing strings.
* Used as keys in maps


<!-- .slide: class="smaller_text" -->
### String types overview

| String type | Owns memory | Creation cost | text available | \0 terminated | compare cost |
|:---------|:----------------|:---------|:----------------|:----------------|:---|
| normal string       | yes      | +       | yes    | yes | + |
| string stream       | yes      | 0       | yes    | yes | n/a |
| string interning    | yes (shared)  | +++ | yes | yes | 0 |
| string views        | no       | 0       | yes    | no | + |
| string hash         | yes      | 0       | no     | n/a | 0 |


### Exercise:

Implement a string hasher!


#### Requirements:
* Take a look at FNV hashes
* Implement a function:
  * Loop over each character
  * create a hash of the complete string.

* Bonus:
  * When finished, implement the hashing algorithm using templates.
  * This can now be a constant evaluator ( resolved at compile time! )
