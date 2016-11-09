#include <iostream>

uint8_t halfAdder( uint8_t left, uint8_t right, uint8_t & carry_out )
{
    uint8_t result_bit = left ^ right;
    carry_out = left & right;
    return result_bit;
}

template<typename T>
T add( T left, T right )
{
    T result = 0;
    uint8_t carry_bit = 0;
    for(unsigned int i = 0; i < sizeof(T) * 8; ++i) {
        uint8_t left_bit = ( left >> i ) & 1;
        uint8_t right_bit = ( right >> i ) & 1;
        uint8_t carry_in = carry_bit;
        uint8_t sum_bit = halfAdder( left_bit, right_bit, carry_bit );
        uint8_t second_carry_bit = 0;
        sum_bit= halfAdder( sum_bit, carry_in, second_carry_bit );
        carry_bit |= second_carry_bit;

        result |= ( sum_bit << i );
    }
    return result;
}

int main()
{
    int8_t test;
    test = add(50, 60);
    std::cout << "sum of a and b is : " << static_cast<int>(test);
}
