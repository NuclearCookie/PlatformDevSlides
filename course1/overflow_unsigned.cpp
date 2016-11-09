#include <cstdio>

int main()
{
  unsigned char will_not_overflow = 127;
  unsigned char will_overflow = 255;
  will_not_overflow++;
  will_overflow++;
  printf("127 became %i, while 255 became %i", will_not_overflow, will_overflow);
}
