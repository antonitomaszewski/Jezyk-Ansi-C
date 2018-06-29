#include <stdio.h>
#include <string.h>
#include <math.h> /* dla atof() */

#define MAXOP 100  /* maks. rozmiar argumentu lub operatora */
#define NUMBER '0'  /* sygnał znalezienia liczby */
#define NAME   'n'  /* sygnał znalezienia nazwy */

int getop(char []);
void push(double);
double pop(void);
void mathfnc(char []);
void kalkulator();

/* kalkulator według Odwrotnej Notacji Polskiej */
void kalkulator()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case NAME:  /* znaleziono nazwę funkcji bibliotecznej */
        mathfnc(s);
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("Błąd: dzielenie przez / 0\n");
        break;
      case '\n': /* pobierz i wypisz wierzchołek stosu */
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("Błąd nieznana operacja %s\n", s);
        break;
    }
  }
  return 0;
}

/* mathfnc: sprawdź, czy w s jest nazwa aktualnej funkcji bibliotecznej */
void mathfnc(char s[])
{
  double op2;

  if (strcmp(s, "sin") == 0)
    push(sin(pop()));
  else if (strcmp(s, "cos")) == 0)
    push(cos(pop()));
  else if (strcmp(s, "exp") == 0)
    push(exp(pop()));
  else if (strcmp(s, "pow") == 0) {
    op2 = pop();
    push(po2(pop(), op2));
  } else
    printf("Błąd: brak implementacji  %s\n", s);    
}
