#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

/* usuń wszystkie komentarze z POPRAWNEGO programu w C */

main()
{
  int c, d;

  while ((c = getchar()) != EOF)
    rcomment(c);
  return 0;
}

/* rcomment: czytaj każdy znak, usuń komentarze */
void rcomment(int c)
{
  int d;

  if (c == '/) {
    if ((d = getchar()) == '*') { //d jest typu int, o co chodzi?. a potem przecierz wywołuje rcomment, które właśnie potrzebuje inta
      in_comment(); /* początek komentarza */
    } else if (d == '/') {
      putchar(c); /* drugi znak / */
      rcomment(d);
    } else {
      putchar(c); /* to nie jest znak komentarza */
      putchar(d);
    }
  } else if (c == '\'' || c == '"') {
    echo_quote(c);  /* to początek stałej */
  } else {
    putchar(c); /* to nie jest komentarz */
  }
}

/* in_comment: szukaj końca POPRAWN komentarza */
void in_comment(void)
{
  int c, d;

  c = getchar();    /* poprzedni znak */
  d = getchar();    /* bieżący znak */
  while (c != '*' || d != '/') {  /* szukaj końca, chyba powinno być && */
    c = d;
    d = getchar();
  }
}

/* echo_quote: wypisz tekst stałej i znajdź jego koniec */
void echo_quote(int c)
{
  int d;

  putchar(c); /* wypisz znak otwierający stałą */
  while ((d = getchar()) != c) {
    putchar(d); /* wypisz jej tekst */
    if (d == '\\')
      putchar(getchar()); /* pomiń sekwencję specjalną */
  }
  putchar(d); /* wypisz znak kończący stałą */
}
