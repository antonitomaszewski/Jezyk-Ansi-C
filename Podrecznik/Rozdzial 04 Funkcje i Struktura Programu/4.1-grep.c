#include <stdio.h>
#define MAXLINE 1000 /* maksymalna długość wiersza */

int getline_moj(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "nie"; /* szukany wzorzec */

/* wypisz wszystkie wiersze zawierające wzorzec, działa na odwrót */

int main()
{
        char line[MAXLINE];
        int found = 0;

        while(getline_moj(line, MAXLINE) > 0)
                if (strindex(line, pattern) >= 0) {
                        printf("%s", line);
                        found++;
                        // printf("nie\n");
                } else {
                        // printf("nie brak\n");
                }
        return found;         /* podaj liczbę znalezionych wierszy */
}

/* getline: wczytaj wiersz do tablicy s; podaj jego długość */
int getline_moj(char s[], int lim)
{
        int c, i;

        i = 0;
        while((--lim) > 0 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        if (c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
}

/* strindex: określ pozycję tekstu t w s lub swróć -1, gdy brak */
int strindex(char s[], char t[])
{
        int i, j, k;

        for (i = 0; s[i] != '\0'; i++) {
                j = i, k = 0;
                while(t[k] != '\0' && s[j] == t[k])
                        j++, k++;
                /* nie bierzemy pod uwagę, że s[i] == t[0] ^ len(t) > (len(s) - i) wtedy wyjdzie za rozmiar s */

                if (k > 0 && t[k] == '\0')
                        return i;
        }
        return -1;
}
