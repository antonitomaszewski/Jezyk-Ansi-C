#include <string.h>

/* strindex: podaj pozycję ostatniego tekstu t w s lub -1 */
int strindex(char s[], t[])
{
  int i, j, k;

  for (i = strlen(s) - strlen(t); i >= 0; i--) { // idziemy od końca, wtedy pierwszy napotkany, będzie tym o który nam chodziło
    j = i;
    k = 0;
    while(t[k] != '\0' && s[j] == t[k]) {
      j++;
      k++;
    }
    if (k > 0 && t[k] == '\0')
    return i;
  }
  return -1;
}
