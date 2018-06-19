#include <stdio.h>

#define TABINC 8  /* odstęp między punktami tabulacyjnymi */

/* detab_new: zastąp znaki tabulacji odpowiednią liczbą odstępów */
int main()
{
  int c, nb, pos;

  nb = 0; /* liczba niezbędnych odstępów */
  pos = 1; /* pozycja znaku w wierszu */
  while ((c = getchar()) != EOF) {
    if (c == '\t') {  /* trafiliśmy na znak tabulacji */
      nb = TABINC - (pos - 1) % TABINC;
      while (nb > 0) {
        putchar(' '); /* zastąp tabulacjię spacjami */
        pos++;
        nb--;
      }
    } else if (c == '\n') { /* trafiliśmy na znak nowego wiersza */
      putchar(c);
      pos = 1;
    } else {  /* trafiliśmy na dowolny inny znak */
      putchar(c);
      ++pos;
    }
  }
}
