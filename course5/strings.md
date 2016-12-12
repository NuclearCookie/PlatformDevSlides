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

First widely used standard to represent strings: **ASCII**

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
