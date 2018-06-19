#include <stdio.h>

#define MAXLINE 1000 /* maksymalny rozmiar wiersza */

int getline_new(char line[], int maxline);
void copy_new(char to[], char from[]);

/* wypisz najdłuższy wiersz */
int main()
{
        int len; /* długość bierzącego wiersza */
        int max; /* poprzednia maksymalna długość */
        char line[MAXLINE]; /* bieżący wiersz z wejścia */
        char longest[MAXLINE]; /* przechowywany maksymalny wiersz */

        max = 0;
        while((len = getline_new(line, MAXLINE)) > 1)
                if (len > max) {
                        max = len;
                        copy_new(longest, line);
                }
        if (max > 0) /* był chociaż jeden wiersz niepusty */
                printf("%s", longest);
        return 0;
}

/* getline: wczytaj wiersz do s, dopaj jego długość */
int getline_new(char s[], int lim)
{
        int c, i;

        for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if (c =='\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

/* copy_new: przepisz z 'from' do 'to' */
/* to musi być dostatecznie duże */
void copy_new(char to[], char from[])
{
        int i = 0;

        i = 0;
        while((to[i] = from[i]) != '\0')
                ++i;
}
