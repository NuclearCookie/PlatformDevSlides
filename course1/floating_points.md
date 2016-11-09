We have learned how to present whole numbers in binary.

How do we handle real numbers?

we want to represent numbers ranging from
* 0.000000000037 ( size in meter of a hydrogen atom ),
* all the way up to 149600000000 ( distance from earth to the sun in meters )

There is an infinite number of real numbers to be represented by only 32 bytes.



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
