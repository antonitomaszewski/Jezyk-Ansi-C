#include <stdio.h>
#include <math.h> /* dla atof() */


#define MAXOP 100 /* maks. długość argumentu lub operatora */
#define NUMBER '0' /* sygnał znalezienia liczby */

int getop(char[]);
void push(double);
double pop(void);
/* kalkulator wg Odwrotnej Notacji Polskiej */
int main()
{
        int type;
        double op2;
        char s[MAXOP];

        while((type = getop(s)) != EOF) {
                switch (type) {
                case NUMBER:
                        push (atof(s));
                        break;
                case '+':
                        push(pop() + pop());
                        break;
                case '*':
                        push(pop() * pop());
                        break;
                case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                case '/':
                        op2 = pop();
                        if (op2 != 0.0)
                                push(pop() / op2);
                        else
                                printf("Błąd dzielenie przez 0\n");
                        break;
                case '%':
                        op2 = pop();
                        if (op2 != 0.0)
                                push(fmod(pop(), op2));
                        else
                                printf("Błąd: dzielenie przez 0 modulo\n");
                case '\n':
                        printf("\t%.8g\n", pop());
                        break;
                default:
                        printf("Błąd: nieznane polecenie %s\n", s);
                        break;
                }
        }
        return 0;
}


#define MAXVAL 100 /* maksymalna głębokość stusu */

int sp = 0; /* następne wonle miejsce na stosie */
double val[MAXVAL]; /* stos wartości */

/* push: wstaw f na stos */
void push(double f)
{
        if (sp < MAXVAL)
                val[sp++] = f;
        else
                printf("błąd: pełen stos: nie można umieścić %g\n", f);
}

/* pop: zdejmij i zwróć wartość ze szczytu */
double pop(void)
{
        if (sp > 0)
                return val[--sp];
        else {
                printf ("Błąd: pusty stos\n");
                return 0.0;
        }
}

/*
