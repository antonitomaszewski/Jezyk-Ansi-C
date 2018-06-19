#include <stdio.h>

#define BUFSIZE 100 /* maks rozmiar bufora */

char buf[BUFSIZE];  /* bufor na zwroty w ungetch */
int bufp = 0; /* następne wolne miejsce w buforze */

int getch(void) /* weź znak, być może oddany na wejście */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* oddaj znak z powrotem na wejście */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: za wiele znaków\n");
        else
                buf[bufp++] = c;
}
