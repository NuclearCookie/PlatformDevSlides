# Strings strings strings



## How to represent strings in computers?

What do we need in a string?

* letters
* numbers
* punctuation
* whitespace
* special characters


## How to represent strings in computers?

map each element to a unique number:

example implementation 1:

| element | number      |
| :------ | :-----------|
| a       | `0000001`   |
| b       | `0000010`   |
| c       | `0000011`   |
| ...     | `...`       |

example implementation 2:

| element | number      |
| :------ | :-----------|
| .       | `0000001`   |
| ,       | `0000010`   |
| ?       | `0000011`   |
| ...     | `...`       |


## How to represent strings in computers?

Imagine 2 computers, 1 with string implementation 1, the other with string implementation 2.
Now try to run a string of computer 1 on computer 2.
`abc` became `.,?` !

**This ask for a standard!**


## String standards

First widely used standard to represent strings: **ASCII** ( first version: 1960 )

### American Standard Code for Information Interchange

_Ass-key_


## ASCII

Uses 7 bits. ( 128 characters )

split into 4 sections of 32 codes.

numbers + punctuation

| Hex code | ASCII Character | Hex code | ASCII Character |
|:---------|:----------------|:---------|:----------------|
| 20       | _Space_         | 30       | 0               |
| 21       | !               | 31       | 1               |
| 22       | "               | 32       | 2               |
| 23       | #               | 33       | 3               |
| 24       | $               | 34       | 4               |
| 25       | %               | 35       | 5               |
| 26       | &               | 36       | 6               |
| 27       | '               | 37       | 7               |
| 28       | (               | 38       | 8               |
| 29       | )               | 39       | 9               |
| 2A       | *               | 3A       | :               |
| 2B       | +               | 3B       | ;               |
| 2C       | ,               | 3C       | <               |
| 2D       | -               | 3D       | =               |
| 2E       | .               | 3E       | >               |
| 2F       | /               | 3F       | ?               |


uppercase + punctuation

| Hex code | ASCII Character | Hex code | ASCII Character |
|:---------|:----------------|:---------|:----------------|
| 40       | @               | 50       | P               |
| 41       | A               | 51       | Q               |
| 42       | B               | 52       | R               |
| 43       | C               | 53       | S               |
| 44       | D               | 54       | T               |
| 45       | E               | 55       | U               |
| 46       | F               | 56       | V               |
| 47       | G               | 57       | W               |
| 48       | H               | 58       | X               |
| 49       | I               | 59       | Y               |
| 4A       | J               | 5A       | Z               |
| 4B       | K               | 5B       | [               |
| 4C       | L               | 5C       | \               |
| 4D       | M               | 5D       | ]               |
| 4E       | N               | 5E       | ^               |
| 4F       | O               | 5F       | _               |

lowercase + punctuation

| Hex code | ASCII Character | Hex code | ASCII Character |
|:---------|:----------------|:---------|:----------------|
| 60       | `               | 70       | P               |
| 61       | a               | 71       | q               |
| 62       | b               | 72       | r               |
| 63       | c               | 73       | s               |
| 64       | d               | 74       | t               |
| 65       | e               | 75       | u               |
| 66       | f               | 76       | v               |
| 67       | g               | 77       | w               |
| 68       | h               | 78       | x               |
| 69       | i               | 79       | y               |
| 6A       | j               | 7A       | z               |
| 6B       | k               | 7B       | {               |
| 6C       | l               | 7C       | |               |
| 6D       | m               | 7D       | }               |
| 6E       | n               | 7E       | ~               |
| 6F       | o               |          |                 |


## Notes:

Very easy to convert cases: a difference of `20h` between the same character with a different case.


## Where are the missing 33 characters?

control characters:

* Most are useless now:
  * Dates back from teletypewriters:
  * SOH ( Start of Heading )
  * EOT ( End of Transmission )
  * ...
* Some are still used:
  * CR: Carriage return
  * LF: Line Feed
  * Tab


## How is this implemented?

Standard C strings:
```c
char greetings[] = "Hello World";
```

an array of values of 8 bit ( normally ).
**Dangerous!** watch out for buffer overflow.

C++:
```c++
std::string greetings = "Hello World";
```

## Problems with ASCII

**It's really american!**

* `24h` is the $ sign. but how do we display the £ or ¥ or € symbol?
* What about accents?
* Other punctuation marks? (¿ ¡)
* Other character sets ( eastern languages, hebrew, arabic, ..)


## Solutions for ASCII

ASCII defines 10 codes to be redefined for national uses.
In addition, the # sign can be replaced by the £ sign, and the $ sign can be replaced by the generalized currency sign ¤.

ASCII uses only 7 bit.
Almost all computers systems characters as an 8 bit values.
This means we have 128 extra characters to define!

* Latin Alphabet No. 1
* Shift-JIS
* DBCS


## Solutions for ASCII: Unicode

First version of unicode: 1991
Unicode is a 16-bit code.
Unicode can represent 65536 different characters!

More than enough for all the world's languages + extra


_or is it..._

Unicode 2.0: 1996

Unicode is now a 32-bit code.
+ 1 million code points!

* Hieroglyphs
* rarely used Kanji or Chinese characters

Currently: Unicode 9.0: 2016

* More languages
* Emoji!!

Currently, 128237 characters are represented.



## Unicode

* First 128 characters are the same as in ASCII ( compatible ) ( 0x0000 through 0x007F )
* Latin Alphabet No.1 extension is in there ( 0x00A0 through 0x00FF )
* Other standards also incorporated.

Sadly, ASCII is really widely used in computers :(


## How to represent Unicode in a pc

* UTF-8
* UTF-16
* UTF-32

UTF = Unicode Transformation Format


## UTF-32

Each character uses 4 bytes.

`A = 00000000 00000000 00000000 01000001`
`水 = 00000000 00000000 01101100 00110100`

* Most characters used: ASCII ( ony 7 bit... )
* A lot of wasted memory
* Fixed size: easy to index and count


## UTF-16

Each character can be represented by 4 bytes _or_ 2 bytes

`A = 00000000 01000001`
`水 = 01101100 00110100`
`𝄞 = 11011000 00110100 11011101 00011110` ( 2 surrogates )


## UTF-8

Each character can be represented by 4 bytes _or_ 3 bytes _or_ 2 bytes _or_ 1 byte

`A = 01000001`
`水 = 11100110 10110000 10110100`
`𝄞 = 111011100 10001000 10111100`


## UTF-8: How to split a codepoint across bytes

We use a stream of bytes. some points will be 1 byte, other will be 2 / 3 / 4. We don't know.
How can know where a character starts?

* For a 1 byte code point: leading bit is 0.
* For a 2 byte code point: bytes are split like this: 110bbbaa 10aaaaaa
* For a 3 byte code point: bytes are split like this: 1110bbbb 10bbbbaa 10aaaaaa
* For a 4 byte code point: bytes are split like this: 11110ccc 10ccbbbb 10bbbbaa 10aaaaaa


## Handy table from wikipedia:

| Codepoints         | UTF-32 | UTF-16 | UTF-8 | Notes on UTF-8|
| :-------------     | :-------------                       | :-------------                      | :-------------                       | :------------- |
| U+0000..U+007F     | 00000000 00000000<br/>00000000 0aaaaaaa | 00000000 0aaaaaaa                   | 0aaaaaaa                             | ASCII equivalents; byte starts with 0bit |
| U+0080..U+07FF     | 00000000 00000000<br/>00000bbb aaaaaaaa | 00000bbb aaaaaaaa                   | 110bbbaa 10aaaaaa                    | First byte starts with 110, second with 10 |
| U+0800..U+FFFF     | 00000000 00000000<br/>bbbbbbbb aaaaaaaa | bbbbbbbb aaaaaaaa	                  | 1110bbbb 10bbbbaa<br/>10aaaaaa      	 | First byte starts with 1110, others with 10 |
| U+010000..U+10FFFF | 00000000 000ccccc<br/>bbbbbbbb aaaaaaaa | 110110cc cccbbbbb 110111bb aaaaaaaa | 11110ccc 10ccbbbb<br/>10bbbbaa 10aaaaaa | First byte starts with 11110, others with 10 |


## Exercise

Write a UTF-8 Iterator.

### Requirements:

* utf8_iterator class
  * Constructor:
    * takes std::string as constructor argument
    * prepares the iterator to access the first char
  * Necessary operators for iterators

Expected usage:

```cpp
utf8_iterator
    iterator(u8"abcd\u03A3ef\u03C0");
uint32_t
    count = 0;

    for( auto char : iterator )
    {
        count++;
        if ( *iterator == 0x03A3 ) {
            std::cout << "Found greek character at " << count << std::endl;
        }
        else if ( *iterator == 0x03C0 ) {
            std::cout << "Found pi at " << count << std::endl;
        }
    }

    std::cout << "Total character count: " << count;
    // would expect this output:
    // Found greek character at 5
    // Found pi at 8
    // Total character count: 8
```
