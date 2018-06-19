/*  Wypisz wszystkie wiersze wejściowe dłuższe niż 80 znaków */
#include <stdio.h>

#define MAXLINE 1000  /* maksymalny rozmiar wiersza */
#define LONGLINE 10   /* dolne ograniczenie rozmiaru */

int getline_new(char line[], int maxline);

/* wypisz wiersze dłuższe niż LONGLINE */
int main()
{
  int len;  /* długość bieżącego wiersza */
  char line[MAXLINE]; /* kopia bieżącego wiersza */

  while ((len = getline_new(line, MAXLINE)) > 1)
    if (len > LONGLINE)
      printf("%s", line);
  return 0;
}


/* getline_new: wczytaj wiersz do s, podaj jego długość */
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
