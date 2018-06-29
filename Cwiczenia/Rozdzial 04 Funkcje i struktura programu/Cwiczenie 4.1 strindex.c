/* strindex: podaj pozycję ostatniego tekstu t w s lub -1 (jeśli go nie ma) */
int strindex(char s[], char t[])
{
  int i, j, k, pos;

  pos = -1;
  for (i = 0; s[i] != '\0'; i++) { // dopóki można czegokolwiek szukać w s
    j = i;  // wprowadzamy nowy indeks j, chwilowy, żeby po wyjściu z pętli pozostawić niezmienione i
    k = 0;  // indeks dla t
    while (t[k] != '\0' && s[j] == t[k]) {  // dopóki jest coś w t i t[0...k] == s[i...j] -> j++, k++, próbujemy porównać o krok dalej
      j++;
      k++;
    }

    if (k > 0 && t[k] == '\0')  // jeśli było cokolwiek do porównania w t i doszliśmy do końca tekstu
    pos = i;
  }
  return pos;
}
