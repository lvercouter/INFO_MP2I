int puissance(int a, int n) {
  int resultat = 1;
  for (int i = 1; i <= n; i++)
    resultat = resultat * a;
  return resultat;
}
