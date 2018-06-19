#include <stdio.h>

/* expand: rozwiń skrócone zapisy z s1 i zapisz je do s2 */
void expand(char s1[], char s2[])
{
        char c;
        int i, j;

        i = j = 0;
        while((c = s1[i++]) != '\0') /* pobierz znak z s1 */
                if (s1[i] == '-' && s1[i + 1] >= c) { /* mamy ciąg znaków do rozszerzenia */
                        i++;
                        while (c < s1[i]) /* rozwiń skrów w s2 */
                                s2[j++] = c++;
                } else {
                        s2[j++] = c;  // po prostu przepisz znak c = s1[i] ( na początku pętli) do s2, i++, j++ zwiększają liczniki post factum
                }
        s2[j] = '\0';
}

int main()
{
        char s1[4] = {'!', '-', '~', '\0'};
        char s2[1000];
        for (int i = 0; i < 999; i++)
                s2[i] = '0';
        expand(s1, s2);
        int i;

        i = 0;
        while (s2[i] != '\0')
                printf("%c", s2[i++]);
        // for (int i = 0; i < 999; i++)
        //         printf("%c", s2[i]);
        return 0;
}
