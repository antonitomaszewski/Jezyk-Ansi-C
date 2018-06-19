#include <stdio.h>

int main()
{
  int c;

  while (c = getchar() != EOF)
    printf("%d\n", c);
  printf("%d - to koniec pliku\n", c);
}
