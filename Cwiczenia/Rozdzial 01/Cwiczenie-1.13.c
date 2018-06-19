#include <stdio.h>

#define MAXHIST 5   /* maksymalma długość histogramu */
#define MAXWORD 11  /* ograniczenie długości słowa */
#define IN 1        /* w słowie */
#define OUT 0       /* poza słowem */

/* wypisz histogram długości słów poziomo */

int main()
{
  int c, i, nc, state;  /* char, iterator, numberofchars, stan */
  int len;            /* długość każdego wykresu */
  int maxvalue;       /* maks. licznik wśród elementów w1[] */
  int ovflow;         /* liczba za długich słów */
  int w[MAXWORD];     /* licznik słów o długości == indeks */

  state  = OUT; /* poza słowem */
  nc     = 0;   /* liczba znaków w słowie */
  ovflow = 0;   /* liczba słów = MAXWORD lub dłuższe */

  for (i = 0; i < MAXWORD; ++i) /* wypełniam 'w' zerami */
    w[i] = 0;

  while ((c = getchar()) != 'a') /* zamiennie na EOF */
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT; /* koniec słowa */
      if (nc > 0)
        if (nc < MAXWORD)
          ++w[nc]; /* słowa o długośći nc */
        else
          ++ovflow;  /* słowo za długie */
      nc = 0;
    } else if (state == OUT)
    {
      state = IN; /* początek słowa */
      nc = 1;
    } else  /* wewnątrz słowa */
      ++nc;
  }
  maxvalue = 0;
  for (i = 1; i < MAXWORD; ++i)
    if (w[i] > maxvalue)
      maxvalue = w[i];  /* maks. licznik słów */
  for (i = 1; i < MAXWORD; ++i) /* dla każdego licznika */
  {
    printf("%5d - %5d : ", i, w[i]);
    if (w[i] > 0){
      if ((len = w[i] * MAXHIST / maxvalue) <= 0)
        len = 1;  /* skalowanie wykresu */
    } else
      len = 0;
    while (len > 0) /* drukowanie wykresu */
    {
      putchar('*'); /* poziomo */
      --len;
    }
    putchar('\n');
  }
  if (ovflow > 0)
    printf("Było %d słów równych lub dłuższych niż %d\n", ovflow, MAXWORD);
}
