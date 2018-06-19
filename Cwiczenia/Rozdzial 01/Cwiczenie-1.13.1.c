// DLA ZERA ZNAKÓW WYRZUCA BŁĄD :: Błąd w obliczeniach zmiennoprzecinkowych (zrzut pamięci)

#include <stdio.h>

#define MAXHIST 15  /* maksymalna długość histogramu */
#define MAXWORD 11  /* ograniczenie długości słowa */
#define IN 1        /* w słowie */
#define OUT 0       /* poza słowem */

/* wypisz histogram długości słów pionowo */

int main()
{
  int c, i, j, nc, state;
  int maxvalue;   /* maks. licznik wśród elementów w[] */
  int ovflow;     /* liczba za długich słów */
  int w[MAXWORD]; /* liczniki słów o długości == indeks */

  state = OUT;    /* poza słowem */
  nc = 0;         /* liczba znaków w słowie */
  ovflow = 0;     /* liczba słów == MAXWORD lub dłuższych */

  for (i = 0; i < MAXWORD; ++i)
      w[i] = 0;
  while ((c = getchar()) != 'a')  /* zamiennie EOF */
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;  /* koniec słowa */
      if (nc > 0)
        if (nc < MAXWORD)
          ++w[nc];  /* słowa o długości nic */
        else
          ++ovflow; /* słowo za dlugie */
      nc = 0;
    } else if (state == OUT)
    {
        state = IN; /* początek słowa */
        nc = 1;
    } else          /* wewnątrz słowa */
        ++nc;
  }
  maxvalue = 0;
  for (i = 0; i < MAXWORD; ++i)
    if (w[i] > maxvalue)
      maxvalue = w[i];  /* maks. licznik słów */
  /*for (i = 0; i < MAXWORD; ++i)
    printf("%d ,", w[i]);
  printf("%d = maxvalue", maxvalue); */
  for (i = MAXHIST; i > 0; --i)  /* dla każdego wiersza */
  {
    printf (" ");
    for (j = 1; j < MAXWORD; ++j) /* wszystkie liczniki */
      if (w[j] * MAXHIST / maxvalue >= i) //|| (i == 1 && w[j] > 0))
        printf ( " *  ");
      else
        printf("  ");
    putchar('\n');
  }
  for (i = 1; i < MAXWORD; ++i)
    printf("%3d ", i);
  putchar('\n');
  for (i = 1; i < MAXWORD; ++i)
    printf("%3d ", w[i]);
  putchar('\n');
  if (ovflow > 0)
    printf("Było %d słów równych lub dłuższych niż %d\n", ovflow, MAXWORD);
}
