#include <stdio.h>

#define NONBLANK 'a'  /* dowolny znak różny od odstępu */

/* zastąp ciągi znaków odstępu jednym takim znakiem */

int main()
{
  int c, lastc;

  lastc = NONBLANK;   /* ostatnio wczytany znak */
  while ((c = getchar()) != EOF)
  {
    if (c != ' ')
      putchar(c);
    if (c == ' ')
      if (lastc != ' ')
        putchar(c);
    lastc = c;
    if (c == 'a')
      break;
  }
}
