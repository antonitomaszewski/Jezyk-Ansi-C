#include <stdio.h>

#define IN 1  /* wewnątrz słowa */
#define OUT 0 /* poza słowem */

/* zlicz wejściowe wiersze, słowa i znaki */

int main()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF)
  {
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
    if (c == 'a')
      break;
  }
  printf("%d %d %d\n", nl, nw, nc); /* 3 liczby całkowite */
}
