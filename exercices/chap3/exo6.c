#include <stdio.h>
#include "../../code/chap3/ABR.h"

ABR* rechercher(ABR *a, int val) {
  while (a != NULL) {
    if (a->valeur == val) return a;
    else if (a->valeur > val) a = a-> gauche;
    else a = a->droit;
  }
  return NULL;
}
