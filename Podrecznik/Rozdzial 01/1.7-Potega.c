#include <stdio.h>

int power(int m, int n);
int power1(int m, int n);

/* testowanie funkcji power */

int main()
{
        int i;

        for(i = 0; i < 10; ++i)
                printf("%d %d %d \n", i, power(2,i), power1(-3,i));
        return 0;
}

/* power:: podnieś base do potęgi n. n>=0 */
int power(int base, int n)
{
        int i, p;

        p = 1;
        for (i = 1; i <= n; ++i)
                p = p * base;
        return p;
}

int power1(int base, int n)
{
        int p;

        for (p = 1; n > 0; --n)
                p = p * base;
        return p;
}
