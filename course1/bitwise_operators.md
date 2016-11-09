| Operator | Symbol | Form | Operation |
| -------- | :------: | ----: | --------- |
| left shift | << | x << y | all bits in x shifted left y bits |
| right shift | >> | x >> y | all bits in x shifted right y bits |
| bitwise NOT | ~ | ~x | all bits in x flipped |
| bitwise AND | & | x & y | each bit in x AND each bit in y |
| bitwise OR | &#124; | x &#124; y | each bit in x OR each bit in y |
| bitwise XOR | ^ | x ^ y | each bit in x XOR each bit in y |



## Left Shift

```
0010 1111 << 1 == 0101 1110
0010 1111 << 4 == 1111 0000
0010 1111 << 8 == 0000 0000
```


## Right Shift

```
0010 1111 >> 1 == 0001 0111
0010 1111 >> 4 == 0000 0010
0010 1111 >> 8 == 0000 0000
```

**Careful:**

```cpp
//signed right shift:
1000 0010 >> 1 == 1100 0001
0100 0010 >> 1 == 0010 0001
//or unsigned right shift:
1000 0010 >> 1 == 0100 0001
0100 0010 >> 1 == 0010 0001
```

Note that the standard does not specify this behavior.



## Bitwise NOT

```
~0010 1111 == 1101 0000
~1111 1111 == 0000 0000
~0000 0000 == 1111 1111
```



## Bitwise AND

```
0010 1111 & 1111 1111 == 0010 1111
0010 1111 & 0000 0000 == 0000 0000
0010 1111 & 1001 0110 == 0000 0110
```



## Bitwise OR

```
0010 1111 | 1111 1111 == 1111 1111
0010 1111 | 0000 0000 == 0010 1111
0010 1111 | 1001 0110 == 1011 1111
```



## Bitwise XOR

```
0010 1111 ^ 1111 1111 == 1101 0000
0010 1111 ^ 0000 0000 == 0010 1111
0010 1111 ^ 1001 0110 == 1011 1001
```

## What can we do with this?

Commonly used in games: bit flags.
