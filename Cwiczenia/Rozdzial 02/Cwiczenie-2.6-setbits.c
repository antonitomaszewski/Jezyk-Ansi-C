// BŁĄD

#include <stdio.h>

/* setbits: wstaw n prawych bitów y do x od pozycji p */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
        unsigned a = (~((~0) << n)); // 0...01..1 (zera, potem n jedynek)
        a <<= (p + 1 - n); // 0...01...10...0 (zera do pozycji p + 1, potem n jedynek potem od pozycji p - n znów same zera)
        a = ~(a); // 1...10...01...1 (zera w granicah p do p - n, reszta jedynki)
        a &= x; // wyzerowanie pozycji od p do p-n w x, reszta taka jak w x (cośtam z x)0...0(cośtam z x)

        unsigned b = ~(~0 << n); // 0...01...1 (zera, potem n jedynek)
        b &= y; // zera, od pozycji n - 1 takie wartości jak w y 0...0 (cośtam z y)
        b <<= (p + 1 - n); // 0...0(cośtam z y)0...0

        return (a | b);
}

// a = (~((~0) << n))  // 0...01..1 (zera, potem n jedynek)
//     a = a << (p + 1 - n) // 0...01...10...0 (zera do pozycji p + 1, potem n jedynek potem od pozycji p - n znów same zera)
//         ~(a) // 1...10...01...1 (zera w granicah p do p - n, reszta jedynki)
//         x & a // wyzerowanie pozycji od p do p-n w x, reszta taka jak w x (cośtam z x)0...0(cośtam z x)
//
//         b = ~(~0 << n); // 0...01...1 (zera, potem n jedynek)
// b &= y;  // zera, od pozycji n - 1 takie wartości jak w y 0...0 (cośtam z y)
// b <<= (p + 1 - n);  // 0...0(cośtam z y)0...0
//
// a | b;              // (cośtam z x)0...0(cośtam z x) | 0...0(cośtam z y)0...0
// // (cośtam z x)[od p do p - n (cośtam z y)](cośtam z x)

int main()
{
        unsigned int a = 5, b = 255;  // a = 00000101, b = 1111 1111, setbits(a,7,4,b) = 0111 1101  == 125?
        unsigned int c = setbits(a, 7, 1, b);
        printf("%u\n", c);

        b = 16;
        printf("%u\n", setbits(a, 5, 1, b));


        b = 16;
        printf("%u\n", setbits(a, 7, 5, b));


        return 0;
}
