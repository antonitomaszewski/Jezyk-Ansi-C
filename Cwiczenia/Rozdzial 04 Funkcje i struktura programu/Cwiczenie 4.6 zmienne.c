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
  int i, type, var = 0;
  double op2, v;
  char s[MAXOP];
  double variable[26];

  for (i = 0; i < 26; i++)
    variable[i] = 0.0;

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
      /* DODANE: POCZĄTEK */
      case '=':
        pop();
        if (var >= 'A' && var <= 'Z')
          variable[var - 'A'] = pop();
        else
          printf("Błąd: brak odopwiedniej (A...Z) nazwy zmiennej\n");
        break;
      /* DODANE: KONIEC */

      case '\n': /* pobierz i wypisz wierzchołek stosu */
        v = pop();
        printf("\t%.8g\n", v);
        break;
      default:
        if (type >= 'A' && type <= 'Z')
          push(variable[type - 'A']);
          else if (type == 'v')
            push(v);
        else
          printf("Błąd: nieznane polecenie %s\n", s);
        break;
    }
    var = type;
  }
  return 0;
}
