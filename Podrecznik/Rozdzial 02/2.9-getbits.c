/* getbits: daj n bitów x od pozycji p */
// np. getbits(x, 4, 3) zwróci bity 4, 3 i 2
unsigned getbits(unsigned x, int p, int n)
{
        return (x >> (p + 1 - n)) & ~(~0 << n);
}
