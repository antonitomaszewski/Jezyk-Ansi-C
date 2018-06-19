/* escape: kopiuj znaki z t -> s, zamieniając  znaki nowego wiersza i znaki tabulacji na czytelne sekwencje specjalne */
void escape (char s[], char t[])
{
        int i, j;

        for (i = j = 0; t[i] != '\0'; i++)
                switch (t[i]) {
                case '\n':  /* był znak nowego wiersza, więc zamień */
                        s[j++] = '\\';
                        s[j++] = 'n';
                        break;
                case '\t':  /* był znak tabulacji więc zamień */
                        s[j++] = '\\';
                        s[j++] = 't';
                        break;
                default:  /* był jakikowliek inny znak, więc po prostu go przepisz */
                        s[j++] = t[i];
                        break;
                }
        s[j] = '\0';
}
/* unescape: kopiuj znaki z s -> t, zamieniając sekwencje specjalne na rzeczywiste znaki nowego wiersza i tabulacji */
void unescape(char s[], char t[])
{
        int i, j;

        for (i = j = 0; s[i] != '\0'; i++)
                if (s[i] != '\\')
                        t[j++] = s[i];
                else switch (s[++i]) {
                        case 'n':
                                t[j++] = '\n';
                                break;
                        case 't':
                                t[j++] = '\t';
                                break;
                        default:
                                t[j++] = '\\';
                                t[j++] = s[i];
                                break;
                        }
        t[j] = '\0';
}
