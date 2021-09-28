#include<stdio.h>

int bissextile(int annee) {
  return ((((annee % 4) == 0) && ((annee % 100) !=0)) ||
    ((annee % 400) == 0));
}

int main(int argc, char**argv) {
  int mois, annee;
  printf("Entrez une annee : ");
  scanf("%d",&annee);
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
      if (bissextile(annee))
        printf("Ce mois a 29 jours\n");
      else
        printf("Ce mois a 28 jours\n");
      break;
    default :
      printf("Ce numero n'est pas celui d'un mois\n");
  }
}
