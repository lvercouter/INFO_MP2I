#include <stdlib.h>
#include "pileInt.h"

// constructeur qui cree renvoie une tete de pile vide
pileInt* newPileInt() {
  pileInt *p = (pileInt *)malloc(sizeof(pileInt));
  p->tete = NULL;
  return p;
}

pileInt* empiler(pileInt *p, int val) {
  //un nouvel element est cree
  elementPileInt *e = (elementPileInt *)malloc(sizeof(elementPileInt));
  e->valeur = val;
  // et devient la tete de la pile
  e->suivant = p->tete;
  p->tete = e;
  return p;
}

pileInt* depiler(pileInt *p) {
  elementPileInt *tmp;
  if (!estPileVide(p)) {
    tmp = p->tete;
    p->tete = p->tete->suivant;
    free(tmp);
  }
  return p;
}

int obtenirElementPile(pileInt *p) {
  return p->tete->valeur;
}

int estPileVide(pileInt *p) {
  return (p->tete == NULL);
}
