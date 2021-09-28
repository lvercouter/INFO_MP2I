#include<stdio.h>

void afficheLigne(int numLigne, int taille) {
  // ecriture des espaces
  for (int i = 1; i <= (taille-numLigne); i++)
    printf(" ");
  // ecriture des etoiles suivies d'un espace
  for (int i = 1; i <= numLigne; i++)
    printf("* ");
  //saut de ligne
  printf("\n");
}

int main(int argc, char**argv) {
  int n;
  printf("Entrez le nombre de lignes souhaitees ? ");
  scanf("%d",&n);
  // une iteration par ligne
  for (int i = 1; i <= n; i++)
    afficheLigne(i,n);
}
