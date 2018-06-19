#include <stdio.h>

/* wylicz rzeczywiste dziedziny wartości typów */
int main()
{
        /* signed - typy ze znakiem */
        printf("signed char min     = %d\n", -(char) ((unsigned char) ~0 >> 1));
        printf("signed char max     = %d\n", (char) ((unsigned char) ~0 >> 1)); /* kolejność: 1) ~0 -> mamy liczbę, która wszędzie ma jedynki, 11...111  2) (unsigned char) ~0 -> przekształcamy do typu unsigned char 3) (unsigned char) ~0 >> 1 przesuwamy w prawo o jeden, by wyzerować bit znaku, mamy 0111...111 4) (char) ((unsigned char) ~0 >> 1)) rzutujemy na char koniec -> otrzymujemy największą możliwą wartość dla obiektu typu char ze znakiem */
        printf("signed short min     = %d\n", -(short) ((unsigned short) ~0 >> 1));
        printf("signed short max     = %d\n", (short) ((unsigned short) ~0 >> 1));
        printf("signed int min     = %d\n", -(int) ((unsigned int) ~0 >> 1));
        printf("signed int max     = %d\n", (int) ((unsigned int) ~0 >> 1));
        printf("signed long min     = %ld\n", -(long) ((unsigned long) ~0 >> 1));
        printf("signed long max     = %ld\n", (long) ((unsigned long) ~0 >> 1));

        /* unsigned - typy bez znaku */
        printf("unsigned char max     = %u\n", (unsigned char) ~0);
        printf("unsigned short max     = %u\n", (unsigned short) ~0);
        printf("unsigned int max     = %u\n", (unsigned int) ~0);
        printf("unsigned long max     = %lu\n", (unsigned long) ~0);
}
