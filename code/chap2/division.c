#include<stdio.h>

int main(int argc, char**argv) {
  int dividende, diviseur, resultat;
  printf("Entrez les 2 valeurs a diviser\n");
  printf("Dividende = ");
  scanf("%d",&dividende);
  printf("Diviseur = ");
  scanf("%d",&diviseur);
  if (diviseur != 0) {
    resultat = dividende / diviseur;
    printf("Le resultat est : %d\n", resultat);
  } else printf("La division par zero n'est pas permise\n");
}
