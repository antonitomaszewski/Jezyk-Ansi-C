#include <stdio.h>

/* itob: zamień liczbę n na postać znakową w podstawie b i zapisz do tablicy s */
void itob(int n, char s[], int b)
{
        int n_ = n;
        int i, j, sign;
        void reverse(char s[]);

        sign = (n < 0) ? -1 : 1;
        n *= sign;

        i = 0;
        do {
                j = n % b;
                s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
        } while ((n /= b) > 0);
        if (sign == -1)
                s[i++] = '-';
        s[i] = '\0';
        printf("%d w bazie %d = ",n_,b);
        for (int j = i - 1; j >= 0; j--)
                printf("%c",s[j]);
        reverse(s);
        printf("\n");
        printf("%d w bazie %d = ",n_,b);
        for (int j = 0; j <= i - 1; j++)
                printf("%c",s[j]);
        printf("\n");

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
        int a;
        char s[4] = { '?', '?', '?', '\0' };
        int base;

        a = -4;
        base = 3;
        itob(a,s,base);
}
