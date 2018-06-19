#include <stdio.h>

/* rightrot: przesuń x cyklicznie w prawo o n pozycji */
unsigned rightrot(unsigned x, int n)
{
        int wordlength(void); /* długość słowa maszyny */
        int rbit;         /* skrajnie prawy bit słowa */

        while (n-- > 0) {
                rbit = (x & 1) << (wordlength() - 1); // biorę najmniej znaczący bit i przesuwam go o na najbardziej znaczącą pozycję
                x >>= 1; // przesuwam całą liczbę o 1 w prawo, dzięki temu wszystkie bity się przesunęły w prawo, a najbardziej znaczący bit jest równy 0, teraz wystarczy dać ora
                x |= rbit;
        }
        return x;
}

/* wordlength: oblicz długość słowa maszyny */
int wordlength(void)
{
        int i;
        unsigned v = (unsigned) ~0; // mamy słowo długości n o wartośći 2^(n-1) i dopóki jej nie wyzerujemy to dodajemy do licznika długości

        for (i = 1; (v >>= 1) > 0; i++)
                ;

        return i;
}

int main()
{
        unsigned int a = 2;
        int n;

        n = 1;
        printf("dla a = %d rotacja w prawo o n = %d pozycji daje nam wynik = %d\n", a, n, rightrot(a,n));

        a = 4;
        n = 2;
        printf("dla a = %d rotacja w prawo o n = %d pozycji daje nam wynik = %d\n", a, n, rightrot(a,n));
}
