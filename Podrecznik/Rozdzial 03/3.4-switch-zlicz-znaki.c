#include <stdio.h>

int main()
{
        int c, i, nwhite, nother, ndigit[10];

        nwhite = nother = 0;
        for (i = 0; i < 10; i++)
                ndigit[i] = 0;
        while((c = getchar()) != EOF && c != 'a') {
                switch (c) {
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                        ndigit[c - '0']++;
                        break;
                case ' ': case '\n': case '\t':
                        nwhite++;
                        break;
                default:
                        nother++;
                        break;
                }
        }

        printf("cyfry =");
        for (i = 0; i < 10; i++)
                printf(" %d było %d razy,",i,ndigit[i]);
        printf(" białe znaki = %d, inne = %d\n", nwhite, nother);
        return 0;
}
