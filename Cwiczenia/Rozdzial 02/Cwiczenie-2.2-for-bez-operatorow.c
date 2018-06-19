/* pierwotna postać :
   for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
   s[i] = c;
 */

/* W ENUM (typ wyliczeniowy) DOMYŚLNIE WARTOŚĆI NADAWANE SĄ PO KOLEI OD 0 po kolejnych naturalnych, jeśli chcesz od innego daj a1 = n, wtedy a2 = n+1 itd. */
enum loop { NO, YES };  /* czy w pętli? NIE, TAK */
enum loop okloop = YES;

int i = 0;
while (okloop == YES)
        if (i >= lim - 1) /* koniec pętli, gdy i poza poprawnym zakresem */
                okloop = NO;
        else if ((c = getchar()) == '\n')
                okloop = NO; /* koniec wiersza */
        else if (c == EOF)
                okloop = NO; /* koniec pliku */
        else
                s[i++] = c; /* najpierw s[i] = c, potem i++, ++i działa naodwrót: najpierw i++ potem s[i] = c */
