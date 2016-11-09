#include <iostream>

int8_t abs( int8_t input )
{
    if( ( input & 0x40 ) == 0x40)
    {
        input = ~input;
        input++;
    }
    return input;
}

int main()
{
    int8_t test = -50;
    test = abs(test);
    std::cout << "Inverse of input is : " << static_cast<int>(test);
}
