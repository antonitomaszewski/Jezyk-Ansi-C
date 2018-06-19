#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: pobierz następny operator lub argument */
int getop(char s[])
{
        int i, c;

        i = 0;
        do {
                c = getch();
        } while (c == ' ' || c == '\t');
        s[i] = c;
        s[++i] = '\0';
        if (!isdigit(c) && c != '.')
                return c; /* to nie liczba */
        // i = 1;
        // if(isdigit(c))  /* buduj część całkowitą */
        //         do {
        //                 c = getch();
        //                 i++;
        //                 s[i] = c;
        //         } while (isdigit(c));
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
