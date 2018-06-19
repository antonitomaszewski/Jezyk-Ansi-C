#include <string.h>

void reverse(char s[])
{
        int c, i, j;

        for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}

/* itoa: zamień liczbę n na znaki w tablicy s */
void itoa(int n, char s[])
{
        int i, sign;

        if ((sign = n) < 0) /* zanotuj znak liczby */
                n = -n; /* n ma być dodatnie od teraz */
        i = 0;
        do {  /* generuj cyfry w odwrotnym porządku */
                s[i++] = n % 10 + '0'; /* weź następną cyfrę */
        } while ((n /= 10) > 0); /* usuń ją */
        if (sign < 0)
                s[i++] = '-';
        s[i] = '\0';
        reverse(s); /* odwróć kolejność cyfr */
}
