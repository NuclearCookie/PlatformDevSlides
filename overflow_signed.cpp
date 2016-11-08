#include <cstdio>

int main()
{
  char will_overflow = 127;
  will_overflow++;
  printf("%i", will_overflow);
}
