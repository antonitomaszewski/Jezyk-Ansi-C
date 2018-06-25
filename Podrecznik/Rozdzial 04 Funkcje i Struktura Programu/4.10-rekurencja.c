#include <stdio.h>

/* printd: wypisz n dziesiętnie */
void printd(int n)
{
  if (n < 0) {
    putchar ('-');
    n = -n;
  }
  if (n / 10)
  printd(n / 10);
  putchar(n % 10 + '0');
}
