#include<stdio.h>

int main(int argc, char**argv) {
  int annee;
  printf("Entrez une annee\n");
  scanf("%d",&annee);
  if ((((annee % 4) == 0) && ((annee % 100) !=0)) ||
    ((annee % 400) == 0))
    printf("Elle est bissextile\n");
  else printf("Elle n'est pas bissextile\n");
}
