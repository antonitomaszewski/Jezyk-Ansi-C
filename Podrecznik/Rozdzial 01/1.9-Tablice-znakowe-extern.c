#include <stdio.h>

#define MAXLINE 1000 /* maksymalny rozmiar wiersza */

int max; /* poprzednia maksymalna długość */
char line[MAXLINE]; /* bieżący wiersz z wejścia */
char longest[MAXLINE]; /* przechowywany maksymalny wiersz */

int getline_new(void);
void copy_new(void);

/* wypisz najdłuższy wiersz, wersja specjalna */
int main()
{
        int len; /* długość bierzącego wiersza */
        extern int max;
        extern char longest[];

        max = 0;
        while((len = getline_new()) > 1)
                if (len > max) {
                        max = len;
                        copy_new();
                }
        if (max > 0) /* był chociaż jeden wiersz niepusty */
                printf("%s", longest);
        return 0;
}

/* getline: wczytaj wiersz do s, dopaj jego długość */
int getline_new(void)
{
        int c, i;
        extern char line[];

        for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;
        if (c =='\n') {
                line[i] = c;
                ++i;
        }
        line[i] = '\0';
        return i;
}

/* copy_new: przepisz z 'from' do 'to' */
/* to musi być dostatecznie duże */
void copy_new(void)
{
        int i = 0;
        extern char line[], longest[];

        i = 0;
        while((longest[i] = line[i]) != '\0')
                ++i;
}
