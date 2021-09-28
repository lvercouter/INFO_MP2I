#include<stdio.h>

int main(int argc, char**argv) {
  int n, factoriel;
  printf("De quel nombre voulez-vous le factoriel ? ");
  do {
    scanf("%d",&n);
    if (n < 1) printf("Le nombre doit etre strictement positif");
  } while (n <1);
  factoriel = 1;
  for (int i = 2; i <= n; i ++)
    factoriel = factoriel * i;
  printf("%d! = %d\n",n,factoriel);
}
