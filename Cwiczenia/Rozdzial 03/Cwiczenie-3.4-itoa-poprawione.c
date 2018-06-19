#include <stdio.h>
/* JEST JAKIŚ BŁĄD W ITOA -- GENERUJE LICZBY + 49 */
#define abs(x)  ((x) < 0 ? -(x) : (x))

/* itoa: zamień liczbę n na znaki w s - wersja zmieniona */
void itoa(int n, char s[])
{
        int i, sign;
        void reverse(char s[]);
        int length(char s[]);

        sign = (n < 0) ? -1 : 1;
        i = 0;
        do {  /* generuj cyfry w odwrotnym porządku */
                s[i++] = abs(n % 10) + '0'; /* weź następną cyfrę */
        } while ((n /= 10) != 0);  /* usuń ją */
        if (sign == -1)
                s[i++] = '-'; /* n był ujemna */
        s[i] = '\0';
        printf("indeks = %d, length = %d\n", i, length(s));
        for (int j = i-1; j >= 0; j--)
                printf("%c", s[j]);
        reverse(s); /* odwróć kolejność cyfr w s */
        for (int j = 0; j <= i-1; j++)
                printf("%c", s[j]);
}
void reverse(char s[])
{
        int length(char s[]);
        int len = length(s) - 1;
        int i = 0;
        char temp;

        while (i < len) {
                temp = s[i];
                s[i] = s[len];
                s[len] = temp;
                i++;
                len--;
        }
}
int length(char s[])
{
        int i;

        while (s[i++] != '\0')
                ;
        return i - 1;
}

int main()
{
        int n = -3;
        char s[3] = {'a', 'a', '\0'};
        itoa(n, s);
        int i;
        //
        // i = length(s) - 1;
        // while (i != 0)
        //         printf("%c ", s[i--]);
        // i = 0;
        // while (s[i] != '\0')
        //         printf("%d ", s[i++]);
        // printf("\n");
        // i = 0;
        // while (s[i] != '\0')
        //         printf("%c", s[i++]);

        int j;
        char t[3] = {'a', 'b', '\0'};
        printf("\n%d\n", length(t));
        j = 0;
        while(t[j] != '\0')
                printf("%c", t[j++]);
        printf("\n");
        reverse(t);
        j = 0;
        while(t[j] != '\0')
                printf("%c", t[j++]);
        printf("\n");

        return 0;
}
