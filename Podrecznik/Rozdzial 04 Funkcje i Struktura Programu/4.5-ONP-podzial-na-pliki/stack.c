#include <stdio.h>
#include "calc.h"
#define MAXVAL 100
static int sp = 0;
static double val[MAXVAL];

/* push: wstaw f na stos */
void push(double f)
{
        if (sp < MAXVAL)
                val[sp++] = f;
        else
                printf("błąd: pełen stos: nie można umieścić %g\n", f);
}

/* pop: zdejmij i zwróć wartość ze szczytu */
double pop(void)
{
        if (sp > 0)
                return val[--sp];
        else {
                printf ("Błąd: pusty stos\n");
                return 0.0;
        }
}
