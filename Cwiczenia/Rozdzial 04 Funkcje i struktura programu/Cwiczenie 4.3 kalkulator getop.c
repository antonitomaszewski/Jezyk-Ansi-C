#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUMBER '0'  /* sygnał znalezienia liczby */

int getch(void);
void ungetch(int);

/* getop: pobierz następny operator lub liczbę */
int getop(char s[])
{
        int i, c;

        i = 0;
        do {
                c = getch();
        } while (c == ' ' || c == '\t');
        s[i] = c;
        s[++i] = '\0';
        if (!isdigit(c) && c != '.' && c != '-')
                return c; /* to nie liczba tylko operator */
        // i = 1;
        // if(isdigit(c))  /* buduj część całkowitą */
        //         do {
        //                 c = getch();
        //                 i++;
        //                 s[i] = c;
        //         } while (isdigit(c));
        if (c == '-') {
          if (isdigit(c = getch()) || c == '.')
            s[++i] = c; /* liczba ujemna */
          else {
            if (c != EOF)
              ungetch(c);
            return '-'; /* znak minus */
          }
        }
        while (isdigit(c)) {
                i++;
                s[i] = c;
                c = getch();
        }
        if (c == '.') /* buduj ułamek */
                do {
                        i++;
                        s[i] = c;
                        c = getch();
                } while (isdigit(c));
        s[++i] = '\0';
        if (c != EOF)
                ungetch(c);
        return NUMBER;
}
