#include <stdio.h>

char buf = 0;

/* getch: wex znak, byćmoże oddany na wejście */
int getch(void)
{
  int c;

  if (buf != 0)
    c = buf;
  else
    c = getchar();
  buf = 0;
  return c;
}

/* ungetch: oddaj znak z powrotem na wejście */
void ungetch(int c)
{
  if (buf != 0)
    printf("Ungetch: za wiele zwrotów\n");
  else
    buf = c;
}
