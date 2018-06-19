/* TEST PROGRAMU */

#include <stdio.h>

#define IN 1  /* wewnątrz słowa */
#define OUT 0 /* poza słowem */

/* zlicz wejściowe wiersze, słowa i znaki */

int main()
{
  int c, nl, nw, nc, state;  /* nl - newline (nowy wiersz)
                                nw - newword (nowy wyraz)
                                nc - newchar (nowy znak)
                                */

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == 'a')
      break;
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc); /* 3 liczby całkowite */
}


/* Wyniki ::
  brak == 0 0 0
  jeden znak == 1 1 2
  slowo dwuznakowe == 1 1 3
  dwa slowa jednoznakowe == 1 2 4
  dwa slowa jednoznakowe w dwóch wierszach == 2 2 3
*/
