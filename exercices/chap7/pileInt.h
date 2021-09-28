#ifndef PILEINT_H
#define PILEINT_H

struct spile {
  int valeur;
  struct spile *suivant;
};
typedef struct spile pileInt;
#endif

pileInt* newPileInt();
pileInt* empiler(pileInt *f, int val);
pileInt* depiler(pileInt *f);
int obtenirElementPile(pileInt *f);
int estPileVide(pileInt *f);
