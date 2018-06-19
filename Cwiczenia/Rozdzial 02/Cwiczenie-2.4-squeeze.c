#include <stdio.h>

/* squeeze: usuń z s1 wszystkie znaki występujące w s2 */
void squeeze(char s1[], char s2[])
{
        int i, j, k;

        for (i = k = 0; s1[i] != '\0'; i++) {
                for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
                        ; /* jeśli znaki się różnią to nie ma potrzeby nic robić */
                if (s2[j] == '\0')   // koniec tekstu s2 -- znaku s1[i] nie ma w s2
                        s1[k++] = s1[i];  // k to indeks dla którego wszystkie znaki o mniejszym indeksie w s1 są unikalne i nie występują w s2
        }
        s1[k] = '\0';
}

int main()
{
        char s1[] = {"abc"}, s2[] = {"cfa"};
        squeeze(s1, s2);
        printf("%s\n", s1);
        return 0;
}
