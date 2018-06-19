#include <stdio.h>

float celsius(float fahr);

/* wypisz zestawienie temperatur Fahrenheita-Celsjusza
   dla fahr = 0, 20, ..., 300; wersja zmiennopozycyjna */

int main()
{
  float fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper)
  {
    printf("%3.0f  %6.1f\n", fahr, celsius(fahr));
    fahr = fahr + step;
  }
}

/* celsius: zamień stopnie Fahrenheita na Celsjusza */

float celsius(float fahr)
{
  return (5.0/9.0) * (fahr - 32.0);
}
