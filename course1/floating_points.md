We have learned how to present whole numbers in binary.

How do we handle real numbers?

we want to represent numbers ranging from
* 0.000000000037 ( size in meter of a hydrogen atom ),
* all the way up to 149600000000 ( distance from earth to the sun in meters )

There is an infinite number of real numbers to be represented by only 32 bit.



## Scientific notation to the rescue

* 0.000000000037 = 3.7 * 10 <sup>-11</sup>
* 149600000000 = 1.49600 * 10<sup>10</sup>
---
* 3.7 and 1.49600 are the _significand_.
* the _exponent_ is the power to which 10 is raised
* by convention:  `1 <=  |significand| < 10`
* ( normalized scientific notation )

Notice: sign of the exponent != sign of the number.
* 0.035 = 3.5 * 10 <sup>-2</sup>
* -0.035 = -3.5 * 10 <sup>-2</sup>



## Scientific notation in binary

In decimal numbers, 1 <= |significand| < 10

Remember that decimal numbers have base 10. so in Binary:

`1 <= significand < 2` or `1 <= significand < 0b10`

example:

101.1101 is expressed as 1.011101 * 2 <sup>2</sup>

from `1 <= significand < 0b10` we can say that there is always only a 1 left of the binary point.



## ANSI/IEEE Std 754-1985

_IEEE Standard for Binary Floating-Point Arithmetic_

* Defines single precision ( 4 bytes ) format
* Defines double precision ( 8 bytes ) format


### Single precision

| Sign | Exponent | Significand |
| --- | --- | --- |
| 1 bit | 8 bit | 23 bit |

because there is always a 1 left of the binary point, we don't include it.

Only 23 bits are used to store the significand, but the precision is **24 bits**

The 8-bit exponent has range [0;255]. This is a _biased_ exponent. We need to subtract a number to get the _unbiased_ exponent.

**For single precision floating-point numbers, the bias is 127**


### Single precision

(-1)<sup>_s_</sup> * 1._f_ * 2<sup>_e_-127</sup>

where
* _s_ = sign bit
* _f_ = significand
* _e_ = exponent


####Special cases
| Sign | Exponent | Significand | Result                            |
| :--- | :------- | :---------- | --------------------------------: |
| 0    | 0        | 0           | 0                                 |
| 1    | 0        | 0           | -0 ( very small negative number ) |
| ?    | 0        | != 0        | unnormalized number               |
| 0    | 255      | 0           | Positive Infinity                 |
| 1    | 255      | 0           | Negative Infinity                 |
| ?    | 255      | != 0        | NaN                               |


### Single precision

24 bit signifcant is roughly equal to 7 decimal digits.

11111111 11111111 1111111 == 16777215

we say that single-precision floating-points offer a _precision_ of 24 bits, or 7 decimal digits.


### Double precision

| Sign | Exponent | Significand |
| --- | --- | --- |
| 1 bit | 11 bit | 52 bit |
