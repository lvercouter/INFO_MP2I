#include <stdlib.h>
#include "pileInt.h"

// constructeur qui cree renvoie une tete de pile vide
pileInt* newPileInt() {
  return NULL;
}

pileInt* empiler(pileInt *p, int val) {
  //un nouvel element est cree
  pileInt *e = (pileInt *)malloc(sizeof(pileInt));
  e->valeur = val;
  // et devient la tete de la pile
  e->suivant = p;
  return e;
}

pileInt* depiler(pileInt *p) {
  pileInt *nvTete;
  if (estPileVide(p))
    return p;
  else {
    nvTete = p->suivant;
    free(p);
    return nvTete;
  }
}

int obtenirElementPile(pileInt *p) {
  return p->valeur;
}

int estPileVide(pileInt *p) {
  return (p == NULL);
}
