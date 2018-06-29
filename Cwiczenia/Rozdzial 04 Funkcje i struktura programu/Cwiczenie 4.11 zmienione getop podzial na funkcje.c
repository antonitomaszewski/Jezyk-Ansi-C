#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'  /* sygnał znalezienia liczby */

int getch(void);
void liczba_dzialania(char s[]);
void pomin_biale_znaki(char s[]);
bool czy_operator(char c);

int getop(char s[])
{
  int c, i;
  static int lastc = 0; /* ostatnio wczytany znak */

  if (lastc == 0)
    c = getch();
  else {
    c = lastc;
    lastc = 0;
  }
  pomin_biale_znaki(s);
  if (czy_operator(s[0]))
    return s[0];
  liczba_dzialania(s);
  if (c != EOF)
    lastc = c;
  return NUMBER;  /* to liczba */
}



void pomin_biale_znaki(char s[])
{
  char c;
  while ((c = getch()) == ' ' || c == '\t')
    c = getch();
  s[0] = c;
  s[1] = '\0';
}

bool czy_operator(char c)
{
  return !isdigit(c) && c != '.';
}

void liczba_dzialania(char s[])
{
  int i = 0;
  char c;

  c = s[i];
  if (isdigit(c)) /* całkowita */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* ułamkowa */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
}
