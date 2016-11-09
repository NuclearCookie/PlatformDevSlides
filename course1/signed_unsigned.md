### Unsigned char:

| decimal | binary |
| --- | --- |
| 0 | 0 |
| 1 | 1 |
| 2 | 10 |
| ... | ... |
| 127 | 0111 1111 |
| 255 | 1111 1111 |

What about negative values?



We are already using all possible values in the 8 bit range..

Solution:

change range from [0;255] to [-128;127]

How do we represent this?



We could go for adding a sign bit:

| decimal | binary |
| --- | --- |
| 0 | 0 |
| 1 | <span style='color:red'>0</span>000 0001 |
| -1 | <span style='color:red'>1</span>000 0001 |
| 2 | <span style='color:red'>0</span>000 0010 |
| -2 | <span style='color:red'>1</span>000 0010 |
| ... | ... |
| 127 | <span style='color:red'>0</span>111 1111 |
| -127 | <span style='color:red'>1</span>111 1111 |



### Let's see if this is ok...

* Problem 1: we have 1 value that is not used: 1000 0000
( negative 0 ??)
* Problem 2: Let's look at operations.



105 + 77 = 182

| | 0110 1001 |
| --- | ---: |
|+| 0100 1101 |
| | 1011 0110 |

105 - 77 = 28

| | 0110 1001 |
| --- | ---: |
|-| 0100 1101 |
| | 0001 1100 |



A computer needs to implement the hardware for math operations.
How can we rewrite a subtraction so that it uses the same system as addition?

a - b == a + ( -b )
<!-- .element: class="fragment" -->

**right?**
<!-- .element: class="fragment" -->



105 - 77 = 28

| | 0110 1001 |
| --- | ---: |
|-| 0100 1101 |
| | 0001 1100 |

105 + -77 = 28

| |  0110 1001 |
| --- | ---: |
|+|  1100 1101 |
| | 10011 0110 |

wait, 105 + -77 = 310 !?



## Complementary numbers.
What is a complementary number?

A complementary number is the number obtained by subtracting a number from its base.

For example:

The nine's complement of 23 is 76 because 23 + 76 = 99, which is the nine's base of 23.

Knowing this, we can rewrite our subtraction:

```
105 -77
105 -77 + 100 - 100
105 -77 + 99 + 1 - 100
105 + (99 - 77) + 1 - 100
```



105 + (99 - 77) + 1 - 100

| | 105 |
| --- | ---: |
|-| 77 |
| | 28 |

==

| | 105 |
| --- | ---: |
|+| 22 |
|+| 1 |
|-| 100 |
| | 28 |



| | 0110 1001 |
| --- | ---: |
|-| 0100 1101 |
| | 0001 1100 |

What is the one's complement of a binary number?



The inverse! `0000 0001 + 1111 1110 = 1111 1111`

| |   0110 1001 |
| --- | ---: |
|+|   1011 0010 |
|+|   0000 0001 |
|-| 1 0000 0000 |
| | 0 0001 1100 |

Now also note that the - 1 0000 0000 is not really necessary because we only have 8 bits memory available.



We have just rewritten a negative value as its one's complement + 1.

**This is called the two's complement.**

0000 0001 + 1111 1111 = 1 0000 0000



### Signed char

We have now a very good binary representation of negative and positive whole numbers.

| decimal | binary |
| --- | --- |
| 127 | 0111 1111 |
| 2 | 0000 0010 |
| 1 | 0000 0001 |
| 0 | 0 |
| -1 | 1111 1111 |
| -2 | 1111 1110 |
| -128 | 1000 0000 |

As you can see:
* We still have the signing bit
* We use all binary combinations [-128;127]
* We can easily perform arithmatic operations on positive and negative values



We can verify this implementation when we overflow.

```cpp
#include <cstdio>

int main()
{
  char will_overflow = 127;
  will_overflow++;
  printf("%i", will_overflow);
}
```
will output: -128.

```cpp
#include <cstdio>

int main()
{
  unsigned char will_not_overflow = 127;
  unsigned char will_overflow = 255;
  will_not_overflow++;
  will_overflow++;
  printf("127 became %i, while 255 became %i", will_not_overflow, will_overflow);
}
```
will output: 127 became 128, while 255 became 0



## How can we easily change the sign of a number through bit manipulation?

| decimal | binary |
| --- | --- |
| 1 | 0000 0001 |
| -1 | 1111 1111 |
| 2 | 0000 0010 |
| -2 | 1111 1110 |
| 127 | 0111 1111 |
| -127 | 1000 0001 |

Do you see a correlation?



### To change the sign of a signed integer we invert the values and add 1.

!0000 0001 = 1111 1110<br/>
1111 1110 + 1 = 1111 1111

and back:

!1111 1111 = 0000 0000<br/>
0000 0000 + 1 = 0000 0001



### This is called the Two's complement
