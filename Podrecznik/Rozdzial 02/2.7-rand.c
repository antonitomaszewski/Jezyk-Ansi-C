unsigned long int next = 1;

/* rand: daj pseudolosowo liczbę całkowitą z przedziału 0...32767 */
int rand(void)
{
        next = next * 1103515245 + 12345;
        return (unsigned int) (next / 65536) % 32768;
}

/* srand: ustal zarodek (seed) dla funkcji rand() */
void srand(unsigned int seed)
{
        next = seed;
}
