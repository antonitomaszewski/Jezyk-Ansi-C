#include <stdio.h>

/* invert: zamień n bitów x od pozycji p: 1 na 0 i odwrotnie */
unsigned invert(unsigned x, int p, int n)
{
        unsigned a = ~(~0 << n);    // 0...01...1 -- jedynki na pozycjach od 0 do n-1, reszta 0
        a <<= (p + 1 - n);    // 0...01...10...0  -- jedynki na pozycjach od p do p+1-n, reszta 0 :: W TYM MOMENCIE MAM STWORZONĄ JUŻ MASKĘ a, wystarczy nią potraktować x i będę mieć wynik
        a ^= x; // 1010011001011000 jakiś dowolny x i do tego xor z maską a daje mi:
        /* 0^1 == 1, 0^0 = 0, więc w przedziałach, gdzie a = 0 nic nie zmieniam,
           zmiany dokonują się tam gdzie a = 1, czyli w przedziale p...(p + 1 - n),
           tutaj mam 1^0=1, więc zmieniam znak oraz 1^1=0, więc również zmieniam znak

           W tym komentarzu na pierwszej pozycji zawsze jest bit 'a', a na drugiej bit 'x', po równasie a^x */
        // return x ^ (~(~0 << n) << (p + 1 - n));
        return a;
}


int main()
{
        unsigned int a = 255; // 1111 1111
        int p = 0, n = 0;
        printf ("%d od pozycji p = %d do p - n + 1 = %d, chcę zamienic n = %d znaków na odwrotne, wynik =  %d\n", a, p, p - n + 1, n, invert(a, p, n));

        p = 0, n = 1;
        printf ("%d od pozycji p = %d do p - n + 1 = %d, chcę zamienic n = %d znaków na odwrotne, wynik =  %d\n", a, p, p - n + 1, n, invert(a, p, n));

        p = 1, n = 2;
        printf ("%d od pozycji p = %d do p - n + 1 = %d, chcę zamienic n = %d znaków na odwrotne, wynik =  %d\n", a, p, p - n + 1, n, invert(a, p, n));

        p = 7, n = 8;
        printf ("%d od pozycji p = %d do p - n + 1 = %d, chcę zamienic n = %d znaków na odwrotne, wynik =  %d\n", a, p, p - n + 1, n, invert(a, p, n));

}
