#include <stdio.h>
#include "arbreInt.h"
#include "listeArbreParLC.h"

int main(int argc, char **argv) {
  arbre *a = newArbreInt(42);
  for (int i = 1; i < 4; i++)
    a = ajouterFils(a,newArbreInt(i));
  listeArbre *l = obtenirFils(a);
  for (int i = 0; i < longueur(l); i++) {
    arbre *f = elementA(l,i);
    for (int j = 1; j < 6; j++)
      f = ajouterFils(f,newArbreInt(obtenirElementRacine(f)*10 + j));
  }
  printf("Racine %d\n",obtenirElementRacine(a));
  printf("Ses fils :\n");
  l = obtenirFils(a);
  for (int i = 0; i < longueur(l); i++) {
    arbre *f = elementA(l,i);
    printf("%d et petits fils ",obtenirElementRacine(f));
    listeArbre *pf = obtenirFils(f);
    for (int j = 0; j < longueur(pf); j++) {
      arbre *pa = elementA(pf,j);
      printf("%d ",obtenirElementRacine(pa));
    }
    printf("\n");
  }
}
