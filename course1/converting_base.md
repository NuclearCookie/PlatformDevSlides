## Base <sub>x</sub>

* Decimal numbers
* Octal numbers
* Hexadecimal numbers
* Binary numbers



<!-- .slide: class="scrollable" -->
| Decimal | Hex | Octal | Binary |
| ------: |----:|------:|-------:|
| 0       | 0x0   | 0     | 0      |
| 1       | 0x1   | 1     | 1      |
| 2       | 0x2   | 2     | 10     |
| 3       | 0x3   | 3     | 11     |
| 4       | 0x4   | 4     | 100    |
| 5       | 0x5   | 5     | 101    |
| 6       | 0x6   | 6     | 110    |
| 7       | 0x7   | 7     | 111    |
| 8       | 0x8   | 10    | 1000   |
| 9       | 0x9   | 11    | 1001   |
| 10      | 0xA   | 12    | 1010   |
| 11      | 0xB   | 13    | 1011   |
| 12      | 0xC   | 14    | 1100   |
| 13      | 0xD   | 15    | 1101   |
| 14      | 0xE   | 16    | 1110   |
| 15      | 0xF   | 17    | 1111   |
| 16      | 0x10  | 20    | 10000  |
| 17      | 0x11  | 21    | 10001  |
| 18      | 0x12  | 22    | 10010  |
| 19      | 0x13  | 23    | 10011  |
| 20      | 0x14  | 24    | 10100  |



## How do you convert between numbers of different base?



### From base <sub>x</sub> to base <sub>10</sub>

0b1001 in decimal? <!-- .element: class="fragment" -->

| 2<sup>3</sup> | 2<sup>2</sup> | 2<sup>1</sup> | 2<sup>0</sup> |
| ------------- | ------------- | ------------- | ------------- |
| 1             | 0             | 0             | 1             |
<!-- .element: class="fragment" -->

->

<!-- .element: class="fragment" -->
| 1 * 8 | 0 * 4 | 0 * 2 | 1 * 1 |
| ---   | ---   | ---   | ---   |
| 8     | 0     | 0     | 1     |
<!-- .element: class="fragment" -->
8 + 0 + 0 + 1 =  9
<!-- .element: class="fragment" -->



### From base <sub>10</sub> to base <sub>x</sub>

18 in binary ( where 18 = y )?

* Find closest multiple of x <= y.
* perform tail division.

`18 / 16 = 1 | 2`

Write down the 1.

Check every smaller multiple and write down 0 ( 8, 4 )

`2 / 2 = 1 | 0`  Keep going until you reached 2<sup>0</sup>

| 2<sup>4</sup> | 2<sup>3</sup> | 2<sup>2</sup> | 2<sup>1</sup> | 2<sup>0</sup> |
| --- | --- | --- | --- | --- |
| 1 | 0 | 0 | 1 | 0 |



# Exercises



## converting numbers
- `0xB4DF00D` to decimal
- `0b1001110` to decimal
- `0o42` to decimal
- `44` to binary
- `123` to hexadecimal
- `82` to octal
- `0b1001011` to hexadecimal
- `0xF00` to binary


## converting numbers
- `0xB4DF00D` == `189657101`
- `0b1001110` == `78`
- `0o42` == `34`
- `44` == `0b101100`
- `123` == `0x7B`
- `82` == `0o122`
- `0b1001011` == `0x4B`
- `0xF00` == `0b111100000000`
