#include <string.h>

/* trim: usuń z s końcowe znaki odstępu, tabulacji, nowego wiersza */
int trim(char s[])
{
        int n;

        for (n = strlen(s) - 1; n >= 0; n--)  //* lecimy od końca, dopóki mamy jeden z tych 3 białych znaków naparzamy dalej,  gdy natrafimy na coś innego, do wychodzimy z tej pętli i potem po nim dajemy znak końca wiersza
                if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
                        break;
        s[n + 1] = '\0';
        return n; // zwracamy indeks ostatniego znaczącego znaku w tablicy (długość napisu - 1)
}
