/* Liczy ilość wystąpień każdej cyfry, znaku białego oraz reszty (w jednej zmiennej) */

#include <stdio.h>

/* zlicz cyfry, białe znaki, inne */

int main()
{
  int c,i,nwhite,nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == 'a')
      break;
    if (c >= '0' && c <= '9')
      ++ndigit[c-'0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  }
  printf("cyfry =");
  for (i = 0; i < 10; ++i)
    printf(" %d", ndigit[i]);
  printf(", białe znaki = %d, inne = %d\n", nwhite, nother);
}
