/* Każde słowo wejściowe wypisze w osobnym wierszu */

#include <stdio.h>

#define IN 1  /* w słowie */
#define OUT 0 /* poza słowem */

/* przepisz wejście na wyjście po jednym słowie w wierszu */

int main()
{
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF)
  {
    if (c == 'a')
      break;
    if (c == ' ' || c == '\n' || c == '\t')
    {
      if (state == IN)
      {
        putchar('\n');  /* koniec słowa */
        state = OUT;
      }
    } else if (state == OUT)
    {
      state = IN;       /* początek słowa */
      putchar(c);
    } else
        putchar(c);     /*wewnątrz słowa */
  }
}
