/* strcat: dowiąż tekst z t do końca tekstu w s;
   tablica s musi być dostatecznie duża */
void strcat(char s[], char t[])
{
        int i, j;

        i = j = 0;
        while (s[i] != '\0') /* znajdź koniec tekstu w s */
                i++;
        while ((s[i++] = t[j++]) != '\0') /* przepisz tekst */
                ;
}
