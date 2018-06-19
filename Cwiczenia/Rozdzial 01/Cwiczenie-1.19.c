/* Funkcja reverse_new odwracająca kolejność znaków tekstu w argumencie s */

#include <stdio.h>

#define MAXLINE 20  /* maksymalny rozmiar wiersza */

int getline_new(char line[], int maxline);
void reverse_new(char s[]);

/* odwróć kolejno wszystkie wiersze wejściowe */
int main()
{
  char line[MAXLINE]; /* bieżący wiersz z wejścia */

  while (getline_new(line, MAXLINE) > 1) {
    reverse_new(line);
    printf("%s", line);
  }
  return 0;
}

/* reverse_new: odwróśckolejność znaków tekstu s */
void reverse_new(char s[])
{
  int i, j;
  char temp;    /* tymczasowe miejsce na znak */

  i = 0;
  while (s[i] != '\0')  /* znajdź znacznik końca tekstu */
    ++i;
  --i;  /* cofnij się przed znacznik końca tekstu */
  if (s[i] == '\n') /* znak nowego wiersza */
    --i;

  j = 0;  /* początek nowego tekstu w s */
  while (j < i) {
    temp = s[j];
    s[j] = s[i];  /* zamień znaki miejscami */
    s[i] = temp;
    --i;
    ++j;
  }
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
