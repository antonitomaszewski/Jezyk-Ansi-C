#include <stdio.h>

/* zlicz znaki odstępu, tabulacji i nowego wiersza */

int main()
{
  int c, nb, nt, nl;

  nb = 0;   /* liczba znaków odstępu */
  nt = 0;   /* liczba znaków tabulacji */
  nl = 0;   /* liczba znaków nowego wiersza */

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
      ++nb;
    else if (c == '\t')
      ++nt;
    else if (c == '\n')
      ++nl;
    else if (c == 'a')
      break;
  }
  printf("%d %d %d\n", nb, nt, nl);
}
