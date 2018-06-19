#include <stdio.h>

/* any: podaj pozycję w s1 pierwszego wystąpienia dowolnego znaku z s2 */
/* biblioteczny odpowiednik: strpbrk - ale on zwraca wskaźnik do znalezionej pozycji */
int any(char s1[], char s2[])
{
        int i, j;

        for (i = 0; s1[i] != '\0'; i++)
                for (j = 0; s2[j] != '\0'; j++)
                        if (s1[i] == s2[j]) /* gdy znaleziono parę takich samych znaków */
                                return i; /* zwróć pozycję w s1 */
        return -1; /* żaden znak w s1 żadnemu w s2 -- intersection = {/0} */
}

int main()
{
        char s1[] = {"ABc"}, s2[] = {"seB"};
        printf("%d\n", any(s1, s2));
        s2[2] = 'C'; // s2 = {"seC"}
        printf("%d\n", any(s1, s2));
        return 0;
}
