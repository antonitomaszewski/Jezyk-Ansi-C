#include <stdio.h>

/* wypisz zestawienie temperatur Celsjusza-Fahernheira
   dla clesius = 0, 20, ..., 300; wersja zmiennopozycyjna */

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;  /* dolna granica temperatur */
  upper = 300;/* górna granica */
  step = 20;  /* rozmiar kroku */

  printf("Celsius Fahr\n");
  celsius = lower;
  while (celsius <= upper)
  {
    fahr = (9.0*celsius) / 5.0 + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
