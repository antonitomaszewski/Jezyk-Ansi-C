#include <stdio.h>

/* zastąp znaki tabulacji i cofania czytelnymi sekwencjami */

int main()
{
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == 'a')
      break;
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else putchar(c);
  }
}
