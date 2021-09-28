#include<stdio.h>

int main(int argc, char**argv) {
  int mois;
  printf("Entrez le numero d'un mois de l'annee : ");
  scanf("%d",&mois);
  switch (mois) {
    case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
      printf("Ce mois a 31 jours\n");
      break;
    case 4 : case 6 : case 9 : case 11 :
      printf("Ce mois a 30 jours\n");
      break;
    case 2 :
      printf("Ce mois a 28 ou 29 jours\n");
      break;
    default :
      printf("Ce numero n'est pas celui d'un mois\n");
  }
}
