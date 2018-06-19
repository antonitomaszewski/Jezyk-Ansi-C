#include <stdio.h>

/* bitcount: policz bity 1 w x szybsza wersja */
/* x &= x - 1 usuwa jedynkę ze skrajnie prawego bitu, podobno,
   jakby mieć x = 2, czyli 0000 0010 to x-1 = 0000 0001 wtedy x&(x-1) daje 0000 0000, więc chyba dobrze, ale ja bym to opisał, że x&(x-1) usuwa najmniej znaczącą jedynkę
   6 = 0110
   5 = 0101
   6&5 = 0100
   więc x&(x-1) zmienia najmniej znaczący bit o wartości 1 na 0, a resztę pozostawia bez zmian */
/* czasowo jest to n = liczba bitów o wartości 1 w x */
int bitcount(unsigned x)
{
        int b;

        for (b = 0; x != 0; x &= x - 1)
                b++;
        return b;
}

int main()
{
        unsigned int a;

        for (a = 0; a < 10; a++)
                printf("Liczba bitów równych 1 w a = %d wynosi %d\n", a, bitcount(a));
        return 0;
}
