/* kopa wejście -> wyjście, z pominięciem końcowych znaków białych oraz usunięciem pustych wierszy */
#include <stdio.h>

#define MAXLINE 20  /* maksymalny rozmiar wiersza */

int getline_new(char line[], int maxline);
int remove_new(char s[]);

/* usuń końcowe znaki odstępu i tabulacji oraz puste wiersze */
int main()
{
  char line[MAXLINE]; /* bieżący wiersz z wejścia */

  while (getline_new(line, MAXLINE) > 0)
    if (remove_new(line) > 0)
      printf("%s", line);
  return 0;
}

/* remove_new: usuwa końcowe znaki odstępu i tabulacji z s */
int remove_new(char s[])
{
  int i;

  i = 0;
  while (s[i] != '\n')  /* znajdź znak nowego wiersza */
    ++i;
  --i;  /* cofnij się o jeden znak */
  while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
    --i;  /* pomiń od końca białe znaki */

  if (i >= 0) { /* jeśli wiersz nie jest pusty */
    ++i;
    s[i] = '\n';  /* oddaj znak nowego wiersza */
    ++i;
    s[i] = '\0';  /* dodaj znacznik końca tekstu */
  }
  return i;
}

/* getline: wczytaj wiersz do s, podaj jego długość */
int getline_new(char s[], int lim)
{
  int c, i, j;

  j = 0;
  for (i = 0; (c = getchar()) != EOF && c!= '\n'; ++i)
    if (i < lim - 2) {
      s[j] = c; /* wiersz ciągle w granicach */
      ++j;
    }
  if (c == '\n') {
    s[j] = c; /* koniec wiersza */
    ++j;
    ++i;
  }
  s[j] = '\0';
  return i;
}
