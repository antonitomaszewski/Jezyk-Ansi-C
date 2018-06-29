#include <ctype.h>

#define MAXLINE


/* atof: przekształć ciąg cyfr s na wartość zmiennopozycyjną podwójnej precyzji, aby obsługiwała naukową notację */
double atof(char s[])
{
        double val, power;  /* znormalizowana liczba */
        int i, sign;
        int exp;  /* wykładnik potęgi */

        i = 0;
        while(isspace(s[i]))  // pomiń białe znaki
                i++;
        sign = ((s[i] == '-') ? -1 : 1);  // znak liczby
        if (s[i] == '+' || s[i] == '-')
                i++;

        val = 0.0;
        while (isdigit(s[i])) {
                val = 10.0 * val + (s[i] - '0');
                i++;
        }
        if (s[i] == '.')
                i++;
        power = 1.0;
        while (isdigit(s[i])) {
                val = 10.0 * val + (s[i] - '0');
                power *= 10.0;
        }
        val =  sign * val / power;

        if (s[i] == 'e' || s[i] == 'E') {
          sign = (s[++i] == '-') ? -1 : 1;

          if (s[i] == '+' || s[i] == '-')
            i++;
          for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
          if (sign == 1)  /* wykłądnik dodatni */
            while (exp-- > 0)
              val *= 10;
          else  /* ujemny */
            while (exp-- > 0)
            val /= 10;
        }

        return val;
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

/* atoi: zamień ciąg cyfr s na wartość całkowitą; użyj atof */
int atoi(char s[])
{
        double atof(char s[]);

        return (int) atof(s);
}

/* prymitywny kalkulator biurowy */

int main()
{
        double sum, atof(char[]);
        char line[MAXLINE];
        int getline_moj(char line[], int max);

        sum = 0;
        while(getline_moj(line, MAXLINE) > 0)
                printf("\t%g\n", sum += atof(line));
        return 0;
}
