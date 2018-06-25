#include <stdio.h>
#define BUFSIZE 100
static char buf[BUFSIZE]; // dzięki static buf i bufp będąwidoczne wyłącznie dla getch i ungetch (od wystąpienia do końca pliku źródłowego)
static int bufp = 0;

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
