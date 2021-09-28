int puissance(int a, int n) {
  int r = 1;
  for (int i = 1; i <= n; i++)
    r = r * a;
  return r;
}
