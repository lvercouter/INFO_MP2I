int main(int argc, char **argv) {
  int n, factoriel;
  printf("De quel nombre voulez-vous le factoriel ? ");
  scanf("%d",&n);
  factoriel = 0;
  for (int i = 2; i <= n; i ++)
    factoriel = factoriel * i;
  printf("%d! = %d\n",n,factoriel);
}
