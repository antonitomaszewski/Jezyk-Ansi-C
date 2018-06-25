/* quicksort: uporządkuj v[left] ... v[right] rosnąco */
void quicksort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right)  /* tablica jest pusta lub ma jeden element -- zakończ działanie (bo jest posortowana) */
    return;
  swap(v, left, (left + right) / 2);  // z jakiegoś powodu typ bierze środkowy element jako dobry do wyznaczania podziału
  last = left;
  for (i = left + 1; i <= right; i++)
    if (v[i] < v[left])
      swap(v, ++last, i); /* kolo zamienia tylko idąc od lewej, a nie naraz od prawej i lewej i zamieniając ze sobą dwa niepasujące */
  swap(v, left, last);  /* wracamy z naszym elementem podziałowym w miejsce gdzie leży obecnie granica (last) */
  quicksort(v, left, last - 1);
  quicksort(v, last + 1, right);  // v[last] jest w dobrym miejscu
}

/* swap: zamień miejscami v[i] i v[j] */
void swap(int v[], int i, int j)
{
  int temp;

  temo = v[i];
  v[i] = v[j];
  v[j] = temp;
}
