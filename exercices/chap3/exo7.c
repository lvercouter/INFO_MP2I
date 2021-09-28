#include <stdio.h>
#include "../../code/chap3/arbreInt.h"
#include "../../code/chap3/listeArbreParLC.h"

int valeurMaximale(arbre *a) {
  int max = a->valeur;
  listeArbre* fils = obtenirFils(a);
  while(fils != NULL) {
    int maxFils = valeurMaximale(fils->valeur);
    if (maxFils > max) max = maxFils;
  }
  return max;
}
