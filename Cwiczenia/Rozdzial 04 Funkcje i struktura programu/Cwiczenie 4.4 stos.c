#include <stdio.h>
#include <math.h> /* dla atof() */


#define MAXOP 100 /* maks. długość argumentu lub operatora */
#define NUMBER '0' /* sygnał znalezienia liczby */

int getop(char[]);
void push(double);
double pop(void);
void clear(void);
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
                /* DODANE: POCZĄTEK */
                case '?': /* Wypisz wierzchołek stosu */
                  op2 = pop();
                  printf("\t%.8g\n", op2);  /* ściągamy wartość ze stosu, drukujemy i wrzucamy ją powrotnie */
                  push(op2);
                  break;
                case 'c': /* Wyczyść stos */
                  clear();
                  break;
                case 'd': /* Utwórz na stosie duplikat wierzchołka */
                  op2 = pop();
                  push(op2);
                  push(op2);
                  break;
                case 's': /* zamień miejscami 2 szczytowe elementy */
                  op1 = pop();
                  op2 = pop();
                  push(op1);
                  push(op1);
                  break;
                /* DODANE: KONIEC */
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


/* clear: wyczyść stos, znajduje się w pliku razem z push i pop*/
void clear(void)
{
  sp = 0;
}
