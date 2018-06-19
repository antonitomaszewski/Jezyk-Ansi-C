/* rightrot: przesuń x cyklicznie w prawo o n pozycji */
unsigned rightrot(unsigned x, int n)
{
        int wordlength(void); /* długość słowa maszyny */
        int wordlen = wordlength();
        unsigned rbits; /* skrajnie prawe bity słowa */

        if ((n = n % wordlen) > 0) {
                rbits = ~(~0 << n) & x; /* n skrajnie prawych bitów x */
                rbits <<= (wordlen - n);  /* przesuń w lewo 0...0(costam z x) <<= (wordlen - n), czyli je ustawione tak: (costam z x)0...0 */
                x >>= n;    /* x przesuń w prawo o n pozycji, czyli mam 0...0(pierwsze (wordlen - n) bitów z x) */
                x |= rbits;   /* (n najmiej znaczących bitów x)0...0 | (wordlen-n najbardziej znaczących bitów x) */
        }
        return x;
}
