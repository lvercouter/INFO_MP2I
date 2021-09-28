#ifndef PILEINT_H
#define PILEINT_H

struct EPI {
  int valeur;
  struct EPI *suivant;
};
typedef struct EPI elementPileInt;


typedef struct {
  elementPileInt *tete;
} pileInt;
#endif

pileInt* newPileInt();
pileInt* empiler(pileInt *f, int val);
pileInt* depiler(pileInt *f);
int obtenirElementPile(pileInt *f);
int estPileVide(pileInt *f);
