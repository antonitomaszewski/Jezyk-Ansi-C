#include <stdio.h>

#define NONBLANK 'b' /*dowolny znak różny od odstępu */

/* zastąp ciągi znaków odstępu jednym takim znakiem */

int main()
{
  int c, lastc;

  lastc = NONBLANK; /* ostatnio wczytany znak */
  while ((c = getchar()) != EOF)
  {
    if (c == 'a')
      break;
    if (c != ' ' || lastc != ' ')
      putchar(c);
    lastc = c;
  }
}
