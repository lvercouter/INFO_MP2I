#include<stdio.h>

int main(int argc, char**argv) {
  int n;
  printf("Entrez le nombre de lignes souhaitees ? ");
  scanf("%d",&n);
  // une iteration par ligne
  for (int i = 1; i <= n; i++) {
    // ecriture des espaces
    for (int j = 1; j <= (n-i); j++)
      printf(" ");
    // ecriture des etoiles suivies d'un espace
    for (int j = 1; j <= i; j++)
      printf("* ");
    //saut de ligne
    printf("\n");
  }
}
